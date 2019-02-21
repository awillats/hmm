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
//#include "convenienceFuns.hpp"

//#include "legacy/dataFuns.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::vector<double> frs = {.03,.9};
    std::vector<double> trs = {0.5,0.2};
    std::vector<double> pis = {.5,.5};
    int nt = 100;
    
    
    HMMv myHMM = HMMv(2,2, trs, frs, pis);
    myHMM.genSeq(nt);
    
    std::cout << myHMM.EM[1][1] << '\n';
    
    std::cout <<myHMM.spikes[1]<<'\n';
    
    
//    std::vector<int> q = genHMM(frs,trs,nt); //from hmmFuns.cpp
    HMM_Data myHMMD = genHMM_Data(trs,frs,nt); //from hmmFuns_.cpp
    //std::cout << myHMM.spikes[1] << '\n';
    
    
    //friend int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n)
    int* vguess = viterbi(myHMM, myHMM.spikes, nt);

    
    for (int i=0;i<nt; i++)
    {
        std::cout << ((myHMM.spikes[i]==1)?"\u2581":"\u2588");
    }
    std::cout<<"<spikes \n";
    
    
    for (int i=0;i<nt; i++)
    {
        std::cout << ((myHMM.states[i]==1)?"\u2581":"\u2588");
    }
    std::cout<<"<states \n";
    for (int i=0;i<nt; i++)
    {
        std::cout << ((vguess[i]==1)?"\u2581":"\u2588");
    }
    std::cout<<"<guessed states \n";
    //std::vector<int> q_hat = viterbi(myHMM,myHMM.spikes,nt);
    
    //std::cout << q << '\n';
    return 0;
}
