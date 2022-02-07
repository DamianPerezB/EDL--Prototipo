//  Perez Benitez Damian    2183034588
//  Carbajal Urquisa Luis Fhernando

//Comentarios adicionales
//  Profesora, por más que intentamos, no pudimos generar ningun tipo de ordenamientos
//  tenemos las funciones en el archivo .c, pero no supimos cual era el error.
//  El programa funciona correctamente. Solo que en caso de querer usar el apartado busqueda
//  se deben ingresar los productos de menor a mayor, ya que usamos una busqueda recursiva
    
//  Además como extra, incluimos la generación de un archivo txt, el cual genera un archivo
//  de nombre Lista_De_Compras en el cual indica los productos con los que ya no cuenta el 
//  refrigerador (Que tienen disponibilidad 0

#include "refrigerador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    int option = 0, option2 = 0, aux =0, inferior = 0, auxiliarFinal;
    ListaSimple *bebida, *embutido, *fruta, *lacteo, *carne, *verdura, *listaTemporal;
    int idBebida=0, idEmbutido=0, idFruta=0, idLacteo=0, idCarne=0, idVerdura=0;
    float elemento = 0;
    //Se crean las listas de todos los alimentos
    bebida   =  crear_ListaSimple();
    embutido =  crear_ListaSimple();
    fruta    =  crear_ListaSimple();
    lacteo   =  crear_ListaSimple();
    carne    =  crear_ListaSimple();
    verdura  =  crear_ListaSimple();

    Nodo *ele1;

    while(option !=7){
        printf("\nREFRIGERADOR ABIERTO\n");
        printf("Selecciona el apartado de tu preferencia");
        printf("\n1- Bebidas");
        printf("\n2- Embutidos");
        printf("\n3- Frutas");
        printf("\n4- Lacteos");
        printf("\n5- Carnes");
        printf("\n6- Verduras");
        printf("\n7- Salir");
        printf("\n   Opcion:\t");
        scanf("%d",&option);
        switch(option){
            case 1:
                do{
                    printf("\nSECCION DE BEBIDAS");
                    printf("\nSelecciona la operacion deseada");
                    printf("\n1- Ingresar una bebida");
                    printf("\n2- Quitar una bebida");
                    printf("\n3- Mostrar la lista de bebidas");
                    printf("\n4- Buscar una bebida");
                    printf("\n5- Ordenar bebidas por precio");
                    printf("\n6- Vaciar lista de bebidas");
                    printf("\n7- Regresar al menu principal");
                    printf("\n   Opcion:\t"); 
                    scanf("%d",&option2);  
                    switch (option2){
                        case 1:
                            ele1 = crear_Nodo(agregar_Producto(option),idBebida);
                            insertar_cola(bebida,ele1);
                            idBebida++;
                            break;
                        case 2:
                            idBebida = idBebida - eliminar_producto(bebida,idBebida);
                            acomodar_Id(bebida,idBebida);
                            break;
                        case 3:
                            imprimir_Lista(bebida);
                            break;
                        case 4:
                            printf("\nIngresa el precio del producto a buscar:\t$");
                            scanf("%f",&elemento);
                            ele1 = crear_Nodo(agregar_Producto_temporal(elemento),idBebida);
                            auxiliarFinal = idBebida;
                            //QuickSort(bebida, inferior, idBebida);
                            ele1 = buscar_Elemento_Recursivo(bebida, inferior, auxiliarFinal, ele1);
                            if (ele1 != NULL){
                                printf ("\nNombre: %s",ele1->datos->nombreAlimento);
                                printf("\n Tipo: %s",ele1->datos->tipoAlimento);
                                printf("\n Precio: $%.2f",ele1->datos->precio);
                                printf("\n Fecha de compra: %02d/%02d/%d",ele1->datos->diaCompra,ele1->datos->mesCompra,ele1->datos->anioCompra);
                                printf("\n Fecha caducidad: %02d/%02d/%04d",ele1->datos->diaCaducicad,ele1->datos->mesCaducidad,ele1->datos->anioCaducidad);
                                printf("\n Disponibilidad: %d\n", ele1->datos->disponibilidad);
                            }
                            break;
                        case 5:
                            //QuickSort(bebida,inferior,idBebida);
                            break;
                        case 6:
                            vaciar_Lista(bebida);
                            idBebida = 0;
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nIngresa una opcion valida\n");
                            break;
                    }
                }while(option2 !=7);
                break;
            case 2:
                do{
                    printf("\nSECCION DE EMBUTIDOS");
                    printf("\nSelecciona la operacion deseada");
                    printf("\n1- Ingresar un embutido");
                    printf("\n2- Quitar un embutido");
                    printf("\n3- Mostrar la lista de embutidos");
                    printf("\n4- Buscar un embutido");
                    printf("\n5- Ordenar embutidos por precio");
                    printf("\n6- Vaciar lista de embutidos");
                    printf("\n7- Regresar al menu principal");
                    printf("\n   Opcion:\t"); 
                    scanf("%d",&option2); 
                    switch (option2){
                        case 1:
                            ele1 = crear_Nodo(agregar_Producto(option),idEmbutido);
                            insertar_cola(embutido,ele1);
                            idEmbutido++;
                            break;
                        case 2:
                            idEmbutido = idEmbutido - eliminar_producto(embutido,idEmbutido);
                            acomodar_Id(embutido,idEmbutido);                        
                            break;
                        case 3:
                            imprimir_Lista(embutido);
                            break;
                        case 4:
                            printf("\nIngresa el precio del producto a buscar:\t$");
                            scanf("%f",&elemento);
                            ele1 = crear_Nodo(agregar_Producto_temporal(elemento),idEmbutido);
                            auxiliarFinal = idEmbutido;
                            //ordenamiento_seleccion(embutido, idEmbutido);
                            ele1 = buscar_Elemento_Recursivo(embutido, inferior, auxiliarFinal, ele1);
                            if (ele1 != NULL){
                                printf ("\nNombre: %s",ele1->datos->nombreAlimento);
                                printf("\n Tipo: %s",ele1->datos->tipoAlimento);
                                printf("\n Precio: $%.2f",ele1->datos->precio);
                                printf("\n Fecha de compra: %02d/%02d/%d",ele1->datos->diaCompra,ele1->datos->mesCompra,ele1->datos->anioCompra);
                                printf("\n Fecha caducidad: %02d/%02d/%04d",ele1->datos->diaCaducicad,ele1->datos->mesCaducidad,ele1->datos->anioCaducidad);
                                printf("\n Disponibilidad: %d\n", ele1->datos->disponibilidad);
                            }
                            break;
                        case 5:
                            ordenamiento_seleccion(embutido, idEmbutido);
                            break;
                        case 6:
                            vaciar_Lista(embutido);
                            idEmbutido = 0;
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nIngresa una opcion valida\n");
                            break;
                    }
                }while(option2 !=7);
                break;
            case 3:
                do{
                    printf("\nSECCION DE FRUTAS");
                    printf("\nSelecciona la operacion deseada");
                    printf("\n1- Ingresar una fruta");
                    printf("\n2- Quitar una fruta");
                    printf("\n3- Mostrar la lista de frutas");
                    printf("\n4- Buscar una fruta");
                    printf("\n5- Ordenar bfrutas por precio");
                    printf("\n6- Vaciar lista de frutas");
                    printf("\n7- Regresar al menu principal");
                    printf("\n   Opcion:\t"); 
                    scanf("%d",&option2); 
                    switch (option2){
                        case 1:
                            ele1 = crear_Nodo(agregar_Producto(option),idFruta);
                            insertar_cola(fruta,ele1);
                            idFruta++;
                            break;
                        case 2:
                            idFruta = idFruta - eliminar_producto(fruta,idFruta);
                            acomodar_Id(fruta,idFruta);
                            break;
                        case 3:
                            imprimir_Lista(fruta);
                            break;
                        case 4:
                            printf("\nIngresa el precio del producto a buscar:\t$");
                            scanf("%f",&elemento);
                            ele1 = crear_Nodo(agregar_Producto_temporal(elemento),idFruta);
                            auxiliarFinal = idFruta;
                            //ordenamiento_seleccion(fruta, idFruta);
                            ele1 = buscar_Elemento_Recursivo(fruta, inferior, auxiliarFinal, ele1);
                            if (ele1 != NULL){
                                printf ("\nNombre: %s",ele1->datos->nombreAlimento);
                                printf("\n Tipo: %s",ele1->datos->tipoAlimento);
                                printf("\n Precio: $%.2f",ele1->datos->precio);
                                printf("\n Fecha de compra: %02d/%02d/%d",ele1->datos->diaCompra,ele1->datos->mesCompra,ele1->datos->anioCompra);
                                printf("\n Fecha caducidad: %02d/%02d/%04d",ele1->datos->diaCaducicad,ele1->datos->mesCaducidad,ele1->datos->anioCaducidad);
                                printf("\n Disponibilidad: %d\n", ele1->datos->disponibilidad);
                            }
                            break;
                        case 5:
                            //ordenamiento_seleccion(fruta, idFruta);
                            break;
                        case 6:
                            vaciar_Lista(fruta);
                            idFruta = 0;
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nIngresa una opcion valida\n");
                            break;
                    }
                }while(option2 !=7);
                break;
            case 4:
                do{
                    printf("\nSECCION DE LACTEOS");
                    printf("\nSelecciona la operacion deseada");
                    printf("\n1- Ingresar un lateo");
                    printf("\n2- Quitar un lacteo");
                    printf("\n3- Mostrar la lista de lacteos");
                    printf("\n4- Buscar un lacteo");
                    printf("\n5- Ordenar lacteos por precio");
                    printf("\n6- Vaciar lista de lacteos");
                    printf("\n7- Regresar al menu principal");
                    printf("\n   Opcion:\t"); 
                    scanf("%d",&option2); 
                    switch (option2){
                        case 1:
                            ele1 = crear_Nodo(agregar_Producto(option),idLacteo);
                            insertar_cola(lacteo,ele1);
                            idLacteo++;
                            break;
                        case 2:
                            idLacteo = idLacteo - eliminar_producto(lacteo,idLacteo);
                            acomodar_Id(lacteo,idLacteo);                        
                            break;
                        case 3:
                            imprimir_Lista(lacteo);
                            break;
                        case 4:
                            printf("\nIngresa el precio del producto a buscar:\t$");
                            scanf("%f",&elemento);
                            ele1 = crear_Nodo(agregar_Producto_temporal(elemento),idLacteo);
                            auxiliarFinal = idLacteo;
                            //ordenamiento_seleccion(lacteo, idLacteo);
                            ele1 = buscar_Elemento_Recursivo(lacteo, inferior, auxiliarFinal, ele1);
                            if (ele1 != NULL){
                                printf ("\nNombre: %s",ele1->datos->nombreAlimento);
                                printf("\n Tipo: %s",ele1->datos->tipoAlimento);
                                printf("\n Precio: $%.2f",ele1->datos->precio);
                                printf("\n Fecha de compra: %02d/%02d/%d",ele1->datos->diaCompra,ele1->datos->mesCompra,ele1->datos->anioCompra);
                                printf("\n Fecha caducidad: %02d/%02d/%04d",ele1->datos->diaCaducicad,ele1->datos->mesCaducidad,ele1->datos->anioCaducidad);
                                printf("\n Disponibilidad: %d\n", ele1->datos->disponibilidad);
                            }
                            break;
                        case 5:
                            //ordenamiento_seleccion(lacteo, idLacteo);
                            break;
                        case 6:
                            vaciar_Lista(lacteo);
                            idLacteo = 0;
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nIngresa una opcion valida\n");
                            break;
                    }
                }while(option2 !=7);
                break;
            case 5:
                do{
                    printf("\nSECCION DE PROTEINAS");
                    printf("\nSelecciona la operacion deseada");
                    printf("\n1- Ingresar una proteina");
                    printf("\n2- Quitar una proteina");
                    printf("\n3- Mostrar la lista de proteinas");
                    printf("\n4- Buscar una proteina");
                    printf("\n5- Ordenar proteinas por precio");
                    printf("\n6- Vaciar lista de proteinas");
                    printf("\n7- Regresar al menu principal");
                    printf("\n   Opcion:\t"); 
                    scanf("%d",&option2);
                    switch (option2){
                        case 1:
                            ele1 = crear_Nodo(agregar_Producto(option),idCarne);
                            insertar_cola(carne,ele1);
                            idCarne++;
                            break;
                        case 2:
                            idCarne = idCarne - eliminar_producto(carne,idCarne);
                            acomodar_Id(carne,idCarne);
                            break;
                        case 3:
                            imprimir_Lista(carne);
                            break;
                        case 4:
                            printf("\nIngresa el precio del producto a buscar:\t$");
                            scanf("%f",&elemento);
                            ele1 = crear_Nodo(agregar_Producto_temporal(elemento),idCarne);
                            auxiliarFinal = idCarne;
                            //ordenamiento_seleccion(carne, idCarne);
                            ele1 = buscar_Elemento_Recursivo(carne, inferior, auxiliarFinal, ele1);
                            if (ele1 != NULL){
                                printf ("\nNombre: %s",ele1->datos->nombreAlimento);
                                printf("\n Tipo: %s",ele1->datos->tipoAlimento);
                                printf("\n Precio: $%.2f",ele1->datos->precio);
                                printf("\n Fecha de compra: %02d/%02d/%d",ele1->datos->diaCompra,ele1->datos->mesCompra,ele1->datos->anioCompra);
                                printf("\n Fecha caducidad: %02d/%02d/%04d",ele1->datos->diaCaducicad,ele1->datos->mesCaducidad,ele1->datos->anioCaducidad);
                                printf("\n Disponibilidad: %d\n", ele1->datos->disponibilidad);
                            }
                            break;
                        case 5:
                            //ordenamiento_seleccion(carne, idCarne);
                            break;
                        case 6:
                            vaciar_Lista(carne);
                            idCarne = 0;
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nIngresa una opcion valida\n");
                            break;
                    } 
                }while(option2 !=7);
                break;
            case 6:
                do{
                    printf("\nSECCION DE VERDURAS");
                    printf("\nSelecciona la operacion deseada");
                    printf("\n1- Ingresar una verdura");
                    printf("\n2- Quitar una verdura");
                    printf("\n3- Mostrar la lista de verduras");
                    printf("\n4- Buscar una verdura");
                    printf("\n5- Ordenar verduras por precio");
                    printf("\n6- Vaciar lista de verduras");
                    printf("\n7- Regresar al menu principal");
                    printf("\n   Opcion:\t"); 
                    scanf("%d",&option2);
                    switch (option2){
                        case 1:
                            ele1 = crear_Nodo(agregar_Producto(option),idVerdura);
                            insertar_cola(verdura,ele1);
                            idVerdura++;
                            break;
                        case 2:
                            idVerdura = idVerdura - eliminar_producto(verdura,idVerdura);
                            acomodar_Id(verdura,idVerdura);
                            break;
                        case 3:
                            imprimir_Lista(verdura);
                            break;
                        case 4:
                            printf("\nIngresa el precio del producto a buscar:\t$");
                            scanf("%f",&elemento);
                            ele1 = crear_Nodo(agregar_Producto_temporal(elemento),idVerdura);
                            auxiliarFinal = idVerdura;
                            //ordenamiento_seleccion(verdura, idVerdura);
                            ele1 = buscar_Elemento_Recursivo(verdura, inferior, auxiliarFinal, ele1);
                            if (ele1 != NULL){
                                printf ("\nNombre: %s",ele1->datos->nombreAlimento);
                                printf("\n Tipo: %s",ele1->datos->tipoAlimento);
                                printf("\n Precio: $%.2f",ele1->datos->precio);
                                printf("\n Fecha de compra: %02d/%02d/%d",ele1->datos->diaCompra,ele1->datos->mesCompra,ele1->datos->anioCompra);
                                printf("\n Fecha caducidad: %02d/%02d/%04d",ele1->datos->diaCaducicad,ele1->datos->mesCaducidad,ele1->datos->anioCaducidad);
                                printf("\n Disponibilidad: %d\n", ele1->datos->disponibilidad);
                            }
                            break;
                        case 5:
                        //ordenamiento_seleccion(verdura, idVerdura);
                            break;
                        case 6:
                            vaciar_Lista(verdura);
                            idVerdura = 0;
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nIngresa una opcion valida\n");
                            break;
                    } 
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
    //N
    FILE *p;
    p= fopen("Lista_De_Compras.txt","wt");
    if(p==NULL){
        printf("No se pudo crear el archivo");
    }
    else{
        printf("\nGenerando lista de compras");
        fprintf(p,"\n\nBebidas\n");
        llenar_txt(p,bebida);
        fprintf(p,"\n\nEmbutidos\n");
        llenar_txt(p,embutido);
        fprintf(p,"\n\nFrutas\n");
        llenar_txt(p,fruta);
        fprintf(p,"\n\nLacteos\n");
        llenar_txt(p,lacteo);
        fprintf(p,"\n\nProteinas\n");
        llenar_txt(p,carne);
        fprintf(p,"\n\nVerduras\n");
        llenar_txt(p,verdura);
    }
    fclose(p);    
    //Se liberan todas las listas antes de terminar el programa
    vaciar_Lista(bebida);
    vaciar_Lista(embutido);
    vaciar_Lista(fruta);
    vaciar_Lista(lacteo);
    vaciar_Lista(carne);
    vaciar_Lista(verdura);

    return(0);
}
