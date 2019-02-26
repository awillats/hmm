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
#include "printFuns.hpp"
#include "hmm_vec.cpp"
#include "hmm_vec.hpp"

/* Function Definitions */
void call_hmmv(const emlrtStack *, const real_T [2], const real_T [2], const
               real_T [2])
{
  std::vector<double> invec;

  /* res_ = coder.opaque('string'); */
  blockPrint(1.0);

  /* convert mat-vec to std::vector<double> */
  invec = { .1, .9 };

  HMMv myHMM = HMMv(2.0, 2.0, invec, invec, invec);
  myHMM.printMyParams();
}

/* End of code generation (call_hmmv.cpp) */
