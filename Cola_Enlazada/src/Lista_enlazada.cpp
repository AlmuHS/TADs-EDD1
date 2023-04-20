#include "../include/Lista_enlazada.h"

#include <cstddef>
#include <iostream>

Lista_enlazada::Lista_enlazada()
{
    this->lista_ptr = NULL;
    this->ultimo = NULL;
}

void Lista_enlazada::insertar_inicio(int valor){
    elemento* nuevo = new elemento;
    nuevo->dato = valor;

    //Si la lista no está vacía, el siguiente del nuevo elemento será el actual elemento inicial
    if(this->lista_ptr != NULL)
        nuevo->siguiente = this->lista_ptr;
    //Si la lista está vacía, el nuevo elemento será tanto el primero como el último
    else{
        nuevo->siguiente = NULL; //Su siguiente es NULL, dado que es el último
        this->ultimo = nuevo; //El puntero del último apuntará a este elemento
    }

    //Independientemente de si la lista estaba vacía o no, una vez insertado el nuevo elemento, el puntero inicial debe apuntar a él
    this->lista_ptr = nuevo;

}

void Lista_enlazada::insertar_final(int valor){
    elemento* nuevo = new elemento;
    nuevo->dato = valor;
    nuevo->siguiente = NULL; //el siguiente será NULL, porque será el último elemento de la lista

    //Si la lista está vacía, el elemento se asigna al puntero inicial
    if(this->es_vacia()){
        this->ultimo = nuevo;
        this->lista_ptr = this->ultimo;
    }
    //Si no, se asigna al puntero final
    else{
        //El puntero último apunta todavía al que será el nuevo penúltimo, por lo que el nuevo elemento será el siguiente a este (y nuevo último)
        this->ultimo->siguiente = nuevo;

        //Una vez insertado el nuevo elemento tras el antiguo último, actualizamos el puntero último para que apunte al nuevo elemento (que será el nuevo último)
        this->ultimo = nuevo;
    }
}

void Lista_enlazada::insertar_intermedio(int pos, int valor){
    if(pos == 0) this->insertar_inicio(valor);
    else{

        elemento* nuevo = new elemento;
        nuevo->dato = valor;

        //Navegamos hasta el elemento de la posicion anterior a donde queremos insertar
        int i = 0;

        //El puntero aux almacenará el elemento anterior a la posición (en caso de que esta sea válida)
        elemento* aux = this->lista_ptr;

        //Debemos comprobar que no nos estemos saliendo de la lista. Para saberlo, comprobamos que aux no sea NULL, lo cual indicaría que no hay elementos suficientes para obtener esa posición
        while(i < pos-1 && aux != NULL){
            aux = aux->siguiente;
            i++;
        }

        /* Reasignamos los punteros */

        //Si el puntero aux no es NULL, no nos hemos salido de la lista, por lo que aux apuntará a la posición anterior a donde vamos a insertar
        if(aux != NULL){
            //El siguiente del nuevo será el siguiente de su antiguo anterior
            nuevo->siguiente = aux->siguiente;

            //El nuevo siguiente del anterior será el nuevo
            aux->siguiente = nuevo;
        }
    }

}

void Lista_enlazada::eliminar_inicio(){

    //Si la lista no está vacía, debemos eliminar el elemento inicial, al que apunta el puntero inicial lista_ptr
    if(!this->es_vacia()){

        //Nos guardamos la dirección del puntero inicial actual, para liberarla luego
        elemento *aux = this->lista_ptr;

        //Si el puntero inicial tiene un siguiente no nulo, entonces hay mas de un elemento en la lista, por lo que el puntero inicial apuntará a su siguiente
        if(this->lista_ptr->siguiente != NULL){
            this->lista_ptr = this->lista_ptr->siguiente;
        }
        //Si no hay elemento siguiente, quiere decir que solo queda un elemento en la lista, por lo que esta se quedará vacía al eliminarlo
        //Por eso, el puntero inicial y el último se convertirán en nulos
        else{
            this->lista_ptr = NULL;
            this->ultimo = NULL;
        }

        //Una vez eliminado el elemento de la lista, liberamos su memoria con la dirección que guardamos en su puntero auxiliar
        delete aux;
    }
    //Si la lista está vacía, el puntero inicial y ultimo valdrá NULL. Los asignamos por si acaso
    else{
        this->lista_ptr = NULL;
        this->ultimo = NULL;
    }
}

