clc
clear
close all
set(groot,'DefaultAxesFontSize',15);
%% TURN ME INTO A FUNCTION PLEASE

trs = [0.2,0.21]; %transition rates
frs = [.1,.6]; %firing rates
pis = [.5,.5]; %initial state probabilitiesco
nt = 2e2;

%% codegen


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

%% actually compare
nrep = 1e5;

perc_diff = zeros(nrep,1);
crt = zeros(nrep,1);
mrt = zeros(nrep,1);

for r = 1:nrep
    [qd,crt_,mrt_] = compare_viterbi_fun(trs,frs,pis,nt);
    [perc_diff(r)] = mean(abs(qd));
    crt(r) = crt_;
    mrt(r) = mrt_;
end

%%
figure(1)
clf
subplot(2,1,1)
[h] = histogram(perc_diff*100,'Normalization','cdf');


area(h.BinEdges(2:end), h.Values,'FaceColor','m')
ylim([0,1])
xlabel('% disagreement between methods')
ylabel('cumulative probability')
set(gca,'XTick',[0:.5:max(perc_diff*100)])

subplot(2,1,2)
[km,kmx] = ksdensity(log10(mrt),'NumPoints',150);
[kc,kcx] = ksdensity(log10(crt),'NumPoints',150);



hold on
plot(kmx,km,'Color',[1,.5,0],'LineWidth',2)
plot(kcx,kc,'b','LineWidth',2)
hold off
legend('matlab','c++')
xlim([-5,-3])
xlabel('log10(runtime)')




