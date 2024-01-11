#include "retard.h"
#include "flyingplane.h"

/*
 Fonction en plus pour afficher les retards en cours avant le tri
*/
void afficherRetardActuel(Vol *vols, int taille, int heureActuelle){
    if ( heureActuelle >= 600 && heureActuelle <=2200 ){
        /* on affiche seulement le numero du vol, l'heure a laquelle il est sencé décollé, la compagnie, son etat de vol*/
        printf("--------------------------------------------------------------------------------------\n");
        printf("| Numero de vol  | Heure decollage attendue   |    Compagnie      |     Etat vol     |\n");
        printf("--------------------------------------------------------------------------------------\n");
        for(int i = 0; i < taille ; i++){
        if (vols[i].heure_decollage >= heureActuelle && strcmp(vols[i].etat_vol, "A l'heure") == 1) { /* strcmp renvoie 0 si les chaines sont identiques, et 1 si elles sont differentes*/
                printf("| %7d        |       %-10d           | %-16s  | %-16s |\n",
                       vols[i].numeroVol,
                       vols[i].heure_decollage,
                       vols[i].compagnie,
                       vols[i].etat_vol
                );
                printf("--------------------------------------------------------------------------------------\n");
            }
        }
    }else {
        printf("soit il n'y a pas de retards, soit vous n'avez pas respectE l'heure du couvre feu!\n");
    }
}

/*
 Fonction qui recupere toutes les donnees de l'état de vol de chaque vol (structure Vol)
*/
int recupDonneesRetard(const char *etat_vol){
    // convertisseur des min de retards dans le bon format 60min appliqué a l'heure de décollage
    int minRetard;
    sscanf(etat_vol, "Retarde (%d min)", &minRetard);
    return minRetard;
}

/*
 Fonction qui convertit la somme du retard et de l'heure de décollage en heures
*/
int readapteHeures(int heure_decollage, int retard) {
    // Permet de readapter la somme décimale en heure au format HHMM
    int h = heure_decollage / 100;
    int mm = heure_decollage % 100;

    // Ajout du retard aux minutes
    int mm2 = mm + retard;

    // Ajustement des heures si les minutes dépassent 60
    if (mm2 >= 60) {
        h = h + 1;
        mm2 = mm2 - 60;
    }

    int readapt = (h * 100) + mm2;
    //printf("%d %d %d\n", heure_decollage, retard, readapt);
    return readapt;
}

/*
 Fonction qui permet de remettre de l'ordre dans les retards en readaptant les heures de decollage,
 d'embarquement et d'enregistrement en fonction de ce qui a etait annonce comme Retard dans
 etat_vol.

- la cmd strstr sert a trouver une sous chaine dans une chaine
- strcpy permet de copier une chaine dans une variable
*/
void reprogrammationRetard(Vol *vols, int taille, int heureActuelle){
    int count = 0;
    for(int i =0; i < taille ; i++){
        // On regarde si le vol n'a pas etait deja reprogrammer
        if (strstr(vols[i].etat_vol, "Retarde") && !strstr(vols[i].etat_vol, "Reprogramme")) {
            int minRetard = recupDonneesRetard(vols[i].etat_vol); // on recupere les min du %s et on le met en %d
            if(vols[i].heure_decollage <= 2159){
                vols[i].heure_decollage = readapteHeures(vols[i].heure_decollage, minRetard); // on ajoute son retard à son heure de décollage
                vols[i].heure_debut_Enregistrement = readapteHeures(vols[i].heure_debut_Enregistrement, minRetard); // on readapte les heures d aussi
                vols[i].heure_fin_Enregistrement = readapteHeures(vols[i].heure_fin_Enregistrement, minRetard);
                vols[i].heure_debut_Embarquement = readapteHeures(vols[i].heure_debut_Embarquement, minRetard); // on readapte les heures embarquements aussi
                vols[i].heure_fin_Embarquement = readapteHeures(vols[i].heure_fin_Embarquement, minRetard);
                strcpy(vols[i].etat_vol, "Reprogramme"); // on met son etat de vol a reprogramme
                count++;
            } else {
                // conditions qui annule les vols si ils sont au dessus de 2200 (qu'est ce qu'on fait de ces vols?)
                strcpy(vols[i].etat_vol, "Annule");
            }
        }
    }

    // verifie si l'user a deja reprogrammer les vols ou non pour eviter que cela se reaffiche a chaque fois
    if(count > 0){
            afficherReprogrammation(vols, taille, heureActuelle);
    }else{
        printf("Les reprogrammations ont deja etait faite.\n\n");
    }

    // fonction qui trie le tableau
    trierTab(vols, taille);

    // for qui permet d'espacer les vols qui n'ont pas 5mins d'intervalle (la piste n'est pas forcement optimisé)
    verifier5minIntervallesEtRespectHeure(&taille, vols);
}

    // for qui permet d'espacer les vols qui n'ont pas 5mins d'intervalle (la piste n'est pas forcement optimisé)

