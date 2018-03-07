function analog()
%ANALOG Exp�rience ANALOG

global serialPort;
cible = fscanf(serialPort);
trouve = false;

fprintf('Exp�rience ANALOG!\n');
fprintf('Appuyez sur E pour commencer...\n');

while ~trouve
    out = fscanf(serialPort);
    if out == 'P'
        time_str = fscanf(serialPort);
        time = str2double(time_str);
        trouve = true;
    else
        % TODO: Valider l'affichage
        % On ajoute 1 parce que l'index de MATLAB commence � 1, alors qu'en
        % C �a commence � 0.
        curseur_analog(cible+1,out+1);
    end
end

global ANALOG;
ANALOG = [ANALOG; time];

end

