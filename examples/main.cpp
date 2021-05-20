/// \brief basic usage of Hidden Markov Model code
///
/// \file
/// "hmm" is a simple set of hidden Markov model (HMM) code.
/// It decodes latent state-switches
/// from a categorical signal (usually a binary spike-train)
///   \author Adam Willats
///   \date 2/21/19

#include <chrono>

#include <iostream>
#include <vector>

#include "../include/hmm_h/hmm_vec.hpp"
#include "../include/hmm_h/printFuns.hpp"
#include "../include/hmm_h/shuttleFuns.hpp"

//#include "legacy/dataFuns.h"
/**
 * This is the main() for testing basic HMM functionality.
 * Builds an HMM, generates a sequence, estimates states, then prints them to
 * cout
 * @param  argv optional args:{nStates, nSamples}
 * @return      0 if successful
 */
int main(int argc, const char *argv[]) {
  /*  // default HMM params
  std::vector<double> trs = {0.1,0.1}; //transition rates
  std::vector<double> frs = {.1,.9}; //firing rates
  std::vector<double> pis = {.1,.9}; //initial state probabilities
  // HMMv myHMM = HMMv(2,2, trs, frs, pis);
   */
  int nt = 175; // 1e3;
  int ntMaxPrint = 1e3;
  int nrep = 0; // 100; 1e3;


  std::cout << "argc " << argc << '\n';
  int nStates = 2;
  int nEmissions = 2;
  int printMode = 1; // 1

  // Override HMM params if we have input from the console
  // For a simplified debugging nStates == nEmissionss here, but that doesn't
  // have to be the case generally

  // Also, for easy in-console visualization, I've chosen parameters such that
  // the most common output For each state matches the identity of that state

  if (argc > 1) {
    std::cout << "argv0: " << argv[1] << '\n';

    int nInput = std::stoi(argv[1]);
    assert(nInput > 0);

    if (nInput == 3) {
      printMode = 3;
    }
    if (nInput > 3) {
      printMode = 0;
    }
    nStates = nInput;
  }
  if (argc > 2) {
    // if there's a second argument it specifies how many time samples to
    // generate & decode
    nt = std::stoi(argv[2]);
  }
  std::cout << "nStates: " << nStates << " nEmissions: "<<nEmissions<<'\n';

  HMMv myHMM = HMMv(nStates, nEmissions);
  // HMMv myHMM = HMMv(nStates, nEmissions, trs, frs, pis);
  // myHMM.printMyParams();

  myHMM.genSeq(2,0);
  myHMM.printSeqs(printMode);
  myHMM.genSeq(2,1);
  myHMM.printSeqs(printMode);

  myHMM.genSeq(nt);
  myHMM.printSeqs(printMode);

  // https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
  auto start_time = std::chrono::system_clock::now();
  int *vguess = viterbi(myHMM, myHMM.spikes, nt);
  auto end_time = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = end_time - start_time;

  for (int i = 0; i < nrep; i++) {
    myHMM.genSeq(nt);

    auto start_time = std::chrono::system_clock::now();
    viterbi(myHMM, myHMM.spikes, nt);
    auto end_time = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    cout << "Run time = " << diff.count() * 1000 << " ms\n";
  }

  int spkAry[nt];
  int stateAry[nt];
  int vguess2[nt];
  myHMM.exportSeqsGuess(nt, spkAry, stateAry, vguess2);

  printVecAsBlock(&vguess[0], myHMM.ntPrint, printMode);
  std::cout << " < guessed states \n";

  // calculate accuracy
  int nCorrect = 0;
  for (int i = 0; i < nt; i++) {
    if (vguess[i] == stateAry[i]) {
      nCorrect++;
    }
  }
  double acc = nCorrect / double(nt);

  std::cout << "Summary - " << nStates << " states, " << nEmissions
            << " events, " << nt << " samples\n";
  std::cout << 100.0 * acc << "% accuracy\n"; // stateAry;
  std::cout << "Run time = " << diff.count() * 1000 << " ms\n";

  return 0;
}
