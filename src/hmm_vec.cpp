//
//  hmm_fs.cpp
//  hmm_tests
//
//  Created by Adam Willats on 8/16/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

///   \brief core functions for hmm, construction and decoding
///
///   \file
///   Constructs HMM object as well as performs viterbi decoding
///   \author Adam Willats.
///   based on viterbi.cpp by Feder1co 5oave: https://gist.github.com/Feder1co5oave/2347228
///   \date 2019-2021

// #include "../include/hmm_h/hmm_vec.hpp"
#include <hmm.h>
//#include "../../../module_help/StAC_rtxi/hmm_tests/hmm_fs.hpp"


 /**
  * adds small constant before taking the logarithm, to avoid log(0) error
  * @param  val input value
  * @return     log(val + small epsilon)
  */
double logE(double val)
{
    double eps = 1e-10;
    //assert(val>=0);
    return log(val+eps);
}
/**
 * Uses the viterbi algorithm to estimate the most-likely state sequence.
 *
 * @param  hmm      object containing parameters of the HMM
 * @param  observed vector of ints representing the obeserved signal
 * @param  n        time-length of the input signal
 * @return          vector of most-likely states
 */
int* viterbi(HMMv const& hmm, std::vector<int> observed, const int n) {
    assert(n > 0); assert(!observed.empty());

    double pmaxDefault = -1e10; //set to 0 if you're using the non-log-transformed versions

    //since observed gets used to index the transition/emission matrix directly
    //we need to check for an out of bounds exception
    if (*max_element(observed.begin(),observed.end()) >= hmm.nevents)
    {
        //This fix is designed for deltas between matlab and c++ indexing. This will not catch every possible mismatch
        //std::cout<<">"<<*max_element(observed.begin(),observed.end())<<","<<hmm.nevents<<"<";
        //temporary fix:
        int delta = hmm.nevents - *max_element(observed.begin(),observed.end());
        for (int i=0;i<n;i++)
        {
            observed[i] = observed[i]+delta-1;
        }
        //std::cout<<"CORRECTING\n"<<"d:"<<delta<<","<<*max_element(observed.begin(),observed.end())<<endl;
        assert(*max_element(observed.begin(),observed.end()) < hmm.nstates);
    }

    int prob0warnflag = 0;
    int *seq = new int[n];//holy cow, need to delete this memory, convert to vectorized to stop memory leak?

    for (int i = 0; i < n; i++) seq[i] = 0;
    double **prob = new double*[n];
    int **prevs = new int*[n];

    for (int i = 0; i < n; i++) {
        prob[i] = new double[hmm.nstates];
        prevs[i] = new int[hmm.nstates];
        //printf("%i.",n); //fixes
        for (int j = 0; j < hmm.nstates; j++) {
            prob[i][j] = 0;
            prevs[i][j] = 0;
        }
    }
    //printf("\nearly check%i\n",n);
    //prob[0][0]=0.0; //why does this fix things!??!
    prob[0][0]=0.0;

    for (int i = 0; i < hmm.nstates; i++) {
        //prob[0][i] = hmm.PI[i] * hmm.EM[i][ observed[0] ]; //non-log version
        prob[0][i] = logE(hmm.PI[i]) + logE(hmm.EM[i][ observed[0] ]); //convert to log

    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < hmm.nstates; j++) {
            double pmax = pmaxDefault, p; int dmax=-1;
            for (int k = 0; k < hmm.nstates; k++) {
                //p = prob[i-1][k] * hmm.TR[k][j]; //non-log version
                p = prob[i-1][k]+logE(hmm.TR[k][j]); //convert to log

                if (p > pmax) {
                    pmax = p;
                    dmax = k;
                }
                if (dmax==-1)
                {
                    std::cout<<">"<<p<<","<<pmax<<"<<\n";
                }
            }
            if (dmax<0)
            {
                prob0warnflag=1;
                dmax=0;
            }
            //prob[i][j] = hmm.EM[j][ observed[i] ] * pmax; //non-log version
            prob[i][j] = logE(hmm.EM[j][ observed[i] ]) + pmax;
            prevs[i-1][j] = dmax;
        }
    }


    double pmax = pmaxDefault; int dmax=-1;
    for (int i = 0; i < hmm.nstates; i++) {
        if (prob[n-1][i] > pmax) {
            pmax = prob[n-1][i];
            dmax = i;
        }
    }
    if (dmax<0)
    {
        prob0warnflag=1;
        dmax=0;
    }
    seq[n-1] = dmax;

    for (int i = n-2; i >= 0; i--) {
       // std::cout<<">"<<i<<"_"<<seq[i+1]<<"_"<<"<\n";
        assert(seq[i+1]>=0);
        seq[i] = prevs[i][ seq[i+1] ]; //fails, generally for 2<< i< n-10
    }

    //check
    for (int i = 0; i < n; i++) {
        //cout << "t = " << i << endl;
        for (int j = 0; j < hmm.nstates; j++) {
            //cout << '[' << j << ']' << prob[i][j] << ' ';
        }
        //cout << "\n\n";
    }

    for (int i = 0; i < n; i++) {
        //cout << "t = " << i << endl;
        for (int j = 0; j < hmm.nstates; j++) {
            //cout << '[' << j << ']' << prevs[i][j] << ' ';
        }
        //cout << "\n\n";
    }
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

    if (prob0warnflag!=0)
    {
        std::cout<<"weird, all probs 0?";
        //weird holdover from before we were working in log probability space
    }
    delete[] prob;
    delete[] prevs;
    return seq;
}

