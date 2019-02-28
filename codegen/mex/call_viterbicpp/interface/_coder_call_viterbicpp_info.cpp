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
    "789cdd53cb4edb4014bd4114d1451012ea07748de421b452cb0e9747a14d0095944645948ec71732625eb22751f8173ea0cb7e44bfa1dfc212dbc9c004d9b554"
    "010b461a8f8f8f75cfb9c7d7d0d8ed34006021db6000aee7a058cd6ce7cf17c71066607a3527a7e31b65a7b97bff05cc16b879efbdabc9c9b4b238b26320b8c2",
    "bd818c30c980a2126fcbc45a724595ed5e1a8404532d861817cc1917d8e512dbda033b3c0372dba36e414ee5f71b7d6417870309493fbdb32b7c00937c72cfbf"
    "2afa9f2dc9c7cfcff5bb5191cfe2043bfe78eb847c4d3149098da9249b9a0d242a9b928fdcee0c22d297b2975f08a3429c0eb9c524e2cc9840be96d4aeb221b2",
    "29df3f2b7ccf95f8f6f9baeffa12e63dfc69dde98dfc7ae6df3995e9bdaad07339399ee918938067c393282a0281eadcf6a1beef3a1ff757950fb79cde6fbfde"
    "7ff4bd5fa3e7f8e3dd762f1b91d018c119b55cab9474c26e3bfc70fa6575a5f53e0aa831c46a2d223d222845b1978bb8c8b2cb8b8cf30ae413cec9fa8f3f4b7f",
    "c3523df3587359310fcf50efa9febb6efbe8fb9a8c7b49f8ededbb51ebcd915cd9fbecf938a8d1a9f3013e2ee973aabe79b8fa374bd58a5a",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1808U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_viterbicpp_info.cpp) */
