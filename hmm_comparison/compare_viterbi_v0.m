clc
clear
close all
%% TURN ME INTO A FUNCTION PLEASE

trs = [0.2,0.21]; %transition rates
frs = [.1,.6]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;

%% generate spikes

%% viterbi both in matlab and cpp, given ground truth params
