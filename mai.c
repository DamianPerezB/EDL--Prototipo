#include "refrigerador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    int option = 0, option2 = 0, aux =0;
    ListaSimple *bebida, *embutido, *fruta, *lacteo, *carne, *verdura;
    bebida = crear_ListaSimple();
    embutido = crear_ListaSimple();
    fruta = crear_ListaSimple();
    lacteo = crear_ListaSimple();
    carne = crear_ListaSimple();
    verdura = crear_ListaSimple();
    Nodo *ele1, *ele2;

    while(option !=7){
        printf("\nRefrigerador abierto\n");
        printf("Selecciona el apartado de tu preferencia\n");
        printf("\n1- Bebidas\n");
        printf("\n2- Embutidos\n");
        printf("\n3- Frutas\n");
        printf("\n4- Lacteos\n");
        printf("\n5- Carnes\n");
        printf("\n6- Verduras\n");
        printf("\n7- Salir\n");
        printf("\n   Opcion:\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                do{
                    printf("\nSeccion de bebidas\n");
                    printf("Selecciona la operacion deseada\n");
                    printf("\n1- Ingresar una bebida\n");
                    printf("\n2- Quitar una bebida\n");
                    printf("\n3- Mostrar la lista de bebidas\n");
                    printf("\n4- Buscar una bebida\n");
                    printf("\n5- Ordenar bebidas por precio\n");
                    printf("\n6- Vaciar lista de bebidas\n");
                    printf("\n7- Regresar al menú principal\n");
                    printf("\n   Opcion:\n"); 
                    scanf("%d",&option2);  
                }while(option2 !=7);
                break;
            case 2:
                do{
                    printf("\nSeccion de embutidos\n");
                    printf("Selecciona la operacion deseada\n");
                    printf("\n1- Ingresar un embutido\n");
                    printf("\n2- Quitar un embutido\n");
                    printf("\n3- Mostrar la lista de embutidos\n");
                    printf("\n4- Buscar un embutido\n");
                    printf("\n5- Ordenar embutidos por precio\n");
                    printf("\n6- Vaciar lista de embutidos\n");
                    printf("\n7- Regresar al menú principal\n");
                    printf("\n   Opcion:\n"); 
                    scanf("%d",&option2); 
                }while(option2 !=7);
                break;
            case 3:
                do{
                    printf("\nSeccion de frutas\n");
                    printf("Selecciona la operacion deseada\n");
                    printf("\n1- Ingresar una fruta\n");
                    printf("\n2- Quitar una fruta\n");
                    printf("\n3- Mostrar la lista de frutas\n");
                    printf("\n4- Buscar una fruta\n");
                    printf("\n5- Ordenar bfrutas por precio\n");
                    printf("\n6- Vaciar lista de frutas\n");
                    printf("\n7- Regresar al menú principal\n");
                    printf("\n   Opcion:\n"); 
                    scanf("%d",&option2); 
                }while(option2 !=7);
                break;
            case 4:
                do{
                    printf("\nSeccion de lacteos\n");
                    printf("Selecciona la operacion deseada\n");
                    printf("\n1- Ingresar un lateo\n");
                    printf("\n2- Quitar un lacteo\n");
                    printf("\n3- Mostrar la lista de lacteos\n");
                    printf("\n4- Buscar un lacteo\n");
                    printf("\n5- Ordenar lacteos por precio\n");
                    printf("\n6- Vaciar lista de lacteos\n");
                    printf("\n7- Regresar al menú principal\n");
                    printf("\n   Opcion:\n"); 
                    scanf("%d",&option2); 
                }while(option2 !=7);
                break;
            case 5:
                do{
                    printf("\nSeccion de proteinas\n");
                    printf("Selecciona la operacion deseada\n");
                    printf("\n1- Ingresar una proteina\n");
                    printf("\n2- Quitar una proteina\n");
                    printf("\n3- Mostrar la lista de proteinas\n");
                    printf("\n4- Buscar una proteina\n");
                    printf("\n5- Ordenar proteinas por precio\n");
                    printf("\n6- Vaciar lista de proteinas\n");
                    printf("\n7- Regresar al menú principal\n");
                    printf("\n   Opcion:\n"); 
                    scanf("%d",&option2); 
                }while(option2 !=7);
                break;
            case 6:
                do{
                    printf("\nSeccion de verduras\n");
                    printf("Selecciona la operacion deseada\n");
                    printf("\n1- Ingresar una verdura\n");
                    printf("\n2- Quitar una verdura\n");
                    printf("\n3- Mostrar la lista de verduras\n");
                    printf("\n4- Buscar una verdura\n");
                    printf("\n5- Ordenar verduras por precio\n");
                    printf("\n6- Vaciar lista de verduras\n");
                    printf("\n7- Regresar al menú principal\n");
                    printf("\n   Opcion:\n"); 
                    scanf("%d",&option2); 
                }while(option2 !=7);
                break;
            case 7:
                option = 7;
                printf("\nRefrigerador cerrado\n");
                break;
            default:
                printf ("\n\nIngresa una opcion valida\n"); 
                break;
        }
    }
    return(0);
}
