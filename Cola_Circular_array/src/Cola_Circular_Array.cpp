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


        //Creamos un array auxiliar para copiar el contenido del array antiguo
        int* array_aux = new int[this->tam];

        //Ampliamos el array, en el cual los elementos se copiaran en las mismas posiciones que estaban anteriormente
        this->cola_circular.aumentar_longitud(this->tam+10);

        //Copiamos los elementos del array al array auxiliar, para poder reubicarlos en el nuevo sin perderlos
        for(int i = 0; i < this->tam; i++){
            array_aux[i] = this->cola_circular.obtener(i);
        }

        //Reubicamos los datos en el array nuevo, de forma que queden ordenados linealmente
        //El inicio quedará en la posición 1, el final en numelementos... etc
        //Debemos recorrer el array de forma circular (usando el inicio), pero insertarlos de forma lineal, empezando por el 0
        for(int i = 0; i < this->num_elementos; i++){
                //Obtenemos el valor de la posición a la que apunta el inicio
                int valor = array_aux[inicio];

                //Modificamos el array ampliado insertando el valor obtenido en su posición lineal
                this->cola_circular.modificar(i, valor);

                //Incrementamos el inicio para acceder a la siguiente posición
                this->inicio++;

                //Si hemos llegado al final del array, pero aún quedan elementos (el bucle no ha terminado), seguimos buscando los siguientes por el inicio
                if(this->inicio == this->tam) this->inicio = 0;
        }

        //Liberamos el array auxiliar
        delete []array_aux;

        //Actualizamos el tamaño a su nueva capacidad, y ajustamos el inicio y el fin a sus actuales posiciones
        this->tam = this->cola_circular.capacidad();
        this->inicio=0;
        this->final = this->num_elementos;


        //Ponemos las posiciones vacías a -1 para poderlas distinguir
        //NOTA: esto no es necesario para el TAD, es simplemente por propósito didactico
        for(int i = this->num_elementos; i < this->tam; i++){
            this->cola_circular.modificar(i,-1);
        }
    }

    //Una vez redimensionado el array (en caso de necesitarlo), insertamos el elemento
    if(this->num_elementos < this->tam){
        this->cola_circular.insertar_pos(this->final, dato);

        //El final se calculará mediante el módulo, para que, en caso de llegar a la última posición del array, si queda espacio libre siga por el inicio del mismo
        this->final = (this->final+1)%this->tam;

        this->num_elementos++;
    }


}

void Cola_Circular_Array::desencolar(){

    //Ponemos la posición a -1, para señalar que se ha eliminado
    //NOTA: no es necesario para el TAD, es solo para propósito didáctico
    this->cola_circular.modificar(this->inicio, -1);

    //Para desencolar, movemos el inicio una posición hacia delante.
    //No hace falta desplazar los elementos, sino que la posición se sobreescribirá cuando encolemos algo nuevo en la misma
    this->inicio++;

    //Si al incrementar el inicio, llegas al final del array, pon el inicio en la primera posición del array, para que los siguientes elementos se encolen al principio del array
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
    return this->num_elementos;
}

int Cola_Circular_Array::capacidad(){
    return this->cola_circular.capacidad();
}


//NOTA: este método no forma parte del TAD, sino que lo usaremos para mostrar el contenido interno del array, para comprobar si los elementos se están insertando circularmente
//El TAD Cola no permite ser recorrido, salvo extrayendo los elementos
void Cola_Circular_Array::mostrar(){
    this->cola_circular.mostrar();


    std::cout<<"\n";
}
