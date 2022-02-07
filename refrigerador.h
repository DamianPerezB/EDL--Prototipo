//  Perez Benitez Damian    
//  Carbajal Urquisa Luis Fhernando

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
    int identificador;
}Producto;

typedef struct Nodo{
    Producto *datos;
    struct Nodo *sig;
}Nodo;

typedef struct ListaSimple{
    Nodo *cabeza;
}ListaSimple;

//Funciones para generar las listas
Producto *agregar_Producto (int TIPO, int ID);
Producto *agregar_Producto_temporal(float elemento);
void copiar_Producto(Nodo *aux, Nodo *aux2);
Nodo *crear_Nodo (Producto *producto);
ListaSimple *crear_ListaSimple ();

//Funciones para editar las listas
int lista_vacia (ListaSimple lista);
void insertar_cabeza (ListaSimple *lista, Nodo *aux);
void insertar_cola (ListaSimple *lista, Nodo *aux);
void insertar_en_medio (ListaSimple *lista, Nodo *anterior, Nodo *elemento);
void quitar_cabeza (ListaSimple *lista);
void quitar_cola (ListaSimple *lista, Nodo *cola);
void quitar_en_medio (ListaSimple *lista, Nodo *elemento);
Nodo *buscar_Elemento_Recursivo (ListaSimple *lista, int superior, Nodo *elemento);
ListaSimple *buscar_Elemento_Recursivo_2 (ListaSimple *lista, ListaSimple *listaTemporal, int inferior, int superior, Nodo *elemento);
void vaciar_Lista (ListaSimple *lista);
void imprimir_Lista (ListaSimple *lista);

//Funciones de ordenamiento
ListaSimple *QuickSort (ListaSimple *lista, int inicio, int final);
ListaSimple *Mergesort (ListaSimple *lista, int inicio, int final);
void mezcla (ListaSimple *lista, int izquierda, int central, int derecha);
void *ordenamiento_seleccion(ListaSimple *lista, int n);
