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
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("call_viterbicpp"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/hmmX/hmm/call_viterbicpp.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737484.64712962962));
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
    "789cdd53cb4edb4014bd418060910a09f5035823798022013bcca30511286a0344a016c6e3db66c4bc644fa2f02f7c004b3ea2dfd06fe912dbc9900972b08428"
    "0b461a8f8f8f75cfb9c7d750db3fac01c0876c8301f8370dc5aa673b7f3ed7873001a3ab3e381d5f2b3bcdf0fd29982c70fdc97bb783936965b167fb40708547",
    "1d1961920145253e9689b5e48a2adbbc310809a65a74312e985f5c60934b6c680fecf10cc8cf1ef508722abfdf6e23bbfede9190b4d3a15de10318e4937bbef3"
    "fbbf1af63f59928f9f9feb777b4c3e7303ecf88bdd1fe424c5242534a692ec68d691a86c4abe70bbd789485bca567e218c0a71d9e5169388336302b920a95d61",
    "5d6423beaf7cdf9eafe912df3e5ff55d6761c6c3bb9b4eafe7d733cfe754a6f7718c9ecbc9f14cc798043c1b9e4451110854bf6d1baafbaef2f1748df3e196d3"
    "bbf7ebbda0efaf157a8ebfd86fb4b211098d119c51cbb54ac961d86c845b97df569696d7a3801a43acd622d23d8252147bb1888b2cbabc483faf40bee19c6cfe",
    "fc33ff372cd533ff6b2ec7ccc33bd47babffaed9383ddf90712b09cf56d77acb9f4ee5d2d181e7e3b842a7ca07f8b8a4cf91fae6f5ea3f0063498ab5",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1808U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_viterbicpp_info.cpp) */
