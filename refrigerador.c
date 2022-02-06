//  Perez Benitez Damian    
//  Carbajal Urquisa Luis Fhernando

#include "refrigerador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Producto *agregar_Producto (int TIPO, int ID){
    Producto *aux = (Producto*)malloc(sizeof(Producto));
    //int option = 0, bandera = 1;
    aux->identificador = ID;
    /*switch (TIPO){
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
    printf("\n Ingresa el nombre del producto (usa guiones bajos en vez de espacios): ");
    scanf("%s",&aux->nombreAlimento);*/
    printf("\n Ingresa su precio: $");
    scanf("%f",&aux->precio);
    /*printf("\n Dia de compra (en numero): ");
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
        aux->disponibilidad = 0;*/
    return (aux);
}

void copiar_Producto(Nodo *aux, Nodo *aux2){
    //strcpy(aux2->datos->nombreAlimento,aux->datos->nombreAlimento);
    //strcpy(aux2->datos->tipoAlimento,aux->datos->tipoAlimento);
    aux2->datos->precio = aux->datos->precio;
    //aux2->datos->anioCompra = aux->datos->anioCompra;
    //aux2->datos->mesCompra = aux->datos->mesCompra;
    //aux2->datos->diaCompra = aux->datos->diaCompra;
    //aux2->datos->anioCaducidad = aux->datos->anioCaducidad;
    //aux2->datos->mesCaducidad = aux->datos->mesCaducidad;
    //aux2->datos->diaCaducicad = aux->datos->diaCaducicad;
    aux2->datos->disponibilidad = aux->datos->disponibilidad;
}

