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
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("call_hmmv"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/rtxi_vm_copy/hmm_modules/hmmX/hmm/call_hmmv.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737512.50149305561));
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
    "789ced54db6ed340105da31651895495503f8037a44ad95e9080b7ba14da8aa42048434405ee663d90157b93bd8edc373e848fe0910fe837f45b78c476bce936"
    "b231829207949136eb9363cd9c391a0ff28eba1e4268353b4823f4e32e2aa2959dfcffb50944b7d0f56895b7e5bd99f7bc329f8d65b454e0d6ccfb5fcb9b2a69",
    "203513c09984e3440c21ca802402a66942259824d2f4ce35a00862c5c71016cc47c6a1c7047494030e5906c473879a829cca9f9f8e807e7e9308148de22bb9dc"
    "05a8f427d7fccdedffecaaffa50a7f5cff6cbfdd1a7fd64a6cf9d367eff1490c518c494804de573411204d8c0f98394c863832290bc622a04a9fe39110815061",
    "c221ce9f07f90fa684f3207b18b785a3ffccd5efe8bb5da1dfe5bdaadbd1bf82ee38f8c1aead97baf9f4affdaaaab75e53cffa6579aa4288da2c1ba24812dee6"
    "203f99116aeebb49c76cd4e9b05139277fd0f7cb867a963f3dea0cb251f1b5e68c12c3948c71d7ef75fcbde0f5f6e6d6e3619b688d8d527ca8520c821767a3b0",
    "0b6f58bff0c4af6c52e63727bb1f2eee5dfa95f5f4bf9acb9a79f80febcdebbbeb75faef9e887010f96f1f3e4ab776fa62f3f885a3e355439d261dc8c5157d5e"
    "cbaf6f3efff79afcbfeb63bf26bff5d1f237baefef0b62b6e918e89cf7fe97fdc5de77f32df6fe34167b7f3ef5167bffeff2ff04d701f5e0",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 3344U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
