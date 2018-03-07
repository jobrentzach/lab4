function curseur_analog( cible, curseur )
%CURSEUR_ANALOG Affichage du curseur dans la console
%   Place un O à la cible et un X au curseur. Affiche sur 64 cases

bin = 256/64;
affichage = char(32*ones(1,64));
position_cible = ceil(cible/bin);
position_curseur = ceil(curseur/bin);
affichage(position_cible) = 'O';
affichage(position_curseur) = 'X';
fprintf('|||%s|||\n',affichage);

end

