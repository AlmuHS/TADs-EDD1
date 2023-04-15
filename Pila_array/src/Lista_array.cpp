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

void Lista_array::aumentar_longitud(int incremento){

    //Reservamos memoria para un nuevo array, de un tamaño superior al actual en la cantidad indicada por el incremento
    //La dirección de memoria del nuevo array se guardará en el puntero nuevo_array
    int *nuevo_array = new int[this->tam+incremento];

    //Una vez reservada la memoria, copiamos los elementos del antiguo array al nuevo
    for(int i = 0; i < this->num_elementos; i++){
        nuevo_array[i] = this->array_ptr[i];
    }

    //Liberamos la memoria del antiguo array
    delete []this->array_ptr;

    //Asignamos al puntero array_ptr la dirección del nuevo array
    this->array_ptr = nuevo_array;

    //Actualizamos el tamaño del array
    this->tam += incremento;
}

bool Lista_array::esvacio(){
    return (this->num_elementos == 0);
}

void Lista_array::insertar(int valor){

    //Si quedan menos de 4 posiciones libres, ampliamos el array
    if(this->num_elementos >= this->tam - 4){
        //incrementamos su longitud en la mitad de su longitud actual (longitud + longitud/2)
        //Dado que el parámetro del método es el incremento de tamaño, este será tam/2
        this->aumentar_longitud(this->tam/2);
    }

    //Hayamos ampliado o no, insertamos el elemento en la primera posición libre de la lista
    //Dado que las posiciones del array empiezan por 0, la primera posición libre será el mismo valor que la cantidad de elementos insertados
    this->array_ptr[this->num_elementos] = valor;

    //Incrementamos el número de elementos insertados
    this->num_elementos++;
}

void Lista_array::insertar_intermedio(int pos, int valor){

    //Si quedan menos de 4 posiciones libres, ampliamos el array
    if(this->num_elementos >= this->tam - 4){
        this->aumentar_longitud(this->tam*2);
    }

    //Si la posición indicada no excede el máximo de posiciones del array, insertamos allí
    if(pos < this->tam){

        //Para insertar en una posición intermedia, desplazamos los elementos posteriores a la derecha
        //Para hacer el recorrido mas fácil, iremos de derecha a izquierda.
        //Al haber posiciones libres por la derecha, podemos hacer la copia del valor a su posición posterior sin peligro de sobreescribir alguno ya existente
        for(int i = this->num_elementos; i >=pos; i--){
            this->array_ptr[i] = this->array_ptr[i-1];
        }

        //Una vez desplazados todos los elementos posteriores a la derecha, insertamos en la posición requerida
        this->array_ptr[pos] = valor;
    }

    //Incrementamos el número de elementos insertados
    this->num_elementos++;
}



int Lista_array::buscar(int valor){
    int i = 0;
    while(this->array_ptr[i] != valor && i < this->num_elementos) i++;

    if(i < this->num_elementos) return i;
    return -1;
}

void Lista_array::eliminar(int valor){

    int pos;

    //Puede haber múltiples elementos con dicho valor, por lo que usaremos un bucle repitiendo el ciclo hasta borrar todos
    do{
        //Buscamos si existe alguna posición con dicho valor
        //En caso de existir, pos almacenará su posición
        pos = this->buscar(valor);

        //Si existe, invocamos al método eliminar_pos con la posición obtenida en la búsqueda, para eliminarlo
        if(pos != -1){
            this->eliminar_pos(pos);
        }
    //Repetimos hasta no encontrar ninguna posición con dicho valor
    }while(pos != -1);
}

void Lista_array::eliminar_pos(int pos){

    //Solo borramos si la posición indicada es válida
    if(pos >= 0 && pos < this->num_elementos){

        //Desplazamos todos los elementos posteriores a dicha posicion hacia la izquierda
        //En este caso, dado que el desplazamiento es a la izquierda, realizaremos el recorrido de forma ascendente
        for(int i = pos; i < this->num_elementos; i++){
            this->array_ptr[i] = this->array_ptr[i+1];
        }

        //Decrementamos el número de elementos
        this->num_elementos--;
    }
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
