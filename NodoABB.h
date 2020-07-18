#ifndef TP5_TRIALGO_NODOABB_H
#define TP5_TRIALGO_NODOABB_H

#include <iostream>

using namespace std;

template <typename Tipo>
class NodoABB {

    // Atributos
    private:
        NodoABB<Tipo>* izquierda;
        NodoABB<Tipo>* derecha;
        NodoABB<Tipo>* padre;
        Tipo dato;

    // Metodos
    public:

        //  PRE: -
        // POST: Construye el nodo con el dato recibido por parametro
        NodoABB(Tipo dato);

        //  PRE: -
        // POST: Devuelve el dato del nodo
        Tipo obtenerDato();

        //  PRE: -
        // POST: Devuelve el puntero izquierdo
        NodoABB<Tipo>* obtenerIzquierda();

        //  PRE: -
        // POST: Devuelve el puntero derecho
        NodoABB<Tipo>* obtenerDerecha();

        //  PRE: -
        // POST: Devuelve el puntero padre
        NodoABB<Tipo>* obtenerPadre();

        //  PRE: -
        // POST: Le asigna dato al atributo dato
        void asignarDato(Tipo dato);

        //  PRE: -
        // POST: Le asigna izquierda al atributo izquierda
        void asignarIzquierda(NodoABB<Tipo>* izquierda);

        //  PRE: -
        // POST: Le asigna derecha al atributo derecha
        void asignarDerecha(NodoABB<Tipo>* derecha);

        //  PRE: -
        // POST: Le asigna padre al atributo padre
        void asignarPadre(NodoABB<Tipo>* padre);

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

/* ------------------------------- Public Methods ------------------------------- */
template <typename Tipo>
NodoABB<Tipo>:: NodoABB(Tipo dato) {
    this->dato = dato;
    izquierda = 0;
    derecha = 0;
    padre = 0;
}

/////////////////////////////////////////////
template <typename Tipo>
Tipo NodoABB<Tipo>:: obtenerDato() {
    return dato;
}

/////////////////////////////////////////////
template <typename Tipo>
NodoABB<Tipo>* NodoABB<Tipo>:: obtenerIzquierda() {
    return izquierda;
}

/////////////////////////////////////////////
template <typename Tipo>
NodoABB<Tipo>* NodoABB<Tipo>:: obtenerDerecha() {
    return derecha;
}

/////////////////////////////////////////////
template <typename Tipo>
NodoABB<Tipo>* NodoABB<Tipo>:: obtenerPadre() {
    return padre;
}

/////////////////////////////////////////////
template <typename Tipo>
void NodoABB<Tipo>:: asignarDato(Tipo dato) {
    this->dato = dato;
}

/////////////////////////////////////////////
template <typename Tipo>
void NodoABB<Tipo>:: asignarIzquierda(NodoABB<Tipo>* izquierda) {
    this->izquierda = izquierda;
}


/////////////////////////////////////////////
template <typename Tipo>
void NodoABB<Tipo>:: asignarDerecha(NodoABB<Tipo>* derecha) {
    this->derecha = derecha;
}

/////////////////////////////////////////////
template <typename Tipo>
void NodoABB<Tipo>:: asignarPadre(NodoABB<Tipo>* padre) {
    this->padre = padre;
}

/////////////////////////////////////////////
template <typename Tipo>
bool NodoABB<Tipo>:: esHoja() {
    return (derecha == 0 && izquierda == 0);
}

/////////////////////////////////////////////
template <typename Tipo>
bool NodoABB<Tipo>:: soloHijoIzquierda() {
    return (derecha == 0 && izquierda != 0);
}

/////////////////////////////////////////////
template <typename Tipo>
bool NodoABB<Tipo>:: soloHijoDerecha() {
    return (derecha != 0 && izquierda == 0);
}
/* ------------------------------------------------------------------------------ */

#endif //TP5_TRIALGO_NODOABB_H
