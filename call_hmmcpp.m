function call_hmmcpp(in)
%#codegen
    if coder.target('MATLAB')
        disp('whoops! accidentally called it instead of codegening it')
    else
        

        %coder.cinclude('printFuns.hpp')
        coder.cinclude('printFuns.cpp')

        str = 'blah';
        res_ = coder.opaque('string');
        res_=coder.ceval('blockPrint',in);
        res = cast(res_,'char')
        %res= coder.ceval('((in==0) ? "\u2581":"\u2588")',in);
    end
end