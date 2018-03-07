function fin()
%FIN Expérience FIN

fprintf('Expérience FIN!\n');
fprintf('Appuyez sur E pour commencer...\n');


global serialPort;

serial_byte = false;
while (serial_byte == false)
    if (serialPort.BytesAvailable)
        time_str = fscanf(serialPort);
        time = str2double(time_str);
        serial_byte = true;
    end
end

fprintf('Votre temps de réaction : %d ms\n', time);

global FIN
FIN = [FIN,time];

end

