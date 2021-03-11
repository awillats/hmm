//
//  shuttleFuns.cpp
//  hmm
//
//  Created by Adam Willats on 2/27/19.
//  Copyright © 2019 Adam Willats. All rights reserved.
//

//#include "shuttleFuns.hpp"
#include <hmm>



std::vector<double> array2vec(double ary[],int len)
{
    std::vector<double> v(ary,ary+len);
    return v;
};
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

void vec2array(std::vector<double> vIn,double *ary)
{
    //return &vIn[0];
    std::copy(vIn.begin(),vIn.end(),ary);
    //https://stackoverflow.com/questions/2923272/how-to-convert-vector-to-array
    //*ary = vIn.data();
};


/*
double * returnDub()
{
    double ary[2] = {4.0,3.2};
    return ary; //this is bad
}
*/
void modDub(double * pDub)
{
    *pDub= *pDub + 1;
    //return modVal;
}

void modDubVec(double * pDub,int lenDub)
{
    for (int i = 0; i<lenDub; i++)
    {
        *(pDub+i)= *(pDub+i) + 1;
    }
    //return modVal;
}
