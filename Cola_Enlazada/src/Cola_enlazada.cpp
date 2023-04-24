#include "Cola_enlazada.h"

Cola_enlazada::Cola_enlazada()
{
    this->num_elementos = 0;
}

void Cola_enlazada::encolar(int dato){
    this->cola.insertar_final(dato); //el inicio de la lista es la última posición de la cola
    this->num_elementos = cola.longitud();
}

void Cola_enlazada::desencolar(){
    this->cola.eliminar_inicio(); //el final de la lista es la primera posición de la cola
    this->num_elementos = cola.longitud();
}

int Cola_enlazada::primero(){
    //El primer elemento de la lista será el que se encuentre en la última posición, dada por el número de elementos -1
    return this->cola.obtener(0);
}

bool Cola_enlazada::esvacia(){
    return this->cola.es_vacia();
}

int Cola_enlazada::longitud(){
    return cola.longitud();
}
