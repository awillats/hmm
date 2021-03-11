clc
clear
close all
addpath('~/Documents/GitHub/hmmX/hmm')
%%
trs = [0.2,0.2]; %transition rates
frs = [.1,.8]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;
call_hmmv(nt,trs,frs,pis);
call_hmmv_mex(nt,trs,frs,pis);