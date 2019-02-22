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
#include "printFuns.hpp" //this causes the linker to fail for some reason

//#include "legacy/dataFuns.h"

//figure out how to fold this nicely into a header
template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "]";
    return out;
}


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
    //HMM_Data myHMMD = genHMM_Data(trs,frs,nt); //from hmmFuns_.cpp
    //std::cout << myHMM.spikes[1] << '\n';
    
    
    //friend int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n)
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
    
    //std::vector<int> q_hat = viterbi(myHMM,myHMM.spikes,nt);
    //std::cout << q << '\n';
    return 0;
}




