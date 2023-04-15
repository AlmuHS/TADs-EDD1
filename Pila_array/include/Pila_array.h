#ifndef PILA_ARRAY_H
#define PILA_ARRAY_H

#include "Lista_array.h"

class Pila_array
{
    Lista_array lista;
    int Tope;
    int capacidad;

    public:
        Pila_array();

        void apilar(int dato);
        void desapilar();

        bool esvacia();
        int cima();
        int longitud();

    protected:

    private:
};

#endif // PILA_ARRAY_H
