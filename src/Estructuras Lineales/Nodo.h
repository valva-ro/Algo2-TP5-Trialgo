#ifndef NODO_H
#define NODO_H

#include <iostream>

template <typename Tipo>
class Nodo {

private:
    Tipo dato;
    Nodo* pSig;

public:

    // PRE: -
    // POST: Construye un nodo con el dato recibido
    Nodo(Tipo datoExterno);

    // PRE: -
    // POST: Le asigna pSigExterno a pSig
    void asignarSiguiente(Nodo* pSigExterno);

    // PRE: -
    // POST: Le asigna datoExterno a dato
    void asignarDato(Tipo datoExterno);

    // PRE: -
    // POST: Devuelve dato
    Tipo obtenerDato();

    // PRE: -
    // POST: Devuelve pSig
    Nodo* obtenerSiguiente();
};


/* ------------------------------- Metodos Publicos ------------------------------- */

////////////////////////////////////////////////
template <typename Tipo>
Nodo<Tipo>:: Nodo(Tipo datoExterno) {
    dato = datoExterno;
    pSig = 0;
}

////////////////////////////////////////////////
template <typename Tipo>
void Nodo<Tipo>:: asignarSiguiente(Nodo<Tipo>* pSigExterno) {
    pSig = pSigExterno;
}

////////////////////////////////////////////////
template <typename Tipo>
Nodo<Tipo>* Nodo<Tipo>:: obtenerSiguiente() {
    return pSig;
}

////////////////////////////////////////////////
template <typename Tipo>
void Nodo<Tipo>:: asignarDato(Tipo datoExterno) {
    dato = datoExterno;
}

////////////////////////////////////////////////
template <typename Tipo>
Tipo Nodo<Tipo>:: obtenerDato() {
    return dato;
}

/* ------------------------------------------------------------------------------ */

#endif //NODO_H