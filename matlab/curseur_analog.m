function curseur_analog( cible, curseur )
%CURSEUR_ANALOG Affichage du curseur dans la console
%   Place un O à la cible et un X au curseur. Affiche sur 64 cases

% TODO: Confirmer que l'affichage sur 64 cases est assez précis

bin = 256/64;
affichage = char(32*ones(1,64));

% La fonction ceil() permet d'avoir une position entre 1 et 64
% inclusivement (ex.: ceil(1/4)=1; ceil(255/4) = 64).
position_cible = ceil(cible/bin);
position_curseur = ceil(curseur/bin);
affichage(position_cible) = 'O';
affichage(position_curseur) = 'X';
fprintf('|||%s|||\n',affichage);

end

