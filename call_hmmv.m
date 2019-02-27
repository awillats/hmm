function out= call_hmmv(trs_,frs_,pis_)
%#codegen
    if coder.target('MATLAB')
        disp('whoops! accidentally called it instead of codegening it')
    else
        printMode=2;
        coder.cinclude('printFuns.cpp'); 
        coder.cinclude('shuttleFuns.cpp'); 
        coder.cinclude('hmm_vec.cpp');
        
        %{
        dub_ = coder.opaque('double []');
        dub_ = coder.ceval('returnDub');
        dub = cast(dub_,'like',[1.0,1.0])
        %}
        
        v = [1.2];
        v2=coder.opaque('double');
        v2=coder.ceval('modDub',coder.ref(v));
        out=cast(v,'like',[1.0]);
        
        myHMMv = coder.opaque('HMMv');
        %coder.ceval('blockPrint',1,printMode);
        
        %convert input vecs to c++
        trs = mat2cvec(trs_);
        frs = mat2cvec(frs_);
        pis = mat2cvec(pis_);
        
        myHMMv = coder.ceval('HMMv myHMM = HMMv',2,2, trs, frs, pis);
        coder.ceval('myHMM.printMyParams');
        coder.ceval('myHMM.genSeq',1e3);
        coder.ceval('myHMM.printSeqs',printMode);
    end
end

function cvec = mat2cvec(matv)
    cvec = coder.opaque('std::vector<double>'); %pre-allocates a std::vec
    cvec = coder.ceval('buildVectorFromAry',matv,length(matv)); %populates the std::vec from matlab vecs
end