Producto *agregar_Producto_temporal(float elemento){
    Producto *aux = (Producto*)malloc(sizeof(Producto));
    aux->precio = elemento;
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

void insertar_cola (ListaSimple *lista, Nodo *aux){
    Nodo *cola;
    cola = lista->cabeza;
    if (lista_vacia(*lista) == 1){
        insertar_cabeza(lista,aux);
    }
    else{
        while(cola->sig != NULL){
            cola = cola->sig;
        }
        cola->sig = aux;
        cola = aux;
    }
}

void insertar_en_medio (ListaSimple *lista, Nodo *anterior, Nodo *elemento){
    if (lista_vacia(*lista) == 1){
        lista->cabeza = elemento;
    }
    else{
        elemento->sig = anterior->sig;
        anterior->sig = elemento;
    }
}

void quitar_cabeza (ListaSimple *lista){
    Nodo *aux = NULL;   
    if(!lista_vacia(*lista)){
        aux = lista->cabeza;
        lista->cabeza = lista->cabeza->sig;
        free(aux);
    } 
}

void quitar_cola (ListaSimple *lista, Nodo *cola){
    Nodo *anterior;
    if(lista_vacia(*lista) == 1){
    }
    else{
        free(cola);
    }
}

void quitar_en_medio (ListaSimple *lista, Nodo *borrar){
    Nodo *anterior;
    if (lista_vacia(*lista) == 1){
        if(lista->cabeza == borrar){
            quitar_cabeza(lista);
        }
        else{
            anterior = lista->cabeza;
            while (anterior->sig != borrar){
                anterior = anterior->sig;
            }
            if (anterior->sig == NULL){
                quitar_cola(lista,anterior);
            }
            else{
                anterior->sig = borrar->sig;
                free(borrar);
            }
        }
    }
}
Nodo *buscar_Elemento_Recursivo (ListaSimple *lista, int superior, Nodo *elemento);

ListaSimple *buscar_Elemento_Recursivo_2 (ListaSimple *lista, ListaSimple *listaTemporal, int inferior, int superior, Nodo *elemento){
    int central;
    Nodo *aux = lista->cabeza;
    if (!lista_vacia(*lista)){
        if (inferior > superior){
            printf("\n El elemento no está aquí ");
            return(listaTemporal);
        }
        else{
            central = (inferior + superior)/2;
            aux = lista->cabeza;
            while (aux->datos->identificador != central){
                aux = aux->sig;
            }
            printf("\nCentral = %d  id=%d",central,aux->datos->identificador);
            printf("\nSi %f = %f se agrega a lista",aux->datos->precio,elemento->datos->precio);
            printf("\nSi %f < %f return 1",aux->datos->precio,elemento->datos->precio);
            printf("\nSi %f > %f return 2",aux->datos->precio,elemento->datos->precio);
            if (aux->datos->precio == elemento->datos->precio){
                printf("\nSe va a agregar a la lista un producto con precio %f",aux->datos->precio);
                insertar_cabeza(listaTemporal,aux);
                printf("\nImprimiendo lista");
                imprimir_Lista(listaTemporal);
                return(listaTemporal);
                
            }
            
            else if (aux->datos->precio < elemento->datos->precio){
                printf("\nReturn 1");
                return buscar_Elemento_Recursivo_2 (lista, listaTemporal, central+1, superior, elemento);
            }
            else{
                printf("\nReturn 2");
                return buscar_Elemento_Recursivo_2 (lista, listaTemporal, inferior, central-1, elemento);
                
            }
        }
    }
    else{
        return(listaTemporal);
    }
}

void vaciar_Lista (ListaSimple *lista){
    Nodo *aux = lista->cabeza;
    if(lista_vacia(*lista) != 1){
        while (aux != NULL){
            aux = aux->sig;
            quitar_cabeza(lista);
        }
    }
    else
        printf("\nLista vacia\n");
    free(aux);
}

void imprimir_Lista (ListaSimple *lista){
    Nodo *aux = lista->cabeza;
    Producto *product;
    if (lista_vacia(*lista) != 1){
        while (aux != NULL){
            product = aux->datos;
            /*printf ("\nNombre: %s",product->nombreAlimento);
            printf("\n Tipo: %s",product->tipoAlimento);*/
            printf("\n Precio: $%.2f",product->precio);
            /*printf("\n Fecha de compra: %02d/%02d/%d",product->diaCompra,product->mesCompra,product->anioCompra);
            printf("\n Fecha caducidad: %02d/%02d/%04d",product->diaCaducicad,product->mesCaducidad,product->anioCaducidad);
            printf("\n Disponibilidad: %d\n", product->disponibilidad);*/
            printf("\n ID: %d",product->identificador);
            aux = aux->sig;
        }
    }
    else
        printf("\nLista vacia\n");
}

ListaSimple *QuickSort (ListaSimple *lista, int inicio, int final){
    int izquierda, derecha, centro, idTemporal;
    float auxPrecio = 0;
    Nodo *pivote = crear_Nodo(agregar_Producto_temporal(auxPrecio));
    Nodo *aux = lista->cabeza;
    Nodo *aux2 = lista->cabeza;
    if (lista_vacia(*lista) != 1) {
        if (inicio < final){
            while (aux->datos->identificador != inicio){
                printf("\n255) Sale cuando id sea %d",inicio);
                aux = aux->sig;
                printf("\naux id: %d",aux->datos->identificador);
            }
            pivote->datos = aux->datos;
            izquierda = inicio;
            derecha = final;
            while (izquierda < derecha){
                printf("\n263) Entre aca");
                aux = lista->cabeza;
                printf("\n2aux id: %d",aux->datos->identificador);
                while (aux->datos->identificador != derecha){
                    printf("\n267) Sale cuando id sea %d",derecha);
                    aux = aux->sig;
                    printf("\naux id: %d",aux->datos->identificador);
                }
                printf("\nSali 267");
                while ((derecha > izquierda) && (aux->datos->precio > pivote->datos->precio)){
                    derecha--;
                    while (aux->datos->identificador != derecha){
                        printf("\nSale cuando id sea %d",derecha);
                        aux = aux->sig;
                        printf("\naux id: %d",aux->datos->identificador);
                    }
                }
                if (derecha > izquierda){
                    while (aux2->datos->identificador != derecha){
                        aux2 = aux2->sig;
                    }
                    aux = lista->cabeza;
                    while (aux->datos->identificador != izquierda){
                        aux = aux->sig;
                    }
                    idTemporal = aux->datos->identificador;
                    aux->datos = aux2->datos;
                    aux->datos->identificador = idTemporal;
                    izquierda++;
                }
                while (aux->datos->identificador != izquierda){
                    aux = aux->sig;
                }
                while ((izquierda < derecha) && (aux->datos->precio < pivote->datos->precio)){
                    izquierda++;
                    while (aux->datos->identificador != izquierda){
                        aux = aux->sig;
                    }
                }
                if (izquierda < derecha){
                    aux = lista->cabeza;
                    while (aux->datos->identificador != izquierda){
                        aux = aux->sig;
                    }
                    aux2 = lista->cabeza;
                    while (aux2->datos->identificador != derecha){
                        aux2 = aux2->sig;
                    }
                    idTemporal = aux2->datos->identificador;
                    aux2->datos = aux->datos;
                    aux2->datos->identificador = idTemporal;
                    derecha--;
                }
            }
            while (aux->datos->identificador != derecha){
                aux = aux->sig;
            }
            idTemporal = aux->datos->identificador;
            aux->datos = pivote->datos;
            aux->datos->identificador = idTemporal;
            centro = derecha;
            QuickSort(lista, inicio, centro-1);
            QuickSort(lista, centro+1, final);
            return (lista);
        }
    }
    else{
        return(lista);
    }
}
ListaSimple *Mergesort (ListaSimple *lista, int primero, int ultimo){
    int central;
    if(primero < ultimo){
        central = (primero + ultimo)/2;
        Mergesort(lista, primero, central);
        Mergesort(lista, central+1, ultimo);
        mezcla (lista, primero, central, ultimo);
    }

}
void mezcla (ListaSimple *lista, int izquierda, int central, int derecha){
    ListaSimple *listaTemporal = crear_ListaSimple();
    Nodo *aux;
}

void *ordenamiento_seleccion(ListaSimple *lista, int n){
    int indiceMenor, i, j;
    int auxid1, auxid2;
    Nodo *aux = lista->cabeza;
    Nodo *aux2 = lista->cabeza;
    for (i=0; i<n-1;i++){
        indiceMenor = i;
        for(j=i+1; j<n; j++){
            aux = lista->cabeza;
            while(aux->datos->identificador != j){
                aux = aux->sig;
            } //aux[j]
            aux2 = lista->cabeza;
            while(aux2->datos->identificador != indiceMenor){
                aux2 = aux2->sig;
            }
            //aux2 [indMenor]
            if(aux->datos->precio < aux2->datos->precio){
                indiceMenor = j;
            }
        }
        if (i != indiceMenor){
            aux = lista->cabeza;
            while(aux->datos->identificador != i){
                aux = aux->sig;
            }   //a[i]
            Nodo *aux3;
            copiar_Producto(aux,aux3); //aux = a[i];
            aux3->datos->identificador = aux->datos->identificador;
            aux2 = lista->cabeza;
            while (aux2->datos->identificador != indiceMenor){ 
                aux2 = aux2->sig;
            }   //aux2[indiceMenor]
            copiar_Producto(aux2,aux); //aux[i] = aux[indMenor]
            //aux2 = aux3;
            copiar_Producto(aux3,aux2); //aux[indMenor] = aux
        }
        printf("\nOrdenado es\n");
        imprimir_Lista(lista);
    }
}
