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
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737484.61798611109));
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
    "789cdd53cd6ed340109ea002e5105409f1009c2b79db8204dceaf2d78ab4a0124a4405e97a3d90153bbbabf5260a371e8487e0c803f00c3c0fb6936d36958325"
    "043d30d278fdf9b366e6fb3c86cec16107006e96091660fd3ad4d12db37abe3183700596a33b3f03df693aede2fdabb056e3ee85f7bece4f61b4c7a99f012535",
    "1e8d29435702cd09cfcbe486a4e6daf73f5b0487855113cc6be68354d897843d13817d59027a1a51e7a0a2aafb4723149f5e8d09dca8588cab6200737faa99bf"
    "c7facf16fad71afc89fd0b7a8f57f8b331c7813f7df28ebd2ed0158ce79cd86323c684da17ec99f4fbe38c8d8806d5a5caa13064b99385d14c70a58613e9d165",
    "52589bd01de27e474c502ceb388b7544735e6bd011f36ddff906ac2ff097bdddd06f1ad7b3bff7ada9dfed15fd826f8117264797c872999ce62a51a83ffa11b4"
    "eb6e9be362ac9a2344e8f72daef707ba5fb4f40bfce9416f50ae4c6aad92827b6974c10ed37e2fdd1b1eef6c6d3fc8126e2df3c6a8cc4c1992aa73b3b68b6d06",
    "bfd8ccaf842e714f76dfffb8f5336dec67ffd15ec28a7df80ffb5dd67fd7ef9dbc7d48f9c0a56feedd9f6edf3da1ada3e7d11c2f5bfab4cd01316ed0b954dffe"
    "bdfabf005c10907c", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1824U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_viterbicpp_info.cpp) */
