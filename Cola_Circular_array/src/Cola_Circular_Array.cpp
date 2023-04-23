#include "Cola_Circular_Array.h"

Cola_Circular_Array::Cola_Circular_Array()
{
    //ctor
    this->final = 0;
    this->inicio = 0;
    this->num_elementos = 0;
    this->tam = cola_circular.capacidad();
}

void Cola_Circular_Array::encolar(int dato){
    if(this->num_elementos < this->tam){
        this->cola_circular.insertar_pos(this->final, dato);
        this->final = (this->final+1)%this->tam;

        this->num_elementos++;
    }
}

void Cola_Circular_Array::desencolar(){
    this->inicio++;
    if(this->inicio == this->tam) this->inicio = 0;
    this->num_elementos--;

}

bool Cola_Circular_Array::esvacia(){
    return (this->num_elementos == 0);
}

int Cola_Circular_Array::primero(){
    return this->cola_circular.obtener(this->inicio);
}

int Cola_Circular_Array::longitud(){
    return this->cola_circular.longitud();
}
