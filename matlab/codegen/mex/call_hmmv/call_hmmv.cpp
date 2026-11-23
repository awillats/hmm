//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// call_hmmv.cpp
//
// Code generation for function 'call_hmmv'
//

// Include files
#include "call_hmmv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "hmm_vec.cpp"
#include "mwmathutil.h"
#include "printFuns.cpp"
#include "shuttleFuns.cpp"

// Variable Definitions
static emlrtDCInfo emlrtDCI{
    41,                                                               // lineNo
    31,                                                               // colNo
    "call_hmmv",                                                      // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m", // pName
    1 // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    41,                                                               // lineNo
    31,                                                               // colNo
    "call_hmmv",                                                      // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m", // pName
    4 // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    42,                                                               // lineNo
    31,                                                               // colNo
    "call_hmmv",                                                      // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m", // pName
    1 // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    43,                                                               // lineNo
    36,                                                               // colNo
    "call_hmmv",                                                      // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m", // pName
    1 // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    41,                                                               // lineNo
    9,                                                                // colNo
    "call_hmmv",                                                      // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m", // pName
    1 // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    42,                                                               // lineNo
    9,                                                                // colNo
    "call_hmmv",                                                      // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m", // pName
    1 // checkKind
};

static emlrtDCInfo g_emlrtDCI{
    43,                                                               // lineNo
    9,                                                                // colNo
    "call_hmmv",                                                      // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m", // pName
    1 // checkKind
};

static emlrtRTEInfo emlrtRTEI{
    41,                                                              // lineNo
    9,                                                               // colNo
    "call_hmmv",                                                     // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    42,                                                              // lineNo
    9,                                                               // colNo
    "call_hmmv",                                                     // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    43,                                                              // lineNo
    9,                                                               // colNo
    "call_hmmv",                                                     // fName
    "/Users/adam/Documents/Research/Projects/hmm/matlab/call_hmmv.m" // pName
};

// Function Definitions
void call_hmmv(const emlrtStack *sp, real_T nt, const real_T trs_[2],
               const real_T frs_[2], const real_T pis_[2],
               coder::array<int32_T, 2U> &spikes,
               coder::array<int32_T, 2U> &states,
               coder::array<int32_T, 2U> &statesGuess)
{
  std::vector<double> frs;
  std::vector<double> pis;
  std::vector<double> trs;
  real_T v[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  //  NEW EXPERIMENTAL, from
  //  https://www.mathworks.com/help/coder/ref/coder.cinclude.html
  //          customSrc = coder.const(fullfile(pwd, '../src/'));
  //          customInc = coder.const(fullfile(pwd, '../build/include/'));
  //          coder.updateBuildInfo('addIncludePaths', customSrc);
  //          coder.updateBuildInfo('addIncludePaths', customInc);
  //          coder.updateBuildInfo('addSourcePaths', customSrc);
  v[0] = 1.0;
  v[1] = 2.0;
  modDubVec(&v[0], 2.0);
  // coder.ceval('blockPrint',1,printMode);
  // convert input vecs to c++
  // pre-allocates a std::vec
  v[0] = trs_[0];
  v[1] = trs_[1];
  trs = array2vec(&v[0], 2.0);
  // populates the std::vec from matlab vecs
  // pre-allocates a std::vec
  v[0] = frs_[0];
  v[1] = frs_[1];
  frs = array2vec(&v[0], 2.0);
  // populates the std::vec from matlab vecs
  // pre-allocates a std::vec
  v[0] = pis_[0];
  v[1] = pis_[1];
  pis = array2vec(&v[0], 2.0);
  // populates the std::vec from matlab vecs
  HMMv myHMM = HMMv(2.0, 2.0, trs, frs, pis);
  myHMM.printMyParams();
  myHMM.genSeq(nt);
  spikes.set_size(&emlrtRTEI, sp, 1, spikes.size(1));
  if (!(nt >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nt, &b_emlrtDCI, (emlrtCTX)sp);
  }
  i = static_cast<int32_T>(muDoubleScalarFloor(nt));
  if (nt != i) {
    emlrtIntegerCheckR2012b(nt, &emlrtDCI, (emlrtCTX)sp);
  }
  spikes.set_size(&emlrtRTEI, sp, spikes.size(0), static_cast<int32_T>(nt));
  if (nt != i) {
    emlrtIntegerCheckR2012b(nt, &e_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(nt);
  for (i1 = 0; i1 < loop_ub; i1++) {
    spikes[i1] = 0;
  }
  states.set_size(&b_emlrtRTEI, sp, 1, states.size(1));
  if (nt != i) {
    emlrtIntegerCheckR2012b(nt, &c_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(nt);
  states.set_size(&b_emlrtRTEI, sp, states.size(0), loop_ub);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(nt, &f_emlrtDCI, (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub; i1++) {
    states[i1] = 0;
  }
  statesGuess.set_size(&c_emlrtRTEI, sp, 1, statesGuess.size(1));
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(nt, &d_emlrtDCI, (emlrtCTX)sp);
  }
  statesGuess.set_size(&c_emlrtRTEI, sp, statesGuess.size(0), loop_ub);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(nt, &g_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    statesGuess[i] = 0;
  }
  myHMM.printSeqs(0.0);
  // export vector to workspace
  myHMM.exportSeqsGuess(nt, &spikes[0], &states[0], &statesGuess[0]);
}

// End of code generation (call_hmmv.cpp)
