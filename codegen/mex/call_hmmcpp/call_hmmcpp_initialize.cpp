/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_hmmcpp_initialize.cpp
 *
 * Code generation for function 'call_hmmcpp_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "call_hmmcpp.h"
#include "call_hmmcpp_initialize.h"
#include "_coder_call_hmmcpp_mex.h"
#include "call_hmmcpp_data.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Definitions */
void call_hmmcpp_initialize()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (call_hmmcpp_initialize.cpp) */
