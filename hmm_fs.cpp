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


#include "hmm_fs.hpp"

struct HMM {
    int states, events;
    double **A, **B;
    double *PI;
    
    HMM(int states, int events, double **A, double **B, double *PI):
    states(states), events(events), A(A), B(B), PI(PI) {
        assert(states > 0); assert(events > 0);
        assert(A != NULL); assert(B != NULL); assert(PI != NULL);
    }
};

int* viterbi(HMM const& hmm, const int observed[], const int n) {
    assert(n > 0); assert(observed != NULL);
    int *seq = new int[n];
    for (int i = 0; i < n; i++) seq[i] = 0;
    double **prob = new double*[n];
    int **prevs = new int*[n];
    for (int i = 0; i < n; i++) {
        prob[i] = new double[hmm.states];
        prevs[i] = new int[hmm.states];
        for (int j = 0; j < hmm.states; j++) { //unnecessary
            prob[i][j] = 0;
            prevs[i][j] = 0;
        }
    }
    
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
    
    
    //////////////////////////////////////////////////////////
    for (int i = 0; i < n; i++) {
        cout << "t = " << i << endl;
        for (int j = 0; j < hmm.states; j++) {
            cout << '[' << j << ']' << prob[i][j] << ' ';
        }
        cout << "\n\n";
    }
    
    for (int i = 0; i < n; i++) {
        cout << "t = " << i << endl;
        for (int j = 0; j < hmm.states; j++) {
            cout << '[' << j << ']' << prevs[i][j] << ' ';
        }
        cout << "\n\n";
    }
    
    cout << endl;
    for (int i = 0; i < n; i++) cout << '[' << i << ']' << seq[i] << ' ';
    cout << endl;
    //////////////////////////////////////////////////////////
    
    
    for (int i = 0; i < n; i++) {
        delete[] prob[i];
        delete[] prevs[i];
    }
    delete[] prob;
    delete[] prevs;
    
    return seq;
}

struct HMMLog {
    int states, events;
    double **A, **B;
    double *PI;
    
    HMMLog(int states, int events, double **A, double **B, double *PI) {
        assert(states > 0); assert(events > 0);
        assert(A != NULL); assert(B != NULL); assert(PI != NULL);
        this->states = states;
        this->events = events;
        this->A = new double*[states];
        for (int i = 0; i < states; i++) {
            this->A[i] = new double[states];
            for (int j = 0; j < states; j++) this->A[i][j] = log(A[i][j]);
        }
        this->B = new double*[states];
        for (int i = 0; i < states; i++) {
            this->B[i] = new double[events];
            for (int j = 0; j < events; j++) this->B[i][j] = log(B[i][j]);
        }
        this->PI = new double[states];
        for (int i = 0; i < states; i++) this->PI[i] = log(PI[i]);
    }
    ~HMMLog() {
        delete[] PI;
        for (int i = 0; i < states; i++) {
            delete[] A[i];
            delete[] B[i];
        }
        delete[] A;
        delete[] B;
    }
};

int* viterbi(HMMLog const& hmm, const int observed[], const int n) {
    assert(n > 0); assert(observed != NULL);
    int *seq = new int[n];
    for (int i = 0; i < n; i++) seq[i] = 0;
    double **prob = new double*[n];
    int **prevs = new int*[n];
    for (int i = 0; i < n; i++) {
        prob[i] = new double[hmm.states];
        prevs[i] = new int[hmm.states];
        for (int j = 0; j < hmm.states; j++) { //unnecessary
            prob[i][j] = 0;
            prevs[i][j] = 0;
        }
    }
    
    for (int i = 0; i < hmm.states; i++) {
        prob[0][i] = hmm.PI[i] + hmm.B[i][ observed[0] ];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < hmm.states; j++) {
            double pmax = -DBL_MAX, p; int dmax;
            for (int k = 0; k < hmm.states; k++) {
                p = prob[i-1][k] + hmm.A[k][j];
                if (p > pmax) {
                    pmax = p;
                    dmax = k;
                }
            }
            prob[i][j] = hmm.B[j][ observed[i] ] + pmax;
            prevs[i-1][j] = dmax;
        }
    }
    
    double pmax = -DBL_MAX; int dmax;
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
    
    //////////////////////////////////////////////////////////*
    for (int i = 0; i < n; i++) {
        cout << "t = " << i << endl;
        for (int j = 0; j < hmm.states; j++) {
            cout << '[' << j << ']' << prob[i][j] << ' ';
        }
        cout << "\n\n";
    }
    
    for (int i = 0; i < n; i++) {
        cout << "t = " << i << endl;
        for (int j = 0; j < hmm.states; j++) {
            cout << '[' << j << ']' << prevs[i][j] << ' ';
        }
        cout << "\n\n";
    }	
    
    cout << endl;
    for (int i = 0; i < n; i++) cout << '[' << i << ']' << seq[i] << ' ';
    cout << endl;
    //////////////////////////////////////////////////////////
    
    
    for (int i = 0; i < n; i++) {
        delete[] prob[i];
        delete[] prevs[i];
    }
    delete[] prob;
    delete[] prevs;
    
    return seq;
}
/*
int main() {
    double A0[2] = {0.7, 0.3}; 
    double A1[2] = {0.3, 0.7};
    double *A[2] = {A0, A1};
    double B0[2] = {0.9, 0.1};
    double B1[2] = {0.2, 0.8};
    double *B[2]= {B0, B1};
    double PI[2] = {0.2, 0.8};
    int observed[] = {0, 0, 1, 0, 0};
    
    HMM hmm(2, 2, A, B, PI);
    delete[] viterbi(hmm, observed, 5);
    
    cout << endl;
    
    HMMLog hmmlog(2, 2, A, B, PI);
    delete[] viterbi(hmmlog, observed, 5);
    
    return 0;
    
}
*/
