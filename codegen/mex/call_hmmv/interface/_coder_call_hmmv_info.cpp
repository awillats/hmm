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
                (3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737483.70181712962));
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
    "789ced54cd6ed340101e570115895491100fd073a46c92562a1c90ea5248ab2605b56989a8a06cec85acd83fd99b28bdf1181c38f411fa101c78029e07dbf1a6"
    "dbc8ae512839541969b3fe32d637df7c1a0f38fb1d0700d6a2030ae0d76348a21c9df8ffca04c20adc8c727a9bbc33f39e93f2997800a5049767deff91de9e14",
    "9a8cf504302ac8e190f7491001813999d2f892538185ee5e28020109251b113fc97ca68c7429276d69813d1a01feda4a4d419c8a9f5f0e88f7f578c8211884d7"
    "72990d20f527d6fc3da7ff52863fb67fa6dfcd1c7f2a2936f9b3571fd049488210611f73b42bbd21274287a845f5deb08f069cf7e21fe461c6cea387518ddb3a",
    "3fe5e87c98a1d3ce3b59b7a5f311ac5ab8b96dea8d6d3e75bb2f59f59ee6d433be98bc277d12d468342c81c0acc688f8a20750dc77918ed9c8d361c2d4bbb2f9"
    "e6e8fb4d413d933fdb6ff7a291709562d4c39a4a11a28edb6dbb3be747cd7ae359bf8695425a4ad6976344384b4e35b10b558d5f68e257342a8b9b93ed8f3f9f",
    "fc7633eba9ff359739f3700feb2deabbebb64fdf3fe77e2f70df6d6e8d1b1ba7bc7e7860e9785b50a74807d838a3cf1bfceaeef92f73f8ffd6c71739fcc64793"
    "9f67afaf73ac9bde8878b0e0fdfeadb5dcef36df72bf4f63b9df17536fb9dfff8dff0fee42e093",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 3296U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_hmmv_info.cpp) */
