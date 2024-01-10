#ifndef PASSAGER_H_INCLUDED
#define PASSAGER_H_INCLUDED

#include "Tri.h"
#include "vol.h"


// Modifiez le prototype de la fonction
void afficherPassager(Vol *vols, int taille, const char *nomFichier);
int nombre_jour_mois(int mois, int annees);
int annee_bissextile(int annee);
int nombre_jour(int jour, int mois, int annee, int day);
int unique1(int tab[], int taille, int k);
#endif // PASSAGER_H_INCLUDED
