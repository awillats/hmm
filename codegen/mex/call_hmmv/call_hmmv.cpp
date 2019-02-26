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
#include "hmm_vec.cpp"

/* Function Definitions */
void call_hmmv(const emlrtStack *, const real_T [2], const real_T [2], const
               real_T [2])
{
  /* coder.cinclude('printFuns.hpp'); */
  /* coder.cinclude('hmm_vec.hpp'); */
  blockPrint(1.0);

  /* convert mat-vec to std::vector<double> */
  HMMv myHMM = HMMv(2.0, 2.0, { .1, .2 }, { .01, .7 }, {
                    .5,.5
                    } );

  myHMM.printMyParams();
  myHMM.genSeq(1000.0);
  myHMM.printSeqs();
}

/* End of code generation (call_hmmv.cpp) */
