#ifndef VOL_H_INCLUDED
#define VOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Modules*/
#include "passager.h"

#define TAILLE_TAB 100
#define MAX_PASSAGERS 500

struct Vol
{
    int numeroVol;
    char compagnie[100];
    char destination[100];
    int num_Comptoir_Enregistrement; //va de 1 à 10
    int heure_debut_Enregistrement;
    int heure_fin_Enregistrement;
    int salle_embarquement;
    int heure_debut_Embarquement;
    int heure_fin_Embarquement; // [4] pour le format HHMM
    int heure_decollage;
    char etat_vol[20];
    Passager passager[20];
};

typedef struct Vol Vol;

// Fonctions
void lireDonneesCSV(const char *nomFichier, Vol *vols, int *taille);
void trierTab(Vol *vols, int taille);
void afficherTabVol(Vol *vols, int taille, int heureActuelle);
void generation_tab(int* heureActuelle, const char *fichierCSV);

#endif // VOL_H_INCLUDED
