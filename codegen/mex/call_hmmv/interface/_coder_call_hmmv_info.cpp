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
                (0.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737482.7637268519));
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
    "789cdd545b4ac34014bd152dfa5111c405f85dc8d82aa888d0f816db2a5ab5285aa7c96807e745322d752f7eb80417e11a5c874b30493b1a352122e887172693"
    "933bdc73eec94d20b75bcb01c064b04001bce4218a42b0c2e753030823f0310ac3dde47349bb7a3f3f06a3112e7c3a773fdc1d2934e9eb016054907a97b78917",
    "008139792be34a4e0516ba71a70878c497ac47dc28734d1969504eaa3206766800f8562cf506c25478bfde21ceed519783d7f1dfe5b23880a13fa1e68794fe47"
    "93fc515ffd594df1676a884dfe7cf3021dfbc4f3117631471bd2e97222b48fb6a9dee9b65187f36678410e66ac15dcf42c3ecbb12e3b3de2c4f45ea5e8cd27e9",
    "85efbfcf09188fe1958ae1eba7f49fe84f02df4c0a9ff1c7e41de912cfa2c1d07802338b1171a33b90dd77968ecf91a6c384e17b8cd7fb41dffb197c267fbe5b"
    "6d06a3612bc5a8833595c24735bb51b5d75a87e5b9d252dbc24a212d256bcb3e229c45ab18d9858ac62f34f0cbe27f382795cba7e9673b914ffdd65ca6ccc33f",
    "e4fbabefae513d395be66ed3b34f1716fba5f9133e57df8be938c8e0c9d201719cd0e787fa09ffd79fd67f0595e3881e",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1800U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
