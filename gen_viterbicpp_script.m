clc
clear
close all
addpath('~/Documents/GitHub/hmmX/hmm')
%%
trs = [0.2,0.21]; %transition rates
frs = [.1,.6]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;
spikes = rand(1,nt)<.2;%cast(double(rand(1,nt)<.2),'int32'); %currently placeholder

%https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
cfg = coder.config('mex');

cfg.TargetLang = 'C++';
codegen call_viterbicpp -config cfg -args {nt,spikes,trs,frs,pis} -report 

disp('done!')


%%
[a,b,c]=call_viterbicpp_mex(nt, spikes, trs,frs,pis)

%vecPrint(st);
%call_hmmv_mex(0);
disp('matlab states')