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
    
    std::vector<double> frs = {.1,.9};
    std::vector<double> trs = {0.01,0.02};
    std::vector<double> pis = {.5,.5};
    int nt = 200;
    
    
    
    
    HMMv myHMM = HMMv(2,2, frs, trs, pis);
    std::cout << myHMM.A[1][1] << '\n';
    
    
//    std::vector<int> q = genHMM(frs,trs,nt); //from hmmFuns.cpp
    HMM_Data myHMMD = genHMM_Data(frs,trs,nt); //from hmmFuns_.cpp
    //std::cout << myHMM.spikes[1] << '\n';
    
    
    //friend int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n)
    int* vguess = viterbi(myHMM, myHMMD.spikes, nt);

    for (int i=0;i<nt; i++)
    {
        std::cout<< vguess[i];
    }
    //std::vector<int> q_hat = viterbi(myHMM,myHMM.spikes,nt);
    
    //std::cout << q << '\n';
    return 0;
}
