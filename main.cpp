//
//  main.cpp
//  hmm
//
//  Created by Adam Willats on 2/21/19.
//  Copyright © 2019 Adam Willats. All rights reserved.
//


#include <iostream>
#include <vector>
#include "hmmFuns.hpp"
//#include "legacy/dataFuns.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::vector<double> frs = {.1,.9};
    std::vector<double> trs = {0.01,0.02};
    int nt = 200;
    
    
    std::vector<int> q = genHMM(frs,trs,nt);
    std::cout << q[1] << '\n';
    return 0;
}
