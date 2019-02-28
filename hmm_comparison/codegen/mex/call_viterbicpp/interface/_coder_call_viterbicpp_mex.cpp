/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_viterbicpp_mex.cpp
 *
 * Code generation for function '_coder_call_viterbicpp_mex'
 *
 */

/* Include files */
#include "call_viterbicpp.h"
#include "_coder_call_viterbicpp_mex.h"
#include "call_viterbicpp_terminate.h"
#include "_coder_call_viterbicpp_api.h"
#include "call_viterbicpp_initialize.h"
#include "call_viterbicpp_data.h"

/* Function Declarations */
static void call_viterbicpp_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[5]);

/* Function Definitions */
static void call_viterbicpp_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[5])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        15, "call_viterbicpp");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "call_viterbicpp");
  }

  /* Call the function. */
  call_viterbicpp_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(call_viterbicpp_atexit);

  /* Module initialization. */
  call_viterbicpp_initialize();

  /* Dispatch the entry-point. */
  call_viterbicpp_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  call_viterbicpp_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_call_viterbicpp_mex.cpp) */
