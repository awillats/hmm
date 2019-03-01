clc
clear
close all
addpath('~/Documents/GitHub/hmmX/hmm')
%%
trs = [0.2,0.21]; %transition rates
frs = [.1,.8]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;


TR = [1-trs(1),trs(1) ; trs(2),1-trs(2)];
EM = [1-frs(1),frs(1) ; 1-frs(2), frs(2)];

%doesn't segfault
[spikes__, states__] = hmmgenerate(nt,TR,EM,'Symbols',[0,1]);
states__ = states__-1;

states = double(rand(1,nt)<.2);
spikes = double(rand(1,nt)<.2);%states;%rand(1,nt)<.2;%cast(double(rand(1,nt)<.2),'int32'); %currently placeholder


%segfaults
% %}

%https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
codegen call_viterbicpp -config cfg -args {nt, spikes, states, trs, frs, pis} -report 
disp('done!')

return

%%
[stg]=call_viterbicpp_mex(nt, spikes__,states__, trs,frs,pis) %random inputs

%vecPrint(st);
%call_hmmv_mex(0);
%disp('matlab states')

figure(1)
clf
hold on
plot(spikes__+1,'k')
plot(states__,'g','LineWidth',3)
plot(stg,'k','LineWidth',2)
hold off
set(gcf,'Position',[          53         709        1388          89]);

return
%%
%[stg]=call_viterbicpp_mex(nt, spikes,max(states__,states, trs,frs,pis)

%%
[stg]=call_viterbicpp_mex(nt, spikes,states__, trs,frs,pis) %success

%%
%%


[stg]=call_viterbicpp_mex(nt, spikes__,states, trs,frs,pis)



%% segfaults
[stg]=call_viterbicpp_mex(nt, spikes__,states__, trs,frs,pis)
