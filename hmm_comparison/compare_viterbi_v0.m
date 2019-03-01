clc
clear
close all
%% TURN ME INTO A FUNCTION PLEASE

trs = [0.2,0.21]; %transition rates
frs = [.1,.6]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;

%% generate spikes

TR = [1-trs(1),trs(1) ; trs(2),1-trs(2)];
EM = [1-frs(1),frs(1) ; 1-frs(2), frs(2)];

[spikes, states] = hmmgenerate(nt,TR,EM);


%% viterbi both in matlab and cpp, given ground truth params


%want 1x300
[stg]=call_viterbicpp_mex(nt, spikes,states, trs,frs,pis)

figure(1)
clf
hold on
plot(spikes+1,'k')
plot(states,'g','LineWidth',3)
%plot(stg,'k','LineWidth',2)
hold off