
function [q_diff,cpp_runtime,mat_runtime] = compare_viterbi_fun(trs,frs,pis,nt)
%{
clc
clear
close all

trs = [0.2,0.21]; %transition rates
frs = [.1,.6]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 3e2;
%}
%% generate spikes

TR = [1-trs(1),trs(1) ; trs(2),1-trs(2)];
EM = [1-frs(1),frs(1) ; 1-frs(2), frs(2)];

[spikes, q_true_] = hmmgenerate(nt,TR,EM,'Symbols',[0,1]);
q_true = q_true_-1;

%% viterbi both in matlab and cpp, given ground truth params



tic
%intentionally made spikes "wrong" here
[q_cpp] = call_viterbicpp_mex(nt, spikes,q_true, trs,frs,pis);
cpp_runtime = toc;



tic
TRxx = [1-trs(1),trs(1) ; trs(2),1-trs(2)];%for fairness of timing (?)
EMxx = [1-frs(1),frs(1) ; 1-frs(2), frs(2)];
[q_mat] = hmmviterbi(spikes+1, TR, EM);
mat_runtime = toc;
%{
%}



%{
tic
TRxx = [1-trs(1),trs(1) ; trs(2),1-trs(2)];%for fairness of timing (?)
EMxx = [1-frs(1),frs(1) ; 1-frs(2), frs(2)];
[q_cpp] = hmmviterbi(spikes+1, TR, EM);
cpp_runtime = toc;

%}

q_diff = double(q_cpp)-(q_mat-1);

end

