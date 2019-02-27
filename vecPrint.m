function vecPrint(vec)
    fprintf('\n');
    for i=1:length(vec)
       switch(vec(i))
           case 0
              fprintf('0');
           case 1
              fprintf('1');
       end
    end
end