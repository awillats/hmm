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
                (737483.51532407408));
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
    "789cdd545b4ac34014bd955af4a322880bf05bc8b42aa81f82f1d9625b45ab168b8f6932dac179914c4bdd8b1f2ec145b806d7e1124cd28e464d8808fae185c9"
    "e4e40ef79c7b7213c855eb3900980a162880970244510c56f87c7a08610c3e4671b49b7c2e6957efe7c7211fe1e2a773f7a3dd914293811e02460569f4788778",
    "01109893b732aee45460a19b778a80477cc9fac48d32d7949126e5a42663a04203c07762a93710a6c2fbcd2e716e8f7a1cbcaeff2e97c5018cfc09353fa4f49f"
    "4ff2477df5672dc59fe91136f9f6f6393af689e723ec628eb6a4d3e344681fed525de9755097f35678410e66ec32b8e95b7c8e63bde0f48913d37b95a2b790a4",
    "17beff3e2761228637d70ddf20a5ff447f12f86653f88c3f26ef489778160d86c61398598c881bdd85ecbeb3747c8e341d260cdf63bcde0ffadecfe033f976b5"
    "d60a46c3568a51076b2a858fea76b3666f5c1e2e94ca2b1d0b2b85b494ac2307887016adf9c82e346ffc4243bf2cfe8773b27ef134f36c27f2a9df9acb9479f8",
    "877c7ff5dd356b2767abdc6d79f6e9d2f2a0bc78c24b8dbd988e830c9e2c1d10c7097d7ea89ff07ffd69fd57bbf38826",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1800U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
