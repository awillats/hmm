/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_viterbicpp.cpp
 *
 * Code generation for function 'call_viterbicpp'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "call_viterbicpp.h"
#include "call_viterbicpp_emxutil.h"
#include "printFuns.cpp"
#include "shuttleFuns.cpp"
#include "hmm_vec.cpp"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 15,    /* lineNo */
  "call_viterbicpp",                   /* fcnName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 16,  /* lineNo */
  "call_viterbicpp",                   /* fcnName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 17,  /* lineNo */
  "call_viterbicpp",                   /* fcnName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 26,  /* lineNo */
  9,                                   /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 27,/* lineNo */
  9,                                   /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 26,    /* lineNo */
  31,                                  /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 26,  /* lineNo */
  31,                                  /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 27,  /* lineNo */
  36,                                  /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 26,  /* lineNo */
  9,                                   /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 27,  /* lineNo */
  9,                                   /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/hmm_comparison/call_viterbicpp.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void call_viterbicpp(const emlrtStack *sp, real_T nt, int32_T spikes[300], const
                     real_T trs_[2], const real_T frs_[2], const real_T pis_[2],
                     emxArray_int32_T *statesGuess)
{
  real_T b_trs_[2];
  std::vector<double> trs;
  std::vector<double> frs;
  emxArray_int32_T *states;
  std::vector<double> pis;
  int32_T i0;
  int32_T loop_ub;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* coder.ceval('blockPrint',1,printMode); */
  /* convert input vecs to c++ */
  st.site = &emlrtRSI;

  /* pre-allocates a std::vec */
  b_trs_[0] = trs_[0];
  b_trs_[1] = trs_[1];
  trs = array2vec(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  st.site = &b_emlrtRSI;

  /* pre-allocates a std::vec */
  b_trs_[0] = frs_[0];
  b_trs_[1] = frs_[1];
  frs = array2vec(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  st.site = &c_emlrtRSI;

  /* pre-allocates a std::vec */
  b_trs_[0] = pis_[0];
  b_trs_[1] = pis_[1];
  emxInit_int32_T(&st, &states, 2, &emlrtRTEI, true);
  pis = array2vec(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  HMMv myHMM = HMMv(2.0, 2.0, trs, frs, pis);
  myHMM.printMyParams();
  myHMM.genSeq(nt);

  /* spikes = cast(zeros(1,nt),'int32'); */
  i0 = states->size[0] * states->size[1];
  states->size[0] = 1;
  if (!(nt >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nt, &b_emlrtDCI, sp);
  }

  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &emlrtDCI, sp);
  }

  states->size[1] = (int32_T)nt;
  emxEnsureCapacity_int32_T(sp, states, i0, &emlrtRTEI);
  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &d_emlrtDCI, sp);
  }

  loop_ub = (int32_T)nt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    states->data[i0] = 0;
  }

  i0 = statesGuess->size[0] * statesGuess->size[1];
  statesGuess->size[0] = 1;
  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &c_emlrtDCI, sp);
  }

  statesGuess->size[1] = (int32_T)nt;
  emxEnsureCapacity_int32_T(sp, statesGuess, i0, &b_emlrtRTEI);
  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &e_emlrtDCI, sp);
  }

  loop_ub = (int32_T)nt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    statesGuess->data[i0] = 0;
  }

  myHMM.printSeqs(0.0);

  /* export vector to workspace */
  myHMM.exportSeqsGuess(nt, spikes, &states->data[0], &statesGuess->data[0]);
  emxFree_int32_T(&states);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (call_viterbicpp.cpp) */
