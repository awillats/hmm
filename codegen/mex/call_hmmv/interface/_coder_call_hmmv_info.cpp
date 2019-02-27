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
                (737483.68017361115));
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
    "789ced54db6ed340101da382406a5024d40fe0b952b60d958007a4b8a53791b60842898820d9d8db7ac5de646fa2f44ffad0073e818fe843bfa0df83ed78d36d"
    "64d755a079401969b33e19ebcc99a3f180b37fe000c0f3f88002b85a86342af149feaf8e213c82db51c96e9377a6de73323e138f6129c595a9f72fb2db934293",
    "911e034605391cf03e0963203027131a5f722ab0d0ad33452024916443e2a79913ca488b72d29416d8a331e03b566a029254f2bc1510efe7e7018730886ee432"
    "1b40e64fa2f9dceebf77d3ff528e3fb67fa6df8d027faa1936f9cef677f425226184b08f397a2fbd012742476897eabd411f059cb7931fe461c6baf1c3b0c66d",
    "9d3d5ba7a5e3498e4e3befe4dd96ce67f0d4c2f586a937b2f9d4ddbee4d55b29a8677c31794ffa24acd178584281598d1171aa0328efbb4cc77414e93061eafd"
    "b6f966e8fba8a49ec977f69bed78245ca518f5b0a65244e8c06d35ddcdeea7fadafa9b7e0d2b85b494ac2f478870969ed5d42eb46afc4263bfe25199df9c347e",
    "5cbeb87673eba9879acb8279f80febcdebbb6b358fbfbde57e3b74bf6ebc1eadbf3ae66b871f2c1d1f4bea94e9001be7f4798b5ffd7bfe5f05fcf7f5f15d01bf"
    "f1d1e467d9eb2f39d6756f483c98f77edf5dec779b6fb1df27b1d8eff3a9b7d8ef7fc7ff07ea00e073",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 3296U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