/*
Fonction qui affiche la reprogrammation des vols retardes

- strcmp permet de comparer deux chaine et renvoie un entier
*/
void afficherReprogrammation(Vol *vols, int taille, int heureActuelle){
    if ( heureActuelle >= 600 && heureActuelle <=2200 ){
        //on affiche seulement le numero du vol, l'heure a laquelle il est sence décolle, la compagnie, son etat de vol
        printf("\n| Numero de vol | Heure decollage reprogramme | Compagnie | Etat vol |\n");
        printf("------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < taille ; i++){
        if (vols[i].heure_decollage >= heureActuelle && strcmp(vols[i].etat_vol, "A l'heure") == 1) {
                printf("|      %-7d  |           %-10d     | %-16s  | %-15s |\n",
                       vols[i].numeroVol,
                       vols[i].heure_decollage,
                       vols[i].compagnie,
                       vols[i].etat_vol
                );
                printf("------------------------------------------------------------------------------------------\n");
            }
        }
    }else {
        printf("soit il n'y a pas de retards, soit vous n'avez pas respecté l'heure du couvre feu!\n");
    }
}

/*
Fonction qui permet de verifier si les heures de decollage respectent bien la regle les 5mins d'intervalle requise
et supprime les vols qui sont hors plage par rapport au couvre feu de 22h - 6h
*/
void verifier5minIntervallesEtRespectHeure(int *taille, Vol *vols) {
    // for qui permet de verifier qu'une heure de decollage n'est pas inf a 6h ou  ou sup a 22h
    for (int j = 0; j < *taille; j++) {
        if ((vols[j].heure_decollage < 600) || (vols[j].heure_decollage > 2200)) {
            for (int k = j; k < *taille - 1; k++) {
                vols[k] = vols[k + 1];
            }
            (*taille)--; // on reduit la taille du tableau avec son pointeur lorsque l'on suppr
            j--;
        }
    }

    // Vérification des intervalles de 5 minutes
    for (int j = 1; j < *taille; j++) {
        if ((vols[j].heure_decollage - vols[j - 1].heure_decollage) <= 5) { // On fait la difference
            vols[j].heure_decollage = vols[j - 1].heure_decollage + 5;
        }
    }
}

