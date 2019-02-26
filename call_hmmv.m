function call_hmmv(trs_,frs_,pis_)
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
        trs = coder.opaque('std::vector<double>','{.1,.2}');
        frs = coder.opaque('std::vector<double>','{.01,.7}');
        pis = coder.opaque('std::vector<double>','{.5,.5}');

                
        myHMMv = coder.ceval('HMMv myHMM = HMMv',2,2,trs,frs,pis);
        coder.ceval('myHMM.printMyParams');
        coder.ceval('myHMM.genSeq',1e3);
        coder.ceval('myHMM.printSeqs');


    end
end