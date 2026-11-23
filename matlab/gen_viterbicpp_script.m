clc
clear
close all


% rngSeed = randi(999);
rngSeed=262;
rng(rngSeed)
do_regen_code = false;

%% TODO
%{
- [ ] 
%}
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

if do_regen_code
    %https://www.mathworks.com/matlabcentral/answers/63047-calling-c-functions-from-matlab
    cfg = coder.config('mex');
    cfg.TargetLang = 'C++';
    codegen call_viterbicpp -config cfg -args {nt, spikes, states, trs, frs, pis} -report 
    disp('done!')
end
%return

%%
[stg]=double(call_viterbicpp_mex(nt, spikes__,states__, trs,frs,pis)); %random inputs
stgmat = hmmviterbi(spikes__+1, TR, EM);
stgmat = stgmat-1;% put in same range as C++ estimates
%vecPrint(st);
%call_hmmv_mex(0);
%disp('matlab states')

orange = [253, 104, 13]/255; % #FD680D
XL = [0,300];
figure(1)
clf
hold on
subplot(2,1,1)
stem(spikes__,'k',LineWidth=2)
% legend('spikes')
xlim(XL)
ylim([0.1,0.9])
set(gca,'YTick',[])
ylabel(["observations","(spikes)"])

subplot(2,1,2)
hold on
plot(states__,'g',LineWidth=3)
plot(stg+0.05,'b',LineWidth=2)
plot(stgmat+0.10,Color=orange,LineWidth=2)
legend('true states','C++ estimate','MATLAB estimate')
xlabel('time steps')
xlim(XL)
yticks([0,1])
ylabel("states")
hold off
set(gcf,'Position',[    837   627   604   178]);

%% Plot confusion between state guess from c++ and matlab as scatter and confusion matrix
% figure(2)
% clf
% plot(double(stg)+randn(1,nt)/10,stgmat+randn(1,nt)/10,'ko','LineWidth',1)
% set(gcf,'Position',[    66   705   113   100])
% xlabel('c++ state')
% ylabel('matlab state')

figure(3)
conf = confusionchart(stg,stgmat,Normalization="row-normalized");
sortClasses(conf,"ascending-diagonal")
w = 0.7
s = 0.9
conf.DiagonalColor = [w,1,w]*s
conf.OffDiagonalColor = [1,w,w]*s
ylabel("C++ state estimate")
xlabel("MATLAB state estimate")
set(gcf,Position=[1442 628 169 177])
%%
[stg]=call_viterbicpp_mex(nt, spikes,states__, trs,frs,pis);
[stg]=call_viterbicpp_mex(nt, spikes,states__, trs,frs,pis); %success
[stg]=call_viterbicpp_mex(nt, spikes__,states, trs,frs,pis);

%% does this segfault?
[stg]=call_viterbicpp_mex(nt, spikes__,states__, trs,frs,pis);
