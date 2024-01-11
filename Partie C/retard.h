#ifndef RETARD_H_INCLUDED
#define RETARD_H_INCLUDED

// Inclusion des bibliotheques standard C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prepocesseur
#define TAILLE_TAB 100

// Inclusion du fichier d'en-tete personnalise "vol.h"
#include "vol.h"

// Fonctions
void afficherRetardActuel(Vol *vols, int taille, int heureActuelle);
void reprogrammationRetard(Vol *vols, int taille, int heureActuelle);
int recupDonneesRetard(const char *etat_vol);
int readapteHeures(int heure_decollage, int retard);
void verifier5minIntervallesEtRespectHeure(int *taille, Vol *vols);
void afficherReprogrammation(Vol *vols, int taille, int heureActuelle);
void OptimiserPiste(Vol *vols, int taille, int heureActuelle);
void supprimerLigneParNumVol(int numVol, Vol * vols, int taille);

#endif // RETARD_H_INCLUDED

