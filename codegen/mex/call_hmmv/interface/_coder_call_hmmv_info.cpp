/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_hmmv_info.cpp
 *
 * Code generation for function '_coder_call_hmmv_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "call_hmmv.h"
#include "_coder_call_hmmv_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties()
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, *(const char * (*)[6])&
    fldNames[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("call_hmmv"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737483.51621527784));
  xResult = emlrtCreateStructMatrix(1, 1, 4, *(const char * (*)[4])&b_fldNames[0]);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.5.0.1033004 (R2018b) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789ced54dd4ae340143e952a0a5604d907f05ae8d4aea05e0866fdc7ea2e5ab528fe4c93d10ece4f48a6a5fb267be1c53ec23ec45eec13ecf36c9266bad39a21"
    "a2d80be981e9e4eb09e7fbcec7c981c2c1510100e6a2033ec09f5948a2149df8fff91e8409188c527aeb7c61e8bd425a4fc72414135c1a7aff29bd5d2914e9aa",
    "1e605490e3366f9220020273d22fe3494e0516aafedd27109050b20ef192cc3d65a44e39a94903ecd308f05d23d507712a7ede6a11f7f1b4cd216885ffe53213"
    "40ea4facf987a5ff62963ffe737f562cfecca758e7af76aed159488210610f73b42ddd36274285688faafd7613b5386fc43fc8c58cdd460f9d323775de59744e",
    "65e984e73a076e43e70c4c1bb8baa9f9ba96be337dc9e0fb64e1d3bee8bc2b3d129469342c81c0accc8878502dc8ef3b4fc770d874e8d07cbfcc7aafe8fb6b0e"
    "9fce5f1dd41ad14838becfa88b15952244474ebde67cb93da95696d79a65ecfb4849c99ab28b0867c9594aec424bda2fd4f32b1a95d1cdc9e6cdef85bf4e269f",
    "ff5e736999870fc837aaefae5e3bbf5ce75e23702e5656bbcb9fcf79e5f8d0d0f12d87274f079838a3cf81fa197bf5adf57f5aeabfd4c70d4b7deda3cebf66af"
    "2f72acaa6e87b830eafdbe35deef66bdf17eefc778bf8f866fbcdfdf56ff1f77b3e07e", ""
  };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 3296U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
