//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// call_viterbicpp.cpp
//
// Code generation for function 'call_viterbicpp'
//

// Include files
#include "call_viterbicpp.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "hmm_vec.cpp"
#include "mwmathutil.h"
#include "printFuns.cpp"
#include "shuttleFuns.cpp"

// Variable Definitions
static emlrtDCInfo emlrtDCI{
    36,                // lineNo
    36,                // colNo
    "call_viterbicpp", // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_viterbicpp.m", // pName
    1 // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    36,                // lineNo
    36,                // colNo
    "call_viterbicpp", // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_viterbicpp.m", // pName
    4 // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    36,                // lineNo
    9,                 // colNo
    "call_viterbicpp", // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_viterbicpp.m", // pName
    1 // checkKind
};

static emlrtRTEInfo emlrtRTEI{
    36,                // lineNo
    9,                 // colNo
    "call_viterbicpp", // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_viterbicpp.m" // pName
};

// Function Definitions
void call_viterbicpp(const emlrtStack *sp, real_T nt,
                     const real_T spikes_[1000], const real_T states_[1000],
                     const real_T trs_[2], const real_T frs_[2],
                     const real_T pis_[2],
                     coder::array<int32_T, 2U> &statesGuess,
                     int32_T spikes[1000], int32_T states[1000])
{
  std::vector<double> frs;
  std::vector<double> pis;
  std::vector<double> trs;
  real_T matv[2];
  real_T d;
  int32_T i;
  int32_T loop_ub;
  //  NEW EXPERIMENTAL, from
  //  https://www.mathworks.com/help/coder/ref/coder.cinclude.html
  // convert input vecs to c++
  // pre-allocates a std::vec
  matv[0] = trs_[0];
  matv[1] = trs_[1];
  trs = array2vec(&matv[0], 2.0);
  // populates the std::vec from matlab vecs
  // pre-allocates a std::vec
  matv[0] = frs_[0];
  matv[1] = frs_[1];
  frs = array2vec(&matv[0], 2.0);
  // populates the std::vec from matlab vecs
  // pre-allocates a std::vec
  matv[0] = pis_[0];
  matv[1] = pis_[1];
  pis = array2vec(&matv[0], 2.0);
  // populates the std::vec from matlab vecs
  HMMv myHMM = HMMv(2.0, 2.0, trs, frs, pis);
  // ceval('str') :> cpp::str();
  //  DEBUG ONLY coder.ceval('myHMM.printMyParams');
  // coder.ceval('myHMM.genSeq',nt);
  // import to C++
  for (i = 0; i < 1000; i++) {
    d = muDoubleScalarRound(spikes_[i]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        loop_ub = static_cast<int32_T>(d);
      } else {
        loop_ub = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      loop_ub = MAX_int32_T;
    } else {
      loop_ub = 0;
    }
    spikes[i] = loop_ub;
    d = muDoubleScalarRound(states_[i]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        loop_ub = static_cast<int32_T>(d);
      } else {
        loop_ub = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      loop_ub = MAX_int32_T;
    } else {
      loop_ub = 0;
    }
    states[i] = loop_ub;
  }
  // prep to export from C++
  statesGuess.set_size(&emlrtRTEI, sp, 1, statesGuess.size(1));
  if (!(nt >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nt, &b_emlrtDCI, (emlrtCTX)sp);
  }
  d = static_cast<int32_T>(muDoubleScalarFloor(nt));
  if (nt != d) {
    emlrtIntegerCheckR2012b(nt, &emlrtDCI, (emlrtCTX)sp);
  }
  statesGuess.set_size(&emlrtRTEI, sp, statesGuess.size(0),
                       static_cast<int32_T>(nt));
  if (nt != d) {
    emlrtIntegerCheckR2012b(nt, &c_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(nt);
  for (i = 0; i < loop_ub; i++) {
    statesGuess[i] = 0;
  }
  // void HMMv::importSpksExportGuess(int nt, int * spikeIn, int * stateIn, int
  // * stateGuessOut)
  myHMM.importSpksExportGuess(nt, &spikes[0], &states[0], &statesGuess[0]);
  // coder.ceval('int* vguess = viterbi(myHMM, myHMM.spikes, nt)');
  //         %{
  //         %prep for export
  //         %this casting in redundant with hard limits on input types
  //         %spikes = cast(zeros(1,nt),'int32');
  //         coder.ceval('myHMM.printSeqs',printMode);
  //         %note this DOES NOT import spikes/states
  //         coder.ceval('myHMM.exportSeqsGuess',nt,coder.ref(spikes),coder.ref(states),coder.ref(statesGuess));
  //
  //         %}
}

// End of code generation (call_viterbicpp.cpp)
