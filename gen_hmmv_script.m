clc
clear
close all
addpath('~/Documents/GitHub/hmmX/hmm')
%%
trs = [0.2,0.2]; %transition rates
frs = [.1,.6]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;

%https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
cfg = coder.config('mex');

cfg.TargetLang = 'C++';
codegen call_hmmv -config cfg -args {trs,frs,pis} -report 
%hmm_vec.cpp printFuns.cpp

%codegen printFuns.cpp call_hmmcpp -config cfg -args {1} -report
disp('done!')


%%
call_hmmv_mex(trs,frs,pis);
%call_hmmv_mex(0);
disp('done')