//
//  shuttleFuns.hpp
//  hmm
//
//  Created by Adam Willats on 2/27/19.
//  Copyright © 2019 Adam Willats. All rights reserved.
//

#ifndef shuttleFuns_hpp
#define shuttleFuns_hpp

#include <stdio.h>
#include "printFuns.hpp"


std::vector<double> array2vec(double[],int);
void vec2array(std::vector<double>, double *);

//double * returnDub(void);
void modDub(double*);
void modDubVec(double *,int);



#endif /* shuttleFuns_hpp */
