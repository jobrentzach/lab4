function statistiques()
%STATISTIQUES Affichage des statistiques

global DEBUT;
global FIN;
global ANALOG;
global ALPHANUM;

% Les fonctions mean() et std() renvoient un NaN si l'argument est un
% vecteur vide.
moyennes = [
    mean(DEBUT);
    mean(FIN);
    mean(ANALOG);
    mean(ALPHANUM)];
ecarts_types = [
    std(DEBUT);
    std(FIN);
    std(ANALOG);
    std(ALPHANUM)];

experiences = {'DEBUT';'FIN';'ALPHANUMERIQUE';'ANALOG'};
stats = {'MOYENNES', 'ECARTS_TYPES'};
T = table(moyennes, ecarts_types,...
    'RowNames', experiences,...
    'VariableNames', stats);
disp(T);
end

