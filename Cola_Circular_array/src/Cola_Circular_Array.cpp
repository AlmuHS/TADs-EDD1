#include "Cola_Circular_Array.h"

#include <iostream>

Cola_Circular_Array::Cola_Circular_Array()
{
    //ctor
    this->final = 0;
    this->inicio = 0;
    this->num_elementos = 0;
    this->tam = cola_circular.capacidad();
}

void Cola_Circular_Array::encolar(int dato){
    if(this->num_elementos == this->tam){

        this->cola_circular.aumentar_longitud(this->tam+10);

        int i;
        for(i = 0; i < this->num_elementos; i++){

            if(i == this->inicio){
                int valor = this->cola_circular.obtener(this->inicio);
                this->cola_circular.modificar(i, valor);
                this->inicio++;

                if(this->inicio == this->tam) this->inicio = 0;
            }
        }

        //Ponemos las posiciones vacías a -1 para poderlas distinguir
        /*for(int j = i; j < this->tam; j++){
            this->cola_circular.modificar(j, -1);
        }*/

        this->inicio=0;
        this->final = this->num_elementos;
    }

    this->tam = this->cola_circular.capacidad();

    if(this->num_elementos < this->tam){
        this->cola_circular.insertar_pos(this->final, dato);
        this->final = (this->final+1)%this->tam;

        this->num_elementos++;
    }


}

void Cola_Circular_Array::desencolar(){
    this->cola_circular.modificar(this->inicio, -1);
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
    return this->tam;
}

int Cola_Circular_Array::capacidad(){
    return this->cola_circular.capacidad();
}


void Cola_Circular_Array::mostrar(){
    this->cola_circular.mostrar();


    std::cout<<"\n";
}
