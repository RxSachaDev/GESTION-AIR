#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int taille_tab(int tab[]);

int indice_du_mini_a_partir_de(int tab[], int i, int taille);

void tri_selection(int tab[], int taille);

void inserer(int tab[], int i);

void tri_insertion(int tab[], int taille);

void renvoi_tab(int tab[], int taille);

void tri_nom(char tab[], int taille);

void tri_age(int tab[], int taille);

void indice_du_maxi_a_parti_de(int tab, int i);

#endif // TRI_H_INCLUDED
