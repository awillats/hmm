/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_viterbicpp_info.cpp
 *
 * Code generation for function '_coder_call_viterbicpp_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "call_viterbicpp.h"
#include "_coder_call_viterbicpp_info.h"

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
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("call_viterbicpp"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/hmmX/hmm/call_viterbicpp.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737484.6988773148));
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
    "789cdd53cb4edb4014bd4101d1452a24c407748de421b412b0c3055a2881566d8008c4633cbe9011f3923d89c2bff403baec47f41bfa2d5dd6763264821c2c55"
    "8505238dc7c7c7bae7dce36ba8ed1dd400e075b6c100fc99836235b29d3f5f18429881c9d5189d8eaf959d66fcfe2cd40bdc78f0def7d1c9b4b238b04320b8c2",
    "c39e8c30c980a212efcbc45a7245956ddf198404532dfa1817cc3517d8e6125bda03bb3c03f28347dd839ccaefb7bac86ebff52424dd746c57f80046f9e49e7f"
    "f8fd5f8dfbaf97e4e3e7e7fadd9a92cfc2083bfe6ce79c1ca598a484c654926dcd7a12954dc9476e777b11e94ad9c92f8451212efbdc621271664c20df486a57",
    "591fd984ef2bdfb7e76baec4b7cf577dd75730efe14f9b4e6fe0d7338fe754a6b73445cfe5e478a6634c029e0d4fa2a80804aa1bdb85eabeab7c3c5cd37cb8e5"
    "f47efaf5fea1efcf157a8e3fdb6b75b211098d119c51cbb54ac941d86e85ef2fbfaeae34d7a3801a43acd622d2038252147bb9888b2cbbbcc830af403ee39c6c",
    "5efc5afc1d96ea99a79acb29f3f002f59eebbf6bb78e4f3764dc49c293776b83e6db63b972b8eff9f852a153e5037c5cd2e7447df3ffeaff057b138aba",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1808U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_viterbicpp_info.cpp) */
