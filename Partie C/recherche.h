#ifndef RECHERCHE_H
#define RECHERCHE_H

// Inclusion des bibliotheques standard C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

// Inclusion du fichier d'en-tete personnalise "vol.h"
#include "vol.h"

// Fonctions
void toLowerString(char *str);
int compareStringsIgnoreCase(const char *str1, const char *str2);
void recherche_dest(const char *desti, int taille, Vol *vols);
void recherche_compagnie(const char *comp, int taille, Vol *vols);
void recherche_heurDecol(int decol, int taille, Vol *vols);
void deductionRechercheDestination(int typeDeRec, const char *saisie, Vol *vols, int taille);
void deductionRechercheCompagnie(const char *saisie, Vol *vols, int taille);
void deductionRechercheHeuresDecol(int HeuresSaisie, Vol *vols, int taille);

#endif // RECHERCHE_H
