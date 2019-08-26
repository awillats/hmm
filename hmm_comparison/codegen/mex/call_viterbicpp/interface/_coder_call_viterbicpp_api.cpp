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
static emlrtRTEInfo b_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_call_viterbicpp_api",        /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *b_emlrt_marshallOut(const int32_T u[1000]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *spikes_,
  const char_T *identifier))[1000];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1000];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trs_,
  const char_T *identifier))[2];
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nt, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const emxArray_int32_T *u);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1000];
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

static const mxArray *b_emlrt_marshallOut(const int32_T u[1000])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 0, 0 };

  static const int32_T iv2[2] = { 1, 1000 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv1, mxINT32_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, *(int32_T (*)[2])&iv2[0], 2);
  emlrtAssign(&y, m1);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *spikes_,
  const char_T *identifier))[1000]
{
  real_T (*y)[1000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(spikes_), &thisId);
  emlrtDestroyArray(&spikes_);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[1000]
{
  real_T (*y)[1000];
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

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1000]
{
  real_T (*ret)[1000];
  static const int32_T dims[2] = { 1, 1000 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  ret = (real_T (*)[1000])emlrtMxGetData(src);
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

void call_viterbicpp_api(const mxArray * const prhs[6], int32_T nlhs, const
  mxArray *plhs[3])
{
  int32_T (*spikes)[1000];
  int32_T (*states)[1000];
  emxArray_int32_T *statesGuess;
  real_T nt;
  real_T (*spikes_)[1000];
  real_T (*states_)[1000];
  real_T (*trs_)[2];
  real_T (*frs_)[2];
  real_T (*pis_)[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  spikes = (int32_T (*)[1000])mxMalloc(sizeof(int32_T [1000]));
  states = (int32_T (*)[1000])mxMalloc(sizeof(int32_T [1000]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &statesGuess, 2, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  nt = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "nt");
  spikes_ = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "spikes_");
  states_ = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "states_");
  trs_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "trs_");
  frs_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "frs_");
  pis_ = e_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "pis_");

  /* Invoke the target function */
  call_viterbicpp(&st, nt, *spikes_, *states_, *trs_, *frs_, *pis_, statesGuess,
                  *spikes, *states);

  /* Marshall function outputs */
  statesGuess->canFreeData = false;
  plhs[0] = emlrt_marshallOut(statesGuess);
  emxFree_int32_T(&statesGuess);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*spikes);
  }

  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(*states);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_call_viterbicpp_api.cpp) */
