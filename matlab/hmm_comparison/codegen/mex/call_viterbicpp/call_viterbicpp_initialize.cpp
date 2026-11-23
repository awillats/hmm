//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// call_viterbicpp_initialize.cpp
//
// Code generation for function 'call_viterbicpp_initialize'
//

// Include files
#include "call_viterbicpp_initialize.h"
#include "_coder_call_viterbicpp_mex.h"
#include "call_viterbicpp_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void call_viterbicpp_initialize()
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (call_viterbicpp_initialize.cpp)
