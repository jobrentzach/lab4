function fin()
%FIN Exp�rience FIN

fprintf('Exp�rience FIN!\n');

global serialPort;
time_str = fscanf(serialPort);
time = str2double(time_str);

fprintf('Votre temps de r�action : %d ms\n', time);

global FIN
FIN = [FIN,time];

end

