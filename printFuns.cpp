//
//  convenienceFuns.cpp
//  xRue
//
//  Created by Adam Willats on 7/19/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#include "printFuns.hpp"

//using namespace std;


std::string blockPrint(int bin)
{
    std::string block= ((bin==0) ? "\u2581":"\u2588");
    return block;
};

void printMat(std::vector< std::vector<double> > mat)
{
    std::cout<<"\n[";
    for (int i=0;i<mat.size();i++)
    {
        for (int j=0; j<mat[i].size();j++)
        {
            std::cout<<mat[i][j];
            if (j<mat[i].size()-1) {std::cout<<", ";};
        }
        
        if (i<mat.size()-1){
            std::cout<<"\n ";
        }
    }
    std::cout<<"]\n";
};


void printVecAsBlock(int* v,int veclen)
{
    for (int i=0; i<veclen; i++)
    {
        std::cout<<blockPrint(v[i]);
    }
};
