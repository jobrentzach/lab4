function menu_principal()
%MENU_PRINCIPAL Menu principal pour choisir l'exp�rience

fprintf('Choisir la commande\n');
fprintf('\tD: Exp�rience D�BUT\n');
fprintf('\tF: Exp�rience FIN\n');
fprintf('\tA: Exp�rience ALPHANUM�RIQUE ou ANALOGIQUE\n');
fprintf('\tC: Afficher les statistiques');
fprintf('S�lection: ');

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

