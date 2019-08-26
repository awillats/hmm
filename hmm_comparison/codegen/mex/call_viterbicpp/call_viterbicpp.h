/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_viterbicpp.h
 *
 * Code generation for function 'call_viterbicpp'
 *
 */

#ifndef CALL_VITERBICPP_H
#define CALL_VITERBICPP_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "call_viterbicpp_types.h"

/* Function Declarations */
extern void call_viterbicpp(const emlrtStack *sp, real_T nt, const real_T
  spikes_[1000], const real_T states_[1000], const real_T trs_[2], const real_T
  frs_[2], const real_T pis_[2], emxArray_int32_T *statesGuess, int32_T spikes
  [1000], int32_T states[1000]);

#endif

/* End of code generation (call_viterbicpp.h) */
