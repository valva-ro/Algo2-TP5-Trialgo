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
    Pila();
    ~Pila();
    int obtenerElementos();
    void agregar(Tipo dato);
    void eliminar();
    Tipo obtenerUltimo();
    bool vacia();
};

template < typename Tipo >
Pila<Tipo>:: Pila () {
    ultimo = 0;
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
    if (!vacia())
        return ultimo->obtenerDato();
}
#endif //PILA_H