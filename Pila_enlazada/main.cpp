#include <iostream>

#include "Pila_enlazada.h"


int main()
{
    Pila_enlazada pila;

    for(int i = 0; i < 10; i++){
        std::cout<<"Apilando "<<i<<"\n";
        pila.apilar(i);
    }

    std::cout<<"\nLa longitud de la pila es "<<pila.longitud()<<"\n";

    while(!pila.esvacia()){
        int dato = pila.cima();
        std::cout<<dato<<" ";
        pila.desapilar();
    }

    if(pila.esvacia()) std::cout<<"La pila está vacía\n";

    for(int i = 0; i < 15; i++){
        std::cout<<"Apilando "<<i<<"\n";
        pila.apilar(i);
    }

    std::cout<<"\nLa longitud de la pila es "<<pila.longitud()<<"\n";

    for(int i = 0; i < 7; i++){
        int dato = pila.cima();
        pila.desapilar();
        std::cout<<"Desapilando "<<dato<<"\n";
    }

    for(int i = 20; i < 28; i++){
        std::cout<<"Apilando "<<i<<"\n";
        pila.apilar(i);
    }

    while(!pila.esvacia()){
        int dato = pila.cima();
        std::cout<<dato<<" ";
        pila.desapilar();
    }
    if(pila.esvacia()) std::cout<<"La pila está vacía\n";
    std::cout<<"\nLa longitud de la pila es "<<pila.longitud()<<"\n";

    return 0;
}
