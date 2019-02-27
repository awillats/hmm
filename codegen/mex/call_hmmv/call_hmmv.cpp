/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * call_hmmv.cpp
 *
 * Code generation for function 'call_hmmv'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "call_hmmv.h"
#include "call_hmmv_emxutil.h"
#include "printFuns.cpp"
#include "shuttleFuns.cpp"
#include "hmm_vec.cpp"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 33,  /* lineNo */
  9,                                   /* colNo */
  "call_hmmv",                         /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "call_hmmv",                         /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 33,    /* lineNo */
  31,                                  /* colNo */
  "call_hmmv",                         /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 33,  /* lineNo */
  31,                                  /* colNo */
  "call_hmmv",                         /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 34,  /* lineNo */
  31,                                  /* colNo */
  "call_hmmv",                         /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 33,  /* lineNo */
  9,                                   /* colNo */
  "call_hmmv",                         /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 34,  /* lineNo */
  9,                                   /* colNo */
  "call_hmmv",                         /* fName */
  "/Users/adam/Documents/GitHub/hmmX/hmm/call_hmmv.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void call_hmmv(const emlrtStack *sp, real_T nt, const real_T trs_[2], const
               real_T frs_[2], const real_T pis_[2], emxArray_int32_T *spikes,
               emxArray_int32_T *states)
{
  real_T v[2];
  std::vector<double> trs;
  std::vector<double> frs;
  std::vector<double> pis;
  int32_T i0;
  int32_T loop_ub;

  /*         %{ */
  /*         dub_ = coder.opaque('double []'); */
  /*         dub_ = coder.ceval('returnDub'); */
  /*         dub = cast(dub_,'like',[1.0,1.0]) */
  /*         %} */
  v[0] = 1.0;
  v[1] = 2.0;
  modDubVec(v, 2.0);

  /* coder.ceval('blockPrint',1,printMode); */
  /* convert input vecs to c++ */
  /* pre-allocates a std::vec */
  v[0] = trs_[0];
  v[1] = trs_[1];
  trs = array2vec(v, 2.0);

  /* populates the std::vec from matlab vecs */
  /* pre-allocates a std::vec */
  v[0] = frs_[0];
  v[1] = frs_[1];
  frs = array2vec(v, 2.0);

  /* populates the std::vec from matlab vecs */
  /* pre-allocates a std::vec */
  v[0] = pis_[0];
  v[1] = pis_[1];
  pis = array2vec(v, 2.0);

  /* populates the std::vec from matlab vecs */
  HMMv myHMM = HMMv(2.0, 2.0, trs, frs, pis);
  myHMM.printMyParams();
  myHMM.genSeq(nt);
  i0 = spikes->size[0] * spikes->size[1];
  spikes->size[0] = 1;
  if (!(nt >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nt, &b_emlrtDCI, sp);
  }

  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &emlrtDCI, sp);
  }

  spikes->size[1] = (int32_T)nt;
  emxEnsureCapacity_int32_T(sp, spikes, i0, &emlrtRTEI);
  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &d_emlrtDCI, sp);
  }

  loop_ub = (int32_T)nt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    spikes->data[i0] = 0;
  }

  i0 = states->size[0] * states->size[1];
  states->size[0] = 1;
  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &c_emlrtDCI, sp);
  }

  states->size[1] = (int32_T)nt;
  emxEnsureCapacity_int32_T(sp, states, i0, &b_emlrtRTEI);
  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &e_emlrtDCI, sp);
  }

  loop_ub = (int32_T)nt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    states->data[i0] = 0;
  }

  /* export vector to workspace */
  myHMM.exportSeqs(&spikes->data[0], &states->data[0]);
  myHMM.printSeqs(0.0);
}

/* End of code generation (call_hmmv.cpp) */
