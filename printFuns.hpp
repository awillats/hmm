//
//  convenienceFuns.cpp
//  xRue
//
//  Created by Adam Willats on 7/19/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#ifndef convenienceFuns_hpp
#define convenienceFuns_hpp

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

std::string blockPrint(int);
void printMat(std::vector< std::vector<double> >);
void printVecAsBlock(int*,int);

//Overloaded << operator to print out vectors!
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

#endif /* convenienceFuns_hpp */
