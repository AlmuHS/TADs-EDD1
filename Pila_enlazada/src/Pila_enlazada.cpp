#include "Pila_enlazada.h"

Pila_enlazada::Pila_enlazada()
{
    //ctor
    this->num_elementos = 0;
}

void Pila_enlazada::apilar(int dato){
    lista.insertar_inicio(dato);
    this->num_elementos = lista.longitud();
}

void Pila_enlazada::desapilar(){
    lista.eliminar_inicio();
    this->num_elementos = lista.longitud();
}


int Pila_enlazada::cima(){
    int dato = lista.obtener(0);

    return dato;
}

int Pila_enlazada::longitud(){
    return lista.longitud();
}

bool Pila_enlazada::esvacia(){
    return lista.es_vacia();
}
