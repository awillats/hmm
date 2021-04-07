/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_viterbicpp_emxutil.h
 *
 * Code generation for function 'call_viterbicpp_emxutil'
 *
 */

#ifndef CALL_VITERBICPP_EMXUTIL_H
#define CALL_VITERBICPP_EMXUTIL_H

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
extern void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (call_viterbicpp_emxutil.h) */
