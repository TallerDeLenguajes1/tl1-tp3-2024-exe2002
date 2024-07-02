#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Punto 3
void main()
{
    char dato[100];
    int longitud,nombres;

    do
    {
        printf("\nIngrese la cantidad de nombres de su lista: ");
        scanf("%d",&nombres);
    } while (nombres < 1 || nombres > 10);
    
    char **lista = malloc(nombres * sizeof(char));

    for (int i = 0; i < nombres; i++)
    {
        fflush(stdin);
        printf("\nIngrese el %der nombre: ", i + 1);
        gets(dato);
        fflush(stdin);


        longitud = strlen(dato) + 1;
        lista[i] = malloc(longitud * sizeof(char));
        strcpy(lista[i], dato);
    }
    printf("\nLa lista es:\n");
    for (int i = 0; i < nombres; i++)
    {
        puts(lista[i]);
    }

    free(lista);
}