///   \brief helper functions for printing HMM parameters and sequences
///
/// \file
/// helper functions for printing hmm parameters and sequences
///   \author Adam Willats
///   \date  7/19/17.

//  Created by Adam Willats on 7/19/17.
//  Copyright © 2017 Adam Willats. All rights reserved.

//#include "printFuns.hpp"
#include <hmm.h>


//using namespace std;
/**
 * [blockPrint description]
 * @param  bin       integer indicating block category. Most likely 0 or 1.
 * @param printMode  0 for ints, 1 for block characters, 2 for _&^
 * @return           string printed to represent block
 */
std::string blockPrint(int bin, int printMode)
{
    std::string block;
    switch (printMode)
    {
        case 0:
            block = std::to_string(bin);
            break;
        case 1:
             block=((bin==0) ? "\u2581":"\u2588");
            break;
        case 2:
            block= ((bin==0) ? "_":"^");
            break;
    }
    return block;
};

/**
 * formats and prints a "vec of vecs" matrix to cout
 * @param mat vector of vectors matrix to be printed to cout
 */
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

/**
 * applies blockPrint to each item in a vector for within-console visualization
 * @param v         vector of integers to be printed
 * @param veclen    length of v
 * @param printMode 0 for ints, 1 for block characters, 2 for _&^
 * @see blockPrint(), printVec()
 */
void printVecAsBlock(int* v,int veclen, int printMode)
{
    for (int i=0; i<veclen; i++)
    {
        std::cout<<blockPrint(v[i],printMode);
    }
};

/**
 * simply prints vector to cout as is
 * @param v vector to be printed
 * @see printVecAsBlock()
 */
void printVec(std::vector<double> v)
{
    std::cout<<"[";
    for (int i=0;i<v.size();i++)
    {
        if (i>0)
        {
            std::cout<<',';
        }
        std::cout<<v[i];
    }
    std::cout<<"]\n";

}
