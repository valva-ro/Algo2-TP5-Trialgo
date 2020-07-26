#ifndef TP5_TRIALGO_NODOABB_H
#define TP5_TRIALGO_NODOABB_H

#include <iostream>

using namespace std;

template <typename Puntero, typename Dato>
class NodoABB {

    // Atributos
    private:
        NodoABB<Puntero, Dato>* izquierda;
        NodoABB<Puntero, Dato>* derecha;
        NodoABB<Puntero, Dato>* padre;
        Puntero dato;

    // Metodos
    public:

        //  PRE: -
        // POST: Construye el nodo con el dato recibido por parametro
        NodoABB(Puntero dato);

        //  PRE: -
        // POST: Libera la memoria del dato
        ~NodoABB();

        //  PRE: -
        // POST: Devuelve el puntero
        Puntero obtenerPuntero();

        //  PRE: -
        // POST: Devuelve el dato al que apunta el puntero
        Dato obtenerDato();

        //  PRE: -
        // POST: Devuelve el puntero izquierdo
        NodoABB<Puntero, Dato>* obtenerIzquierda();

        //  PRE: -
        // POST: Devuelve el puntero derecho
        NodoABB<Puntero, Dato>* obtenerDerecha();

        //  PRE: -
        // POST: Devuelve el puntero padre
        NodoABB<Puntero, Dato>* obtenerPadre();

        //  PRE: -
        // POST: Le asigna dato al atributo dato
        void asignarDato(Puntero dato);

        //  PRE: -
        // POST: Le asigna izquierda al atributo izquierda
        void asignarIzquierda(NodoABB<Puntero, Dato>* izquierda);

        //  PRE: -
        // POST: Le asigna derecha al atributo derecha
        void asignarDerecha(NodoABB<Puntero, Dato>* derecha);

        //  PRE: -
        // POST: Le asigna padre al atributo padre
        void asignarPadre(NodoABB<Puntero, Dato>* padre);

        //  PRE: -
        // POST: Devuelve true si el nodo es hoja, de lo contrario false
        bool esHoja();

        //  PRE: -
        // POST: Devuelve true si el nodo tiene hijo a la derecha, de lo contrario false
        bool soloHijoDerecha();

        //  PRE: -
        // POST: Devuelve true si el nodo tiene hijo a la izquierda, de lo contrario false
        bool soloHijoIzquierda();
};

/* ------------------------------- Metodos Publicos ------------------------------- */
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>:: NodoABB(Puntero dato) {
    this->dato = dato;
    izquierda = 0;
    derecha = 0;
    padre = 0;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>:: ~NodoABB<Puntero, Dato>() {
    delete dato;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
Puntero NodoABB<Puntero, Dato>:: obtenerPuntero() {
    return dato;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
Dato NodoABB<Puntero, Dato>:: obtenerDato() {
    return *dato;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* NodoABB<Puntero, Dato>:: obtenerIzquierda() {
    return izquierda;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* NodoABB<Puntero, Dato>:: obtenerDerecha() {
    return derecha;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* NodoABB<Puntero, Dato>:: obtenerPadre() {
    return padre;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
void NodoABB<Puntero, Dato>:: asignarDato(Puntero dato) {
    this->dato = dato;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
void NodoABB<Puntero, Dato>:: asignarIzquierda(NodoABB<Puntero, Dato>* izquierda) {
    this->izquierda = izquierda;
}


/////////////////////////////////////////////
template <typename Puntero, typename Dato>
void NodoABB<Puntero, Dato>:: asignarDerecha(NodoABB<Puntero, Dato>* derecha) {
    this->derecha = derecha;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
void NodoABB<Puntero, Dato>:: asignarPadre(NodoABB<Puntero, Dato>* padre) {
    this->padre = padre;
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
bool NodoABB<Puntero, Dato>:: esHoja() {
    return (derecha == 0 && izquierda == 0);
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
bool NodoABB<Puntero, Dato>:: soloHijoIzquierda() {
    return (derecha == 0 && izquierda != 0);
}

/////////////////////////////////////////////
template <typename Puntero, typename Dato>
bool NodoABB<Puntero, Dato>:: soloHijoDerecha() {
    return (derecha != 0 && izquierda == 0);
}

/* ------------------------------------------------------------------------------ */

#endif //TP5_TRIALGO_NODOABB_H