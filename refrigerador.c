#include "refrigerador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Producto *agregar_Producto (int TIPO){
    Producto *aux = (Producto*)malloc(sizeof(Producto));
    switch (TIPO){
        case 1:
            strcpy(aux->tipoAlimento,"Bebidas");
            break;
        case 2:
            strcpy(aux->tipoAlimento,"Embutidos");
            break;
        case 3:
            strcpy(aux->tipoAlimento,"Frutas");
            break;
        case 4:
            strcpy(aux->tipoAlimento,"Lacteos");
            break;
        case 5:
            strcpy(aux->tipoAlimento,"Carnes");
            break;
        default:
            strcpy(aux->tipoAlimento,"Verduras");
            break;
    }
    char NOMBREALIMENTO[12];
    int PRECIO, ANIOCOMP, MESCOMP, DIACOMP, ANIOCAD, MESCAD, DIACAD;
    strcpy(aux->nombreAlimento,NOMBREALIMENTO);
    aux->precio = PRECIO;
    aux->anioCompra = ANIOCOMP;
    aux->mesCompra = MESCOMP;
    aux->diaCompra = DIACOMP;
    aux->anioCaducidad = ANIOCAD;
    aux->mesCaducidad = MESCAD;
    aux->diaCaducicad = DIACAD;
    aux->disponibilidad = 1;
}

Nodo *crear_Nodo (Producto *producto){
    Nodo *aux = (Nodo*)malloc(sizeof(Producto));
    aux->datos = producto;
    aux->sig = NULL;
}

ListaSimple *crear_ListaSimple (){
    ListaSimple *aux = (ListaSimple*)malloc(sizeof(ListaSimple));
    aux->cabeza = NULL;
    return (aux);
}


//Funciones para editar las listas
int lista_vacia (ListaSimple lista){
    if (lista.cabeza == NULL){
        return (1);             //Lista vacia
    }
    else{
        return (0);             //Lista NO vacia
    }
}

void insertar_cabeza (ListaSimple *lista, Nodo *aux){
    if (lista_vacia(*lista) == 1){
        lista->cabeza = aux;    
    }
    else{
        aux->sig = lista->cabeza;
        lista->cabeza = aux;
    }
}

void insertar_cola (ListaSimple *lista, Nodo *aux);
void insertar_en_medio (ListaSimple *lista, Nodo *anterior, Nodo *elemento);
void quitar_cabeza (ListaSimple *lista);
void quitar_cola (ListaSimple *lista);
void quitar_en_medio (ListaSimple *lista, Nodo *elemento);
Nodo *buscar_Elemento (ListaSimple *lista, Nodo *elemento);
void vaciar_Lista (ListaSimple *lista);
void imprimir_Lista (ListaSimple *lista);