/*
Cette fonction permet de prendre les vols qui ont etes reprogramme et de les mettre a des plages horaires de vol annule ou
le creneau existe encore, tout en evitant de reprogramme sur des vols annules trop lointain (moins de 2heures).

- strcmp permet de comparer une chaine et renvoie un entier
- strcopy ici me permet de copier les valeurs du vol reprogramme a celui du vol annule
*/
void OptimiserPiste(Vol *vols, int taille, int heureActuelle){
    char choix[3];
    int compt = 0, count = 0;

    // Verifier si les vols ont étés reprogramme
    for(int k = 0; k < taille ;k++){
        if(strcmp(vols[k].etat_vol, "Reprogramme") == 0)
            compt++;
    }

    /* je compte le nombre d'occurence de "Reprogramme" et si elle est egale a 0 c'est que l'user n'a pas reprogrammer les vols
    retardes*/
    if (compt == 0){
        reprogrammationRetard(vols, taille, heureActuelle);
    }

    // En fonction de l'optimisation, les vols reprogrammes doivent etre optimiser sur des creneaux ou les vols sont annules
    for (int i = 1; i < taille; i++) {
        if(strcmp(vols[i].etat_vol, "Reprogramme") == 0){
            // trouve le vol annule le plus proche apres l'horaire de decollage du vol reprogramme
            for(int k = i; k < taille; k++){
                if(strcmp(vols[k].etat_vol, "Annule") == 0) {
                    count++;
                    // evite les reprogrammations avec des vols annule espace de 2h
                    if((vols[k].heure_decollage - vols[i].heure_decollage) < 200) {
                            int temp = vols[i].heure_decollage;
                            vols[i].heure_decollage = vols[k].heure_decollage;
                            vols[k].heure_decollage = temp;

                            char tempCharEtat[100];
                            strcpy(tempCharEtat, vols[k].etat_vol);
                            strcpy(vols[k].etat_vol, "null"); // je met l'etat du vol du vol retardé reprogramme a null pour supprimer son horaire
                            strcpy(tempCharEtat, "Reprogramme");
                            strcpy(vols[i].etat_vol, tempCharEtat);

                            temp = vols[i].heure_debut_Enregistrement;
                            vols[i].heure_debut_Enregistrement = vols[k].heure_debut_Enregistrement;
                            vols[k].heure_debut_Enregistrement = temp;

                            temp = vols[i].heure_fin_Enregistrement;
                            vols[i].heure_fin_Enregistrement = vols[k].heure_fin_Enregistrement;
                            vols[k].heure_fin_Enregistrement = temp;

                            temp = vols[i].heure_debut_Embarquement;
                            vols[i].heure_debut_Embarquement = vols[k].heure_debut_Embarquement;
                            vols[k].heure_debut_Embarquement = temp;

                            temp = vols[i].heure_fin_Embarquement;
                            vols[i].heure_fin_Embarquement = vols[k].heure_fin_Embarquement;
                            vols[k].heure_fin_Embarquement = temp;


                            trierTab(vols, taille);

                    }
                }
            }
        }
    }

    // supprime les lignes avec un etat de vol egal a "null"
    for(int i = 0; i < taille; i++){
        if(strcmp(vols[i].etat_vol, "null") == 0){
            for(int j = i; j < taille - 1; j++) {
                vols[j] = vols[j + 1];
            }
                taille--; // je reduis la taille du tableau apres avoir suppr
                i--;
        }
        // si il y a des annules qui n'ont pas trouve preneur je les supprime dans un 2eme temps
        if(strcmp(vols[i].etat_vol, "Annule") == 0){
            for(int j= i; j < taille - 1; j++) {
                vols[j] = vols[j + 1];
            }
                taille--; // je reduis la taille du tableau apres avoir suppr
                i--;
        }
    }

     /* je compte aussi si il y a des modifications pour demander a l'user d'afficher tout les vols sans conditions d'heure actuelle
     si il  y a deja eu une optimisation et que le cout est a 0 alors je dis que l'optimisation a deja etait realiser*/
     if(count > 0){
        printf("Voulez vous affichez tous les vols ? (0ui/Non)\n");
        scanf("%s", &choix);
        affichagePlane();

        if (strcmp(choix, "Oui") == 0) {
            if ( heureActuelle >= 600 && heureActuelle <=2200){
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("| Heure decollage | Numero de vol | Compagnie | Destination | Numero comptoir d'enregistrement | Heure debut enregistrement | Heure fin enregistrement| Salle d'embarquement |Heure debut embarquement| Heure fin embarquement | Etat vol |\n");

            for(int i; i < taille; i++){
                if(vols[i].heure_decollage >= heureActuelle){
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
                    printf("| %-4d | %-2d |             %-20s |    %-10s | %-2d | %-4d | %-4d | %d | %-4d | %-4d | %-17s|\n",
                        vols[i].heure_decollage,
                        vols[i].numeroVol,
                        vols[i].compagnie,
                        vols[i].destination,
                        vols[i].num_Comptoir_Enregistrement,
                        vols[i].heure_debut_Enregistrement,
                        vols[i].heure_fin_Enregistrement,
                        vols[i].salle_embarquement,
                        vols[i].heure_debut_Embarquement,
                        vols[i].heure_fin_Embarquement,
                        vols[i].etat_vol);
                }
            }
                printf("------------------------------------------------------------------------------------------------------------------------\n");


            }else{
                printf("Les vols ne sont compris qu'entre 6h (600) et 22h (2200) dut au couvre feu !\n");
            }
        } else if(strcmp(choix, "Non") == 0){
            printf("Au revoir\n");

        }
     }else{
        printf("\n\nVous avez deja reoptimiser la piste.\n\n\n");
     }
}
