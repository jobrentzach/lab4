function menu_principal()
%MENU_PRINCIPAL Menu principal pour choisir l'exp�rience
%clc; � ajouter pour effacer tout ce qui pr�c�de avant d'afficher le menu
%(Esth�tisme)
fprintf('Choisir la commande\n');
fprintf('\tD: Exp�rience D�BUT\n');
fprintf('\tF: Exp�rience FIN\n');
fprintf('\tA: Exp�rience ALPHANUM�RIQUE ou ANALOGIQUE\n');
fprintf('\tC: Afficher les statistiques\n');
fprintf('S�lection: ');

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

