#include "passager.h"
#include "tri.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 4383 jours séparent la date du rendu et cette même date il y a 12 ans; attention aux années bissextiles

int annee_bissextile(int annee) {
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int nombre_jour_mois(int mois, int annee) {
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

int nombre_jour(int jour, int mois, int annee, int day) {
    int diff;
    diff = day - jour;
    return diff;
}

// Fonction pour échanger deux dates dans le tableau
void echangerDates(double *date1, double *date2) {
    double temp = *date1;
    *date1 = *date2;
    *date2 = temp;
}

void echangerIndices(int *index1, int *index2) {
    int temp = *index1;
    *index1 = *index2;
    *index2 = temp;
}

void afficherPassager(Vol *vols, int taille, const char *nomFichier) {
    lireDonneesCSV(nomFichier, vols, &taille);
    printf("%s", nomFichier);
    printf("\n| Nom | Prenom | Date de naissance | Numero du siege | Prix du billet |\n");
    printf("-------------------------------------------------------------------------\n");
    int i, taille2, j, k, day, month, year;
    double cpt_month, cpt_day, cpt_year, somme_total;  // Renommée en somme_total
    char temp[10];
    time_t t = time(NULL);

    // Convertir le temps actuel en structure tm
    struct tm *timeinfo = localtime(&t);

    int annee = timeinfo->tm_year + 1900;
    int mois = timeinfo->tm_mon + 1;
    int jour = timeinfo->tm_mday;

    for (i = 0; i < taille; i++) {
        printf("\n");
        taille2 = taille_tab(vols[i].passager[j].date_naiss); // Renommée ici
        double tab[100]; // Tableau pour stocker les dates
        int indices[100]; // Tableau pour stocker les indices des dates

        for (j = 0; j < taille2; j++) {
            sscanf(vols[i].passager[j].date_naiss, "%d/%d/%d", &day, &month, &year);
            cpt_year = 365.25 * (annee - year);
            cpt_month = 0;

            for (k = month; k < mois; k++) {
                cpt_month += nombre_jour_mois(k, year);
            }

            cpt_day = nombre_jour(day, month, year, jour);
            somme_total = cpt_day + cpt_month + cpt_year;
            tab[j] = somme_total;
            indices[j] = j;
        }

        for (j = 0; j < taille2 - 1; j++) {
            int min_index = j;
            for (k = j + 1; k < taille2; k++) {
                if (tab[k] < tab[min_index]) {
                    min_index = k;
                }
            }

            echangerDates(&tab[min_index], &tab[j]);
            echangerIndices(&indices[min_index], &indices[j]);
        }

        for (j = 0; j < taille2; j++) {
            printf("%s/%s/%s/ ", vols[i].passager[indices[j]].nom,
                    vols[i].passager[indices[j]].prenom,
                    vols[i].passager[indices[j]].date_naiss);

        }
    }
}
