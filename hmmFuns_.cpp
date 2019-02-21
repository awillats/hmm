//
//  hmmFuns.cpp
//  xRue
//
//  Created by Adam Willats on 7/19/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#include "hmmFuns_.hpp" //not needed here?
//#include <iostream>
//#include <vector>
using namespace std;

//consider other ways to solve this problem: https://visualstudiomagazine.com/articles/2016/06/01/how-to-write-a-function.aspx

HMM_Data genHMM_Data(vector<double> frs, vector<double> trs, int numSteps){
    vector<int> states(numSteps);
    vector<int> spikes(numSteps);
    
    states[0] = 0;
    
    //intialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> unif(0, 1);

    for (int i=0; i<numSteps; i++){
        //get emiss
        //get transit
        
        //spit spikes
        spikes[i] = (unif(gen) < frs[states[i]]) ? 1 : 0;
        
        //update future state from current transition probability

	//NB: This if condition shouldn't be necessary...but module crashes in rtxi without it
        if (i<(numSteps-1)) {states[i+1] = (unif(gen) < trs[states[i]]) ? 1-states[i] : states[i];}
    }
    return HMM_Data{states,spikes};
}

vector<int> genHMM_Spikes(vector<double> frs, vector<double> trs, int numSteps){
    HMM_Data HD = genHMM_Data(frs,trs,numSteps);
    return HD.spikes;
}



