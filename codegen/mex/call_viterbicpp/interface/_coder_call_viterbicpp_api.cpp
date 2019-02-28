/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_call_viterbicpp_api.cpp
 *
 * Code generation for function '_coder_call_viterbicpp_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "call_viterbicpp.h"
#include "_coder_call_viterbicpp_api.h"
#include "call_viterbicpp_data.h"

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *spikes_, const char_T *identifier))[300];
static boolean_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[300];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trs_,
  const char_T *identifier))[2];
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nt, const
  char_T *identifier);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static boolean_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[300];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *spikes_, const char_T *identifier))[300]
{
  boolean_T (*y)[300];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(spikes_), &thisId);
  emlrtDestroyArray(&spikes_);
  return y;
}
  static boolean_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[300]
{
  boolean_T (*y)[300];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trs_,
  const char_T *identifier))[2]
{
  real_T (*y)[2];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(trs_), &thisId);
  emlrtDestroyArray(&trs_);
  return y;
}
  static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nt, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nt), &thisId);
  emlrtDestroyArray(&nt);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2]
{
  real_T (*y)[2];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 0U, (int32_T *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[300]
{
  boolean_T (*ret)[300];
  static const int32_T dims[2] = { 1, 300 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "logical",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  ret = (boolean_T (*)[300])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  real_T (*ret)[2];
  static const int32_T dims[2] = { 1, 2 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  ret = (real_T (*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void call_viterbicpp_api(const mxArray * const prhs[5], int32_T)
{
  real_T nt;
  boolean_T (*spikes_)[300];
  real_T (*trs_)[2];
  real_T (*frs_)[2];
  real_T (*pis_)[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  nt = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "nt");
  spikes_ = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "spikes_");
  trs_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "trs_");
  frs_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "frs_");
  pis_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "pis_");

  /* Invoke the target function */
  call_viterbicpp(&st, nt, *spikes_, *trs_, *frs_, *pis_);
}

/* End of code generation (_coder_call_viterbicpp_api.cpp) */
