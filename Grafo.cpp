//
// Created by alexteper on 2/8/20.
//

#include "Grafo.h"

const int INFINITO = 100000;
Grafo::Grafo() {
    this->distanciaMatriz = NULL;
    this->elementos= 0;
    this->precioMatriz= NULL;
    this->vertices =NULL;
}

Grafo::Grafo(Matriz<int> *precio, Matriz<float> *distancia, int elementos, Lista<string> *vertices) {
    this->distanciaMatriz = distancia;
    this->elementos= vertices->getTam();
    this->precioMatriz= precio;
    this->vertices =vertices;
}

Grafo::~Grafo() {

}

bool Grafo::existeArista(string origen, string destino) {
    bool exsiste= true;
    if (existeVertice(origen)&&existeVertice(destino)){
        if ((distanciaMatriz->obtenerValor(vertices->getPosicion(origen),vertices->getPosicion(destino))>INFINITO)&&(precioMatriz->obtenerValor(vertices->getPosicion(origen),vertices->getPosicion(destino))>INFINITO))
            exsiste = false;
    }

    return exsiste;
}

bool Grafo::existeVertice(string vertice) {
    bool exsiste;
    if (vertices->getPosicion(vertice) != -1) // getPosicion devuelve un -1 si no exsiste ese elemento en la lista
        exsiste = true;
    else
        exsiste= false;

    return  exsiste;
}

float Grafo::obtenerDistancia(string origen, string destino) {
    float distancia= INFINITO;
    if (existeArista(origen,destino)){
        distancia= distanciaMatriz->obtenerValor(vertices->getPosicion(origen),vertices->getPosicion(destino));
    }

    return  distancia;
}

int Grafo::obtenerPrecio(string origen, string destino) {
    int precio = INFINITO;
    if(existeArista(origen,destino)){
        precio= precioMatriz->obtenerValor(vertices->getPosicion(origen),vertices->getPosicion(destino));
    }

    return precio;

}

void Grafo::insertarArista(string origen, string destino, int precio, float distancia) {

}