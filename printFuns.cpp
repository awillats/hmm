//
//  convenienceFuns.cpp
//  xRue
//
//  Created by Adam Willats on 7/19/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#include "printFuns.hpp"

//using namespace std;


std::string blockPrint(int bin, int printMode)
{
    std::string block;
   // block=((bin==0) ? "\u2581":"\u2588");

    switch (printMode)
    {
        case 1:
             block=((bin==0) ? "\u2581":"\u2588");
        case 2:
            block= ((bin==0) ? "_":"^");
        case 0:
            block = std::to_string(bin);
            //((bin==0) ? "0":"1");
            //generalize http://www.cplusplus.com/reference/cstdlib/itoa/
    }

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


void printVecAsBlock(int* v,int veclen, int printMode)
{
    for (int i=0; i<veclen; i++)
    {
        std::cout<<blockPrint(v[i],printMode);
    }
};

