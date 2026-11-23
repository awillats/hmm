#include "doctest.h"
#include <hmm.h>

#include <algorithm>
#include <cmath>
#include <numeric>
#include <stdexcept>
#include <vector>

TEST_SUITE("hmm_viterbi") {

TEST_CASE("HMMv constructors and row normalization") {
  SUBCASE("2-state rate constructor") {
    std::vector<double> trs = {0.1, 0.2};
    std::vector<double> frs = {0.15, 0.85};
    std::vector<double> pis = {0.7, 0.3};
    HMMv hmm(2, 2, trs, frs, pis);

    CHECK(hmm.nstates == 2);
    CHECK(hmm.nevents == 2);
    CHECK(hmm.TR[0][0] == doctest::Approx(0.9));
    CHECK(hmm.TR[0][1] == doctest::Approx(0.1));
    CHECK(hmm.TR[1][0] == doctest::Approx(0.2));
    CHECK(hmm.TR[1][1] == doctest::Approx(0.8));
    CHECK(hmm.EM[0][0] == doctest::Approx(0.85));
    CHECK(hmm.EM[0][1] == doctest::Approx(0.15));
    CHECK(hmm.EM[1][0] == doctest::Approx(0.15));
    CHECK(hmm.EM[1][1] == doctest::Approx(0.85));
    CHECK(hmm.PI[0] == doctest::Approx(0.7));
    CHECK(hmm.PI[1] == doctest::Approx(0.3));
  }

  SUBCASE("General matrix constructor normalizes TR rows (EM parameter shadows member)") {
    std::vector<std::vector<double>> tr = {{8.0, 2.0}, {1.0, 3.0}};
    std::vector<std::vector<double>> em = {{0.75, 0.25, 0.0}, {0.0, 0.25, 0.75}};
    std::vector<double> pi = {0.4, 0.6};
    HMMv hmm(2, 3, tr, em, pi);

    CHECK(hmm.TR[0][0] == doctest::Approx(0.8));
    CHECK(hmm.TR[0][1] == doctest::Approx(0.2));
    CHECK(hmm.TR[1][0] == doctest::Approx(0.25));
    CHECK(hmm.TR[1][1] == doctest::Approx(0.75));
    CHECK(hmm.EM[0][0] == doctest::Approx(0.75));
    CHECK(hmm.EM[0][1] == doctest::Approx(0.25));
    CHECK(hmm.EM[0][2] == doctest::Approx(0.0));
    CHECK(hmm.EM[1][0] == doctest::Approx(0.0));
    CHECK(hmm.EM[1][1] == doctest::Approx(0.25));
    CHECK(hmm.EM[1][2] == doctest::Approx(0.75));
  }

  SUBCASE("Asymmetric state and emission counts (2x4 and 4x2)") {
    HMMv hmm_2x4(2, 4);
    CHECK(hmm_2x4.nstates == 2);
    CHECK(hmm_2x4.nevents == 4);
    for (int i = 0; i < 2; ++i) {
      double tr_sum = std::accumulate(hmm_2x4.TR[i].begin(), hmm_2x4.TR[i].end(), 0.0);
      double em_sum = std::accumulate(hmm_2x4.EM[i].begin(), hmm_2x4.EM[i].end(), 0.0);
      CHECK(tr_sum == doctest::Approx(1.0));
      CHECK(em_sum == doctest::Approx(1.0));
    }

    HMMv hmm_4x2(4, 2);
    CHECK(hmm_4x2.nstates == 4);
    CHECK(hmm_4x2.nevents == 2);
    auto spk = hmm_4x2.genSeq(20);
    CHECK(spk.size() == 20);
    int* path = viterbi(hmm_4x2, spk, 20);
    for (int i = 0; i < 20; ++i) {
      CHECK(path[i] >= 0);
      CHECK(path[i] < 4);
    }
    delete[] path;
  }
}

TEST_CASE("Analytic 2-state and 3-state Viterbi oracle") {
  SUBCASE("2-state unambiguous MAP path") {
    std::vector<double> trs = {0.05, 0.05};
    std::vector<double> frs = {0.05, 0.95};
    std::vector<double> pis = {0.5, 0.5};
    HMMv hmm(2, 2, trs, frs, pis);

    std::vector<int> obs = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    std::vector<int> expected = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    int* path = viterbi(hmm, obs, static_cast<int>(obs.size()));
    for (size_t i = 0; i < obs.size(); ++i) {
      CHECK(path[i] == expected[i]);
    }
    delete[] path;
  }

  SUBCASE("3-state unambiguous MAP path") {
    std::vector<std::vector<double>> tr = {
        {0.8, 0.1, 0.1},
        {0.1, 0.8, 0.1},
        {0.1, 0.1, 0.8},
    };
    std::vector<std::vector<double>> em = {
        {0.9, 0.05, 0.05},
        {0.05, 0.9, 0.05},
        {0.05, 0.05, 0.9},
    };
    std::vector<double> pi = {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0};
    HMMv hmm(3, 3, tr, em, pi);

    std::vector<int> obs = {0, 0, 1, 1, 2, 2, 0, 2};
    // Last single 0->2: P(stay 2 at t=6) vs P(0 at t=6)->2:
    // Em(0,0)=0.9 vs Em(2,0)=0.05; 0.1*0.9*0.1 = 0.009 vs 0.8*0.05*0.8 = 0.032!
    // Let's use clean blocks of length >= 2 so MAP path equals obs:
    std::vector<int> obs_blocks = {0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 0, 0};
    int* path = viterbi(hmm, obs_blocks, static_cast<int>(obs_blocks.size()));
    for (size_t i = 0; i < obs_blocks.size(); ++i) {
      CHECK(path[i] == obs_blocks[i]);
    }
    delete[] path;
  }
}

TEST_CASE("Initial-state PI semantics at t=0") {
  // Symmetric TR and uninformative EM at t=0 so PI decides state[0].
  std::vector<std::vector<double>> tr = {{0.5, 0.5}, {0.5, 0.5}};
  std::vector<std::vector<double>> em = {{0.5, 0.5}, {0.5, 0.5}};
  std::vector<int> obs = {0};

  HMMv hmm_p0(2, 2, tr, em, {0.9, 0.1});
  int* path0 = viterbi(hmm_p0, obs, 1);
  CHECK(path0[0] == 0);
  delete[] path0;

  HMMv hmm_p1(2, 2, tr, em, {0.1, 0.9});
  int* path1 = viterbi(hmm_p1, obs, 1);
  CHECK(path1[0] == 1);
  delete[] path1;
}

TEST_CASE("Viterbi tie-breaking and deterministic transitions") {
  SUBCASE("Exact tie picks lowest state index") {
    std::vector<std::vector<double>> tr = {{0.5, 0.5}, {0.5, 0.5}};
    std::vector<std::vector<double>> em = {{0.5, 0.5}, {0.5, 0.5}};
    std::vector<double> pi = {0.5, 0.5};
    HMMv hmm(2, 2, tr, em, pi);

    std::vector<int> obs = {0, 1, 0, 1};
    int* path = viterbi(hmm, obs, static_cast<int>(obs.size()));
    for (size_t i = 0; i < obs.size(); ++i) {
      CHECK(path[i] == 0);
    }
    delete[] path;
  }

  SUBCASE("Deterministic cycle permutation transition matrix") {
    std::vector<std::vector<double>> tr = {
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 0.0, 0.0},
    };
    std::vector<std::vector<double>> em = {
        {0.8, 0.2},
        {0.5, 0.5},
        {0.2, 0.8},
    };
    std::vector<double> pi = {1.0, 0.0, 0.0};
    HMMv hmm(3, 2, tr, em, pi);

    std::vector<int> obs = {0, 1, 1, 0, 0, 1};
    int* path = viterbi(hmm, obs, static_cast<int>(obs.size()));
    std::vector<int> expected = {0, 1, 2, 0, 1, 2};
    for (size_t i = 0; i < obs.size(); ++i) {
      CHECK(path[i] == expected[i]);
    }
    delete[] path;
  }
}

