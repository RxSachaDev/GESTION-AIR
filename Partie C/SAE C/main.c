#include <stdio.h>
#include <stdlib.h>
#include "Tri.h"

int main()
{
    char tab[6] = {'bbc', 'bcb', 'cbb', 'ddd', 'eqod', 'ffrf'};
    int taille = taille_tab(tab);
    printf("%d \n", taille);
    printf("Tableau original :\n");
    renvoi_tab(tab, taille);
    printf("\n");
    tri_nom(tab, taille);
    renvoi_tab(tab,taille);
    return 0;
}
