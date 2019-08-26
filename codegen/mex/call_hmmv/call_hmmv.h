/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_hmmv.h
 *
 * Code generation for function 'call_hmmv'
 *
 */

#ifndef CALL_HMMV_H
#define CALL_HMMV_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "call_hmmv_types.h"

/* Function Declarations */
extern void call_hmmv(const emlrtStack *sp, real_T nt, const real_T trs_[2],
                      const real_T frs_[2], const real_T pis_[2],
                      emxArray_int32_T *spikes, emxArray_int32_T *states,
                      emxArray_int32_T *statesGuess);

#endif

/* End of code generation (call_hmmv.h) */
