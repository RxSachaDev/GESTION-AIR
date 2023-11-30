#include <stdio.h>
#include <stdlib.h>
#include "Tri.h"

int main()
{
    int tab[8]= {15, 12, 13, 22, 4, 85};
    int taille = taille_tab(tab);
    printf("Tableau original :\n");
    renvoi_tab(tab, taille);
    printf("\n");
    indice_du_mini_a_partir_de(tab,0, taille);
    tri_selection(tab, taille);
    renvoi_tab(tab,taille);
    return 0;
}
