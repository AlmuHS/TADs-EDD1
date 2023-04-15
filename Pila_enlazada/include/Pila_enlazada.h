#ifndef PILA_ENLAZADA_H
#define PILA_ENLAZADA_H

#include "Lista_enlazada.h"

class Pila_enlazada
{
    Lista_enlazada lista;
    int num_elementos;

    public:
        Pila_enlazada();

        void apilar(int dato);
        void desapilar();
        bool esvacia();
        int cima();
        int longitud();
};

#endif // PILA_ENLAZADA_H
