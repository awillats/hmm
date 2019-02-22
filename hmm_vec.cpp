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
    int *seq = new int[n];//holy cow, need to delete this memory, convert to vectorized to stop memory leak?

    for (int i = 0; i < n; i++) seq[i] = 0;
    double **prob = new double*[n];
    int **prevs = new int*[n];
    
    for (int i = 0; i < n; i++) {
        prob[i] = new double[hmm.nstates];
        prevs[i] = new int[hmm.nstates];
        //printf("%i.",n); //fixes
        //printf("x"); //insufficient
        //i;
        for (int j = 0; j < hmm.nstates; j++) {
            prob[i][j] = 0;
            prevs[i][j] = 0;
            
        }
    }
    //printf("\nearly check%i\n",n);
    //prob[0][0]=0.0; //why does this fix things!??!
        prob[0][0]=0.0;

    for (int i = 0; i < hmm.nstates; i++) {
        prob[0][i] = hmm.PI[i] * hmm.EM[i][ observed[0] ];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < hmm.nstates; j++) {
            double pmax = 0, p; int dmax=-1;
            for (int k = 0; k < hmm.nstates; k++) {
                p = prob[i-1][k] * hmm.TR[k][j];
                if (p > pmax) {
                    pmax = p;
                    dmax = k;
                }
            }
            prob[i][j] = hmm.EM[j][ observed[i] ] * pmax;
            prevs[i-1][j] = dmax;
        }
    }
    

    double pmax = 0; int dmax=-1;
    for (int i = 0; i < hmm.nstates; i++) {
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
        for (int j = 0; j < hmm.nstates; j++) {
            ////cout << '[' << j << ']' << prob[i][j] << ' ';
        }
        //cout << "\n\n";
    }
    
    for (int i = 0; i < n; i++) {
        ////cout << "t = " << i << endl;
        for (int j = 0; j < hmm.nstates; j++) {
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




void HMMv::printMyParams()
{
    std::cout<<"transition matrix:";
    printMat(TR);
    std::cout<<"\nemission matrix:";
    printMat(EM);
};

std::vector<int>  HMMv::genSeq(int nt)
{
    //zero out the class's vectors
    states = std::vector<int> (nt,0);
    spikes = std::vector<int> (nt,0);
    
    //set random seed
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> unif(0, 1);
    
    for (int i=0;i<nt; i++)
    {
        states[i] = 0;
    };
    
    for (int i=0;i<nt; i++)
    {
        int curState =states[i];
        int otherState = 1-curState;
        //generate spikes
        spikes[i] = (unif(gen) < EM[curState][1]) ? 1 : 0;
        
        if (i<(nt-1))
        {
            //only works for state={0,1}
            double pTr = TR[curState][otherState];
            
            //generate next steps transition rule
            //NB: do this with a matrix mult eventually?
            states[i+1] = (unif(gen) < pTr) ? otherState : curState;
        }
    };
    
    //std::vector<int> whatev(nt,13);
    //spikes = whatev;
    return spikes;
};






























