//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_call_viterbicpp_api.cpp
//
// Code generation for function '_coder_call_viterbicpp_api'
//

// Include files
#include "_coder_call_viterbicpp_api.h"
#include "call_viterbicpp.h"
#include "call_viterbicpp_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *spikes_,
                                   const char_T *identifier))[3000];

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3000];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trs_,
                                   const char_T *identifier))[2];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3000];

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nt,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const coder::array<int32_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const int32_T u[3000]);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

// Function Definitions
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *spikes_,
                                   const char_T *identifier))[3000]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3000];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(spikes_), &thisId);
  emlrtDestroyArray(&spikes_);
  return y;
}

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3000]
{
  real_T(*y)[3000];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trs_,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(trs_), &thisId);
  emlrtDestroyArray(&trs_);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3000]
{
  static const int32_T dims[2]{1, 3000};
  real_T(*ret)[3000];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[3000])emlrtMxGetData(src);
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
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
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

static const mxArray *emlrt_marshallOut(const int32_T u[3000])
{
  static const int32_T iv[2]{0, 0};
  static const int32_T iv1[2]{1, 3000};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxINT32_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

void call_viterbicpp_api(const mxArray *const prhs[6], int32_T nlhs,
                         const mxArray *plhs[3])
{
  coder::array<int32_T, 2U> statesGuess;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*spikes_)[3000];
  real_T(*states_)[3000];
  real_T(*frs_)[2];
  real_T(*pis_)[2];
  real_T(*trs_)[2];
  real_T nt;
  int32_T(*spikes)[3000];
  int32_T(*states)[3000];
  st.tls = emlrtRootTLSGlobal;
  spikes = (int32_T(*)[3000])mxMalloc(sizeof(int32_T[3000]));
  states = (int32_T(*)[3000])mxMalloc(sizeof(int32_T[3000]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  nt = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "nt");
  spikes_ = b_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "spikes_");
  states_ = b_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "states_");
  trs_ = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "trs_");
  frs_ = c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "frs_");
  pis_ = c_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "pis_");
  // Invoke the target function
  call_viterbicpp(&st, nt, *spikes_, *states_, *trs_, *frs_, *pis_, statesGuess,
                  *spikes, *states);
  // Marshall function outputs
  statesGuess.no_free();
  plhs[0] = emlrt_marshallOut(statesGuess);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*spikes);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(*states);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_call_viterbicpp_api.cpp)
