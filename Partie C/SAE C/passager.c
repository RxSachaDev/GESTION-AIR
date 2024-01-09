#include "passager.h"
#include "tri.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 4383 jours sparent la date du rendu et cette mme date il y a 12 ans; attention aux annes bissextiles


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

int unique(int tab[], int taille, int k){
    for (int i = 0; i < taille; i++){
        if (tab[i] == k){
            return 1;
        }
    }
    return 0;
}

// Fonction pour changer deux dates dans le tableau
void echangerDates(double *date1, double *date2) {
    double temp = *date1;
    *date1 = *date2;
    *date2 = temp;
}

void echangerIndices(int index1, int index2) {
    int temp = index1;
    index1 = index2;
    index2 = temp;
}

void afficherPassager(Vol *vols, int taille, const char *nomFichier) {
    lireDonneesCSV(nomFichier, vols, &taille);
    int n_vol;
    printf("Choisissez le vol pour lequel vous voulez afficher la liste de passager : ");
    scanf("%d",&n_vol);
    printf("\nVol %d\n", n_vol);
    printf("\n| Nom | Prenom | Date de naissance | Numero du siege | Prix du billet |\n");
    printf("-------------------------------------------------------------------------\n");

    int i, j, k, day, month, year, cpt = 0, temp2;
    double cpt_month, cpt_day, cpt_year, somme_total;
    double temp[1];
    time_t t = time(NULL);

    // Convertir le temps actuel en structure tm
    struct tm *timeinfo = localtime(&t);

    int annee = timeinfo->tm_year + 1900;
    int mois = timeinfo->tm_mon + 1;
    int jour = timeinfo->tm_mday;

    for (i = 1; i != n_vol; i++) {
    }
    i -= 1;
    for (j=0; vols[i].passager[j].prix_billet != 0; j++) {
        cpt += 1;
    }
    double tab[cpt],tab2[cpt];
    int l =0;
    int m =0;
    for (j = 0; j < cpt; j++) {
        sscanf(vols[i].passager[j].date_naiss, "%d/%d/%d", &day, &month, &year);
        cpt_year = 365.25 * (annee - year);
        cpt_month = 0;

        for (k = month; k < mois; k++) {
            cpt_month += nombre_jour_mois(k, year);
        }

        cpt_day = nombre_jour(day, month, year, jour);
        somme_total = cpt_day + cpt_month + cpt_year;
        if (somme_total < 4383){
            tab[l] = vols[i].passager[j].prix_billet;
            l += 1;
        }
        else {
            tab2[m] = vols[i].passager[j].prix_billet;
            m += 1;
        }
    }
    tri_selection_dec(tab,cpt);
    tri_selection_dec(tab2,cpt);
    int cpt2 = 0, cpt3 = 0;
    for (j = 0; tab[j] > 0.1; j++){
        cpt2 += 1;
    }
    for (j = 0; tab2[j] > 0.1; j++){
        cpt3 += 1;
    }

    int indice[cpt2], indice2[cpt3];
    int n=0;

    for(j=0; j<cpt; j++){
        for (k=j; k<cpt; k++){
            if ( vols[i].passager[k].prix_billet == tab[j] && n < cpt2 && unique(indice, n, k) == 0 ){
                indice[n]= k;
                n += 1;
            }
        }
    }
    n = 0;
    for(j=0; j<cpt; j++){
        for (k=0; k<cpt; k++){
            if ( vols[i].passager[k].prix_billet == tab2[j] && n < cpt3 &&  unique(indice2, n, k) == 0){
                indice2[n]= k;;
                n += 1;
            }
        }
    }
    for (j=0;j < cpt2-1; j++) {
        if (vols[i].passager[indice[j]].prix_billet == vols[i].passager[indice[j+1]].prix_billet) {
           if (strcmp(vols[i].passager[indice[j]].nom, vols[i].passager[indice[j+1]].nom) > 0) {
                temp2 = indice[j];
                indice[j] = indice[j+1];
                indice[j+1] = temp2;
            }
        }
    }
    for (j=0;j < cpt3-1; j++) {
        if (vols[i].passager[indice2[j]].prix_billet == vols[i].passager[indice2[j+1]].prix_billet) {
           if (strcmp(vols[i].passager[indice2[j]].nom, vols[i].passager[indice2[j+1]].nom) > 0) {
                temp2 = indice2[j];
                indice2[j] = indice2[j+1];
                indice2[j+1] = temp2;
            }
        }
    }
    for (j=0;j < cpt2-1; j++) {
        if (strcmp(vols[i].passager[indice[j]].nom, vols[i].passager[indice[j+1]].nom)== 0 && vols[i].passager[indice[j]].prix_billet == vols[i].passager[indice[j+1]].prix_billet) {
           if (strcmp(vols[i].passager[indice[j]].prenom, vols[i].passager[indice[j+1]].prenom) > 0) {
                temp2 = indice[j];
                indice[j] = indice[j+1];
                indice[j+1] = temp2;
            }
        }
    }
    for (j=0;j < cpt3-1; j++) {
        if (strcmp(vols[i].passager[indice2[j]].nom, vols[i].passager[indice2[j+1]].nom)== 0 && vols[i].passager[indice2[j]].prix_billet == vols[i].passager[indice2[j+1]].prix_billet) {
           if (strcmp(vols[i].passager[indice2[j]].prenom, vols[i].passager[indice2[j+1]].prenom) > 0) {
                temp2 = indice2[j];
                indice2[j] = indice2[j+1];
                indice2[j+1] = temp2;
            }
        }
    }
    for (j=0; j<cpt2; j++){
        printf("|  %s  |  %s  |  %s  |  %d  |  %.2f  |\n",vols[i].passager[indice[j]].nom,
                vols[i].passager[indice[j]].prenom,
                vols[i].passager[indice[j]].date_naiss,
                vols[i].passager[indice[j]].numero_siege,
                vols[i].passager[indice[j]].prix_billet );

    }
    for (j=0; j<cpt3; j++){
        printf("|  %s  |  %s  |  %s  |  %d  |  %.2f  |\n",vols[i].passager[indice2[j]].nom,
                vols[i].passager[indice2[j]].prenom,
                vols[i].passager[indice2[j]].date_naiss,
                vols[i].passager[indice2[j]].numero_siege,
                vols[i].passager[indice2[j]].prix_billet );

    }
    printf("\n\n\n");
    printf("-------------------------------------------------------------------------\n");
    char nom[20], prenom[20];
    int resultat[cpt];
    int trouver = 0, trouver2 = 0;

    printf("Saisir le Nom souhaite : ");
    scanf("%s", &nom);
    printf("\n");
    k=0;
    for (j=0;j < cpt; j++ ){
        if (strcmp(vols[i].passager[j].nom, nom) == 0){
            printf("|  %s  |  %s  |  %s  |  %d  |  %.2f  |\n",vols[i].passager[j].nom,
                vols[i].passager[j].prenom,
                vols[i].passager[j].date_naiss,
                vols[i].passager[j].numero_siege,
                vols[i].passager[j].prix_billet );
            trouver += 1;
            resultat[k] = j;
            k += 1;
        }
    }
    printf("\n");
    if (trouver == 0){
        printf("Le nom '%s' est introuvable pour ce vol.", nom);
    }
    else if (trouver > 1){
        printf("Entrer un Prenom : ");
        scanf("%s",&prenom);
        printf("\n");
        for (j=0;j < k; j++ ){
            if (strcmp(vols[i].passager[resultat[j]].prenom, prenom) == 0){
                printf("|  %s  |  %s  |  %s  |  %d  |  %.2f  |\n",vols[i].passager[resultat[j]].nom,
                    vols[i].passager[resultat[j]].prenom,
                    vols[i].passager[resultat[j]].date_naiss,
                    vols[i].passager[resultat[j]].numero_siege,
                    vols[i].passager[resultat[j]].prix_billet );
                trouver2 += 1;
            }
        }
        printf("\n");
        if (trouver2 == 0){
            printf("Le prenom '%s' est introuvable pour ce vol.", prenom);
        }
    }
}


