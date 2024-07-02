#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRES 5
// Punto 3
void main()
{
    char **lista = malloc(NOMBRES * sizeof(char));
    char dato[100];
    int longitud;

    for (int i = 0; i < NOMBRES; i++)
    {
        printf("\nIngrese el %der nombre: ", i + 1);
        gets(dato);

        longitud = strlen(dato) + 1;
        lista[i] = malloc(longitud * sizeof(char));
        strcpy(lista[i], dato);
    }
    printf("\nLa lista es:\n");
    for (int i = 0; i < NOMBRES; i++)
    {
        puts(lista[i]);
    }

    free(lista);
}