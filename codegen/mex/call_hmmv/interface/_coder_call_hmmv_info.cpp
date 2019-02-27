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
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737483.54996527778));
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
    "789ced54cb4edb4014bd46b402895448553f80355206025261510997b7085041a01188c7c41ec88879c99e4461c767b060d14fe847b0e00bf89eda8e270c915d"
    "5750b240b9d2647c72ad73cf3dbabee06c6e3b00f0293aa0001e2620895274e2ff27bb1046e07994d2dbe49dbef79c94cfc407184d70a9effdbbf4f6a4d0a4a3",
    "bb805141765abc41820808cc498fc6979c0a2c74ed5a11084828599bf849e6823252a39c54a505366804f89a95ea8138153f2f378977b5dfe21034c327b9cc06"
    "90fa136bbeb5fb3f7fea7f34c31fdb3fd3ef7c8e3f932936f9e3d5137410922044d8c71cad48afc589d0215aa77aa3d5404dceebf10ff2306367d143bbcc6d9d",
    "e7b64e4bc7c70c9d76dec9ba2d9de33066e1ca92a9d7b1f9d4df7dc9aaf725a79ef1c5e43de993a04ca3610904666546c4a56e4271df453afa234f870953efb7"
    "cdf782be770bea99fcf166b51e8d84ab14a31ed6548a106dbbb5aafbfd6caf3233bbd02863a590969235640711ce92339dd885a68d5fa8eb57342a839b93a5d3",
    "fbcf8f6e663df5567399330fefb0dea0bebb5af5f06891fbf5c0fd39ffb5333b77c86776b62c1d3f0aea14e9001b67f4f98c5ffd7ffe5f39fcffeae3b71c7ee3"
    "a3c9bf64af4f71ac2b5e9b7830e0fd7eb336dcef36df70bff762b8df07536fb8df5fc7ff0746ebe0f2",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 3296U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
