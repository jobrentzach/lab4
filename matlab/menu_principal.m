function menu_principal()
%MENU_PRINCIPAL Menu principal pour choisir l'expérience
%clc; à ajouter pour effacer tout ce qui précède avant d'afficher le menu
%(Esthétisme)
fprintf('Choisir la commande\n');
fprintf('\tD: Expérience DÉBUT\n');
fprintf('\tF: Expérience FIN\n');
fprintf('\tA: Expérience ALPHANUMÉRIQUE ou ANALOGIQUE\n');
fprintf('\tC: Afficher les statistiques\n');
fprintf('Sélection: ');

global serialPort;

serial_byte = false;
while (serial_byte == false)
    if (serialPort.BytesAvailable)
        choix = fscanf(serialPort);
        fprintf('%c\n',choix)
        serial_byte = true;
    end
end

switch choix
    case 'D'
        debut();
    case 'F'
        fin();
    case 'A'
        menu_A();
    case 'C'
        statistiques();
    otherwise
        fprintf('Erreur, veuillez recommencer\n');
end
end

