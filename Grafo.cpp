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
    this->elementos= vertices->obtenerTam();
    this->precioMatriz= precio;
    this->vertices =vertices;
}

Grafo::~Grafo() {

}

bool Grafo::existeArista(string origen, string destino) {
    bool exsiste= true;
    if (existeVertice(origen)&&existeVertice(destino)){
        if ((distanciaMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino))>INFINITO)&&(precioMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino))>INFINITO))
            exsiste = false;
    }

    return exsiste;
}

bool Grafo::existeVertice(string vertice) {
    bool exsiste;
    if (vertices->obtenerPosicion(vertice) != -1) // obtenerPosicion devuelve un -1 si no exsiste ese elemento en la lista
        exsiste = true;
    else
        exsiste= false;

    return  exsiste;
}

float Grafo::obtenerDistancia(string origen, string destino) {
    float distancia= INFINITO;
    if (existeArista(origen,destino)){
        distancia= distanciaMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    }

    return  distancia;
}

int Grafo::obtenerPrecio(string origen, string destino) {
    int precio = INFINITO;
    if(existeArista(origen,destino)){
        precio= precioMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    }

    return precio;

}

void Grafo::insertarArista(string origen, string destino, int precio, float distancia) {
    int posicionOrigen = vertices->obtenerPosicion(origen);
    int posicionDestino = vertices->obtenerPosicion(destino);

    if(!existeArista(origen,destino)){
        if(existeVertice(origen)&&existeVertice(destino)) { //si exsisten los dos vertices exsiste una fila columna en las matrices por lo que solo modifico el dato
            precioMatriz->modificarElemento(precio,posicionOrigen,posicionDestino);
            distanciaMatriz->modificarElemento(distancia,posicionOrigen,posicionDestino);
        }else if(existeVertice(origen)){ //si solo exsiste el origen
            precioMatriz->agregarFilasColumnas(1,1); //redimensiono para agregar el destino
            distanciaMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(destino); //agrego el dato nuevo a la lista de vertices
            precioMatriz->modificarElemento(precio,posicionOrigen,posicionDestino); //con la matriz ya armada correcta modifico el precio.
            distanciaMatriz->modificarElemento(distancia,posicionOrigen,posicionDestino);
            elementos ++;
        }else if (existeVertice(destino)){
            precioMatriz->agregarFilasColumnas(1,1);
            distanciaMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(origen);
            precioMatriz->modificarElemento(precio,posicionOrigen,posicionDestino);
            distanciaMatriz->modificarElemento(distancia,posicionOrigen,posicionDestino);
            elementos ++;
        }else  { //no exsiste ni el origen ni el destino
            precioMatriz->agregarFilasColumnas(2,2); //tengo que agregar una fila/columna para origen y una para destino
            distanciaMatriz->agregarFilasColumnas(2,2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            elementos = elementos+2;
            precioMatriz->modificarElemento(precio,posicionOrigen,posicionDestino);
            distanciaMatriz->modificarElemento(distancia,posicionOrigen,posicionDestino);
        }

        cout<<"\n\t Arista conectada correctamente\n";
    }else
        cout<<"\n\t Ya exsiste una arista que los une \n";
}