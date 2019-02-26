/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_hmmcpp_api.cpp
 *
 * Code generation for function '_coder_call_hmmcpp_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "call_hmmcpp.h"
#include "_coder_call_hmmcpp_api.h"
#include "call_hmmcpp_data.h"

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *in, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const int64_T u);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 0U, (int32_T *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *in, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(in), &thisId);
  emlrtDestroyArray(&in);
  return y;
}

static const mxArray *emlrt_marshallOut(const int64_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
  *(int64_T *)emlrtMxGetData(m1) = u;
  emlrtAssign(&y, m1);
  return y;
}

void call_hmmcpp_api(const mxArray * const prhs[1], int32_T, const mxArray *
                     plhs[1])
{
  real_T in;
  int64_T res;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  in = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "in");

  /* Invoke the target function */
  res = call_hmmcpp(&st, in);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(res);
}

/* End of code generation (_coder_call_hmmcpp_api.cpp) */
