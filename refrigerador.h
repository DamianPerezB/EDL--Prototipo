//  Perez Benitez Damian    2183034588
//  Carbajal Urquisa Luis Fhernando

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estruturas
typedef struct Producto{
    char tipoAlimento[12];
    char nombreAlimento[25];
    float precio;
    int anioCompra;
    int mesCompra;
    int diaCompra;
    int anioCaducidad;
    int mesCaducidad;
    int diaCaducicad;
    int disponibilidad;
}Producto;

typedef struct Nodo{
    Producto *datos;
    int identificador;
    struct Nodo *sig;
}Nodo;

typedef struct ListaSimple{
    Nodo *cabeza;
}ListaSimple;

//Funciones para generar las listas
Producto *agregar_Producto (int TIPO);
Producto *agregar_Producto_temporal(float elemento);
Nodo *crear_Nodo (Producto *producto, int ID);
ListaSimple *crear_ListaSimple ();

//Funciones para editar las listas
int lista_vacia (ListaSimple lista);
void insertar_cabeza (ListaSimple *lista, Nodo *aux);
void insertar_cola (ListaSimple *lista, Nodo *aux);
void insertar_en_medio (ListaSimple *lista, Nodo *anterior, Nodo *elemento);
void quitar_cabeza (ListaSimple *lista);
void quitar_cola (ListaSimple *lista, Nodo *cola);
void quitar_en_medio (ListaSimple *lista, Nodo *elemento);
Nodo *buscar_Elemento_Recursivo (ListaSimple *lista, int inferior, int superior, Nodo *elemento);
void vaciar_Lista (ListaSimple *lista);
void imprimir_Lista (ListaSimple *lista);

//Funciones de ordenamiento
void QuickSort (ListaSimple *lista, int inicio, int final);
void *ordenamiento_seleccion(ListaSimple *lista, int n);
Nodo* Identificador(ListaSimple *lista, int identificador);
void Intercambiar(Nodo *a, Nodo *b);
int eliminar_producto(ListaSimple *lista, int n);
void acomodar_Id(ListaSimple *lista, int n);

//Funcion para archivo (Opcional)
void llenar_txt(FILE *p, ListaSimple *lista);
