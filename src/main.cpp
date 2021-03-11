//
//  main.cpp
//  hmm
//
//  Created by Adam Willats on 2/21/19.
//  Copyright © 2019 Adam Willats. All rights reserved.
//
#include <iostream>
#include <vector>

//#ifdef USE_MYMATH
#   include "../fake_lib/fake.h"
//#endif

#include "../include/hmm_h/hmm_vec.hpp"
#include "../include/hmm_h/printFuns.hpp"
#include "../include/hmm_h/shuttleFuns.hpp"

//#include "legacy/dataFuns.h"

int main(int argc, const char *argv[]) {
  int printMode = 0;
  /*
  std::vector<double> trs = {0.1,0.1}; //transition rates
  std::vector<double> frs = {.1,.9}; //firing rates
  std::vector<double> pis = {.1,.9}; //initial state probabilities
   */
  int nt = 1e3;
  int nrep = 0; // 1e3;

  // HMMv myHMM = HMMv(2,2, trs, frs, pis);

  // std::vector<std::vector<double>> trs = {{0.9,0.1},{.1,.9}};
  // std::vector<std::vector<double>> frs = {{0.9,0.05,0.05},{.1,0.45,.45}};
  std::vector<std::vector<double>> trs = {
      {0.8, 0.1, 0.1}, {.1, .8, .1}, {.1, .1, .8}};
  std::vector<std::vector<double>> frs = {
      {0.9, 0.05, 0.05}, {.1, 0.45, .45}, {.1, 0.8, .1}};

  std::vector<double> pis = {.1, .9};

  float inputValue = 125.0;

  #ifdef USE_MYMATH
    const double outputValue = cmake::my::mysqrt(inputValue);
    std::cout << "use flag is defined !!" << endl;
  #else
    const double outputValue = inputValue;
    std::cout << "use flag is undefined :( " <<endl;
  #endif

  //const double outputValue2 = cmake::my::mysqrt(inputValue);
  std::cout << cmake::my::mysqrt(inputValue);
  //outputValue;
  //std::cout << outputValue2;


  /*

    HMMv myHMM = HMMv(3, 3, trs, frs, pis);

 // myHMM.printMyParams();
  myHMM.genSeq(nt);

  myHMM.printSeqs(printMode);

  int* vguess = viterbi(myHMM, myHMM.spikes, nt);
  for (int i=0;i<nrep;i++)
  {
      myHMM.genSeq(nt);
      viterbi(myHMM, myHMM.spikes, nt);
  }

  int spkAry[nt];
  int stateAry[nt];
  int vguess2[nt];
  myHMM.exportSeqsGuess(nt,spkAry,stateAry,vguess2);

  //print percent of states which are 0. Just as a sanity check that transition
 probabilities are reasonably implemented int stateSum =
 std::accumulate(myHMM.states.begin(),myHMM.states.end(),0); double stateProb =
 double(stateSum)/double(nt); std::cout<<stateProb<<'\n';

  printVecAsBlock(&vguess[0], nt,printMode);
  //std::vector<int> v = array2vec(&vguess[0], nt);
*/
  std::cout << "<guessed states \n";

  return 0;
}
