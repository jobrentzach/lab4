function debut()
%DEBUT Exp�rience D�BUT

fprintf('Exp�rience D�BUT!\n');

global serialPort;
time_str = fscanf(serialPort);
time = str2double(time_str);

fprintf('Votre temps de r�action : %d ms\n', time);

global DEBUT
DEBUT = [DEBUT,time];

end

