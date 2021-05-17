/// \brief basic usage of Hidden Markov Model code
///
/// \file
/// "hmm" is a simple set of hidden Markov model (HMM) code.
/// It decodes latent state-switches
/// from a categorical signal (usually a binary spike-train)
///   \author Adam Willats
///   \date 2/21/19

// /TODO(awillats): allow the main method to accept state size for better testing

// /TODO(awillats):output metrics of success, namely % accuracy, maybe also compute time

#include <chrono>

#include <iostream>
#include <vector>

#include "../include/hmm_h/hmm_vec.hpp"
#include "../include/hmm_h/printFuns.hpp"
#include "../include/hmm_h/shuttleFuns.hpp"

//#include "legacy/dataFuns.h"
/**
 * This is the main() for testing basic HMM functionality.
 * Builds an HMM, generates a sequence, estimates states, then prints them to cout
 * @param  argv optional args:{nStates, nSamples}
 * @return      0 if successful
 */
int main(int argc, const char *argv[]) {
  /*
  std::vector<double> trs = {0.1,0.1}; //transition rates
  std::vector<double> frs = {.1,.9}; //firing rates
  std::vector<double> pis = {.1,.9}; //initial state probabilities
   */
  int nt = 175;//1e3;
  int ntMaxPrint = 1e3;
  int nrep = 100; // 1e3;

  // HMMv myHMM = HMMv(2,2, trs, frs, pis);

  std::cout << "argc" << argc << '\n';

  //default HMM params
  std::vector<std::vector<double>> trs = {{0.9,0.1},{.1,.9}};
  std::vector<std::vector<double>> frs = {{0.9,0.1},{.2,.8}};
  std::vector<double> pis = {.1, .9};
  int nStates = 2;
  int nEmission = 2;
  int printMode = 1; //1


 //Override HMM params if we have input from the console
 //For a simplified debugging nStates == nEmissions here, but that doesn't have to be the case generally

 //Also, for easy in-console visualization, I've chosen parameters such that the most common output
 //For each state matches the identity of that state

  if (argc>1)
  {
      std::cout << "argv0: " << argv[1] << '\n';

      int nInput = std::stoi(argv[1]);
      assert(nInput>0);

      if (nInput==3) { printMode=3;}
      if (nInput>3) {printMode=0;}

      nStates = nInput;
      // nEmission = nInput;
      pis = HMMv::simplePriorVec(nStates);
      frs = HMMv::simpleEmissMat(nStates,nEmission);
      trs = HMMv::simpleTransMat(nStates);
  }
  if (argc>2)
  {
      // if there's a second argument it specifies how many time samples to generate & decode
      nt = std::stoi(argv[2]);
  }
  std::cout << "nStates: "<<nStates << '\n';

  HMMv myHMM = HMMv(nStates, nEmission, trs, frs, pis);

 myHMM.printMyParams();
 myHMM.genSeq(nt);

 myHMM.printSeqs(printMode);

//https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time

auto start_time = std::chrono::system_clock::now();
 int *vguess = viterbi(myHMM, myHMM.spikes, nt);
 auto end_time = std::chrono::system_clock::now();
 std::chrono::duration<double> diff = end_time-start_time;
 cout << "Run time = " << diff.count() << " ms\n";

 for (int i = 0; i < nrep; i++) {
   myHMM.genSeq(nt);

   auto start_time = std::chrono::system_clock::now();
   viterbi(myHMM, myHMM.spikes, nt);
   auto end_time = std::chrono::system_clock::now();
   std::chrono::duration<double> diff = end_time-start_time;

   cout << "Run time = " << diff.count() << " ms\n";

  }

  int spkAry[nt];
  int stateAry[nt];
  int vguess2[nt];
  myHMM.exportSeqsGuess(nt,spkAry,stateAry,vguess2);

  //print percent of states which are 0. Just as a sanity check that transition
 //probabilities are reasonably implemented
 int stateSum = std::accumulate(myHMM.states.begin(), myHMM.states.end(), 0);
 double stateProb = double(stateSum)/double(nt);
 //std::cout<< "\n avg output: "<<stateProb<<"\n";

 printVecAsBlock(&vguess[0], myHMM.ntPrint, printMode);
  //std::vector<int> v = array2vec(&vguess[0], nt);

  std::cout << " < guessed states \n";

  // std::vector<double> gp;
  // std::vector<std::vector<double>> ge;
  // std::vector<std::vector<double>> gt;
  //
  //
  // for (int i=2; i<=10; i++)
  //  {
  //      std::cout<<endl<<i<<" states -- \n";
  //      gp = HMMv::simplePriorVec(i);
  //      ge = HMMv::simpleEmissMat(i,2); //can also try (3,i) etc.
  //      gt = HMMv::simpleTransMat(i);
  //
  //      std::cout<<"transitions:\n";
  //      printMat(gt);
  //      std::cout<<"emissions:\n";
  //      printMat(ge);
  //      std::cout<<"prior:\n";
  //      printVec(gp);
  //      std::cout<<endl;
  //  }
  return 0;
}
