#include <stdio.h>
#include <time.h>

#define fila 5
#define columna 12
void main()
{
    int matriz[fila][columna];
    int max = 0, min = 50000;
    int mesmas, mesmenos, ventasmas, ventasmenos;
    float suma, total, promedio;
    srand(time(NULL));

    // Punto 2a
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            matriz[i][j] = 10000 + rand() % 50000;
            printf("%d  ", matriz[i][j]); // Punto 2b
        }
        printf("\n");
    }

    // Punto 2c
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            suma += matriz[i][j];
        }
        promedio = suma / 12;
        printf("\n\tEl promedio del anio %d es :%f\n", i + 1, promedio);
        suma = 0;
    }

    // Punto 2d
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (matriz[i][j] > max)
            {
                max = matriz[i][j];
                mesmas = j;
                ventasmas = matriz[i][j];
            }

            if (matriz[i][j] < min)
            {
                min = matriz[i][j];
                mesmenos = j;
                ventasmenos = matriz[i][j];
            }
        }

        printf("\nLa mayor cantidad de ventas en el anio %d fue en el mes %d con un total de %d ventas", i + 1, mesmas, ventasmas);
        printf("\nLa menor cantidad de ventas en el anio %d fue en el mes %d con un total de %d ventas\n", i + 1, mesmenos, ventasmenos);
    }
}