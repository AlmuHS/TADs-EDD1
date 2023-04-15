#include <iostream>
#include <cstdlib>

#include "include/Lista_array.h"




int main()
{
    Lista_array lista;

    for(int i = 0; i < 20; i++){
        lista.insertar(i);
    }

    lista.mostrar();
    std::cout<<"El tamaño de la lista es "<<lista.longitud();
    std::cout<<"\nLa capacidad de la lista es "<<lista.capacidad()<<"\n";

    for(int i = 0; i < 30; i++){
        lista.insertar(i*2);
    }

    lista.mostrar();
    std::cout<<"El tamaño de la lista es "<<lista.longitud();
    std::cout<<"\nLa capacidad de la lista es "<<lista.capacidad()<<"\n";

    for(int i = 0; i < lista.longitud()/2; i++){
        int pos = rand()%(lista.longitud());
        lista.eliminar_pos(pos);
    }

    lista.mostrar();
    std::cout<<"El tamaño de la lista es "<<lista.longitud();
    std::cout<<"\nLa capacidad de la lista es "<<lista.capacidad()<<"\n";

    std::cout<<"El elemento de la 28a posicion es "<<lista.obtener(28)<<"\n";
    std::cout<<"El elemento de la 100 posicion es "<<lista.obtener(100)<<"\n";


    std::cout<<"\nInsertando en la posicion 20 el valor 200\n";
    lista.insertar_intermedio(20, 200);
    lista.mostrar();

    std::cout<<"\nInsertando en una posicion no existente\n";
    lista.insertar_intermedio(90, 105);
    lista.mostrar();


    return 0;
}
