//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_call_hmmv_api.cpp
//
// Code generation for function '_coder_call_hmmv_api'
//

// Include files
#include "_coder_call_hmmv_api.h"
#include "call_hmmv.h"
#include "call_hmmv_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trs_,
                                   const char_T *identifier))[2];

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nt,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const coder::array<int32_T, 2U> &u);

// Function Definitions
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trs_,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(trs_), &thisId);
  emlrtDestroyArray(&trs_);
  return y;
}

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2]{1, 2};
  real_T(*ret)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nt,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(nt), &thisId);
  emlrtDestroyArray(&nt);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<int32_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxINT32_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<int32_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<int32_T, 2U> *)&u)->size(),
                     2);
  emlrtAssign(&y, m);
  return y;
}

void call_hmmv_api(const mxArray *const prhs[4], int32_T nlhs,
                   const mxArray *plhs[3])
{
  coder::array<int32_T, 2U> spikes;
  coder::array<int32_T, 2U> states;
  coder::array<int32_T, 2U> statesGuess;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*frs_)[2];
  real_T(*pis_)[2];
  real_T(*trs_)[2];
  real_T nt;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  nt = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "nt");
  trs_ = b_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "trs_");
  frs_ = b_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "frs_");
  pis_ = b_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "pis_");
  // Invoke the target function
  call_hmmv(&st, nt, *trs_, *frs_, *pis_, spikes, states, statesGuess);
  // Marshall function outputs
  spikes.no_free();
  plhs[0] = emlrt_marshallOut(spikes);
  if (nlhs > 1) {
    states.no_free();
    plhs[1] = emlrt_marshallOut(states);
  }
  if (nlhs > 2) {
    statesGuess.no_free();
    plhs[2] = emlrt_marshallOut(statesGuess);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_call_hmmv_api.cpp)
