#include "Grafo.h"
const int INFINITO = 999999;

Grafo::Grafo() {
    this->elementos= 0;
    this->precioMatriz= new Matriz<int>;
    this->distanciaMatriz = new Matriz<float>;
    this->vertices = new Lista<string>;
    precioMatriz->asignarInicializador(INFINITO);
    distanciaMatriz->asignarInicializador(INFINITO);
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
        int posicionOrigen;
        int posicionDestino;
        if(existeVertice(origen)&&existeVertice(destino)) {
            posicionOrigen = vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            distanciaMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
        }

        else if(existeVertice(origen)){
            precioMatriz->agregarFilasColumnas(1,1);
            distanciaMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(destino);
            posicionOrigen = vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            distanciaMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else if (existeVertice(destino)){
            precioMatriz->agregarFilasColumnas(1,1);
            distanciaMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(origen);
            posicionOrigen = vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            distanciaMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else{
            precioMatriz->agregarFilasColumnas(2,2);
            distanciaMatriz->agregarFilasColumnas(2,2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            posicionOrigen = vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            distanciaMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
            elementos += 2;
        }
    }
    else
        cout<<"\n\tYa existe una arista que une " << origen << " y " << destino << "\n";
}

void Grafo:: mostrarMatrizPrecios() {
    for (int i = 0; i < precioMatriz->longitudFilas(); ++i) {
        for (int j = 0; j < precioMatriz->longitudColumnas(); ++j) {
            cout << "\t" << precioMatriz->obtenerValor(i, j) << "\t";
        }
        cout << "\n";
    }
}

void Grafo:: mostrarMatrizTiempos() {
    for (int i = 0; i < distanciaMatriz->longitudFilas(); ++i) {
        for (int j = 0; j < distanciaMatriz->longitudColumnas(); ++j) {
            cout << "\t" << distanciaMatriz->obtenerValor(i, j) << "\t";
        }
        cout << "\n";
    }
}