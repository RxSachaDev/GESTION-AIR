#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Modules*/
#include "Tri.h"
#include "vol.h"
#include "passager.h"

int main()
{
    printf("Entrez le nom du fichier : ");
    char filename[50], *a;
    fgets(filename, sizeof(filename), stdin);
    strtok(filename, "\n");

    printf("Entrez l'heure : ");
    int hour;
    scanf("%d", &hour);
    getchar();

    generation_tab(&hour, filename);


    return 0;
}
