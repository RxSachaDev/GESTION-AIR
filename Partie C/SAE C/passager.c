#include "passager.h"
#include "tri.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void afficherPassager(Vol *vols, int taille) {
    printf("\n| Nom | Prenom | Date de naissance | Numero du siege | Prix du billet |\n");
    printf("-------------------------------------------------------------------------\n");

    int i = 0, j, plus_douze = taille, temp, taille2, tab[10], k;

    while (i < plus_douze) {
        printf("\n");
        j = 0;
        taille2 = taille_tab(vols[i].passager[j].date_naiss);

        while (j < taille2) {
            tab[j] = atoi(vols[i].passager[j].date_naiss + taille2 - 4);
            j++;
        }

        for (k = 0; k < taille2 - 1; k++) {
            if (tab[k] >= 2011) {
                // Do something with the elements greater than or equal to 2011
            } else {
                temp = tab[k];
                tab[k] = tab[taille2 - 1];
                tab[taille2 - 1] = temp;
            }
        }

        for (j = 0; j < taille2; j++) {
            printf("%s | %s | %s | %d | %f |\n",
                   vols[i].passager[j].nom,
                   vols[i].passager[j].prenom,
                   vols[i].passager[j].date_naiss,
                   vols[i].passager[j].numero_siege,
                   vols[i].passager[j].prix_billet);
        }

        i++;
    }
}
