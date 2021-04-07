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
static emlrtRTEInfo emlrtRTEI = { 29,  /* lineNo */
  9,                                   /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/rtxi_vm_copy/hmm_modules/hmmX/hmm/call_viterbicpp.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 29,    /* lineNo */
  36,                                  /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/rtxi_vm_copy/hmm_modules/hmmX/hmm/call_viterbicpp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 29,  /* lineNo */
  36,                                  /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/rtxi_vm_copy/hmm_modules/hmmX/hmm/call_viterbicpp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 29,  /* lineNo */
  9,                                   /* colNo */
  "call_viterbicpp",                   /* fName */
  "/Users/adam/Documents/GitHub/rtxi_vm_copy/hmm_modules/hmmX/hmm/call_viterbicpp.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void call_viterbicpp(const emlrtStack *sp, real_T nt, const real_T spikes_[3000],
                     const real_T states_[3000], const real_T trs_[2], const
                     real_T frs_[2], const real_T pis_[2], emxArray_int32_T
                     *statesGuess, int32_T spikes[3000], int32_T states[3000])
{
  real_T b_trs_[2];
  std::vector<double> trs;
  std::vector<double> frs;
  std::vector<double> pis;
  int32_T i0;
  real_T d0;
  int32_T loop_ub;

  /* convert input vecs to c++ */
  /* pre-allocates a std::vec */
  b_trs_[0] = trs_[0];
  b_trs_[1] = trs_[1];
  trs = array2vec(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  /* pre-allocates a std::vec */
  b_trs_[0] = frs_[0];
  b_trs_[1] = frs_[1];
  frs = array2vec(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  /* pre-allocates a std::vec */
  b_trs_[0] = pis_[0];
  b_trs_[1] = pis_[1];
  pis = array2vec(b_trs_, 2.0);

  /* populates the std::vec from matlab vecs */
  HMMv myHMM = HMMv(2.0, 2.0, trs, frs, pis);

  /* ceval('str') :> cpp::str(); */
  /*  DEBUG ONLY coder.ceval('myHMM.printMyParams'); */
  /* coder.ceval('myHMM.genSeq',nt);  */
  /* import to C++ */
  for (i0 = 0; i0 < 3000; i0++) {
    d0 = muDoubleScalarRound(spikes_[i0]);
    if (d0 < 2.147483648E+9) {
      if (d0 >= -2.147483648E+9) {
        loop_ub = (int32_T)d0;
      } else {
        loop_ub = MIN_int32_T;
      }
    } else if (d0 >= 2.147483648E+9) {
      loop_ub = MAX_int32_T;
    } else {
      loop_ub = 0;
    }

    spikes[i0] = loop_ub;
  }

  for (i0 = 0; i0 < 3000; i0++) {
    d0 = muDoubleScalarRound(states_[i0]);
    if (d0 < 2.147483648E+9) {
      if (d0 >= -2.147483648E+9) {
        loop_ub = (int32_T)d0;
      } else {
        loop_ub = MIN_int32_T;
      }
    } else if (d0 >= 2.147483648E+9) {
      loop_ub = MAX_int32_T;
    } else {
      loop_ub = 0;
    }

    states[i0] = loop_ub;
  }

  /* prep to export from C++ */
  i0 = statesGuess->size[0] * statesGuess->size[1];
  statesGuess->size[0] = 1;
  if (!(nt >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nt, &b_emlrtDCI, sp);
  }

  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &emlrtDCI, sp);
  }

  statesGuess->size[1] = (int32_T)nt;
  emxEnsureCapacity_int32_T(sp, statesGuess, i0, &emlrtRTEI);
  if (nt != (int32_T)muDoubleScalarFloor(nt)) {
    emlrtIntegerCheckR2012b(nt, &c_emlrtDCI, sp);
  }

  loop_ub = (int32_T)nt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    statesGuess->data[i0] = 0;
  }

  /* void HMMv::importSpksExportGuess(int nt, int * spikeIn, int * stateIn, int * stateGuessOut) */
  myHMM.importSpksExportGuess(nt, spikes, states, &statesGuess->data[0]);

  /* coder.ceval('int* vguess = viterbi(myHMM, myHMM.spikes, nt)'); */
  /*         %{ */
  /*         %prep for export */
  /*         %this casting in redundant with hard limits on input types */
  /*         %spikes = cast(zeros(1,nt),'int32'); */
  /*         coder.ceval('myHMM.printSeqs',printMode);  */
  /*         %note this DOES NOT import spikes/states */
  /*         coder.ceval('myHMM.exportSeqsGuess',nt,coder.ref(spikes),coder.ref(states),coder.ref(statesGuess)); */
  /*  */
  /*         %} */
}

/* End of code generation (call_viterbicpp.cpp) */
