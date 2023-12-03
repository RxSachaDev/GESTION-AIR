#include "passager.h"
#include "Tri.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficherPassager(Vol *vols, int taille)
{

    printf("\n| Nom | Prénom | Date de naissance | Numéro du siège | Prix du billet |\n");
    printf("-------------------------------------------------------------------------");
    int i=0,plus_douze = taille-1, temp, j, taille2 = taille();
    while(i < plus_douze){
            j = 0;
            while ( j < 10){
                if (vols[i].passager[j].nom >= 2011){
                    j++;
                }
                else {
                    temp = vols[i].passager[j].nom;
                    vols[i].passager[j].nom = vols[i].passager[j].nom;
                    tab[plus_douze] = temp;
                    plus_douze -= 1;
                    j++;
                }
                i++;
        }
    }
}
