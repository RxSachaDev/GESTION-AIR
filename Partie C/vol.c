/*modules*/
#include "vol.h"
#include "passager.h"
#include "retard.h"


// Fonction pour lire les donnees du fichier CSV et remplir le tableau de struct
void lireDonneesCSV(const char *nomFichier, Vol *vols, int *taille) {
    FILE *fichier = fopen(nomFichier, "r+");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
   }else{

    // on recupere ligne par ligne les infos du CSV
    char ligne[1100];
    fgets(ligne, sizeof(ligne), fichier);
    char *passager;

    //Pour extraire ensuite les infos grace � un sscanf
    *taille = 0;
    while(fgets(ligne, sizeof(ligne), fichier)){
        sscanf(ligne, "%d,%99[^,],%99[^,],%d,%d,%d,%d,%d,%d,%d,%19[^,],%*[^\n]",
        &vols[*taille].numeroVol,
        vols[*taille].compagnie, // unique
        vols[*taille].destination, // unique
        &vols[*taille].num_Comptoir_Enregistrement,
        &vols[*taille].heure_debut_Enregistrement,
        &vols[*taille].heure_fin_Enregistrement,
        &vols[*taille].salle_embarquement,
        &vols[*taille].heure_debut_Embarquement,
        &vols[*taille].heure_fin_Embarquement,
        &vols[*taille].heure_decollage,
        vols[*taille].etat_vol);

        // on va faire pareil pour les passagers sert a recuperer les infos entre la 1ere occu " et la 1ere occu " dans chaque ligne (ce qui correspond aux passagers)
        char *passagersStart = strchr(ligne, '\"');
        char *passagersEnd = strchr(passagersStart + 1, '\"');
        *passagersEnd = '\0'; // Pour remplacer le guillement fermant par le caractere nul
        char *passager = strtok(passagersStart + 1, "\";"); // strtok permet d'extraire des chaines de caract�res

        int i = 0;
        while (passager != NULL) {
            //printf("OK3 - Passager: %s\n", passager);

            // Assurez-vous que vous avez suffisamment d'espace pour les passagers
            if (i < MAX_PASSAGERS) {
                // Pour extraire les champs des passagers et les mettre
                int passagerResultats = sscanf(passager, "%99[^,],%99[^,],%10[^,],%d,%lf",
                    vols[*taille].passager[i].nom,
                    vols[*taille].passager[i].prenom,
                    vols[*taille].passager[i].date_naiss,
                    &vols[*taille].passager[i].numero_siege,
                    &vols[*taille].passager[i].prix_billet);
            }
            passager = strtok(NULL, "\";");
            i++;
        }
        (*taille)++;
    }
    fclose(fichier);
   }
}

void trierTab(Vol *vols, int taille){
    // for qui tri les vols (lignes du csv) par heure de décollage
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (vols[j].heure_decollage > vols[j + 1].heure_decollage) {
                Vol temp = vols[j];
                vols[j] = vols[j + 1];
                vols[j + 1] = temp;
            }
        }
    }
}



void afficherTabVol(Vol *vols, int taille, int heureActuelle){
    trierTab(vols, taille); // On trie le nouveau tableau

    // on verifie qu'il est bien des heures de decollages standards entre les intervalles et le respect du couvre feu
    verifier5minIntervallesEtRespectHeure(&taille, vols);
    if ( heureActuelle >= 600 && heureActuelle <=2200 ){
        // on va afficher les vols qui sont dans les 3 heures qui suivent l'heure actuelle
        printf("\n| Heure decollage | Numero de vol | Compagnie | Destination | Numero comptoir d'enregistrement | Heure debut enregistrement | Heure fin enregistrement| Salle d'embarquement |Heure debut embarquement| Heure fin embarquement | Etat vol |\n");
         printf("------------------------------------------------------------------------------------------------------------------------\n");
        int i = 0;
        while(i < taille){
            if(vols[i].heure_decollage >= heureActuelle){
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
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
            }
            i++;
        }
    }else{
        printf("Les vols ne sont compris qu'entre 6h (600) et 22h (2200) dut au couvre feu !\n");
    }

}

// tableau qui va prendre toutes les structures charge
