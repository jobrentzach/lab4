function analog()
%ANALOG Expérience ANALOGIQUE

global serialPort;
trouve = false;

while ~trouve
    out = fscanf(serialPort);
    if out == 'P'
        time_str = fscanf(serialPort);
        time = str2double(time_str);
        trouve = true;
    else
        % TODO: Affichage avec un curseur
        fprintf(out);
    end
end

global ANALOG;
ANALOG = [ANALOG; time];

end

