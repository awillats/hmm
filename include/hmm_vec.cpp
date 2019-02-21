//
//  hmm_fs.cpp
//  hmm_tests
//
//  Created by Adam Willats on 8/16/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

/**
 * Feder1co 5oave
 */


#include "hmm_vec.hpp"
//#include "../../../module_help/StAC_rtxi/hmm_tests/hmm_fs.hpp"


int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n) {
    //printf("vit start vec");
    assert(n > 0); assert(!observed.empty());
    //printf("vit start vec");
    int *seq = new int[n];//holy cow, need to delete this memory

    for (int i = 0; i < n; i++) seq[i] = 0;
    double **prob = new double*[n];
    int **prevs = new int*[n];
    
    for (int i = 0; i < n; i++) {
        prob[i] = new double[hmm.states];
        prevs[i] = new int[hmm.states];
        //printf("%i.",n); //fixes
        //printf("x"); //insufficient
        //i;
        for (int j = 0; j < hmm.states; j++) { 
            prob[i][j] = 0;
            prevs[i][j] = 0;
            
        }
    }
    //printf("\nearly check%i\n",n);
    //prob[0][0]=0.0; //why does this fix things!??!
        prob[0][0]=0.0;

    for (int i = 0; i < hmm.states; i++) {
        prob[0][i] = hmm.PI[i] * hmm.B[i][ observed[0] ];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < hmm.states; j++) {
            double pmax = 0, p; int dmax;
            for (int k = 0; k < hmm.states; k++) {
                p = prob[i-1][k] * hmm.A[k][j];
                if (p > pmax) {
                    pmax = p;
                    dmax = k;
                }
            }
            prob[i][j] = hmm.B[j][ observed[i] ] * pmax;
            prevs[i-1][j] = dmax;
        }
    }
    

    double pmax = 0; int dmax;
    for (int i = 0; i < hmm.states; i++) {
        if (prob[n-1][i] > pmax) {
            pmax = prob[n-1][i];
            dmax = i;
        }
    }
    seq[n-1] = dmax;
    
    for (int i = n-2; i >= 0; i--) {
        seq[i] = prevs[i][ seq[i+1] ];
    }
    
    //////////////////////////////////////////////////////////check
    for (int i = 0; i < n; i++) {
        ////cout << "t = " << i << endl;
        for (int j = 0; j < hmm.states; j++) {
            ////cout << '[' << j << ']' << prob[i][j] << ' ';
        }
        //cout << "\n\n";
    }
    
    for (int i = 0; i < n; i++) {
        ////cout << "t = " << i << endl;
        for (int j = 0; j < hmm.states; j++) {
            ////cout << '[' << j << ']' << prevs[i][j] << ' ';
        }
        ////cout << "\n\n";
    }
    
    ////cout << endl;

    ////cout << endl;
    //////////////////////////////////////////////////////////
       
//following comments are old, not sure if still apply
    // this is causing the crash
    //need to delete array of arrays
    // https://stackoverflow.com/questions/4193982/delete-a-pointer-to-pointer-as-array-of-arrays
  //  printf("\n%i\n",n);

        prob[0][0]=0.0; //delete?
    for (int i = 0; i < n; i++) {
        delete[] prob[i];
        delete[] prevs[i];
    }

   // printf("lastlast\n");
    delete[] prob;
    delete[] prevs;
   
    return seq;
    
}






























