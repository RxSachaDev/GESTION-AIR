#include "recherche.h"

void recherche_dest(const char *desti, int taille, Vol *vols) {
    int compt = 0;

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Ville | Compagnie | Heure | Numerovol | Comptoir | debutEnr | FinEnr | salle | debutEmb | finEmb | EtatVol |\n");

    for (int i = 0; i < taille; i++) {
        if (strstr(vols[i].destination, desti) != NULL) {
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("|    %-10s |             %-20s | %-4d | %-2d | %-2d | %-4d | %-4d | %d | %-4d | %-4d | %-17s|\n",
                    vols[i].destination,
                    vols[i].compagnie,
                    vols[i].heure_decollage,
                    vols[i].numeroVol,
                    vols[i].num_Comptoir_Enregistrement,
                    vols[i].heure_debut_Enregistrement,
                    vols[i].heure_fin_Enregistrement,
                    vols[i].salle_embarquement,
                    vols[i].heure_debut_Embarquement,
                    vols[i].heure_fin_Embarquement,
                    vols[i].etat_vol);
            compt++;
        }
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    if (compt == 0) {
        deductionRechercheDestination(1, desti, vols, taille);
    }
}

void recherche_compagnie(const char *comp, int taille, Vol *vols) {
    int compt = 0;

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Compagnie | Ville | Heure | Numerovol | Comptoir | debutEnr | FinEnr | salle | debutEmb | finEmb | EtatVol |\n");

    for (int i = 0; i < taille; i++) {
        if (strstr(vols[i].compagnie, comp) != NULL) {
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("|             %-20s |    %-10s | %-4d | %-2d | %-2d | %-4d | %-4d | %d | %-4d | %-4d | %-17s|\n",
                    vols[i].compagnie,
                    vols[i].destination,
                    vols[i].heure_decollage,
                    vols[i].numeroVol,
                    vols[i].num_Comptoir_Enregistrement,
                    vols[i].heure_debut_Enregistrement,
                    vols[i].heure_fin_Enregistrement,
                    vols[i].salle_embarquement,
                    vols[i].heure_debut_Embarquement,
                    vols[i].heure_fin_Embarquement,
                    vols[i].etat_vol);
            compt++;
        }
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    if (compt == 0) {
        deductionRechercheCompagnie(comp, vols, taille);
    }
}

void recherche_heurDecol(int decol, int taille, Vol *vols) {
    int compt = 0;

    printf("Voici les vols les plus proches que l'heure saisis \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Heure | Compagnie | Ville | Numerovol | Comptoir | debutEnr | FinEnr | salle | debutEmb | finEmb | EtatVol |\n");

    for (int i = 0; i < taille; i++) {
        if ((vols[i].heure_decollage == decol)) {
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("| %-4d |             %-20s |    %-10s | %-2d | %-2d | %-4d | %-4d | %d | %-4d | %-4d | %-17s|\n",
                    vols[i].heure_decollage,
                    vols[i].compagnie,
                    vols[i].destination,
                    vols[i].numeroVol,
                    vols[i].num_Comptoir_Enregistrement,
                    vols[i].heure_debut_Enregistrement,
                    vols[i].heure_fin_Enregistrement,
                    vols[i].salle_embarquement,
                    vols[i].heure_debut_Embarquement,
                    vols[i].heure_fin_Embarquement,
                    vols[i].etat_vol);
            compt++;
        }
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    if (compt == 0) {
        char decolChar[20];
        sprintf(decolChar, "%d", decol);
        deductionRechercheHeuresDecol(decol, vols, taille);
    }

}

void suggestionCorrection(const char *input, const char *suggestion) {
    printf("\nVouliez-vous dire : %s ?\n", suggestion);
}

void toLowerString(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

int compareStringsIgnoreCase(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (tolower((unsigned char)*str1) != tolower((unsigned char)*str2)) {
            return 0;
        }
        str1++;
        str2++;
    }

    // Si l'une des chaînes n'est pas arrivée à sa fin, elles ne sont pas égales
    return (*str1 == '\0' && *str2 == '\0');
}

void deductionRechercheDestination(int typeDeRec, const char *saisie, Vol *vols, int taille) {
    // Convertir la saisie de l'utilisateur en minuscules
    char saisieMinuscule[50];
    strcpy(saisieMinuscule, saisie);
    toLowerString(saisieMinuscule);

    int suggestionTrouvee = 0;

    for (int i = 0; i < taille; i++) {
        // Convertir la chaîne dans la structure Vol en minuscules
        char destinationMinuscule[50];
        strcpy(destinationMinuscule, vols[i].destination);
        toLowerString(destinationMinuscule);

        // Vérifier si la saisie de l'utilisateur est une sous-chaîne de la destination
        const char *deducMot = strstr(destinationMinuscule, saisieMinuscule);

        if (deducMot != NULL && strstr(deducMot, saisieMinuscule) != NULL) {
            // Utiliser le nom de la destination comme suggestion
            suggestionCorrection(saisie, vols[i].destination);
            suggestionTrouvee = 1;
            break;
        }
    }

    if (!suggestionTrouvee) {
        printf("\nAucune suggestion de destination n'a ete trouvee pour : %s\n", saisie);
    }
}

void deductionRechercheCompagnie(const char *saisie, Vol *vols, int taille) {
    // Convertir la saisie de l'utilisateur en minuscules
    char saisieMinuscule[50];
    strcpy(saisieMinuscule, saisie);
    toLowerString(saisieMinuscule);

    int suggestionTrouvee = 0;

    for (int i = 0; i < taille; i++) {
        // Convertir la chaîne dans la structure Vol en minuscules
        char compagnieMinuscule[50];
        strcpy(compagnieMinuscule, vols[i].compagnie);
        toLowerString(compagnieMinuscule);

        // Vérifier si la saisie de l'utilisateur est une sous-chaîne de la compagnie
        if (strstr(compagnieMinuscule, saisieMinuscule) != NULL ||
            strstr(saisieMinuscule, compagnieMinuscule) != NULL) {
            // Utiliser le nom de la compagnie comme suggestion
            suggestionCorrection(saisie, vols[i].compagnie);
            suggestionTrouvee = 1;
            break;
        }
    }

    if (!suggestionTrouvee) {
        printf("\nAucune suggestion de compagnie n'a ete trouvee pour : %s\n", saisie);
    }
}


void deductionRechercheHeuresDecol(int heuresSaisies, Vol *vols, int taille) {
    int compteur = 0;
    int nbHeureSaisie; // Ajout de la déclaration de nbHeureSaisie

    nbHeureSaisie = heuresSaisies; // Utilisation de la variable heuresSaisies plutôt que saisie
    printf("\nL'heure que vous avez saisie ne correspond pas a un vol.\n\n");

    for (int i = 0; i < taille; i++) {
        if (vols[i].heure_decollage == nbHeureSaisie || (vols[i].heure_decollage >= nbHeureSaisie - 5 && vols[i].heure_decollage <= nbHeureSaisie + 5)) {
            printf("Nous avons trouve celui-ci cependant (dans une plage de 5 minutes avant et apres) : \n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("| Heure | Numero Vol | Destination |\n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("| %-4d | %-2d | %-20s |\n",
                   vols[i].heure_decollage,
                   vols[i].numeroVol,
                   vols[i].destination
            );
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");
            compteur++;
        }
    }

    if (compteur == 0)
        printf("Il n'y a pas de vols dans un intervalle de 5 minutes avant et apres.\n");
}
