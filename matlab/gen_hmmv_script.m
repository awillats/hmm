clc
clear
close all

%addpath('~/Documents/GitHub/hmmX/hmm')

% addpath('/usr/local/include')
% addpath('/usr/local/include/hmm_h/')
%%
trs = [0.2,0.21]; %transition rates
frs = [.1,.6]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;

%https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
cfg = coder.config('mex');

cfg.TargetLang = 'C++';
codegen call_hmmv -config cfg -args {nt,trs,frs,pis} -report 
%hmm_vec.cpp printFuns.cpp

%codegen printFuns.cpp call_hmmcpp -config cfg -args {1} -report
disp('done!')


%%
[spk,st,stg]= call_hmmv_mex(nt, trs,frs,pis);
vecPrint(st);
%call_hmmv_mex(0);
disp('matlab states')