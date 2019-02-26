clc
clear
close all
addpath('~/Documents/GitHub/hmmX/hmm')
%%
trs = [0.2,0.2]; %transition rates
frs = [.1,.8]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;

%call_hmmcpp(1)

%code.ceval();

%https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
cfg = coder.config('mex');
%cfg.CustomHeaderCode = '#include <iostream>';
%cfg.CustomHeaderCode = '#include <cassert>';
%cfg.CustomHeaderCode = '#include "printFuns.hpp"';

cfg.TargetLang = 'C++';
codegen call_hmmcpp -config cfg -args {1} -report

%codegen printFuns.cpp call_hmmcpp -config cfg -args {1} -report
disp('done!')


%%
call_hmmcpp_mex(1)
call_hmmcpp_mex(0)
disp('done')