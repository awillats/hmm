clc
clear
close all
% addpath('~/Documents/GitHub/hmmX/hmm')
%%
trs = [0.1,0.1]/2; %transition rates
frs = [.1,.5]/2; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e3;%3e2;


TR = [1-trs(1),trs(1) ; trs(2),1-trs(2)];
EM = [1-frs(1),frs(1) ; 1-frs(2), frs(2)];

%doesn't segfault
[spikes__, states__] = hmmgenerate(nt,TR,EM,'Symbols',[0,1]);
states__ = states__-1;

states = double(rand(1,nt)<.2);
spikes = double(rand(1,nt)<.2);

%https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
codegen call_viterbicpp -config cfg -args {nt, spikes, states, trs, frs, pis} -report 
disp('done!')

%return

%%
[stg]=call_viterbicpp_mex(nt, spikes__,states__, trs,frs,pis) %random inputs
stgmat = hmmviterbi(spikes__+1, TR, EM);
%vecPrint(st);
%call_hmmv_mex(0);
%disp('matlab states')


XL = [0,300];
figure(1)
clf
hold on
subplot(2,1,1)
plot(spikes__,'k')
legend('spikes')
xlim(XL)


subplot(2,1,2)
hold on
plot(states__,'g','LineWidth',4)
plot(stg,'k','LineWidth',2)
plot(stgmat-.9,'b','LineWidth',2)
legend('true states','c++ estimate','matlab estimate')
xlabel('time steps')
xlim(XL)
hold off
set(gcf,'Position',[    837   627   604   178]);


figure(2)
clf
plot(double(stg)+randn(1,nt)/10,stgmat+randn(1,nt)/10,'ko','LineWidth',1)
set(gcf,'Position',[    66   705   113   100])
xlabel('c++ state')
ylabel('matlab state')


%return
%%
[stg]=call_viterbicpp_mex(nt, spikes,states__, trs,frs,pis)

%%
[stg]=call_viterbicpp_mex(nt, spikes,states__, trs,frs,pis) %success

%%
%%


[stg]=call_viterbicpp_mex(nt, spikes__,states, trs,frs,pis)



%% segfaults
[stg]=call_viterbicpp_mex(nt, spikes__,states__, trs,frs,pis)
