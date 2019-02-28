clc
clear
close all
addpath('~/Documents/GitHub/hmmX/hmm')
%%
trs = [0.2,0.21]; %transition rates
frs = [.1,.6]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;
states = rand(1,nt)<.2;
spikes = states;%rand(1,nt)<.2;%cast(double(rand(1,nt)<.2),'int32'); %currently placeholder

%https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
cfg = coder.config('mex');

cfg.TargetLang = 'C++';
codegen call_viterbicpp -config cfg -args {nt,spikes,states,trs,frs,pis} -report 

disp('done!')


%%
[stg]=call_viterbicpp_mex(nt, spikes,states, trs,frs,pis)

%vecPrint(st);
%call_hmmv_mex(0);
disp('matlab states')

figure(1)
clf
hold on
plot(spikes+1,'k')
plot(states,'g','LineWidth',3)
plot(stg,'k','LineWidth',2)
hold off