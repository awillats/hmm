% SHOULD CALL GEN_HMMV_SCRIPT first if call_hmmv_mex doesnt work
% clc
clear
close all

%%
trs = [0.2,0.2]; %transition rates
frs = [.1,.8]; %firing rates
pis = [.5,.5]; %initial state probabilities
nt = 3e2;
% call_hmmv(nt,trs,frs,pis);
call_hmmv_mex(nt,trs,frs,pis);