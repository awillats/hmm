//
//  hmm_fs.hpp
//  hmm_tests
//
//  Created by Adam Willats on 8/16/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#ifndef hmm_vec_hpp
#define hmm_vec_hpp

#include <stdio.h>
#include <cassert>
#include <iostream>
#include <cmath>
#include <cfloat>

#include <vector>
#include <algorithm>

#include <random>

#include "printFuns.hpp"

//2d vectors http://thispointer.com/creating-a-matrix-using-2d-vector-in-c-vector-of-vectors/

//options for passing vectors to function https://stackoverflow.com/questions/26647152/passing-vectors-to-a-function-value-vs-reference-c
//http://thispointer.com/5-different-ways-to-initialize-a-vector-in-c/


struct HMMv {

    int nstates, nevents;
    std::vector< std::vector<double> > TR, EM;
    std::vector<double> PI;
    
    std::vector<int> states;
    std::vector<int> spikes;
    
    //https://stackoverflow.com/questions/18795776/error-no-matching-function-for-call-to-when-constructing-an-unintialized-stru
    HMMv(): nstates(2), nevents(2) { ;};

   //constructor where you just specify the firing and transition rate vectors, note should only work for 2 states...
    HMMv(int nstates, int nevents, std::vector< double> vTr, std::vector< double> vFr, std::vector<double> PI):
    nstates(nstates), nevents(nevents), PI(PI) {
        //assert(nstates > 0); assert(nevents > 0);
        assert(nstates==2); assert(nevents==2); //for now building the matrices only works for n=2
        assert(!vFr.empty()); assert(!vTr.empty()); assert(!PI.empty());

	    std::vector<double> Av0;
	    std::vector<double> Av1;
	    std::vector<double> Bv0;
	    std::vector<double> Bv1;

        //NB:transpose the matrix representation rather than the execution rules
        //NB:verify the matrix representation against standard approaches
        
        //Build tranistion matrix;
        Av0.push_back(1-vTr[0]); //0,0
	    Av0.push_back(vTr[0]); //0,1
	    Av1.push_back(vTr[1]); //1,0
	    Av1.push_back(1-vTr[1]); //1,1
        TR.push_back(Av0);
        TR.push_back(Av1);
        
        //Build emission matrix
  	    Bv0.push_back(1-vFr[0]);
	    Bv0.push_back(vFr[0]);
	    Bv1.push_back(1-vFr[1]);
	    Bv1.push_back(vFr[1]);
	    EM.push_back(Bv0);
	    EM.push_back(Bv1);
        //printMyParams();
    }
    //alternate more direct constructor? or just a consequence of the block above?
    HMMv(int nstates, int nevents, std::vector< std::vector<double> > TR, std::vector< std::vector<double> > EM, std::vector<double> PI):
    nstates(nstates), nevents(nevents), TR(TR), EM(EM), PI(PI) {
        assert(nstates > 0); assert(nevents > 0);
        assert(!TR.empty()); assert(!EM.empty()); assert(!PI.empty());
    }

   //friend std::vector<int> genStates(HMMv const& hmm);
   friend int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n);
   friend void printMat(std::vector< std::vector<double> >);

public:
    std::vector<int> genSeq(int);
    void printMyParams();
    
//private:
};








#endif /* hmm_fs_hpp */
