#include "passager.h"
#include "tri.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 4383 jours séparent la date du rendu et cette même date il y a 12 ans; attention aux années bissextiles

int annee_bissextile(int annee)
{
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

int nombre_jour(int mois, int annee)
{
    if (mois == 2 && annee_bissextile(annee)) {
        return 29;
    } else if (mois == 2) {
        return 28;
    } else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
        return 30;
    } else {
        return 31;
    }
}

void afficherPassager(Vol *vols, int taille, const char *nomFichier) {
    lireDonneesCSV(nomFichier, vols, &taille);
    printf("%s", nomFichier);
    printf("\n| Nom | Prenom | Date de naissance | Numero du siege | Prix du billet |\n");
    printf("-------------------------------------------------------------------------\n");
    int i, taille2, j, k, day, month, year, cpt_month, cpt_day;
    double cpt_year, cpt_total;
    char temp[10];
    time_t t = time(NULL);

    // Convertir le temps actuel en structure tm
    struct tm *timeinfo = localtime(&t);

    int annee = timeinfo->tm_year + 1900;
    int mois = timeinfo->tm_mon + 1;
    int jour = timeinfo->tm_mday;


    for (i = 1; i<taille; i++){
            printf("\n");
        taille2 = taille_tab(vols[i].passager[j].date_naiss);
        cpt_day = 0;
        cpt_month = 0;
        cpt_year = 0;
        cpt_total = 0;
        for (j=1; j<3; j++){
            sscanf(vols[i].passager[j].date_naiss,"%d/%d/%d", &day, &month, &year);
            int diff;
            diff = annee-year;
            cpt_year = diff * 365;
            for (k=1; k<=month; k++){
                cpt_month += nombre_jour(k, year);
            }
            for (int l = 0; l <= day; l++){
                cpt_day += 1;
            }
            cpt_total = cpt_day + cpt_month + cpt_year;
            if (cpt_total >= 4383){
                strcpy(temp, vols[i].passager[j].date_naiss);
                strcpy(vols[i].passager[j].date_naiss, vols[i].passager[taille2-1].date_naiss);
                strcpy(vols[i].passager[taille2-1].date_naiss, temp);
            }
            printf("%s = %.2f ", vols[i].passager[j].date_naiss, cpt_year);
        }
    }
}
