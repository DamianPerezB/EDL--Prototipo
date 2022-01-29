#include "refrigerador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//printf("%04d\n", x);

Producto *agregar_Producto (int TIPO){
    Producto *aux = (Producto*)malloc(sizeof(Producto));
    int option = 0, bandera = 1;
    switch (TIPO){
        case 1:
            strcpy(aux->tipoAlimento,"Bebida");
            break;
        case 2:
            strcpy(aux->tipoAlimento,"Embutido");
            break;
        case 3:
            strcpy(aux->tipoAlimento,"Fruta");
            break;
        case 4:
            strcpy(aux->tipoAlimento,"Lacteo");
            break;
        case 5:
            strcpy(aux->tipoAlimento,"Carne");
            break;
        default:
            strcpy(aux->tipoAlimento,"Verdura");
            break;
    }
    printf("\n Ingresa el nombre del producto: ");
    scanf("%s",&aux->nombreAlimento);
    printf("\n Ingresa su precio: $");
    scanf("%f",&aux->precio);
    printf("\n Dia de compra (en numero): ");
    scanf("%d",&aux->diaCompra);
    printf("\n Mes de compra (en numero): ");
    scanf("%d",&aux->mesCompra);
    printf("\n Anio de compra (en numero): ");
    scanf("%d",&aux->anioCompra);
    do{
        printf("\n Tu protucto tiene una fecha de caducidad especifica?");
        printf("\n Ingresa el numero");
        printf("\n 1) Si\t2) No\nOpcion: ");
        scanf("%d",&option);
        switch (option){
        case 1:
            printf("\n Dia de caducidad (en numero): ");
            scanf("%d",&aux->diaCaducicad);
            printf("\n Mes de caducidad (en numero): ");
            scanf("%d",&aux->mesCaducidad);
            printf("\n Anio de caducidad (en numero): ");
            scanf("%d",&aux->anioCaducidad);
            bandera = 0;
            break;
        case 2:
            aux->diaCaducicad = 0;
            aux->mesCaducidad = 0;
            aux->anioCaducidad = 0;
            bandera = 0;
            break;
        default:
            printf("\nIngresa un numero valido\n");
            break;
        }
    }while(bandera != 0);
    printf("\n Tiene disponibilidad?");
    printf("\n Ingresa el numero");
    printf("\n 1) Si\t2) No\nOpcion: ");
    scanf("%d",&option);
    if(option == 1)
        aux->disponibilidad = 1;
    else    
        aux->disponibilidad = 0;
    printf("\nProducto: %s",aux->tipoAlimento);;
    printf("\nNombre: %s",aux->nombreAlimento);
    printf("\nPrecio: $%.2f",aux->precio);
    printf("\nFecha de compra: %02d/%02d/%d",aux->diaCompra,aux->mesCompra,aux->anioCompra);
    printf("\nFecha caducidad: %02d/%02d/%04d",aux->diaCaducicad,aux->mesCaducidad,aux->anioCaducidad);
    printf("\nDisponibilidad: %d", aux->disponibilidad);
    return (aux);
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
