function menu_A()
%MENU_A Menu pour choisir entre l'exp�rience ALPHANUM�RIQUE ou ANALOGIQUE

fprintf('Choisir l''exp�rience ALPHANUM�RIQUE ou ANALOGIQUE\n');
fprintf('\t0: Exp�rience ALPHANUM�RIQUE\n');
fprintf('\t1: Exp�rience ANALOGIQUE\n');
fprintf('\tB: Retour au menu principal\n');
fprintf('S�lection: ');

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

