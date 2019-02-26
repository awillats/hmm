/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_hmmcpp.cpp
 *
 * Code generation for function 'call_hmmcpp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "call_hmmcpp.h"
#include "printFuns.cpp"

/* Function Definitions */
int64_T call_hmmcpp(const emlrtStack *, real_T in)
{
  int64_T res;
  int res_;

  /* coder.cinclude('printFuns.hpp') */
  res_ = blockPrint(in);
  res = (int64_T)res_;

  /* res= coder.ceval('((in==0) ? "\u2581":"\u2588")',in); */
  return res;
}

/* End of code generation (call_hmmcpp.cpp) */
