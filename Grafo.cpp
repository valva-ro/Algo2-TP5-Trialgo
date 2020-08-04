#include "Grafo.h"
const int INFINITO = 100000;

Grafo::Grafo() {
    this->distanciaMatriz = new Matriz<float>(INFINITO,2,2);
    this->elementos= 0;
    this->precioMatriz= new Matriz<int>(INFINITO,2,2);
    this->vertices = new Lista<string>;
}

Grafo::Grafo(Matriz<int> *precio, Matriz<float> *distancia, int elementos, Lista<string> *vertices) {
    this->distanciaMatriz = distancia;
    this->elementos = vertices->obtenerTam();
    this->precioMatriz = precio;
    this->vertices = vertices;
}

Grafo::~Grafo() {
    delete distanciaMatriz;
    delete precioMatriz;
    delete vertices;
}

bool Grafo::existeArista(string origen, string destino) {
    bool existe = false;
    if (existeVertice(origen) && existeVertice(destino)){
        if ((distanciaMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino)) < INFINITO) &&
            (precioMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino)) < INFINITO))
            existe = true;
    }
    return existe;
}

bool Grafo::existeVertice(string vertice) {
    bool existe = false;
    if (vertices->obtenerPosicion(vertice) != -1)
        existe = true;
    return existe;
}

float Grafo::obtenerDistancia(string origen, string destino) {
    float distancia = INFINITO;
    if (existeArista(origen, destino))
        distancia= distanciaMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));

    return  distancia;
}

int Grafo::obtenerPrecio(string origen, string destino) {
    int precio = INFINITO;
    if (existeArista(origen, destino))
        precio = precioMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));

    return precio;
}

void Grafo::insertarArista(string origen, string destino, int precio, float distancia) {

    if(!existeArista(origen,destino)){
        if(existeVertice(origen)&&existeVertice(destino)) {
            int posicionOrigen = vertices->obtenerPosicion(origen);
            int posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            distanciaMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
        }

        else if(existeVertice(origen)){
            precioMatriz->agregarFilasColumnas(1,1);
            distanciaMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(destino);
            int posicionOrigen = vertices->obtenerPosicion(origen);
            int posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            distanciaMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else if (existeVertice(destino)){
            precioMatriz->agregarFilasColumnas(1,1);
            distanciaMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(origen);
            int posicionOrigen = vertices->obtenerPosicion(origen);
            int posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            distanciaMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else{
            precioMatriz->agregarFilasColumnas(2,2);
            distanciaMatriz->agregarFilasColumnas(2,2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            int posicionOrigen = vertices->obtenerPosicion(origen);
            int posicionDestino = vertices->obtenerPosicion(destino);
            elementos += 2;
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            distanciaMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
        }

        cout<<"\n\t Arista conectada correctamente\n";
    }
    else
        cout<<"\n\t Ya existe una arista que los une \n";
}