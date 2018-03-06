function [] = uart2()
    
    global DEBUT FIN ANALOG ALPHANUM;
    DEBUT = [];
    FIN = [];
    ANALOG = [];
    ALPHANUM = [];
    
    clear;
    clc;
    warning off

    global serialPort;
    
    fprintf('Appuyez sur ENTRER pour quitter\n');

    c = onCleanup(@()cleanup);
    
    serialPort = serial('COM3');
    set(serialPort,'BaudRate',115200);
    fopen(serialPort);

	while (true)
        menu_principal();
    end

end


function [] = cleanup()

   global serialPort;
   
   fprintf('Cleaning up:...\n');
   
   %Fermeture du port sériel
   fclose(serialPort);
   
end

