#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "recherche.h"
#include "vol.h"
#include "passager.h"
#include "retard.h"
#include "color.h"
#include "flyingplane.h"
#include "Tri.h"


int main()
{
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    // Calculez l'heure actuelle en format "minuteminuteheureheure"
    int heureActuelle = tm_info->tm_hour * 100 + tm_info->tm_min;
    color(13,0);
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

    char filename[50] = "data_vols.csv";
    /*printf("Entrez le nom du fichier : ");
    scanf("%s", &filename);*/
    lireDonneesCSV(filename, vols, &taille);
    trierTab(vols, taille);
    int quitter = 0;
    printf("\n\nBienvenue a l'aeroport Grenoble Alpes Isere \n\n\n\n");
    while (quitter == 0) {
        char choix ;  // Utiliser un entier pour stocker le choix de l'utilisateur
        char choix1 ;

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

        // Traiter le choix de l'utilisateur avec des instructions if-else if-else
        if (choix == '1') {
                char choix1;
                printf(">>>> 1. Afficher les vols\n");
                printf(">>>> 2. Quitter\n");
                printf("Veuillez saisir votre choix\n");
                scanf(" %c",&choix1);
                if(choix1 == '1'){
                    afficherTabVol(vols, taille, heureActuelle);
                }
                else if(choix == '2'){
                    quitter = 1;
                }
        }
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
                        //suppression du tampon d'entre de la saisie
                        while ((c = getchar()) != '\n' && c != EOF);
                        printf("Entrer votre destination : ");
                        fgets(destination, 50, stdin);

                        // Supprimer le caractre de nouvelle ligne s'il est prsent
                        size_t len = strlen(destination);
                        if (len > 0 && destination[len - 1] == '\n') {
                            destination[len - 1] = '\0';
                        }
                        recherche_dest(destination, taille,vols);
                    }
                    else if(choix == '2'){
                        char compagnie[50];
                        int c;
                        //suppression du tampon d'entre de la saisie
                        while ((c = getchar()) != '\n' && c != EOF);
                        printf("Entrer votre compagnie : ");
                        fgets(compagnie, 50, stdin);

                        // Supprimer le caractre de nouvelle ligne s'il est prsent
                        size_t len = strlen(compagnie);
                        if (len > 0 && compagnie[len - 1] == '\n') {
                            compagnie[len - 1] = '\0';
                        }
                        recherche_compagnie(compagnie, taille, vols);
                    }
                    else if(choix == '3'){
                        int heurdecoll;
                        printf("Entrer votre heure de decollage : ");
                        scanf("%d",&heurdecoll);
                        recherche_heurDecol(heurdecoll,taille,vols);
                        }
                    else if(choix == 4){
                        quitter = 1;
                    }
                    }
            }

            else if (choix == '3') {
                    generation_passager(&heureActuelle,filename);
            }
            else if (choix == '4'){
                    while(choix1 != '4'){
                    printf(" >>>> 1. Afficher la liste des retards actuels\n");
                    printf(" >>>> 2. Reprogrammer les retards\n");
                    printf(" >>>> 3. Optimiser la piste\n");
                    printf(" >>>> 4. Quitter\n");
                    printf("Veuillez saisir votre choix\n");
                    scanf(" %c",&choix1);
                    if(choix1 == '1'){
                        afficherRetardActuel(vols, taille, heureActuelle);
                    }
                    else if(choix1 == '2'){
                        reprogrammationRetard(vols, taille, heureActuelle);
                        afficherReprogrammation(vols, taille, heureActuelle);
                    }
                    else if(choix1 == '3'){
                        //affichagePlane();
                        OptimiserPiste(vols,taille, 600);
                    }
                }
            }

         else if (choix == '5') {
                    const char plane[] =
                "\n"
                "                                      /\\                                                 _\n"
                "                                     /  \\                                               / |\n"
                "       AU REVOIR !                  /    \\                                             /  |\n"
                "                                   /      \\          /\\                    __________ /   |__________\n"
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
