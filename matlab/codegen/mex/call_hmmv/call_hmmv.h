//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// call_hmmv.h
//
// Code generation for function 'call_hmmv'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void call_hmmv(const emlrtStack *sp, real_T nt, const real_T trs_[2],
               const real_T frs_[2], const real_T pis_[2],
               coder::array<int32_T, 2U> &spikes,
               coder::array<int32_T, 2U> &states,
               coder::array<int32_T, 2U> &statesGuess);

// End of code generation (call_hmmv.h)
