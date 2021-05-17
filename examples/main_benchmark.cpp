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
  int nrep = 0; // 1e3;

  // HMMv myHMM = HMMv(2,2, trs, frs, pis);

  std::cout << "argc" << argc << '\n';

  //default HMM params
  std::vector<std::vector<double>> trs = {{0.9,0.1},{.1,.9}};
  std::vector<std::vector<double>> frs = {{0.9,0.1},{.2,.8}};
  //std::vector<std::vector<double>> frs = {{0.9,0.05,0.05},{.1,0.45,.45}};

  std::vector<double> pis = {.1, .9};
  int nStates = 2;
  int nEmission = 2;
  int printMode = 1;


 //Override HMM params if we have input from the console
 //For a simplified debugging nStates == nEmissions here, but that doesn't have to be the case generally

 //Also, for easy in-console visualization, I've chosen parameters such that the most common output
 //For each state matches the identity of that state

  if (argc>1)
  {
      std::cout << "argv0: " << argv[1] << '\n';

      int nInput = std::stoi(argv[1]);
      
      switch (nInput)
      {
        case 2:
            //use trs, frs set on line 44
            break;
        case 3:
            // trs = {
            //     {0.8, 0.1, 0.1},
            //      {.1, .8, .1},
            //       {.1, .1, .8}};
            // frs = {
            //     {0.9, 0.05, 0.05},
            //      {.15, 0.7, .15},
            //       {.1, 0.1, .8}};
            // pis = {.1, .9, .1};
            // nStates = 3;
            // nEmission = 3;
            // printMode = 3;
            break;
        //default:
        }
  }
  if (argc>2)
  {
      // if there's a second argument it specifies how many time samples to generate & decode
      nt = std::stoi(argv[2]);
  }
  std::cout << "nStates: "<<nStates << '\n';

  HMMv myHMM = HMMv(nStates, nEmission, trs, frs, pis);

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
 //probabilities are reasonably implemented
 int stateSum = std::accumulate(myHMM.states.begin(), myHMM.states.end(), 0);
 double stateProb = double(stateSum)/double(nt);
 //std::cout<< "\n avg output: "<<stateProb<<"\n";

 printVecAsBlock(&vguess[0], myHMM.ntPrint, printMode);
  //std::vector<int> v = array2vec(&vguess[0], nt);
/**/
  std::cout << " < guessed states \n";

  return 0;
}