/**
 * prints model's paramters in matrix form
 */
void HMMv::printMyParams()
{
    std::cout<<"transition matrix:";
    printMat(TR);
    std::cout<<"\nemission matrix:";
    printMat(EM);
};

/**
 * prints model's spikes and states
 * @param printMode 0 for ints, 1 for block characters, 2 for _&^
 */
void HMMv::printSeqs(int printMode)
{
    printVecAsBlock(&states[0], ntPrint, printMode);
    std::cout<<" < states \n";

    printVecAsBlock(&spikes[0], ntPrint, printMode);
    std::cout<<" < spikes \n";
};

/**
 * exports HMM's recorded spikes and states vectors to input ptrs
 * @param spikeLoc ptr to spikes for output
 * @param stateLoc ptr to states for output
 */
void HMMv::exportSeqs(int * spikeLoc, int * stateLoc)
{
    std::copy(spikes.begin(), spikes.end(), spikeLoc);
    std::copy(states.begin(), states.end(), stateLoc);
};
/**
 * Imports spikes (and true states), decodes a state estimate, then exports the estimates states through stateGuessOut
 * @param nt            number of time samples
 * @param spikeIn       pointer to spikes being loaded in for decoding
 * @param stateIn       (unused) ptr to true states
 * @param stateGuessOut ptr to output decoded states
 */
//
void HMMv::importSpksExportGuess(int nt, int * spikeIn, int * stateIn, int * stateGuessOut)
{
    spikes = array2vec(spikeIn,nt);//import spikes to HMM object
    states = array2vec(stateIn,nt);//import states to HMM object Not sur

    //std::vector<int> spikes2= array2vec(spikeIn,nt);

    int* vguess = viterbi(*this , spikes, nt);
    std::copy(vguess, vguess+nt, stateGuessOut);
    delete[] vguess; //fixes matlab crash?

};

/**
 * Copies spikes and states into input pointers
 * @param nt            number of time samples
 * @param spikeOut      pointer to where spikes should be output
 * @param stateOut      pointer to where true state values should be output
 * @param stateGuessOut pointer to where guessed states should be output
 */
void HMMv::exportSeqsGuess(int nt, int * spikeOut, int * stateOut, int * stateGuessOut)
{
    std::copy(spikes.begin(), spikes.end(), spikeOut);//export HMM.spikes to pointer location
    std::copy(states.begin(), states.end(), stateOut);//export HMM.states to pointer location

    int* vguess = viterbi(*this , spikes, nt);
    std::copy(vguess, vguess+nt, stateGuessOut);
    delete[] vguess;
};


/**
 * Generates a sequence of states, and their accompanying outputs
 * @param  nt_ number of time samples
 * @return     spikes - vector of output values (int)
 */
