//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_call_viterbicpp_info.cpp
//
// Code generation for function 'call_viterbicpp'
//

// Include files
#include "_coder_call_viterbicpp_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *emlrtMexFcnResolvedFunctionsInfo();

// Function Definitions
static const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5]{
      "789ced56414f8330142e3acd12a372f2ec3f68a289472f2e4e0f2ec40d0f1a23153a61b6"
      "3029d3ed5778f5e8cff4e8182bd026b5b8e9d4c577793cbef6fbde7b"
      "c02bc0383d3300005b20b3ddcdcc4f1d30a77e058826e386b4ce109783355013f671fc79"
      "eadd284cf030c98210519ceff4221a84284c3aa33e0631661179c4de",
      "04e9060477028adbe5a09546f4b804e5410aa5d7473e76efdb030a629f1519927290f7c3"
      "51d45bd3f44336b91ff2ba79f538ffaa522f43fa4fde97e8c9b6a8fa"
      "d6957a1972655f4f4ad4e96d57d4937db1be2ec4ff7adfa33754f0557d5f76147aa684db"
      "97ad8b8366bbd16b9d3cd8bdbb9185f62db759e461697474790045cc",
      "f9dfe6e457f595f3bf28f657ede39e82df947068331c33883c446123720714870983e798"
      "6114bb3eb4e2a887ddf11d9f52485142d0ad98a733639eb22d6a1ed5"
      "a5b8d0cb90ee8090f468faa9fafa33ea71fe0d8d1ec7c77397972ae83b0afe65994fcbae"
      "f75be6efd0f858479787eabff4afcdc7457dcf63fd9b2064092244d0",
      "07733e07dd39f5aad85fb5be4305bf29e19f7f0e5068c93b0a659796", ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3384U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[6]{
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  const char_T *propFieldName[5]{"Version", "ResolvedFunctions", "EntryPoints",
                                 "CoverageInfo", "IsPolymorphic"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"Name",
                emlrtMxCreateString((const char_T *)"call_viterbicpp"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"FullPath",
                emlrtMxCreateString(
                    (const char_T *)"/Users/adam/Documents/Research/Projects/"
                                    "hmm/matlab/call_viterbicpp.m"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"TimeStamp",
                emlrtMxCreateDoubleScalar(738622.52491898148));
  xResult =
      emlrtCreateStructMatrix(1, 1, 5, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, (const char_T *)"Version",
                emlrtMxCreateString((const char_T *)"9.11.0.1769968 (R2021b)"));
  emlrtSetField(xResult, 0, (const char_T *)"ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, (const char_T *)"EntryPoints", xEntryPoints);
  return xResult;
}

// End of code generation (_coder_call_viterbicpp_info.cpp)
