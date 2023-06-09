#include <iostream>

using namespace std;

#include "Cola_enlazada.h"

int main()
{
    Cola_enlazada cola;

    for(int i = 0; i < 10; i++){
        cola.encolar(i);
    }

    while(!cola.esvacia()){
        int dato = cola.primero();
        cola.desencolar();
        std::cout<<dato<<" ";
    }
    std::cout<<"\n";

    for(int i = 10; i < 20; i++){
        std::cout<<"Encolando "<<i<<std::endl;
        cola.encolar(i);
    }

    for(int i = 5; i < 10; i++){
        std::cout<<"Encolando "<<i<<std::endl;
        cola.encolar(i);
    }

    std::cout<<"Desencolando 8 elementos\n";
    for(int i = 0; i < 7; i++){
        int dato = cola.primero();
        std::cout<<"Desencolando "<<dato<<std::endl;
        cola.desencolar();
    }


    std::cout<<"\nVaciando la cola\n";
    while(!cola.esvacia()){
        int dato = cola.primero();
        cola.desencolar();
        std::cout<<dato<<" ";
    }

    return 0;
}
