/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_hmmv_terminate.cpp
 *
 * Code generation for function 'call_hmmv_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "call_hmmv.h"
#include "call_hmmv_terminate.h"
#include "_coder_call_hmmv_mex.h"
#include "call_hmmv_data.h"

/* Function Definitions */
void call_hmmv_atexit()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void call_hmmv_terminate()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (call_hmmv_terminate.cpp) */
