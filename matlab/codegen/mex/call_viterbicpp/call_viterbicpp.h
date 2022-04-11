//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// call_viterbicpp.h
//
// Code generation for function 'call_viterbicpp'
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
void call_viterbicpp(const emlrtStack *sp, real_T nt,
                     const real_T spikes_[3000], const real_T states_[3000],
                     const real_T trs_[2], const real_T frs_[2],
                     const real_T pis_[2],
                     coder::array<int32_T, 2U> &statesGuess,
                     int32_T spikes[3000], int32_T states[3000]);

// End of code generation (call_viterbicpp.h)
