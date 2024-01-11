#include "Tri.h"

int taille_tab(const char *chaine) {
    int taille = 0;
    while (chaine[taille] != '\0') {
        taille++;
    }
    return taille;
}

void inserer(int tab[], int i)
{
    char val = tab[i];
    while (i>0 && tab[i] < tab[i-1]){
        tab[i] = tab[i-1];
        tab[i-1] = val;
        i = i-1;
    }
}

void tri_insertion(int tab[], int taille)
{
    int i = 1;

    while (i < taille) {
        inserer(tab,i);
        i = i+1;
    }
}

int indice_du_mini_a_partir_de(int tab[], int i, int taille)
{
    int i_mini = i;

    while (i < taille){
        if (tab[i] < tab[i_mini]){
            i_mini = i;
        }
        i = i+1;
    }
    return i_mini;
}

void tri_selection(int tab[], int taille)
{
    int i = 0, i_mini, temp;

    while (i < taille - 1){
        i_mini = indice_du_mini_a_partir_de(tab, i, taille);
        temp = tab[i];
        tab[i] = tab[i_mini];
        tab[i_mini] = temp;
        i = i+1;
    }
}
void renvoi_tab( int tab[], int taille)
{
    int i =0;
    while ( i < taille){
        printf("%d ", tab[i]);
        i += 1;
    }
}

void tri_age( int tab[], int taille)
{
    int i=0,plus_douze = taille-1, temp;
    while(i < plus_douze){
        if (tab[i] >= 2011){
            i++;
        }
        else {
            temp = tab[i];
            tab[i] = tab[plus_douze];
            tab[plus_douze] = temp;
            plus_douze -= 1;
        }
    }
}

int indice_du_maxi_a_parti_de(double tab[], int i, int taille)
{
    int i_maxi = i;

    while (i < taille){
        if (tab[i] > tab[i_maxi]){
            i_maxi = i;
        }
        i = i+1;
    }
    return i_maxi;

}

void tri_selection_dec(double tab[], int taille)
{
    int i = 0, i_maxi;
    double temp;

    while (i < taille - 1){
        i_maxi = indice_du_maxi_a_parti_de(tab, i, taille);
        temp = tab[i];
        tab[i] = tab[i_maxi];
        tab[i_maxi] = temp;
        i = i+1;
    }
}

