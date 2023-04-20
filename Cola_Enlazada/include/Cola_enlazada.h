#ifndef COLA_ENLAZADA_H
#define COLA_ENLAZADA_H

#include "Cola_enlazada.h"
#include "Lista_enlazada.h"

class Cola_enlazada
{
    Lista_enlazada cola;
    int num_elementos;


    public:
        Cola_enlazada();

        void encolar(int dato);
        void desencolar();
        int primero();

        bool esvacia();
        int longitud();
};

#endif // COLA_ENLAZADA_H
