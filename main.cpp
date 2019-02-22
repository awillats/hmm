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

#include "hmmFuns_.hpp"
//#include "hmm_fs.hpp"
//#include "convenienceFuns.hpp" //this causes the linker to fail for some reason

//#include "legacy/dataFuns.h"

std::string blockPrint(int bin)
{
    std::string block= ((bin==0) ? "\u2581":"\u2588");
    return block;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::vector<double> trs = {0.1,0.1}; //one of these elements is being interpretted as 1-X
    std::vector<double> frs = {.1,.6};
    std::vector<double> pis = {.5,.5};
    int nt = 2e2;
    
    HMMv myHMM = HMMv(2,2, trs, frs, pis);
    myHMM.printMyParams();
    myHMM.genSeq(nt);

    //std::vector<int> q = genHMM(frs,trs,nt); //from hmmFuns.cpp
    HMM_Data myHMMD = genHMM_Data(trs,frs,nt); //from hmmFuns_.cpp
    //std::cout << myHMM.spikes[1] << '\n';
    
    
    //friend int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n)
    int* vguess = viterbi(myHMM, myHMM.spikes, nt);

    
    //from here on out is just printing vectors
    for (int i=0;i<nt; i++)
    {
        std::cout << blockPrint(myHMM.spikes[i]==1);
    }
    std::cout<<"<spikes \n";
    
    
    for (int i=0;i<nt; i++)
    {
        std::cout << blockPrint(myHMM.states[i]==1);
    }
    int stateSum = std::accumulate(myHMM.states.begin(),myHMM.states.end(),0);
    double stateProb = double(stateSum)/double(nt);
    std::cout<<stateProb;
    std::cout<<"<states \n";
    for (int i=0;i<nt; i++)
    {
        std::cout << blockPrint(vguess[i]==1);
    }
    std::cout<<"<guessed states \n";
    
    //std::vector<int> q_hat = viterbi(myHMM,myHMM.spikes,nt);
    //std::cout << q << '\n';
    return 0;
}




