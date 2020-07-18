#ifndef COLA_H
#define COLA_H

#include "Nodo.h"
#include <iostream>

using namespace std;

template < typename Tipo >
class Cola {

    // Atributos
    private:
        Nodo<Tipo>* primero;
        Nodo<Tipo>* ultimo;
        int elementos;

    // Metodos
    public:

        //  PRE: -
        // POST: Construye un objeto de tipo Cola con primero y ultimo apuntando a NULL
        Cola();

        //  PRE: La cola esta creada
        // POST: Libera los recursos utilizados
        ~Cola();

        //  PRE: -
        // POST: Devuelve la cantidad de elementos
        int obtenerElementos();

        //  PRE: -
        // POST: Devuelve el dato almacenado en el primer nodo
        Tipo obtenerPrimero();

        //  PRE: -
        // POST: Encola el dato
        void encolar(Tipo dato);

        //  PRE: -
        // POST: Desencola el dato
        void desencolar();

        //  PRE: -
        // POST: Devuelve true si la cola esta vacia, de lo contrario false
        bool vacia();
};

template < typename Tipo >
Cola<Tipo>:: Cola () {
    primero = 0;
    ultimo = 0;
    elementos = 0;
}
template < typename Tipo >
Cola<Tipo>:: ~Cola() {
    while (!vacia())
        desencolar();
}

template < typename Tipo >
int Cola<Tipo>:: obtenerElementos() {
    return elementos;
}

template < typename Tipo >
Tipo Cola<Tipo>:: obtenerPrimero() {
    return primero->obtenerDato();
}

template < typename Tipo >
bool Cola<Tipo>:: vacia() {
    return elementos == 0;
}

template < typename Tipo >
void Cola<Tipo>:: encolar(Tipo dato) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(dato);
    if (vacia())
        primero = nuevoNodo;
    else
        ultimo->setNext(nuevoNodo);
    ultimo = nuevoNodo;
    elementos++;
}

template < typename Tipo >
void Cola<Tipo>:: desencolar() {
    if (!vacia()) {
        Nodo<Tipo>* aux = primero;
        if (primero == ultimo)
            primero = ultimo = 0;
        else
            primero = primero->getNext();
        delete aux;
        elementos--;
    }
}

#endif //COLA_H