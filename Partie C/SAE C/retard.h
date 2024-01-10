#ifndef RETARD_H_INCLUDED
#define RETARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_TAB 100

// avoir accès à l'état du vol dans la structure 'Vol'
#include "vol.h"

// Fonctions
void afficherRetardActuel(Vol *vols, int taille, int heureActuelle);
void reprogrammationRetard(Vol *vols, int taille, int heureActuelle);
int recupDonneesRetard(const char *etat_vol);
int readapteHeures(int heure_decollage, int retard);
void afficherReprogrammation(Vol *vols, int taille, int heureActuelle);
void generationTabRetard(int *heureActuelle, int taille, Vol *vols);
void OptimiserPiste(Vol *vols, int taille, int heureActuelle);

#endif // RETARD_H_INCLUDED
