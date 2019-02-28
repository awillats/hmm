function call_blockprint(in)
%#codegen
    if coder.target('MATLAB')
        disp('whoops! accidentally called it instead of codegening it')
    else
        coder.cinclude('printFuns.cpp')
        res_ = coder.opaque('string');%don't think this does anything
        
        res_= coder.ceval('blockPrint',in);
    end
end