#include "recherche.h"

/*
 Fonction qui permet de rechercher les vols ayant une destination que l'user va rentrer dans le termi
*/
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

    // On compte si la destination entree par l'user a ete trouve sinon on essaie de deduire
    if (compt == 0) {
        deductionRechercheDestination(1, desti, vols, taille);
    }
}

/*
Fonction qui permet de rechercher les vols ayant pour compagnie la compagnie que l'user rentre dans le termi
*/
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

    // On compte si la destination entree par l'user a ete trouve sinon on essaie de deduire
    if (compt == 0) {
        deductionRechercheCompagnie(comp, vols, taille);
    }
}

/*
Fonction qui permet de rechercher l'heure que l'user rentre dans le termi
*/
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

    // On compte si l'heure entree par l'user a ete trouve sinon on essaie de deduire une heure dans un intervalle d'1h
    if (compt == 0) {
        char decolChar[20];
        sprintf(decolChar, "%d", decol);
        deductionRechercheHeuresDecol(decol, vols, taille);
    }

}

/*
Fonction qui est appelee uniquement lorsque les fonctions de deduction ont trouves une suggestion
*/
void suggestionCorrection(const char *input, const char *suggestion) {
    printf("\nVouliez-vous dire : %s ?\n", suggestion);
}

void toLowerString(char *chaine) {
    while (*chaine) {
        *chaine = tolower((unsigned char)*chaine);
        chaine++;
    }
}

/*
Fonction qui compare deux chaines de caracteres

- tolower sert a convertir un carac en minuscule
*/
int compareStringsIgnoreCase(const char *chaine1, const char *chaine2) {
    while (*chaine1 && *chaine2) {
        if (tolower((unsigned char)*chaine1) != tolower((unsigned char)*chaine2)) {
            return 0;
        }
        chaine1++;
        chaine2++;
    }

    // Si l'une des chaines n'est pas arrivee a sa fin, elles ne sont pas pareil
    return (*chaine1 == '\0' && *chaine2 == '\0');
}

void deductionRechercheDestination(int typeDeRec, const char *saisie, Vol *vols, int taille) {
    // Converti la saisie de l'utilisateur en minuscules
    char saisieMinuscule[50];
    strcpy(saisieMinuscule, saisie);
    toLowerString(saisieMinuscule);

    int suggestionTrouvee = 0;

    for (int i = 0; i < taille; i++) {
        // Converti la chaîne dans la structure Vol en minuscules
        char destinationMinuscule[50];
        strcpy(destinationMinuscule, vols[i].destination);
        toLowerString(destinationMinuscule);

        // Verifie si la saisie de l'utilisateur est une sous-chaine de la destination
        const char *deducMot = strstr(destinationMinuscule, saisieMinuscule);

        if (deducMot != NULL && strstr(deducMot, saisieMinuscule) != NULL) {
            // Utilise le nom de la destination comme suggestion
            suggestionCorrection(saisie, vols[i].destination);
            suggestionTrouvee = 1;
            break;
        }
    }

    if (!suggestionTrouvee) {
        printf("\nAucune suggestion de destination n'a ete trouvee pour : %s\n", saisie);
    }
}

/*
Fonction qui permet de deduire la recherche de l'user sur les compagnie en fonctions de ce qu'il y a dans le tab vols
Utilisation des cmd strstr, strcpy
- strstr trouve une sous-chaine dans une chaine
- strcpy copie une chaine de caracteres dans une variable ou une autre chaine
*/
void deductionRechercheCompagnie(const char *saisie, Vol *vols, int taille) {
    // Converti la saisie de l'utilisateur en minuscules
    char saisieMinuscule[50];
    strcpy(saisieMinuscule, saisie);
    toLowerString(saisieMinuscule);

    int suggestionTrouvee = 0;

    for (int i = 0; i < taille; i++) {
        // Converti la chaîne dans la structure Vol en minuscules
        char compagnieMinuscule[50];
        strcpy(compagnieMinuscule, vols[i].compagnie);
        toLowerString(compagnieMinuscule);

        // Verifie si la saisie de l'utilisateur est une sous-chaine de la compagnie
        if (strstr(compagnieMinuscule, saisieMinuscule) != NULL ||
            strstr(saisieMinuscule, compagnieMinuscule) != NULL) {
            // Utilise le nom de la compagnie comme suggestion
            suggestionCorrection(saisie, vols[i].compagnie);
            suggestionTrouvee = 1;
            break;
        }
    }

    if (!suggestionTrouvee) {
        printf("\nAucune suggestion de compagnie n'a ete trouvee pour : %s\n", saisie);
    }
}

/*
Fonction de deduction sur l'heure de decollage saisie sur le terminal par rapport ici a un entier donc
c'est plus une ou des proposition(s) pour trouver l'heure ou l'heure la plus proche
*/
void deductionRechercheHeuresDecol(int HeuresSaisie, Vol *vols, int taille) {
    int compt = 0;
    printf("\nL'heure que vous avez saisie ne correspond pas a un vol.\n\n");

    for (int i = 0; i < taille; i++) {
        if (vols[i].heure_decollage == HeuresSaisie || (vols[i].heure_decollage >= HeuresSaisie - 100 && vols[i].heure_decollage <= HeuresSaisie + 100)) {
            printf("Nous avons trouve celui-ci cependant (dans une plage de 1h avant et apres) : \n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("| Heure | Numero Vol | Destination |\n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("| %-4d | %-2d | %-20s |\n",
                   vols[i].heure_decollage,
                   vols[i].numeroVol,
                   vols[i].destination
            );
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");
            compt++;
        }
    }

    if (compt == 0)
        printf("Il n'y a pas de vols dans un intervalle de 5 minutes avant et apres.\n");
}


