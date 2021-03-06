clc
clear
close all
addpath('~/Documents/GitHub/hmmX/hmm')
%%
trs = [0.2,0.2]; %transition rates
frs = [.1,.8]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;

%https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
cfg = coder.config('mex');

cfg.TargetLang = 'C++';
codegen call_blockprint -config cfg -args {1} -report

%codegen printFuns.cpp call_hmmcpp -config cfg -args {1} -report
disp('done!')


%%
call_blockprint_mex(1);
call_blockprint_mex(0);
disp('done')