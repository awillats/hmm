/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_blockprint_mex.cpp
 *
 * Code generation for function '_coder_call_blockprint_mex'
 *
 */

/* Include files */
#include "call_blockprint.h"
#include "_coder_call_blockprint_mex.h"
#include "call_blockprint_terminate.h"
#include "_coder_call_blockprint_api.h"
#include "call_blockprint_initialize.h"
#include "call_blockprint_data.h"

/* Function Declarations */
static void call_blockprint_mexFunction(int32_T nlhs, int32_T nrhs, const
  mxArray *prhs[1]);

/* Function Definitions */
static void call_blockprint_mexFunction(int32_T nlhs, int32_T nrhs, const
  mxArray *prhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        15, "call_blockprint");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "call_blockprint");
  }

  /* Call the function. */
  call_blockprint_api(prhs, nlhs);
}

void mexFunction(int32_T nlhs, mxArray *[], int32_T nrhs, const mxArray *prhs[])
{
  mexAtExit(call_blockprint_atexit);

  /* Module initialization. */
  call_blockprint_initialize();

  /* Dispatch the entry-point. */
  call_blockprint_mexFunction(nlhs, nrhs, prhs);

  /* Module termination. */
  call_blockprint_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_call_blockprint_mex.cpp) */
