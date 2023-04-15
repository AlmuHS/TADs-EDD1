#include <iostream>
#include "include/Lista_enlazada.h"


int main()
{
    Lista_enlazada lista;

    if(lista.es_vacia()) std::cout<<"La lista está vacía\n";

    std::cout<<"\nInsertando 10 elementos\n";
    for(int i = 0; i < 10; i++){
        lista.insertar_final(i*4);
    }
    lista.mostrar();

    std::cout<<"El contenido de la posicion 3 es "<<lista.obtener(3)<<std::endl;

    std::cout<<"\nInsertando valor 256 en posicion 7\n";
    lista.insertar_intermedio(7, 256);
    lista.mostrar();
    std::cout<<"\nLa longitud de la lista es "<<lista.longitud()<<"\n";

    std::cout<<"\nEliminando valor de la posicion 4\n";
    lista.eliminar(4);
    lista.mostrar();

    std::cout<<"\nLa longitud de la lista es "<<lista.longitud()<<"\n";

    std::cout<<"\nCambiando el contenido de la posición 3 al valor 6\n";
    lista.modificar(3, 6);
    lista.mostrar();

    std::cout<<"\nInsertando el valor 48 al inicio de la lista\n";
    lista.insertar_inicio(48);
    lista.mostrar();

    std::cout<<"\nInsertando el valor 78 en la posicion 6\n";
    lista.insertar_intermedio(6, 78);
    lista.mostrar();

    std::cout<<"\nEliminando el último elemento de la lista\n";
    lista.eliminar_final();
    lista.mostrar();

    std::cout<<"\nInsertando el numero 56 al final de la lista\n";
    lista.insertar_final(56);
    lista.mostrar();

    std::cout<<"\nInsertando el numero 54 al final de la lista\n";
    lista.insertar_final(54);
    lista.mostrar();
    std::cout<<"\nLa capacidad de la lista es "<<lista.longitud()<<"\n";

    std::cout<<"\nEliminando el tercer elemento de la lista\n";
    lista.eliminar(2);
    lista.mostrar();

    std::cout<<"\nEliminando el 100 elemento de la lista\n";
    lista.eliminar(100);
    lista.mostrar();

    std::cout<<"\nVaciando la lista\n";
    while(!lista.es_vacia()){
        lista.eliminar_final();
        lista.mostrar();
        std::cout<<"La capacidad de la lista es "<<lista.longitud()<<"\n\n";
    }
    lista.mostrar();
    if(lista.es_vacia()) std::cout<<"La lista está vacía";

    std::cout<<"\nInsertando el valor 1 en la lista vacia\n";
    lista.insertar_final(1);
    lista.mostrar();

    std::cout<<"\nInsertando 7 nuevos elementos\n";
    for(int i = 0; i < 7; i++){
        lista.insertar_final(i*4);
    }
    lista.mostrar();

    std::cout<<"La longitud de la lista es "<<lista.longitud()<<"\n";

    std::cout<<"\nInsertando 4 elementos al inicio\n";
    for(int i = 0; i < 4; i++){
        lista.insertar_inicio(i*7);
        //lista.insertar_intermedio(0, i*7);
    }
    lista.mostrar();

    std::cout<<"\nBuscando el elemento con valor 4\n";
    int pos = lista.buscar(4);
    std::cout<<"El elemento está en la posicion "<<pos<<std::endl;

    std::cout<<"\nBuscando el elemento con valor 24\n";
    pos = lista.buscar(24);
    std::cout<<"El elemento está en la posicion "<<pos<<std::endl;

    std::cout<<"\nBuscando el elemento con valor 1000\n";
    pos = lista.buscar(1000);
    std::cout<<"El elemento está en la posicion "<<pos<<std::endl;

    std::cout<<"\nObteniendo el elemento de la posicion 8\n";
    int valor = lista.obtener(8);
    std::cout<<"El valor de la posicion 8 es "<<valor<<std::endl;

    std::cout<<"\nObteniendo el elemento de la posicion 28\n";
    valor = lista.obtener(28);
    std::cout<<"El valor de la posicion 28 es "<<valor<<std::endl;


    std::cout<<"\nEliminando el elemento inicial\n";
    lista.eliminar_inicio();
    lista.mostrar();

    std::cout<<"\nVaciando la lista a partir de los elementos iniciales\n";
    while(!lista.es_vacia()){
        lista.eliminar_inicio();
        lista.mostrar();
    }

    if(lista.es_vacia()) std::cout<<"La lista está vacía\n";

    return 0;
}