TEST_CASE("Log-probability numerical stability on long sequence (nt=5000)") {
  std::vector<double> trs = {0.02, 0.02};
  std::vector<double> frs = {0.1, 0.9};
  std::vector<double> pis = {0.9, 0.1};
  HMMv hmm(2, 2, trs, frs, pis);

  const int nt = 5000;
  std::vector<int> obs(nt, 0);
  for (int i = nt / 2; i < nt; ++i) {
    obs[i] = 1;
  }

  int* path = viterbi(hmm, obs, nt);
  for (int i = 0; i < nt / 2 - 5; ++i) {
    CHECK(path[i] == 0);
  }
  for (int i = nt / 2 + 5; i < nt; ++i) {
    CHECK(path[i] == 1);
  }
  delete[] path;
}

TEST_CASE("Export, import, and shuttleFuns round-trip") {
  HMMv hmm(2, 2, {0.05, 0.05}, {0.05, 0.95}, {0.9, 0.1});
  std::vector<int> spk_in = {0, 0, 0, 1, 1, 1};
  std::vector<int> st_in = {0, 0, 0, 1, 1, 1};
  std::vector<int> guess_out(6, -1);

  hmm.importSpksExportGuess(6, spk_in.data(), st_in.data(), guess_out.data());
  for (int i = 0; i < 6; ++i) {
    CHECK(guess_out[i] == st_in[i]);
  }

  std::vector<int> spk_exp(6, -1), st_exp(6, -1), guess_exp(6, -1);
  hmm.exportSeqsGuess(6, spk_exp.data(), st_exp.data(), guess_exp.data());
  for (int i = 0; i < 6; ++i) {
    CHECK(spk_exp[i] == spk_in[i]);
    CHECK(st_exp[i] == st_in[i]);
    CHECK(guess_exp[i] == st_in[i]);
  }

  double raw_d[3] = {1.5, 2.5, 3.5};
  auto vec_d = array2vec(raw_d, 3);
  REQUIRE(vec_d.size() == 3);
  CHECK(vec_d[1] == doctest::Approx(2.5));
  double out_d[3] = {0.0, 0.0, 0.0};
  vec2array(vec_d, out_d);
  CHECK(out_d[0] == doctest::Approx(1.5));
  CHECK(out_d[2] == doctest::Approx(3.5));
}

TEST_CASE("Input validation in Release and Debug builds") {
  HMMv hmm(2, 2, {0.05, 0.05}, {0.05, 0.95}, {0.9, 0.1});
  std::vector<int> obs = {0, 1, 0, 1};

  CHECK_THROWS_AS(viterbi(hmm, obs, 0), std::invalid_argument);
  CHECK_THROWS_AS(viterbi(hmm, obs, -3), std::invalid_argument);
  CHECK_THROWS_AS(viterbi(hmm, std::vector<int>{}, 1), std::invalid_argument);
  CHECK_THROWS_AS(viterbi(hmm, obs, 10), std::invalid_argument);
  CHECK_THROWS_AS(viterbi(hmm, std::vector<int>{0, -1, 1}, 3), std::invalid_argument);

  HMMv bad_hmm = hmm;
  bad_hmm.nstates = 0;
  CHECK_THROWS_AS(viterbi(bad_hmm, obs, 4), std::invalid_argument);
}

}  // TEST_SUITE("hmm_viterbi")
