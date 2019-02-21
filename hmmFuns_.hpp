//
//  hmmFuns.hpp
//  xRue
//
//  Created by Adam Willats on 7/19/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

//this is the header guard which stops from being multi-included!
#ifndef hmmFuns_hpp
#define hmmFuns_hpp

#include <stdio.h>
#include <vector>
#include <random>
#include <tuple>

struct HMM_Data
{
    std::vector<int> states, spikes;
};

HMM_Data genHMM_Data(std::vector<double> frs, std::vector<double> trs, int numSteps);
std::vector<int> genHMM_Spikes(std::vector<double> frs, std::vector<double> trs, int numSteps);
//std::tuple<std::vector<int>, std::vector<int>> genHMM_Tie(std::vector<double> frs, std::vector<double> trs, int numSteps);
#endif /* hmmFuns_hpp */



