/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_hmmcpp_api.h
 *
 * Code generation for function '_coder_call_hmmcpp_api'
 *
 */

#ifndef _CODER_CALL_HMMCPP_API_H
#define _CODER_CALL_HMMCPP_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_call_hmmcpp_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void call_hmmcpp(real_T in);
extern void call_hmmcpp_api(const mxArray * const prhs[1], int32_T nlhs);
extern void call_hmmcpp_atexit(void);
extern void call_hmmcpp_initialize(void);
extern void call_hmmcpp_terminate(void);
extern void call_hmmcpp_xil_terminate(void);

#endif

/* End of code generation (_coder_call_hmmcpp_api.h) */
