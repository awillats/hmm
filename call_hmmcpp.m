function res=call_hmmcpp(in)
%#codegen
    if coder.target('MATLAB')
        disp('whoops! accidentally called it instead of codegening it')
    else
        

        %coder.cinclude('printFuns.hpp')
        coder.cinclude('printFuns.cpp')

        res_ = coder.opaque('int');
        res_= coder.ceval('blockPrint',in);
        res = cast(res_,'int32');
        %res= coder.ceval('((in==0) ? "\u2581":"\u2588")',in);
    end
end