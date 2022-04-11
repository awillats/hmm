function [spikes,states,statesGuess]= call_hmmv(nt, trs_,frs_,pis_)
%#codegen
     coder.extrinsic('pwd', 'fullfile');

    if coder.target('MATLAB')
        disp('WARNING! accidentally called function from MATLAB instead of codegening it')
    else
        % NEW EXPERIMENTAL, from https://www.mathworks.com/help/coder/ref/coder.cinclude.html
%         customSrc = coder.const(fullfile(pwd, '../src/'));
%         customInc = coder.const(fullfile(pwd, '../build/include/'));
%         coder.updateBuildInfo('addIncludePaths', customSrc);
%         coder.updateBuildInfo('addIncludePaths', customInc);
%         coder.updateBuildInfo('addSourcePaths', customSrc);
        customDir = coder.const(fullfile(pwd, 'hmm_install'));
        coder.updateBuildInfo('addSourcePaths',  customDir);
        coder.updateBuildInfo('addIncludePaths', customDir);

        printMode=0;
        coder.cinclude('printFuns.cpp'); 
        coder.cinclude('shuttleFuns.cpp'); 
        coder.cinclude('hmm_vec.cpp');
       
        v = [1, 2];
        coder.ceval('modDubVec',coder.ref(v),length(v));
        out=v;
        
        myHMMv = coder.opaque('HMMv');
        %coder.ceval('blockPrint',1,printMode);
        
        %convert input vecs to c++
        trs = mat2cvec(trs_);
        frs = mat2cvec(frs_);
        pis = mat2cvec(pis_);
        
        myHMMv = coder.ceval('HMMv myHMM = HMMv',2,2, trs, frs, pis);
        coder.ceval('myHMM.printMyParams');
        coder.ceval('myHMM.genSeq',nt);
        
        
        
        spikes = cast(zeros(1,nt),'int32');
        states = cast(zeros(1,nt),'int32');
        statesGuess = cast(zeros(1,nt),'int32');
        
        coder.ceval('myHMM.printSeqs',printMode);
        %export vector to workspace
        coder.ceval('myHMM.exportSeqsGuess',nt,coder.ref(spikes),coder.ref(states),coder.ref(statesGuess));
    end
end

function cvec = mat2cvec(matv)
    cvec = coder.opaque('std::vector<double>'); %pre-allocates a std::vec
    cvec = coder.ceval('array2vec',matv,length(matv)); %populates the std::vec from matlab vecs
end
