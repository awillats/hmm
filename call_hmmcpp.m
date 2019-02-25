function call_hmmcpp(in)
%#codegen
    if coder.target('MATLAB')
        disp('whoops! accidentally called it instead of codegening it')
    else
        
      coreCPath ='/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers';
      coreCPath2 ='/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/IOKit/stream';
      coreCPath3 ='/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/IOKit/stream';

      
      %updateBuildInfo idea from: https://www.mathworks.com/help/simulink/slref/coder.cinclude.html

      
      coder.updateBuildInfo('addIncludePaths',...
          coreCPath);
          coder.updateBuildInfo('addIncludePaths',...
          coreCPath2);
      coder.cinclude('assert.h')
      coder.cinclude('IOStream.h')
  
      %  coder.cinclude('<cassert>')
      %coder.cinclude('<iostream>')

        %coder.cinclude('hmm_vec.hpp')
    coder.cinclude('printFuns.hpp')

        %res = coder.opaque('string');
        %res=coder.ceval('blockPrint',in);
    end
end