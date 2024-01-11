#ifndef VOL_H_INCLUDED
#define VOL_H_INCLUDED

// Inclusion des bibliotheques standard C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Preprocesseurs
#define TAILLE_TAB 100
#define MAX_PASSAGERS 500

/* Structure Passager correspond a tout les attributs de la derniere chaine caractere entre
"" d'une ligne du csv correspond a un vol*/
struct Passager
{
    char nom[30];
    char prenom[30];
    char date_naiss[10]; // au format jj/mm/aaaa
    int numero_siege;
    double prix_billet; // prise en compte des centimes
};

// alias de struct pour eviter d'ecrire struct Passager
typedef struct Passager Passager;

//Structure Vol correspond a tout les attributs d'une ligne du csv correspond a un vol
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

// alias de struct pour eviter d'ecrire struct Vol
typedef struct Vol Vol;

// Fonctions
void lireDonneesCSV(const char *nomFichier, Vol *vols, int *taille);
void trierTab(Vol *vols, int taille);
void afficherTabVol(Vol *vols, int taille, int heureActuelle);


#endif // VOL_H_INCLUDED
