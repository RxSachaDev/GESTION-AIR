#include <stdio.h>
#include <stdlib.h>

int taille_tab(int tab[])
{
    int i = 0, taille = 0;

    while(tab[i] != 0){
        taille += 1;
        i +=1;
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
        printf("%c ", tab[i]);
        i += 1;
    }
}

/*
void tri_nom(char tab[], int taille)
{
    int i = 1, j;
    char temp;
    while (i < taille){
        j = i;
        while(j>0 && tab[j-1] > tab[j]){
            temp = tab[j-1];
            tab[j-1] = tab[j];
            tab[j] = temp;
            j--;
        }
        i++;
    }
}
*/
