//
//  shuttleFuns.cpp
//  hmm
//
//  Created by Adam Willats on 2/27/19.
//  Copyright © 2019 Adam Willats. All rights reserved.
//

#include "shuttleFuns.hpp"

//extract to a different header
std::vector<double> buildVectorFromAry(double ary[], int len)
{
    std::vector<double> v(len,0);
    for (int i=0; i<len;i++)
    {
        v[i] =ary[i];
    }
    return v;
};

double returnDub()
{
    return 42.1;
}
