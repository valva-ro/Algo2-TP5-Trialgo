//
// Created by alexteper on 2/8/20.
//

#include "Grafo.h"

const int INFINITO = 100000;
const float INFINITOF = 100000.0;

Grafo::Grafo() {
    this->elementos = 0;
    this->precioMatriz = new Matriz<int>;
    this->tiempoMatriz = new Matriz<float>;
    this->vertices = new Lista<string>;
    precioMatriz->asignarInicializador(INFINITO);
    tiempoMatriz->asignarInicializador(INFINITOF);
}

Grafo::Grafo(Matriz<int> *precio, Matriz<float> *distancia, int elementos, Lista<string> *vertices) {
    this->tiempoMatriz = distancia;
    this->elementos = vertices->obtenerTam();
    this->precioMatriz = precio;
    this->vertices = vertices;
}

Grafo::~Grafo() {
    delete precioMatriz;
    delete tiempoMatriz;
    delete vertices;
}

bool Grafo::existeArista(string origen, string destino) {
    bool existe = true;
    if (existeVertice(origen) && existeVertice(destino)) {
        int posicionOrigen = vertices->obtenerPosicion(origen);
        int posicionDestino = vertices->obtenerPosicion(destino);
        if (tiempoMatriz->obtenerValor(posicionOrigen, posicionDestino > INFINITO) &&
            precioMatriz->obtenerValor(posicionOrigen, posicionDestino > INFINITO))
            existe = false;
    }
    else
        existe = false;

    return existe;
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
        distancia= tiempoMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
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
    int posicionDestino;
    int posicionOrigen;

    if(!existeArista(origen,destino)) {

        if(existeVertice(origen) && existeVertice(destino)) { //si exsisten los dos vertices exsiste una fila columna en las matrices por lo que solo modifico el dato
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
        }

        else if(existeVertice(origen)) { //si solo exsiste el origen
            precioMatriz->agregarFilasColumnas(1,1); //redimensiono para agregar el destino
            tiempoMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(destino); //agrego el dato nuevo a la lista de vertices
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino); //con la matriz ya armada correcta modifico el precio.
            tiempoMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else if (existeVertice(destino)) {
            precioMatriz->agregarFilasColumnas(1,1);
            tiempoMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(origen);
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else { //no exsiste ni el origen ni el destino
            precioMatriz->agregarFilasColumnas(2,2); //tengo que agregar una fila/columna para origen y una para destino
            tiempoMatriz->agregarFilasColumnas(2,2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(distancia, posicionOrigen, posicionDestino);
            elementos += 2;
        }

        cout<<"\n\tArista conectada correctamente\n";
    }else
        cout<<"\n\tYa exsiste una arista que los une " << origen << " y " << destino;
}