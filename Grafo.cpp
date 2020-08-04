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
    this->elementos = vertices->getTam();
    this->precioMatriz = precio;
    this->vertices = vertices;
}

Grafo::~Grafo() {

}

bool Grafo::existeArista(string origen, string destino) {
    bool existe = false;
    if (existeVertice(origen) && existeVertice(destino)){
        if ((distanciaMatriz->obtenerValor(vertices->getPosicion(origen),vertices->getPosicion(destino)) < INFINITO) &&
            (precioMatriz->obtenerValor(vertices->getPosicion(origen),vertices->getPosicion(destino)) < INFINITO))
            existe = true;
    }
    return existe;
}

bool Grafo::existeVertice(string vertice) {
    bool existe = false;
    if (vertices->getPosicion(vertice) != -1)
        existe = true;
    return existe;
}

float Grafo::obtenerDistancia(string origen, string destino) {
    float distancia = INFINITO;
    if (existeArista(origen, destino))
        distancia= distanciaMatriz->obtenerValor(vertices->getPosicion(origen),vertices->getPosicion(destino));

    return  distancia;
}

int Grafo::obtenerPrecio(string origen, string destino) {
    int precio = INFINITO;
    if (existeArista(origen, destino))
        precio = precioMatriz->obtenerValor(vertices->getPosicion(origen),vertices->getPosicion(destino));

    return precio;
}

void Grafo::insertarArista(string origen, string destino, int precio, float distancia) {
    int posicionOrigen = vertices->getPosicion(origen);
    int posicionDestino = vertices->getPosicion(destino);

    if(!existeArista(origen,destino)){
        if(existeVertice(origen)&&existeVertice(destino)) {
            precioMatriz->modificarElemento(precio,posicionOrigen,posicionDestino);
            distanciaMatriz->modificarElemento(distancia,posicionOrigen,posicionDestino);
        }

        else if(existeVertice(origen)){
            precioMatriz->agregarFilasColumnas(1,1);
            distanciaMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(destino);
            precioMatriz->modificarElemento(precio,posicionOrigen,posicionDestino);
            distanciaMatriz->modificarElemento(distancia,posicionOrigen,posicionDestino);
            elementos ++;
        }

        else if (existeVertice(destino)){
            precioMatriz->agregarFilasColumnas(1,1);
            distanciaMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(origen);
            precioMatriz->modificarElemento(precio,posicionOrigen,posicionDestino);
            distanciaMatriz->modificarElemento(distancia,posicionOrigen,posicionDestino);
            elementos ++;
        }

        else{
            precioMatriz->agregarFilasColumnas(2,2);
            distanciaMatriz->agregarFilasColumnas(2,2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            elementos = elementos+2;
            precioMatriz->modificarElemento(precio,posicionOrigen,posicionDestino);
            distanciaMatriz->modificarElemento(distancia,posicionOrigen,posicionDestino);
        }

        cout<<"\n\t Arista conectada correctamente\n";
    }
    else
        cout<<"\n\t Ya existe una arista que los une \n";
}