void Lista_enlazada::eliminar_final(){

    if(!this->es_vacia()){

        //Solo queda un elemento (el inicio)
        if(this->lista_ptr->siguiente == NULL){
            delete lista_ptr;
            this->lista_ptr = NULL;
            this->ultimo = NULL;

        }
        //En otro caso
        else{
            /* Navegamos hasta la penultima posicion */

            //Este puntero, tras finalizar el recorrido, tendrá la dirección de la penúltima posición
            elemento* aux = this->lista_ptr;

            //La penúltima posición será la cual tenga como siguiente al último elemento
            while(aux->siguiente != this->ultimo){
                aux = aux->siguiente;
            }

            //Liberamos la memoria de la actual ultima posicion
            delete this->ultimo;

            //Actualizamos el puntero ultimo con el antiguo penultimo, almacenado en aux
            this->ultimo = aux;
            this->ultimo->siguiente = NULL;
        }

    }
}

void Lista_enlazada::eliminar(int pos){

    //Solo podemos eliminar un elemento si la lista no esta vacía
    if(pos >= 0 && !this->es_vacia()){

        //Navegamos hasta la posición anterior a la que queremos eliminar
        int i = 0;

        //Este puntero almacenará, tras el recorrido, la posición anterior a la que queremos eliminar
        elemento* aux = this->lista_ptr;

        //Recorremos hasta la posición, o hasta salirnos de la lista
        while(i < pos-1 && aux != NULL){
            aux = aux->siguiente;
            i++;
        }

        //Si aux no es nulo, no nos hemos salido de la lista
        if(aux != NULL){

            //Para eliminar el elemento, hacemos que el elemento anterior apunte al siguiente del elemento a eliminar
            elemento *aux2 = aux->siguiente; //este será el elemento a eliminar
            aux->siguiente = aux2->siguiente;//reasignamos el siguiente del anterior al siguiente del que queremos eliminar
            delete aux2; //y liberamos la memoria del elemento eliminado
        }
    }

}

void Lista_enlazada::mostrar(){
    elemento *aux = this->lista_ptr;
    while(aux != NULL){
        std::cout<<aux->dato<<" ";
        aux = aux->siguiente;
    }
    std::cout<<"\n";
}

int Lista_enlazada::buscar(int valor){
    elemento* aux = this->lista_ptr;
    int pos = 0;

    bool encontrado = false;

    //Recorremos la lista hasta encontrar el valor o salirnos
    //Debemos comprobar que el propio aux no sea NULL, en lugar de que su siguiente no lo sea, porque el valor podría encontrarse al final de la lista (el cual tendría su siguiente a NULL)

    //Comprobaremos el contenido de la posición dentro del bucle, para asegurarnos de estar accediendo a un elemento válido (no nulo)
    while(!encontrado && aux != NULL){

        //Si hemos entrado al bucle, es que la posición no es nula, por lo que podemos comprobar el contenido del elemento actual sin peligro
        //Si el valor de este elemento se corresponde con el buscado, ponemos encontrado a true para finalizar la búsqueda
        if(aux->dato == valor) encontrado = true;

        //Si no, seguimos buscando en la siguiente posición
        else{
            aux = aux->siguiente;
            pos++;
        }
    }

    //Si aux no es NULL, habremos encontrado el valor sin salirnos de la lista.
    if(aux != NULL) return pos;
    else return -1;

}

int Lista_enlazada::obtener(int pos){
    elemento* aux = this->lista_ptr;
    int i = 0;
    int valor;

    //Recorremos la lista hasta esa posicion o hasta salirnos (en caso de que la lista no tenga suficientes elementos para llegar a esa posición)
    while(i < pos && aux != NULL){
        aux = aux->siguiente;
        i++;
    }

    //Si aux no es NULL, entonces hemos encontrado esa posición dentro de la lista, con lo que nos guardaremos su valor
    if(aux != NULL){
        valor = aux->dato;
    }

    //Si es NULL, no existe esa posición, por lo que guardaremos el valor -1 para avisar de esta situación
    else valor = -1;

    return valor;
}

void Lista_enlazada::modificar(int pos, int valor){
    elemento* aux = this->lista_ptr;
    int i = 0;

    while(i < pos && aux != NULL){
        aux = aux->siguiente;
        i++;
    }

    if(aux != NULL){
        aux->dato = valor;
    }
}

int Lista_enlazada::longitud(){
    elemento* aux = this->lista_ptr;
    int longitud = 0;

    if(this->lista_ptr != NULL){
        while(aux != NULL){
            aux = aux->siguiente;
            longitud++;
        }
    }
    return longitud;

}

bool Lista_enlazada::es_vacia(){
    return (this->lista_ptr == NULL || this->ultimo == NULL);
}

Lista_enlazada::~Lista_enlazada()
{
    elemento* aux = this->lista_ptr;
    while(aux != NULL){
        elemento *aux2 = aux->siguiente;
        delete aux;
        aux = aux2;
    }
}


