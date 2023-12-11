#include "passager.h"
#include "tri.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void afficherPassager(Vol *vols, int taille, const char *nomFichier) {
    lireDonneesCSV(nomFichier, vols, &taille);
    printf("%c", nomFichier);
    printf("\n| Nom | Prenom | Date de naissance | Numero du siege | Prix du billet |\n");
    printf("-------------------------------------------------------------------------\n");

    int i = 0, j = 0, plus_douze = taille - 1, temp, taille2, k, l;
    char tab[100];
    printf("ok1");
    while (i < plus_douze) {
            printf("\n");
            printf("ok2");
        j = 0;
        taille2 = taille_tab(vols[i].passager[j].date_naiss);

        while (j < taille2){
            printf("ok3");
            if (atoi(vols[i].passager[j].date_naiss + taille2 - 4 ) >= 2011) {
                tab[j] = *vols[i].passager[j].date_naiss;
            }
            else {
                tab[taille2-1] = *vols[i].passager[j].date_naiss;
                taille2 -= 1;
            }
            j++;
        }
        for (k=0;k<taille2;k++){
            printf("%s ", tab[k]);
            printf("ok6");
        }
        i++;
    }
}
