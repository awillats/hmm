function call_hmmv(trs,frs,pis)
%#codegen
    if coder.target('MATLAB')
        disp('whoops! accidentally called it instead of codegening it')
    else
        coder.cinclude('printFuns.cpp'); 
                %coder.cinclude('printFuns.hpp');

        coder.cinclude('hmm_vec.cpp');
                %coder.cinclude('hmm_vec.hpp');

        myHMMv = coder.opaque('HMMv');
        coder.ceval('blockPrint',1);
        
        %convert mat-vec to std::vector<double>
        invec = coder.opaque('std::vector<double>','{.1,.9}');
        myHMMv = coder.ceval('HMMv myHMM = HMMv',2,2,invec,invec,invec);
        coder.ceval('myHMM.printMyParams');
    end
end