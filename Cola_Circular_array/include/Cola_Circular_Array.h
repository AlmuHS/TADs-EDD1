#ifndef COLA_CIRCULAR_ARRAY_H
#define COLA_CIRCULAR_ARRAY_H

#include "Lista_array.h"

class Cola_Circular_Array
{
    Lista_array cola_circular;
    int inicio, final;
    int tam, num_elementos;

    public:
        Cola_Circular_Array();

        void encolar(int dato);
        void desencolar();

        bool esvacia();
        int primero();
        int longitud();
};

#endif // COLA_CIRCULAR_ARRAY_H
