#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define LISTA 5
typedef struct{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;
typedef struct{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos          // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir"
} Cliente;
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
Cliente cargarClientes(Cliente *c, int cant);
void mostrarClientes(Cliente *c, int cant);
float costoProducto(Producto prod);
// Punto 4
void main()
{
    int cantClientes, respuesta;
    srand(time(NULL));
    // Punto 4i
    do{
        printf("\nIngrese la cantidad de clientes: ");
        scanf("%d", &cantClientes);
    } while (cantClientes < 1 || cantClientes > 5);

    // Punto 4ii
    do{
        puts("\nDesea cargar los datos? (1 para si y 0 para no):");
        scanf("%d", &respuesta);
    } while (respuesta != 0 && respuesta != 1);
    if (respuesta == 1){
        Cliente *clien = malloc(cantClientes * sizeof(Cliente));
        fflush(stdin);

        *clien = cargarClientes(clien, cantClientes);

        mostrarClientes(clien,cantClientes);
        free(clien);
    }
}

Cliente cargarClientes(Cliente *c, int cant){
    char nombre[30];
    int longitud, cantidad, r;
    for (int i = 0; i < cant; i++){

        // ID
        c[i].ClienteID = i+1;

        // NOMBRE
        printf("\nIngrese su Nombre: ");
        fflush(stdin);
        gets(nombre);
        fflush(stdin);
        longitud = strlen(nombre) + 1;
        c[i].NombreCliente = (char *)malloc(longitud * sizeof(char));
        strcpy(c[i].NombreCliente, nombre);


        // Cantidad de Productos a pedir
        cantidad = 1 + rand() % 4;
        c[i].CantidadProductosAPedir = cantidad;

        // Productos
        c[i].Productos = (Producto *) malloc(cantidad * sizeof(Producto));
    
        for (int j = 0; j < cantidad; j++){
            c[i].Productos[j].ProductoID = j;
            c[i].Productos[j].Cantidad = 1 + rand()% 9;
            r = rand()%4;
            longitud = strlen(TiposProductos[r])+1;
            c[i].Productos[j].TipoProducto = (char*) malloc(longitud * sizeof(char));
            strcpy(c[i].Productos[j].TipoProducto,TiposProductos[r]);
            c[i].Productos[j].PrecioUnitario = 10 + rand()%90;
        }
    }
    return *c;
}
void mostrarClientes(Cliente *c, int cant){
    float total;
    int limite;
    for (int i = 0; i < cant; i++){

        printf("\n======================================");
        printf("\n        Datos del cliente [%d]        ",c[i].ClienteID);
        printf("\n======================================");
        printf("\nNombre del cliente ----->");
        puts(c[i].NombreCliente);
        printf("Cantidad de productos a pedir ---> %d",c[i].CantidadProductosAPedir);
        printf("\n=====Lista de productos=====");
        limite = c[i].CantidadProductosAPedir;
        for (int j = 0; j < limite; j++){
            printf("\n      Producto %d",c[i].Productos[j].ProductoID);
            printf("\nCantidad: %d",c[i].Productos[j].Cantidad);
            printf("\nNombre del producto: ");
            puts(c[i].Productos[j].TipoProducto);
            printf("Precio unitario: %.2f",c[i].Productos[j].PrecioUnitario);
            printf("\n");
            total += costoProducto(c[i].Productos[j]);
        }
        printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
        printf("\n      TOTAL A PAGAR $%.2f",total);
        printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
        
        printf("\n\n\n");

    } 
}
float costoProducto(Producto prod){

    float tot;
    tot = prod.Cantidad * prod.PrecioUnitario;
    return (tot);
}