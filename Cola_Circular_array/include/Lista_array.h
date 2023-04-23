#ifndef LISTA_ARRAY_H
#define LISTA_ARRAY_H


class Lista_array
{
    int* array_ptr;
    int tam;
    int num_elementos;

    public:
        Lista_array();
        ~Lista_array();

        void aumentar_longitud(int longitud);

        void insertar(int valor);
        void insertar_intermedio(int pos, int valor);
        void insertar_pos(int pos, int valor);
        void eliminar(int valor);
        void eliminar_pos(int pos);
        int buscar(int valor);
        int obtener(int pos);
        bool esvacio();
        void modificar(int pos, int valor);
        void mostrar();
        int longitud();
        int capacidad();
};

#endif // LISTA_ARRAY_H
