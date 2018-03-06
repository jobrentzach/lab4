function menu_A()
%MENU_A Menu pour choisir entre l'expérience ALPHANUMÉRIQUE ou ANALOGIQUE

fprintf('Choisir l''expérience ALPHANUMÉRIQUE ou ANALOGIQUE\n');
fprintf('\t0: Expérience ALPHANUMÉRIQUE\n');
fprintf('\t1: Expérience ANALOGIQUE\n');
fprintf('\tB: Retour au menu principal\n');
fprintf('Sélection: ');

global serialPort;
choix = fscanf(serialPort);
fprintf('%c\n',choix)

switch choix
    case '0'
        alphanum();
    case '1'
        analog();
    case 'B'
        menu();
    otherwise
        fprintf('Erreur, retour au menu principal\n');
end
end

