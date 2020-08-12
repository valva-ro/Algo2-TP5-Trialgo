#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

using namespace std;

template < typename Tipo >
class Pila {

    private:
        Nodo<Tipo>* ultimo;
        int elementos;

    public:
        //  PRE: -
        // POST: Construye un objeto pila con 0 elementos y ultimo apuntando a nullptr
        Pila();

        //  PRE: -
        // POST: Libera los recursos de la pila
        ~Pila();

        //  PRE: -
        // POST: Devuelve la cantidad de elementos de la pila
        int obtenerElementos();

        //  PRE: -
        // POST: Agrega dato al final
        void agregar(Tipo dato);

        //  PRE: -
        // POST: Elimina el ultimo nodo
        void eliminar();

        //  PRE: -
        // POST: Devuelve el dato del ultimo nodo
        Tipo obtenerUltimo();

        //  PRE: -
        // POST: Devuelve verdadero si la pila esta vacia
        bool vacia();
};

template < typename Tipo >
Pila<Tipo>:: Pila () {
    ultimo = nullptr;
    elementos = 0;
}
template < typename Tipo >
Pila<Tipo>:: ~Pila() {
    while (!vacia())
        eliminar();
}

template < typename Tipo >
int Pila<Tipo>:: obtenerElementos() {
    return elementos;
}

template < typename Tipo >
bool Pila<Tipo>:: vacia() {
    return elementos == 0;
}

template < typename Tipo >
void Pila<Tipo>:: agregar(Tipo dato) {
    Nodo<Tipo>* nuevo = new Nodo<Tipo>(dato);
    nuevo->asignarSiguiente(ultimo);
    ultimo = nuevo;
    elementos++;
}

template < typename Tipo >
void Pila<Tipo>:: eliminar() {
    if (!vacia()) {
        Nodo<Tipo>* aux = ultimo;
        ultimo = ultimo->obtenerSiguiente();
        delete aux;
        elementos--;
    }
}

template < typename Tipo >
Tipo Pila<Tipo>:: obtenerUltimo() {
    return ultimo->obtenerDato();
}
#endif //PILA_H