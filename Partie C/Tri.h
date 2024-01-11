#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED

// Inclusion des bibliotheques standard C
#include <stdio.h>
#include <stdlib.h>

/*Fonctions*/
int taille_tab(const char *chaine);
int indice_du_mini_a_partir_de(int tab[], int i, int taille);

void tri_selection(int tab[], int taille);
void inserer(int tab[], int i);

void tri_insertion(int tab[], int taille);
void renvoi_tab(int tab[], int taille);

void tri_nom(char tab[], int taille);
void tri_age(int tab[], int taille);

int indice_du_maxi_a_parti_de(double tab[], int i, int taille);
void tri_selection_dec(double tab[], int taille);

#endif // TRI_H_INCLUDED
