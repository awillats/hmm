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
                (737484.72979166661));
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
    "789cdd53cb4edb4014bda9206a17a92255fd80ae913c3c2a4177b8f411d4f010a469046a613cbe6d46cc4bf6244a77fd103e80251fc137f02d2cb19d0c99444e"
    "2d552d8b8e341e1f1feb9e738fafa1b6bb570380e7d906037057876235b29d3f6f8e213c81d9d5989c8eaf959d66fafe322c15b831f7dee5e4645a591cd93110",
    "5ce1fe404698644051890f65622db9a2ca767e1a8404532d861817cc772eb0c325b6b5075a3c03f283473d809ccaef77fac82e8e0712927e3ab52b7c00937c72"
    "cf577effe7d3fe974af2f1f373fdee2cc8a739c18e3f7dff957c4e3149098da924ef341b485436251fb96d0d22d297b2975f08a3429c0db9c524e2cc9840be92",
    "d4aeb321b219dfe7be6fcf57bdc4b7cf577dd767f0748a7fb5b69ddec8af677e9f5399decb057a2e27c7331d6312f06c781245452050fdb07da8eebbcac7fc5a"
    "e4c32da777edd7fb83be0f2af41c7fbadbee6523121a2338a3966b9592bdb0d30edf9e1dadafae6d4501358658ad45a44704a528f64a111759717991715e817c",
    "c439d9fe76f3e2362cd533ff682e61c13cfc877a8ff5df75dadd933732ee25e197d79ba3b58dae5cddffe4f938acd0a9f2013e2ee973a6bef97bf5ef01d32d8b"
    "38", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1808U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_viterbicpp_info.cpp) */
