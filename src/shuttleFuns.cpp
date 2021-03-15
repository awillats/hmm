///   \brief helper functions for converting data types for HMM models
///
/// \file
/// helper functions for converting data types for HMM models
///   \author Adam Willats
///   \date   2/27/19.

//  Created by Adam Willats on 2/27/19.
//  Copyright © 2019 Adam Willats. All rights reserved.
//

//#include "shuttleFuns.hpp"
#include <hmm.h>


/**
 * converts C array (of doubles) to std::vector of doubles
 * @param  ary C array in
 * @param  len length of vector
 * @return     std::vector converted from input
 */
std::vector<double> array2vec(double ary[],int len)
{
    std::vector<double> v(ary,ary+len);
    return v;
};

/**
 * converts C array (of ints) to std::vector of ints
 * @param  ary C array in
 * @param  len ength of vector
 * @return    std::vector converted from input
 */
std::vector<int> array2vec(int ary[],int len)
{
    std::vector<int> v(ary,ary+len);
    return v;
};

//extract to a different header
/*
template <typename T>
std::vector<T> array2vec(T ary[], int len)
{
    std::vector<T> v(ary,ary+len);

    std::vector<int> v(len,0);
    for (int i=0; i<len;i++)
    {
        v[i] =ary[i];
    }
    return v;
};
*/

/**
 * converts std::vector of doubles to array using std::copy
 * @param vIn std::vector in
 * @param ary pointer to location where array should be copied
 */
void vec2array(std::vector<double> vIn,double *ary)
{
    //return &vIn[0];
    std::copy(vIn.begin(),vIn.end(),ary);
    //https://stackoverflow.com/questions/2923272/how-to-convert-vector-to-array
    //*ary = vIn.data();
};

/**
 * modifies the value at a pointer location, for debuggin
 * @param pDub pointer to double
 * @warning for debug only
 */
void modDub(double * pDub)
{
    *pDub= *pDub + 1;
    //return modVal;
}

/**
 * modifies the values across vector at a pointer location, for debuggin
 * @param pDub pointer to start of vector of doubles
 * @param lenDub length of vector of doubles
 * @warning for debug only
 */
void modDubVec(double * pDub,int lenDub)
{
    for (int i = 0; i<lenDub; i++)
    {
        *(pDub+i)= *(pDub+i) + 1;
    }
    //return modVal;
}
