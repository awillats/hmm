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
                (0.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/hmmX/hmm/call_viterbicpp.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737484.69035879627));
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
    "789cdd53cb4edb4014bd4114c1220809f503ba46f200452aec7069038840511b2002b5301edf9211f3923d89c28e0fe10358f2117c43bf85656d274326c8a9a5"
    "aab0e848e3f1f1b1ee39f7f81a6abbfb350098cf361880c71928563ddbf9f385018429185ff5e1e9f85ad96946efbf81e902d79fbd773b3c995616fb76000457",
    "78d0951126195054e25399584baea8b2ad6b839060aa450fe382f9c905b6b8c4a6f6c00ecf806c78d413c8a9fc7eab83ecea5b5742d2494776850f60984feef9"
    "ceefff62d4ff74493e7e7eaedfad09f92c0cb1e3cf3e7f2747292629a13195e493665d89caa6649bdb9d6e443a52b6f30b615488f31eb798449c1913c87792da",
    "55d64336e6fbc2f7edf99a29f1edf355df750e6647f8a6b1e9f4fa7e3df3e79ccaf4de4ed07339399ee918938067c393282a0281ead276a0baef2a1fcfd7241f"
    "6e39bd7bbfde5ff4fda542cff167bbcd763622a13182336ab95629d90f5bcdf0e3f9d7d5e595f528a0c610abb588749fa014c55e2ae2224b2e2f32c82b90af38",
    "279b3f1e167f85a57ae685e61226ccc37fa8f75aff5dab797cba21e376129eac7de8afbc3f96cb077b9e8fc30a9d2a1fe0e3923ec7ea9b7f57ff37c9a98b36",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1808U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_viterbicpp_info.cpp) */
