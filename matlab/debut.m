function debut()
%DEBUT Expérience DÉBUT

fprintf('Expérience DÉBUT!\n');

global serialPort;
time_str = fscanf(serialPort);
time = str2double(time_str);

fprintf('Votre temps de réaction : %d ms\n', time);

global DEBUT
DEBUT = [DEBUT,time];

end

