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
    int n_vol;
    printf("Choisissez le vol pour lequel vous voulez afficher la liste de passager : ");
    scanf("%d",&n_vol);
    printf("\nVol %d\n", n_vol);
    printf("\n| Nom | Prenom | Date de naissance | Numero du siege | Prix du billet |\n");
    printf("-------------------------------------------------------------------------\n");

    int i, taille2, j, k, day, month, year;
    double cpt_month, cpt_day, cpt_year, somme_total;
    double temp[1];
    time_t t = time(NULL);

    // Convertir le temps actuel en structure tm
    struct tm *timeinfo = localtime(&t);

    int annee = timeinfo->tm_year + 1900;
    int mois = timeinfo->tm_mon + 1;
    int jour = timeinfo->tm_mday;

    for (i = 1; i != n_vol; i++) {}
    i -= 1;
    taille2 = taille_tab(vols[i].passager[j].date_naiss);
    double tab[100];
    int indices[100];
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
            if (tab[k] < tab[min_index] ||
                (tab[k] == tab[min_index] &&
                strcmp(vols[i].passager[indices[k]].nom, vols[i].passager[indices[min_index]].nom) < 0)) {
                min_index = k;
            }
        }

        echangerDates(&tab[min_index], &tab[j]);
        echangerIndices(&indices[min_index], &indices[j]);
    }

    int i_tab2 = 0;
    int i_tab3 = 0;
    double tab2[10], tab3[10];

    for (j = 0; j < taille2; j++) {
        if (tab[j] < 4383) {
            tab2[i_tab2] = vols[i].passager[indices[j]].prix_billet;
            i_tab2++;
        }
        else {
            tab3[i_tab3] = vols[i].passager[indices[j]].prix_billet;
            i_tab3++;
        }
    }

    tri_selection_dec(tab2, i_tab2);
    tri_selection_dec(tab3, i_tab3);

    for (j = 0; j < i_tab2 - 1; j++) {
        if (tab2[j] == tab2[j+1]) {
            k = j;
            while (k < i_tab2 - 1 && vols[i].passager[indices[k]].prix_billet == tab2[j]) {
                if (strcmp(vols[i].passager[indices[k]].nom, vols[i].passager[indices[k+1]].nom) > 0) {
                    temp[0] = tab2[j];
                    tab2[j] = tab2[j+1];
                    tab2[j+1] = temp[0];
                    echangerIndices(&indices[k], &indices[k+1]);
                }
                k++;
            }
        }
    }
    j = 0;
    for (j=0;j < i_tab3 - 1; j++) {
        if (tab3[j] == tab3[j+1]) {
            k = j;
            while (k < i_tab3 - 1 && vols[i].passager[indices[k]].prix_billet == tab3[j]) {
                if (strcmp(vols[i].passager[indices[k]].nom, vols[i].passager[indices[k+1]].nom) > 0) {
                    echangerIndices(&indices[k], &indices[k+1]);
                }
                k++;
            }
        }
    }
    for (j=0; j<i_tab2; j++){
        for (k=0; k< taille2; k++){
            if (vols[i].passager[indices[k]].prix_billet == tab2[j] && vols[i].passager[indices[k]].prix_billet != 0 && tab2[j] != tab2[j+2]){
                printf("|  %s  |  %s  |  %s  |  %d  |  %.2f  |\n",vols[i].passager[indices[k]].nom,
                vols[i].passager[indices[k]].prenom,
                vols[i].passager[indices[k]].date_naiss,
                vols[i].passager[indices[k]].numero_siege,
                vols[i].passager[indices[k]].prix_billet );
            }
        }
    }
    for (j=0; j<i_tab3; j++){
        for (k=0; k< taille2; k++){
            if (vols[i].passager[indices[k]].prix_billet == tab3[j] && vols[i].passager[indices[k]].prix_billet != 0 && tab3[j] != tab3[j+1]){
                printf("|  %s  |  %s  |  %s  |  %d  |  %.2f  |\n",vols[i].passager[indices[k]].nom,
                vols[i].passager[indices[k]].prenom,
                vols[i].passager[indices[k]].date_naiss,
                vols[i].passager[indices[k]].numero_siege,
                vols[i].passager[indices[k]].prix_billet );
            }
        }
    }
    const char plane[] =
        "\n"
        "                                      /\\                                                 _\n"
        "                                     /  \\                                               / |\n"
        "                                    /    \\                                             /  |\n"
        "                                   /      \\          /\\                    __________ /   |__________\n"
        "                                  /        \\        /  \\                   \\--------_|    |_--------/\n"
        "                                 /          \\|\\____/____\\____________/-------------/       |_________________________/|\n"
        "                                /            \\\\-----||-------||-----                     /--||----------||-----------/\n"
        "                               /              \\  /(_)(_)  \\(_)(_) (_____________________/ (_)(_)      (_)(_)\n"
        "                              /                \\/          \\\n"
        "                             /                              \\               /\\\n"
        "                  /\\        /                                \\             /  \\                  /\\\n"
        "                 /  \\      /                                  _---_       /    \\    /\\          /  \\\n"
        "                /    \\    /                                  |     |    _/__    \\  /  \\        /    \\\n"
        "               /      \\  /                                  _|     |_  |    |____\\/    \\      /      \\\n"
        "              /        \\/                                  |         | |         |      \\    /        \\\n"
        "   /\\        /                                             |         |/|         |       \\  /          \\\n"
        "  /  \\      /                                           ___|         |_|         |____    \\/            \\\n"
        " /    \\    /                   _______                 |   |         |           |    |                  \\\n"
        "/      \\  /                   |       |                |   |         |           |    |                   \\\n"
        "        \\/            __--__  |       |                |   |         |           |    |                    \\\n"
        "                  ___|      |_|       |                |   |         |           |    |                     \\\n"
        "     _______     |            |       |            ____|__ |         |           |    |                      \\\n"
        "    |       |    |            |       |__         |       ||         |           |    |\n";
    printf("%s", plane);

    i += 1;

}























