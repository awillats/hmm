function call_viterbicpp(nt, spikes_, trs_,frs_,pis_)
%#codegen
    if coder.target('MATLAB')
        disp('whoops! accidentally called it instead of codegening it')
    else
        printMode=0;
        coder.cinclude('printFuns.cpp'); 
        coder.cinclude('shuttleFuns.cpp'); 
        coder.cinclude('hmm_vec.cpp');
        
        myHMMv = coder.opaque('HMMv');
               
        %convert input vecs to c++
        trs = mat2cvec(trs_);
        frs = mat2cvec(frs_);
        pis = mat2cvec(pis_);
        
        myHMMv = coder.ceval('HMMv myHMM = HMMv',2,2, trs, frs, pis);
        coder.ceval('myHMM.printMyParams');
        coder.ceval('myHMM.genSeq',nt); 
         
        %import to C++
        spikes = cast(double(spikes_),'int32');
        
        %prep to export from C++
         states = cast(zeros(1,nt),'int32');
        statesGuess = cast(zeros(1,nt),'int32');
        
        %void HMMv::importSpksExportGuess(int nt, int * spikeIn, int * stateIn, int * stateGuessOut)
        coder.ceval('myHMM.importSpksExportGuess',nt, coder.ref(spikes), coder.ref(states), coder.ref(statesGuess));
        %coder.ceval('int* vguess = viterbi(myHMM, myHMM.spikes, nt)');
    
        
        
        %{
        %prep for export
        %this casting in redundant with hard limits on input types
        %spikes = cast(zeros(1,nt),'int32');
       
        
        coder.ceval('myHMM.printSeqs',printMode); 

        %note this DOES NOT import spikes/states
        coder.ceval('myHMM.exportSeqsGuess',nt,coder.ref(spikes),coder.ref(states),coder.ref(statesGuess));

        %}
    end
end

function cvec = mat2cvec(matv)
    cvec = coder.opaque('std::vector<double>'); %pre-allocates a std::vec
    cvec = coder.ceval('array2vec',matv,length(matv)); %populates the std::vec from matlab vecs
end
