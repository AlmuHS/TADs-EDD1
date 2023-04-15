#include "Pila_array.h"

Pila_array::Pila_array()
{
    this->Tope = -1;
    this->capacidad = lista.capacidad();
}

void Pila_array::apilar(int dato){
    lista.insertar(dato);
    this->Tope = lista.longitud()-1;
}

void Pila_array::desapilar(){
    lista.eliminar_final();
    this->Tope = lista.longitud()-1;
}

bool Pila_array::esvacia(){
    return lista.esvacio();
}

int Pila_array::longitud(){
    return lista.longitud();
}

int Pila_array::cima(){
    int dato = lista.obtener(this->Tope);

    return dato;
}
