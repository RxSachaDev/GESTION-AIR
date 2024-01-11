#include "flyingplane.h"

/*
Fonction qui permet de se deplacer dans l'espace (x et y) et grace a la biblio windows.h
*/
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*
la fonction qui permet de faire se deplacer la chaine qui correspond a un avion
*/
void affichagePlane() {
    const char ligne1[] = "            |\\\n";
    const char ligne2[] = "            | \\___________\n";
    const char ligne3[] = "            |            |_\\\n";
    const char ligne4[] = "             \\_____---_____/\n";
    const char ligne5[] = "              | |       \\.";
    const char ligne6[] = "               \\ \\    ./";

    int x = 5;
    int y = 5;
    const char obj[] = "-----------------";
    const char road[] = "\n--------------------------------------------------------------------------------------------------------------------------------------\n";

    int screenWidth = 110;
    int roadLength = screenWidth - 1;

    while (1) {
        system("cls");
        gotoxy(x, y);
        printf("%s", ligne1);
        gotoxy(x, y + 1);
        printf("%s", ligne2);
        gotoxy(x, y + 2);
        printf("%s", ligne3);
        gotoxy(x, y + 3);
        printf("%s", ligne4);
        gotoxy(x, y + 4);
        x++;
        if (y == 5){
            printf("%.*s", roadLength, ligne5);
            printf("%s", road);
        }

        if (y == 4){
            printf("%.*s", roadLength, ligne6);
            printf("\n%s", road);
        }
        if (y == 3){
            printf("\n\n%s", road);
        }

        if ( y == 2){
            printf("\n\n\n%s", road);
        }


         if (x == 30 || x == 60 || x == 89){
                y--;
         }

        if (x >= screenWidth) {
            break;
        }

        Sleep(50);
    }

}
