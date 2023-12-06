#include "passager.h"
#include "tri.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

    void afficherPassager(Vol *vols, int taille)
    {

         printf("\n| Nom | Prenom | Date de naissance | Numero du siege | Prix du billet |\n");
         printf("-------------------------------------------------------------------------\n");
         int i=0, j=0, plus_douze = taille - 1, temp, taille2;
         while(i < plus_douze){
                j = 0;
                taille2 = taille_tab(vols[i].passager[j].date_naiss);
                while ( j < taille2 - 1){
                    if ( atoi(vols[i].passager[j].date_naiss + taille2 - 3)>= 2011){
                        j++;
                    }
                    else {
                        temp = *vols[i].passager[j].date_naiss;
                        *vols[i].passager[j].date_naiss = *vols[i].passager[taille2 - 1].date_naiss;
                        *vols[i].passager[taille2 - 1].date_naiss = temp;
                        plus_douze -= 1;
                        j++;
                    }
                    printf("%s ", vols[i].passager[j].date_naiss);
                    i++;
                }
        }
    }
