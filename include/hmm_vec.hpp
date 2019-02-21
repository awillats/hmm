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


//2d vectors http://thispointer.com/creating-a-matrix-using-2d-vector-in-c-vector-of-vectors/

//options for passing vectors to function https://stackoverflow.com/questions/26647152/passing-vectors-to-a-function-value-vs-reference-c
//http://thispointer.com/5-different-ways-to-initialize-a-vector-in-c/


struct HMMv {
    int states, events;
    std::vector< std::vector<double> > A, B;
    std::vector<double> PI;
    
    //https://stackoverflow.com/questions/18795776/error-no-matching-function-for-call-to-when-constructing-an-unintialized-stru
    HMMv(): states(2), events(2) { ;}; 

   //constructor where you just specify the firing and transition rate vectors, note should only work for 2 states...
    HMMv(int states, int events, std::vector< double> vFr, std::vector< double> vTr, std::vector<double> PI):
    states(states), events(events), PI(PI) {
        assert(states > 0); assert(events > 0);
        assert(!vFr.empty()); assert(!vTr.empty()); assert(!PI.empty());

	    std::vector<double> Av0;
	    std::vector<double> Av1;
	    std::vector<double> Bv0;
	    std::vector<double> Bv1;

	    Av0.push_back(1-vTr[0]);
	    Av0.push_back(vTr[0]);
	    Av1.push_back(vTr[1]);
	    Av1.push_back(1-vTr[1]);

	    Bv0.push_back(1-vFr[0]);
	    Bv0.push_back(vFr[0]);
	    Bv1.push_back(1-vFr[1]);
	    Bv1.push_back(vFr[1]);
	 
	    A.push_back(Av0);
	    A.push_back(Av1);

	    B.push_back(Bv0);
	    B.push_back(Bv1);
    }

    HMMv(int states, int events, std::vector< std::vector<double> > A, std::vector< std::vector<double> > B, std::vector<double> PI):
    states(states), events(events), A(A), B(B), PI(PI) {
        assert(states > 0); assert(events > 0);
        assert(!A.empty()); assert(!B.empty()); assert(!PI.empty());
    }

   friend std::vector<int> genStates(HMMv const& hmm);
   friend int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n); 
};




#endif /* hmm_fs_hpp */
