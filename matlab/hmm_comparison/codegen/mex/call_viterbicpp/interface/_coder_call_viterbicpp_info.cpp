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
      "789ced56c14e8340105db49a26c6cac9cf280713efc6c6eac186d8e24163ecba6c85ba0b"
      "c8526dffc09bbfe1d14fb4946e8149369062ab36ce6578bcd9793303"
      "1d8ab48b4b0d21d4408999fb899f3ba4cffd16ca1be43510a7e5c3d10eaae5ce49fe7dee"
      "89ef45741c25c0c39c2e4eda3e773dec45bd4940514885cf5ea83d63",
      "062ea33d97d36e167462c4cf32d402c4547c7dea50f2d41d71143a22ad9065c1621e7d45"
      "bfb582794083f3807155f564fe6da55ec204aff6b7e8415b577fbb4a"
      "bd84b9b5ee662d16e91d94d4833e8dafe7f0bfde6af4c68a7c65df9743859e0e78eba673"
      "7ddceeb6869df3676bf83831f19149da99bd58a0535407526099bfae",
      "55cbaf9aabccffa1385f768e278afc3ae00d4bd05018d8c6dc68f964c4a91709e38a0a8a"
      "43e21866e80f2999de713837388e187e882fef89cf031cbac2f740dd"
      "fd25eb86b6aefd540738d54b98c188b1f853f553fd054beac9fc7b057a929fee61d96a4e"
      "bfafc8bf29fb6ad3f57ecb3e7eabb82f55ff53fffabeacfafb6e000c",
      "eb967cb339abc3f54484194befeb2bfe8e7d2ace97edcf04188138c9577e2e467e425f9e"
      "b8aac4",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3432U, &nameCaptureInfo);
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
                emlrtMxCreateDoubleScalar(738622.52223379631));
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
