#include <iostream>

using namespace std;

#include "Cola_Circular_Array.h"

int main()
{
    Cola_Circular_Array cola;

    for(int i = 0; i < 20; i++){
        std::cout<<"Encolando "<<i<<std::endl;
        cola.encolar(i);
    }

    cola.mostrar();

    std::cout<<"La longitud de la cola es "<<cola.longitud()<<"\n";
    std::cout<<"La capacidad de la cola es "<<cola.capacidad()<<"\n";


    std::cout<<"Desencolando 4 elementos\n";
    for(int i = 0; i < 4; i++){
        int dato = cola.primero();
        std::cout<<"Desencolando "<<dato<<std::endl;
        cola.desencolar();
    }

    cola.mostrar();


    for(int i = 30; i < 33; i++){
        std::cout<<"Encolando "<<i<<std::endl;
        cola.encolar(i);
        //cola.mostrar();
    }
    std::cout<<"La longitud de la cola es "<<cola.longitud()<<"\n";
    std::cout<<"La capacidad de la cola es "<<cola.capacidad()<<"\n";

    cola.mostrar();

    for(int i = 40; i < 53; i++){
        std::cout<<"Encolando "<<i<<std::endl;
        cola.encolar(i);
        //cola.mostrar();
    }

    std::cout<<"Desencolando 10 elementos\n";
    for(int i = 0; i < 10; i++){
        int dato = cola.primero();
        std::cout<<"Desencolando "<<dato<<std::endl;
        cola.desencolar();
    }

    for(int i = 100; i < 122; i++){
        std::cout<<"Encolando "<<i<<std::endl;
        cola.encolar(i);
        //cola.mostrar();
    }

    std::cout<<"La longitud de la cola es "<<cola.longitud()<<"\n";
    std::cout<<"La capacidad de la cola es "<<cola.capacidad()<<"\n";

    cola.mostrar();


    std::cout<<"\nVaciando la cola\n";
    while(!cola.esvacia()){
        int dato = cola.primero();
        cola.desencolar();
        std::cout<<dato<<" ";
    }




    return 0;
}
