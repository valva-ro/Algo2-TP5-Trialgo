#ifndef TP5_TRIALGO_NODOABB_H
#define TP5_TRIALGO_NODOABB_H

#include <iostream>

using namespace std;

template <typename Tipo>
class NodoABB {

    private:
        NodoABB<Tipo>* izquierda;
        NodoABB<Tipo>* derecha;
        NodoABB<Tipo>* padre;
        Tipo dato;

    public:
        NodoABB(Tipo dato);
        Tipo obtenerDato();
        NodoABB<Tipo>* obtenerIzquierda();
        NodoABB<Tipo>* obtenerDerecha();
        NodoABB<Tipo>* obtenerPadre();
        void asignarDato(Tipo dato);
        void asignarIzquierda(NodoABB<Tipo>* izquierda);
        void asignarDerecha(NodoABB<Tipo>* derecha);
        void asignarPadre(NodoABB<Tipo>* padre);
        bool esHoja();
        bool soloHijoDerecha();
        bool soloHijoIzquierda();
};

/* ------------------------------- Public Methods ------------------------------- */
template <typename Tipo>
NodoABB<Tipo>:: NodoABB(Tipo dato) {
    this->dato = dato;
    izquierda = NULL;
    derecha = NULL;
    padre = NULL;
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
    return (derecha == NULL && izquierda == NULL);
}

/////////////////////////////////////////////
template <typename Tipo>
bool NodoABB<Tipo>:: soloHijoIzquierda() {
    return (derecha == NULL && izquierda != NULL);
}

/////////////////////////////////////////////
template <typename Tipo>
bool NodoABB<Tipo>:: soloHijoDerecha() {
    return (derecha != NULL && izquierda == NULL);
}
/* ------------------------------------------------------------------------------ */

#endif //TP5_TRIALGO_NODOABB_H
