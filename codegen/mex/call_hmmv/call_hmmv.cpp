/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_hmmv.cpp
 *
 * Code generation for function 'call_hmmv'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "call_hmmv.h"
#include "printFuns.cpp"
#include "shuttleFuns.cpp"
#include "hmm_vec.cpp"

/* Function Definitions */
void call_hmmv(const emlrtStack *, const real_T trs_[2], const real_T frs_[2],
               const real_T pis_[2])
{
  real_T b_trs_[2];
  std::vector<double> trs;
  std::vector<double> frs;
  std::vector<double> pis;

  /* coder.ceval('blockPrint',1,printMode); */
  /* convert input vecs to c++ */
  /* pre-allocates a std::vec */
  b_trs_[0] = trs_[0];
  b_trs_[1] = trs_[1];
  trs = buildVectorFromAry(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  /* pre-allocates a std::vec */
  b_trs_[0] = frs_[0];
  b_trs_[1] = frs_[1];
  frs = buildVectorFromAry(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  /* pre-allocates a std::vec */
  b_trs_[0] = pis_[0];
  b_trs_[1] = pis_[1];
  pis = buildVectorFromAry(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  HMMv myHMM = HMMv(2.0, 2.0, trs, frs, pis);
  myHMM.printMyParams();
  myHMM.genSeq(1000.0);
  myHMM.printSeqs(2.0);
}

/* End of code generation (call_hmmv.cpp) */
