#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
     int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;

Cliente* cargarCliente(Cliente *_cliente, int cant);
Producto* cargarProducto(Producto *_producto, int cant);
void mostrar(Cliente *clientes, int cant);

int main(){
    int cant = 0;
    
    printf("ingrese la cantidad de clientes de 1 a 5: ");
    scanf("%d", &cant);
    getchar();
   // fflush(stdin);
    Cliente * clientt = (Cliente*) malloc(sizeof(Cliente) * cant);
    clientt = cargarCliente(clientt, cant);
    mostrar(clientt, cant);
    getchar();
    free(clientt);
    return 0;
}

Cliente * cargarCliente(Cliente *_cliente, int cant){
    char nombre[80];
    
    for (int i = 0; i < cant; i++)
    {
       _cliente[i].ClienteID = i+1;
       puts("\nIngrese su nombre:\n");
       gets(nombre);
       getchar();
       int tamanio = strlen(nombre);    
       _cliente[i].NombreCliente = (char *) malloc(sizeof(char) * tamanio); 
       strcpy(_cliente[i].NombreCliente, nombre);     
       _cliente[i].CantidadProductosAPedir = 1 +rand() % (6 - 1);
        
       _cliente[i].Productos = (Producto *) malloc(sizeof(Producto) * _cliente[i].CantidadProductosAPedir);
       Producto *nuevoProd = cargarProducto( _cliente[i].Productos, _cliente[i].CantidadProductosAPedir);
      _cliente[i].Productos = nuevoProd;
    
       free(nuevoProd);
       fflush(stdin);
    }
    return _cliente;
}

Producto* cargarProducto(Producto *_producto, int cant){
   
    for (int j = 0; j < cant; j++)
    {
       
        _producto[j].ProductoID = j + 1;
        _producto[j].Cantidad = 1+ rand() % (11 - 1);
        int aleatorio = 1 +rand() % (6 - 1);
        int tamanio = strlen(TiposProductos[aleatorio - 1]);
        _producto[j].TipoProducto = (char *) malloc(sizeof(char) * tamanio);
        strcpy( _producto[j].TipoProducto, TiposProductos[aleatorio - 1]);
        fflush(stdin);
        _producto[j].PrecioUnitario = 10 + rand () % (101 - 10);
        
    }
    return _producto;
}

void mostrar(Cliente *clientes, int cant){
    for (int i = 0; i < cant; i++)
    {
        printf("\n--------------------------\n\n");
        printf("Persona numero:%d", clientes[i].ClienteID);
        printf("\nNombre:");
        puts(clientes[i].NombreCliente);
        printf("\nLa cantidad de productos a pedir es:%d", clientes[i].CantidadProductosAPedir);
       
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\n\nProducto numero:%d", clientes[i].Productos->ProductoID);
            printf("\nCantidad de productos:%d", clientes[i].Productos[j].Cantidad);
            printf("\nTipo de producto:");
            puts(clientes[i].Productos[j].TipoProducto);
            printf("Precio del producto:%.2f", clientes[i].Productos[j].PrecioUnitario);
        }   
    }
}
