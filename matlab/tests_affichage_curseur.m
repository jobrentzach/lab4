bin = 256/64;
for i = 1:50
    out = 256*(sin(pi*i/20)).^2;
    affichage = char(32*ones(1,64));
    position_cible = round(rand()*64) + 1;
    position_curseur = round(out/bin) + 1;
    affichage(position_cible) = 'O';
    affichage(position_curseur) = 'X';
    fprintf('|||%s|||\n',affichage);
end