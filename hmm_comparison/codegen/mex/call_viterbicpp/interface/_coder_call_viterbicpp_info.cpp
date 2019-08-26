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
    "/Users/adam/Documents/GitHub/rtxi_vm_copy/hmm_modules/hmmX/hmm/call_viterbicpp.m"));
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
    "789cdd53db6ed430109d45e5f6b06825c407f05c296e0b12f0d670dd8a6d41b094150582e30cac856f729c55fac687f0117c020f7c03df43925d77dd2a211282"
    "3e3092639f8c3567cec904067bfb0300b8562d3000a3cbd0c4b05af5fbd112c205381dc3d5eef383b6ddacef5f848d060fcfdcfbbada99560e4bb704822b3c28",
    "648ab6028a4a3c299369c915556e7a6c102ce65a2c306b321fb9c0299738d10118f30ac8c741ea04d4a9fafc608eecf3cb42829de7eb76450860e54fddf3f70e"
    "fd1b2dfe84fe79bd6f3bfc19adb0cf1f3d7a475ee5687342332ac943cd0a89cae5e40977e32225d6953c59c88469734ce65226526785c0bc3ecfea0761548864",
    "c11dda94336322795352b7c316c8423d1f3af45c6ad113e6fbbef755b8b2c65fc6bb9eaf0ceb99dffbd7c677a383cffbe7f34c6768235e0d9555544402d52737"
    "877edd7d7d9c8dae3e7c78be6f61bd3fd0fdac87cfe78ff626b36a7462630467d471ad72b21f4f27f1fde4c5ced6f6dd34a2c610a7b5487549508a666d367691",
    "4def1759fa15c9739c93ddf73faeff8c5bf9cc3f9a4be89887ff90efbcfebbe9e4f0cd3d99cd6cfcfaf69d72fbd6a1dc3a781af4f1bc87a7af0f08718bce53f5"
    "cddfabff0bd0b89456", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1832U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_viterbicpp_info.cpp) */
