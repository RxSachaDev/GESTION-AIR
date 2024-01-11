// Inclusion des bibliotheques standard C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

/* Inclusion des fichiers d'en-tete personnalise pour toutes les fonctions
de generation du tableau de structures, de recherche, d'affichage des passagers
de la gestion des retards, des animations.
*/
#include "recherche.h"
#include "vol.h"
#include "passager.h"
#include "retard.h"
#include "color.h"
#include "flyingplane.h"


int main()
{
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t); // heure de l'ordinateur

    // Calculez l'heure actuelle en format "HHMM"
    int heureActuelle = 600;//tm_info->tm_hour * 100 + tm_info->tm_min;
    color(13,0);

    /*Tableau de struct Vol*/
    Vol vols[TAILLE_TAB];
    int taille = 0;

    color(1,15);
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                      *                                                                                                 \n");
    printf("                     ***                                                                                                \n");
    printf("                    *****                                                                                               \n");
    printf("                   *******    **              /////  /////   ////// //       // ////// /////  //     //////             \n");
    printf("                  *********  ****            //      //   // //     // //    // //  // //   / //     //                 \n");
    printf("                 *****************           //      //  //  ////   //   //  // //  // /////  //     ////               \n");
    printf("                *******************          //  /// /////   //     //     //// //  // //   / //     //                 \n");
    printf("               *********************         /////   //   // ////// //       // ////// /////  ////// //////             \n");
    printf("              ***********************                                                                                   \n");
    printf("             *************************          ///  //     /////  /////  /////     //////  ////  ///// //////  /////   \n");
    printf("            ***************************        // // //     //   / //    /            //   /      //    //   // //      \n");
    printf("           *****************************      ////// //     /////  ////   ////  ////  //    ////  ////  //   /  ////    \n");
    printf("          *******************************    //   // //     //     //         /       //        / //    /////   //      \n");
    printf("         *********************************  //    // ////// //     ///// /////      ////// /////  ///// //   // /////   \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");

    color(15,0);

    char filename[50];
    printf("\nEntrez le nom du fichier : ");
    scanf("%s", &filename);
    lireDonneesCSV(filename, vols, &taille);
    trierTab(vols, taille);
    int quitter = 0;
    printf("\n\nBienvenue a l'aeroport Grenoble Alpes Isere \n\n\n\n");
    while (quitter == 0) {
        char choix ;
        char choix1;

        color(11,0);
        printf("------------ MENU ------------\n\n");
        color(15,0);
        printf(">>>> 1. Affichage des vols\n");
        printf(">>>> 2. Recherche des vols\n");
        printf(">>>> 3. Afficher liste des passagers\n");
        printf(">>>> 4. Affichage des retards/annulations\n");
        printf(">>>> 5. Quitter\n\n");
        color(11,0);
        printf("------------ MENU ------------\n\n");
        color(15,0);
        printf("Veuillez saisir votre choix\n");

        scanf(" %c", &choix);

        // sous-menu pour la partie vol
        if (choix == '1') {
                char choix1;
                printf(">>>> 1. Afficher les vols\n");
                printf(">>>> 2. Quitter\n");
                printf("Veuillez saisir votre choix\n");
                scanf(" %c",&choix1);
                if(choix1 == '1'){

                    /* si l'utilisateur tape sur 1 dans le terminal cela affichera la liste des vols du tab
                    en fonction de l'heure actuelle*/
                    afficherTabVol(vols, taille, heureActuelle);
                }
                else if(choix == '2'){
                    // la personne quitte le sous-menu
                    quitter = 1;
                }
        }

        // sous-menu pour la partie recherche
        else if (choix == '2') {
                while(choix != '4'){
                    printf(" >>>> 1. Rechercher par destination\n");
                    printf(" >>>> 2. Rechercher par compagnie\n");
                    printf(" >>>> 3. Rechercher par heure de decollage\n");
                    printf(" >>>> 4. Quitter\n");
                    printf("Veuillez saisir votre choix\n");
                    scanf(" %c",&choix);
                    if(choix == '1'){
                        char destination[50];
                        int c;

                        // Enleve les caracteres residuel lors de l'entree d'info de l'user
                        while ((c = getchar()) != '\n' && c != EOF);
                        printf("Entrer votre destination : ");
                        fgets(destination, 50, stdin);

                        // Supprime le caractere de nouvelle ligne s'il est present
                        size_t len = strlen(destination);
                        if (len > 0 && destination[len - 1] == '\n') {
                            destination[len - 1] = '\0';
                        }

                        /* Appel de la fonction qui va permettre de trouver la desti que l'user a rentrer
                        dans le terminal*/
                        recherche_dest(destination, taille,vols);
                    }
                    else if(choix == '2'){
                        char compagnie[50];
                        int c;

                        // Enleve les caracteres residuel lors de l'entree d'info de l'user
                        while ((c = getchar()) != '\n' && c != EOF);
                        printf("Entrer votre compagnie : ");
                        fgets(compagnie, 50, stdin);

                        // Supprime le caractere de nouvelle ligne s'il est present
                        size_t len = strlen(compagnie);
                        if (len > 0 && compagnie[len - 1] == '\n') {
                            compagnie[len - 1] = '\0';
                        }
                        /* Appel de la fonction qui va permettre de trouver la compagnie que l'user a
                        rentrer dans le terminal*/
                        recherche_compagnie(compagnie, taille, vols);
                    }
                    else if(choix == '3'){
                        int heurdecoll;
                        printf("Entrer votre heure de decollage : ");
                        scanf("%d",&heurdecoll);

                        /* Appel de la fonction qui va permettre de trouver l'heure de decollage
                        que l'user a rentrer dans le terminal*/
                        recherche_heurDecol(heurdecoll,taille,vols);
                        }
                }
        }

        else if (choix == '3') {
                /* Appel de la fonction qui va permettre de trouver le contenu de la liste des
                passer rentrer dans le terminal par l'user en fonction du NumeroVol */
                afficherPassager(vols, taille, filename);
        }
        // sous-menu pour la partie des Retards
        else if (choix == '4'){
                while(choix1 != '4'){
                    printf(" >>>> 1. Afficher la liste des retards actuels\n");
                    printf(" >>>> 2. Reprogrammer les retards et remettre a l'heure\n");
                    printf(" >>>> 3. Optimiser la piste\n");
                    printf(" >>>> 4. Quitter\n");
                    printf("Veuillez saisir votre choix\n");
                    scanf(" %c",&choix1);
                    if(choix1 == '1'){

                        /* Appel de la fonction qui affiche les retards actuels mais pas reprogramme*/
                        afficherRetardActuel(vols, taille, heureActuelle);
                    }
                    else if(choix1 == '2'){
                        /* Appel de la fonction qui reprogramme les vols retardes*/
                        reprogrammationRetard(vols, taille, heureActuelle);
                    }
                    else if(choix1 == '3'){
                        /* Appel de la fonction qui optimise les vols reprogramme en fonction de
                        ceux qui sont annules pour prendre leurs creneaux*/
                        OptimiserPiste(vols,taille, 600);
                    }
                }
                choix1 = '0';

         }
         /* Dessin de sortie d'application*/
         else if (choix == '5') {
                const char plane[] =
                "\n"
                "                                      /\\                                                 _\n"
                "                                     /  \\                                               / |\n"
                "                                    /    \\                                             /  |\n"
                "          AU REVOIR !              /      \\          /\\                    __________ /   |__________\n"
                "                                  /        \\        /  \\                   \\--------_|    |_--------/\n"
                "                                 /          \\|\\____/____\\____________/-------------/       |_________________________/|\n"
                "                                /            \\\\-----||-------||-----                     /--||----------||-----------/\n"
                "                               /              \\  /(_)(_)  \\(_)(_) (_____________________/ (_)(_)      (_)(_)\n"
                "                              /                \\/          \\\n"
                "                             /                              \\               /\\\n"
                "                  /\\        /                                \\             /  \\                  /\\\n"
                "                 /  \\      /                                  _---_       /    \\    /\\          /  \\\n"
                "                /    \\    /                                  |     |    _/__    \\  /  \\        /    \\\n"
                "               /      \\  /                                  _|     |_  |    |____\\/    \\      /      \\\n"
                "              /        \\/                                  |         | |         |      \\    /        \\\n"
                "   /\\        /                                             |         |/|         |       \\  /          \\\n"
                "  /  \\      /                                           ___|         |_|         |____    \\/            \\\n"
                " /    \\    /                   _______                 |   |         |           |    |                  \\\n"
                "/      \\  /                   |       |                |   |         |           |    |                   \\\n"
                "        \\/            __--__  |       |                |   |         |           |    |                    \\\n"
                "                  ___|      |_|       |                |   |         |           |    |                     \\\n"
                "     _______     |            |       |            ____|__ |         |           |    |                      \\\n"
                "    |       |    |            |       |__         |       ||         |           |    |\n";
                printf("%s", plane);

                quitter = 1;
        } else {
            printf("Choix invalide, veuillez ressayer.\n");
        }
    }
}
