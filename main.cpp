//
//  main.cpp
//  hmm
//
//  Created by Adam Willats on 2/21/19.
//  Copyright © 2019 Adam Willats. All rights reserved.
//


#include <iostream>
#include <vector>

#include "hmm_vec.hpp"
#include "printFuns.hpp"
#include "shuttleFuns.hpp"


//#include "legacy/dataFuns.h"




int main(int argc, const char * argv[]) {
    int printMode = 1;
    std::vector<double> trs = {0.2,0.2}; //transition rates
    std::vector<double> frs = {.1,.8}; //firing rates
    std::vector<double> pis = {.5,.5}; //initial state probabilities
    int nt = 3e2;
    
    
    //std::cout<<returnDub();
    
    
    HMMv myHMM = HMMv(2,2, trs, frs, pis);
    myHMM.printMyParams();
    myHMM.genSeq(nt);
    myHMM.printSeqs(printMode);

    int* vguess = viterbi(myHMM, myHMM.spikes, nt);

    //print percent of states which are 0. Just as a sanity check that transition probabilities are reasonably implemented
    int stateSum = std::accumulate(myHMM.states.begin(),myHMM.states.end(),0);
    double stateProb = double(stateSum)/double(nt);
    std::cout<<stateProb<<'\n';
    
    printVecAsBlock(&vguess[0], nt,printMode);
    std::cout<<"<guessed states \n";
    return 0;
}




