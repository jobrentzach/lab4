function menu_principal()
%MENU_PRINCIPAL Menu principal pour choisir l'expérience

fprintf('Choisir la commande\n');
fprintf('\tD: Expérience DÉBUT\n');
fprintf('\tF: Expérience FIN\n');
fprintf('\tA: Expérience ALPHANUMÉRIQUE ou ANALOGIQUE\n');
fprintf('\tC: Afficher les statistiques');
fprintf('Sélection: ');

global serialPort;
choix = fscanf(serialPort);
fprintf('%c\n',choix)

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

