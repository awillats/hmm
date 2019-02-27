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
                (737483.51008101855));
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
    "789cdd545b4ac34014bd952afa5129880bf05bc85815d40fc1f8ac581f68ad45f1314d463b382f9269a97f2ec40f97e0225c83eb70092669c7a6352122e88717"
    "2693933bdc73eec94d20b7bb9f0380c9608102781f83280ac10a9f17bb104660300abddde47349bbea9f1f857c840b43e79e7abb2385261ddd058c0a72d0e20d",
    "e20540604e3ecbb892538185ae3e28021ef1256b1337cadc5246aa94938a8c81320d00df8ea53e41980aef379ac4b93f6971f09a7e5f2e8b03e8f9136a7e4ee9"
    "3f9fe48ffaeacf6a8a3fc51e36f98bad4b74ea13cf47d8c51c6d4aa7c589d03edaa1badc6aa026e7f5f0821cccd87570d3b6f80cc77ade691327a6f72645ef58",
    "925ef8fefb9c80f13e7edc58337c9d94fe13fd49e09b4ee133fe98bc235de25934181a4f60663122ee7413b2fbced2311c693a4c18be9778bd1ff47d98c167f2"
    "17bb957a301ab6528c3a5853297cb46f572bf6faf5f1fc5c69b96161a590969235640711cea2351bd985668d5fa8eb97c5ff704ed6ae5ea7deec443ef54b7309",
    "29f3f00ff9feeabbab566ae72bdcad7bf6d9e252a7b450e373077b311d47193c593a208e13fa1ca89ff07ffd69fd0f1da088a6",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1800U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
