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
    "/Users/adam/Documents/GitHub/rtxi_vm_copy/hmm_modules/hmmX/hmm/call_viterbicpp.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737512.50149305561));
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
    "789cdd53cd6ed430109e45e5efb06825c40370ae14b70509b8354061ab6e0b82a5ac28903a8e612d3cb6e538abf4d607e12178040e3c03cf43925d77dd2a4b24"
    "043d3092637ff9ac99f9be4ca0b7bbdf03805bd5020330b80e4df4ab55bf1fcc215c81f3d15fec9eefb5ed6679ff2aac35b87fe1ded7c5ceb472bc74732085e2",
    "0705a6dc564051e46769328d4251e5c6278683e5b996339e35cc2721f958201fe9000c4505f059409d819aaacf4fa69c7d795d20d869be6c57860016fed43d7f"
    "0ff51f2ff5afb5f813fae7f5be5fe1cf60813d7fb4f381bcc9b9cd09cd2892a79a15c895cbc973e186454aac2b4532c384697342a68809eaac903cafcf93fa41",
    "1895329909c76d2a983111de45eab6d88cb350cf71a827e8f75a8b9e90effade37e1c6129f0eb77dbd32cc677eef5f5bbd3b2bea79ff3ccf74c66d24aaa1b28a"
    "ca4872f5d94da15b77571f1763551f3e7cbd6f61be3fd0fda2a39ee78f7647936a746263a460d409ad72b21f8f47f1e3e4d5d6c6e6c334a2c610a7b54c754938",
    "ca66ad37769175ef1799fb15e125cec9f6c71fb77fc6adf5cc3f9a4b58310fff61bdcbfaefc6a3c3778f309bd8f8edfd07e5e6bd43dc38d80bfa78d951a7ab0f"
    "08718bce73f9cddfcbff0b090594b6", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1832U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_call_viterbicpp_info.cpp) */
