function fin()
%FIN Expérience FIN

fprintf('Expérience FIN!\n');

global serialPort;
time_str = fscanf(serialPort);
time = str2double(time_str);

fprintf('Votre temps de réaction : %d ms\n', time);

global FIN
FIN = [FIN,time];

end

