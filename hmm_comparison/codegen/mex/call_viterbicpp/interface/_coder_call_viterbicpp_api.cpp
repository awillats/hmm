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
#include "call_viterbicpp_emxutil.h"
#include "call_viterbicpp_data.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_call_viterbicpp_api",        /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static int32_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *spikes,
  const char_T *identifier))[300];
static int32_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[300];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trs_,
  const char_T *identifier))[2];
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nt, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const emxArray_int32_T *u);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static int32_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static int32_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *spikes,
  const char_T *identifier))[300]
{
  int32_T (*y)[300];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(spikes), &thisId);
  emlrtDestroyArray(&spikes);
  return y;
}
  static int32_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[300]
{
  int32_T (*y)[300];
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

static const mxArray *emlrt_marshallOut(const emxArray_int32_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxINT32_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, &u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
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

static int32_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[300]
{
  int32_T (*ret)[300];
  static const int32_T dims[2] = { 1, 300 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int32",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  ret = (int32_T (*)[300])emlrtMxGetData(src);
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

void call_viterbicpp_api(const mxArray * const prhs[5], int32_T, const mxArray
  *plhs[1])
{
  emxArray_int32_T *statesGuess;
  const mxArray *prhs_copy_idx_1;
  real_T nt;
  int32_T (*spikes)[300];
  real_T (*trs_)[2];
  real_T (*frs_)[2];
  real_T (*pis_)[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &statesGuess, 2, &c_emlrtRTEI, true);
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, false, -1);

  /* Marshall function inputs */
  nt = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "nt");
  spikes = c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "spikes");
  trs_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "trs_");
  frs_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "frs_");
  pis_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "pis_");

  /* Invoke the target function */
  call_viterbicpp(&st, nt, *spikes, *trs_, *frs_, *pis_, statesGuess);

  /* Marshall function outputs */
  statesGuess->canFreeData = false;
  plhs[0] = emlrt_marshallOut(statesGuess);
  emxFree_int32_T(&statesGuess);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_call_viterbicpp_api.cpp) */
