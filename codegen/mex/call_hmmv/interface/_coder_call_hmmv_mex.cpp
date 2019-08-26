/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_hmmv_mex.cpp
 *
 * Code generation for function '_coder_call_hmmv_mex'
 *
 */

/* Include files */
#include "call_hmmv.h"
#include "_coder_call_hmmv_mex.h"
#include "call_hmmv_terminate.h"
#include "_coder_call_hmmv_api.h"
#include "call_hmmv_initialize.h"
#include "call_hmmv_data.h"

/* Function Declarations */
static void call_hmmv_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[4]);

/* Function Definitions */
static void call_hmmv_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[4])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4, 9,
                        "call_hmmv");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "call_hmmv");
  }

  /* Call the function. */
  call_hmmv_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(call_hmmv_atexit);

  /* Module initialization. */
  call_hmmv_initialize();

  /* Dispatch the entry-point. */
  call_hmmv_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  call_hmmv_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_call_hmmv_mex.cpp) */
