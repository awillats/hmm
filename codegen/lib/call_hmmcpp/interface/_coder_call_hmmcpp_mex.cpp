/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_hmmcpp_mex.cpp
 *
 * Code generation for function '_coder_call_hmmcpp_mex'
 *
 */

/* Include files */
#include "_coder_call_hmmcpp_api.h"
#include "_coder_call_hmmcpp_mex.h"

/* Function Declarations */
static void call_hmmcpp_mexFunction(int32_T nlhs, int32_T nrhs, const mxArray
  *prhs[1]);

/* Function Definitions */
static void call_hmmcpp_mexFunction(int32_T nlhs, int32_T nrhs, const mxArray
  *prhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        11, "call_hmmcpp");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "call_hmmcpp");
  }

  /* Call the function. */
  call_hmmcpp_api(prhs, nlhs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  (void)plhs;
  mexAtExit(call_hmmcpp_atexit);

  /* Module initialization. */
  call_hmmcpp_initialize();

  /* Dispatch the entry-point. */
  call_hmmcpp_mexFunction(nlhs, nrhs, prhs);

  /* Module termination. */
  call_hmmcpp_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_call_hmmcpp_mex.cpp) */
