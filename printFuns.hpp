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
//template<typename T>
//ostream& operator<< (ostream& out, const vector<T>& v);
//std::ostream& operator<< (std::ostream&, const std::vector<T>&);


#endif /* convenienceFuns_hpp */
