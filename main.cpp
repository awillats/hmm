//
//  main.cpp
//  hmm
//
//  Created by Adam Willats on 2/21/19.
//  Copyright © 2019 Adam Willats. All rights reserved.
//


#include <iostream>
#include <vector>

//#include "hmm_vec.hpp"
#include "printFuns.hpp" //this causes the linker to fail for some reason

//#include "legacy/dataFuns.h"




int main(int argc, const char * argv[]) {
    
    std::vector<double> trs = {0.2,0.2}; //transition rates
    std::vector<double> frs = {.1,.8}; //firing rates
    std::vector<double> pis = {.5,.5}; //initial state probabilities
    int nt = 3e2;
    
    int in=1;
    std::cout<<blockPrint(0);
    std::string block= ((in==0) ? "\u2581":"\u2588");
    std::cout << block;

    /*
    HMMv myHMM = HMMv(2,2, trs, frs, pis);
    myHMM.printMyParams();
    myHMM.genSeq(nt);

    int* vguess = viterbi(myHMM, myHMM.spikes, nt);

    //from here on out is just printing vectors
    printVecAsBlock(&myHMM.spikes[0], nt);
    std::cout<<"<spikes \n";
    
    printVecAsBlock(&myHMM.states[0], nt);
    std::cout<<"<states";
    int stateSum = std::accumulate(myHMM.states.begin(),myHMM.states.end(),0);
    double stateProb = double(stateSum)/double(nt);
    std::cout<<stateProb<<'\n';
    
    
    printVecAsBlock(&vguess[0], nt);
    std::cout<<"<guessed states \n";
     */
    return 0;
}




