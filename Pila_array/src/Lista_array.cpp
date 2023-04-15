/*----------------------------------------|
| Autor: 				  |
| Fecha:                                  |
| Versión:                                |
|-----------------------------------------|
| Descripción del Programa:               |
|                                         |
|----------------------------------------*/
// Librerías
#include <iostream>

// Implementación de Procedimientos y Funciones
#include "../include/Lista_array.h"

Lista_array::Lista_array()
{
    this->array_ptr = new int[20];
    this->tam = 20;
    this->num_elementos = 0;
}

Lista_array::~Lista_array()
{
    delete []this->array_ptr;
}

void Lista_array::aumentar_longitud(int longitud){
    int *nuevo_array = new int[this->tam+longitud];

    for(int i = 0; i < this->num_elementos; i++){
        nuevo_array[i] = this->array_ptr[i];
    }

    delete this->array_ptr;
    this->array_ptr = nuevo_array;

    this->tam = longitud;
}

bool Lista_array::esvacio(){
    return (this->num_elementos == 0);
}

void Lista_array::insertar(int valor){
    if(this->num_elementos >= this->tam - 4){
        this->aumentar_longitud(this->tam*2);
    }

    this->array_ptr[this->num_elementos] = valor;
    this->num_elementos++;
}

void Lista_array::insertar_intermedio(int pos, int valor){
    if(pos < this->tam && this->num_elementos < this->tam){

        for(int i = this->num_elementos; i >=pos; i--){
            this->array_ptr[i] = this->array_ptr[i-1];
        }

        this->array_ptr[pos] = valor;
    }


    if(this->num_elementos >= this->tam - 4){
        this->aumentar_longitud(this->tam*2);
    }

    this->num_elementos++;
}



int Lista_array::buscar(int valor){
    int i = 0;
    while(this->array_ptr[i] != valor && i < this->num_elementos) i++;

    if(i < this->num_elementos) return i;
    else return -1;
}

void Lista_array::eliminar(int valor){
    int pos = this->buscar(valor);

    if(pos != -1){
        this->eliminar_pos(pos);
    }
}

void Lista_array::eliminar_pos(int pos){
    if(pos >= 0 && pos < this->num_elementos){
        for(int i = this->num_elementos; i < pos; i--){
            this->array_ptr[i] = this->array_ptr[i-1];
        }
        this->num_elementos--;
    }
}

void Lista_array::eliminar_final(){
    this->num_elementos--;
}

int Lista_array::obtener(int pos){
    if(pos < this->num_elementos) return this->array_ptr[pos];
    else return -1;
}

void Lista_array::modificar(int pos, int valor){
    if(pos < this->num_elementos){
        this->array_ptr[pos] = valor;
    }
}

void Lista_array::mostrar(){
    for(int i = 0; i < this->num_elementos; i++){
        std::cout<<this->array_ptr[i]<<" ";
    }
    std::cout<<std::endl;
}

int Lista_array::longitud(){
    return this->num_elementos;
}

int Lista_array::capacidad(){
    return this->tam;
}
