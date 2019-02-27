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
                (737483.499537037));
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
    "789cdd545b4ac34014bd1515fda814c405f82d64ac0aea87d0f8165b15adb5283ea6c96807e745322df5cf85f8e1125c846b701d2ec124edb4a9264404fdf0c2"
    "647272877bce3db909e4f62a3900980a162880f77188221facf079a10b61048623dfdb4d3e97b4abc1f931188d70fed3b9a7deee48a149477701a3821cb47883",
    "78011098937e1957722ab0d0d50745c023be646de246995bca489572529631b04b03c0b763a93e0853e1fd469338f7272d0e5ed31fc86571003d7f42cdcf29fd"
    "8f26f9a3befab396e24fa1874dfe62eb129dfac4f3117631479bd2697122b48f76a8de6d355093f37a78410e66ec3ab8695b7c9663bde0b48913d37b93a2773c",
    "492f7cff7d4ec2c4003f964a86af93d27fa23f097c33297cc61f9377a44b3c8b0643e309cc2c46c49d6e4276df593a3e479a0e1386ef255eef077d1f66f099fc"
    "c55eb91e8c86ad14a30ed6540a1f55ec6ad95ebf3e5e982fae342cac14d252b286ec20c259b4e622bbd09cf10b75fdb2f81fce49e9ea75facd4ee453bf349790",
    "320fff90efafbebb6ab976becaddba679f2d2d778a8b353e7fb01fd37194c193a503e238a1cfa1fa09ffd79fd6ff000f5a88a3",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1800U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