std::vector<int>  HMMv::genSeq(int nt_, int currentState)
{
    //currentState is optional, defaults to NULL
    nt =nt_;
    int ntMaxPrint = 600;
    ntPrint = std::min(nt,ntMaxPrint); // hardcoded maximimum length of sequence to print
    //zero out the class's vectors
    states = std::vector<int> (nt,0);
    spikes = std::vector<int> (nt,0);

    //set random seed
    std::random_device rd;
    std::mt19937 gen(rd()); //choose a specific integer to "freeze" the random seed

    // NOTE:: this should all be done when the HMM is CONSTRUCTED!
    // NOT every time we have to generate a new sequence
    // save trDistrs and emDistrs as properties of the HMMv !!!

    std::discrete_distribution<int> piDist(PI.begin(),PI.end());
    std::vector< std::discrete_distribution <int> > trDistrs;
    std::vector< std::discrete_distribution <int> > emDistrs;

    //build distributions for emission and transition
    for (int k=0;k<nstates;k++)
    {
        std::discrete_distribution<int> trDistr(TR[k].begin(),TR[k].end());
        trDistrs.push_back(trDistr);

        std::discrete_distribution<int> emDistr(EM[k].begin(),EM[k].end());
        emDistrs.push_back(emDistr);
    }


    if (currentState==-1)
    {
        states[0] = piDist(gen); //gen the first state
    }
    else
    {
        states[0] = currentState;
    }

    for (int i=0;i<nt; i++)
    {
        int curState =states[i];

        //generate spikes
        spikes[i] = emDistrs[curState](gen);

        if (i<(nt-1))
        {
            //generate next steps transition rule
            states[i+1] = trDistrs[curState](gen);
        }
    };
    return spikes;
};

/**
 * Simple macro to print to cout
 * @param strin string to be printed
 * @note mostly for debugging, could be removed
 */
void setWarning(char * strin)
{
    std::cout<<strin;
}

// some functions for generating default matrices for
// debugging and benchmarking models

std::vector< std::vector<double> > HMMv::simpleTransMat(int nStates)
{
    //initialize transition matrix to be very likely to stay in the same state
    double pStay = 0.95;
    double pMove = (1.0 - pStay) / (nStates-1);

    std::vector<double> baseRow(nStates, pMove);
    std::vector<std::vector<double>> TransMat(nStates, baseRow);

    //https://www.techiedelight.com/vector-of-vector-cpp/
    for (int i=0; i < nStates; i++)
    {
        TransMat[i][i] = pStay;
    }
    return TransMat;
}
std::vector< std::vector<double> > HMMv::simpleEmissMat(int nStates,int nEmission)
{
    // what to do for non-square emission matrices?
        // either
    double pSame = 0.9;
    double pOther = (1.0-pSame) / nEmission;

    std::vector<double> baseRow(nEmission, pOther);
    std::vector<std::vector<double>> EmissMat(nStates, baseRow);


    if (nStates == nEmission)
    {
        // make the likely emission symbol the same as the state index
        // i.e. while in state 2, emit symbol 2
        for (int i=0; i < nStates; i++)
        {
            EmissMat[i][i] = pSame;
        }
    }
    else
    {
        // NOTE! with this method, rows will NOT be correctly normalized as is.
        // the constructor should successfully normalize them as it loads them however
        double w = double(nEmission) / nStates;
        double dx = double(nEmission-1) / (nStates-1);
        double spread = 1;// controls how "peaky" and separable the different
        //states's emissions are

        for (int i=0; i<nStates; i++)
        {
            for (int j=0; j<nEmission; j++)
            {
                EmissMat[i][j] = exp( -1*spread* pow(j - dx*(i),2) );
            }
            //normalize rows
            double rowTotal = 0;
            for (int j=0; j<nEmission; j++)
            {
                rowTotal += EmissMat[i][j];
            }
            for (int j=0; j<nEmission; j++)
            {
                EmissMat[i][j] = EmissMat[i][j]/rowTotal;
            }
        }
    }
    return EmissMat;
}
std::vector< double > HMMv::simplePriorVec(int nStates)
{
    //strategy here is to make one state (the 0th?) likely at 90% chance
    // then divide up remaining probability amongst the other states
    int idxLikely = 0;
    double pLikely = 0.9;
    double pOther = (1.0 - pLikely) / (nStates-1);

    std::vector<double> PriorVec(nStates, pOther);
    PriorVec[idxLikely] = pLikely;
    return PriorVec;
}



//
