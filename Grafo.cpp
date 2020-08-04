#include "Grafo.h"

const int E_INFINITO = 999999;
const float F_INFINITO = 999998.9;

void Grafo::mostrarCaminosMinimosPrecios(string origen, string destino) {
    Matriz<int>* recorridosMin = caminoMinimoPrecio();
    if(existeArista(origen,destino))
        cout << "\tPrecio Minimo:\t" << recorridosMin->obtenerValor(vertices->obtenerPosicion(origen), vertices->obtenerPosicion(destino));
    delete recorridosMin;
}

void Grafo::mostrarCaminosMinimosTiempos(string origen, string destino) {
    Matriz<float>* recorridosMin = caminoMinimoTiempo();
    if(existeArista(origen,destino))
        cout << "\tTiempo Minimo:\t" << recorridosMin->obtenerValor(vertices->obtenerPosicion(origen), vertices->obtenerPosicion(destino));
    delete recorridosMin;
}

Matriz<int>* Grafo::caminoMinimoPrecio() {

    Matriz<int>* precio = new Matriz<int>(precioMatriz->obtenerInicializador(), precioMatriz->longitudFilas(), precioMatriz->longitudColumnas());
    for (int i = 0; i < precioMatriz->longitudFilas(); ++i) {
        for (int j = 0; j < precioMatriz->longitudColumnas(); ++j) {
            precio->modificarElemento(precioMatriz->obtenerValor(i,j), i, j);
        }
    }

    for(int k = 0; k < precio->longitudFilas(); k++) {
        for (int i = 0; i < precio->longitudFilas(); i++) {
            for (int j = 0; j < precio->longitudFilas(); j++) {
                if (precio->obtenerValor(i, k) + precio->obtenerValor(k, j) < precio->obtenerValor(i, j))
                    precio->modificarElemento((precio->obtenerValor(i, k) + precio->obtenerValor(k, j)), i, j);
            }
        }
    }
    return precio;
}

Matriz<float>* Grafo::caminoMinimoTiempo() {

    Matriz<float>* tiempo = new Matriz<float>(tiempoMatriz->obtenerInicializador(), tiempoMatriz->longitudFilas(), tiempoMatriz->longitudColumnas());
    for (int i = 0; i < tiempo->longitudFilas(); ++i) {
        for (int j = 0; j < tiempo->longitudColumnas(); ++j) {
            tiempo->modificarElemento(tiempoMatriz->obtenerValor(i,j), i, j);
        }
    }

    for(int k = 0; k < tiempo->longitudFilas(); k++) {
        for (int i = 0; i < tiempo->longitudFilas(); i++) {
            for (int j = 0; j < tiempo->longitudFilas(); j++) {
                if (tiempo->obtenerValor(i, k) + tiempo->obtenerValor(k, j) < tiempo->obtenerValor(i, j))
                    tiempo->modificarElemento((tiempo->obtenerValor(i, k) + tiempo->obtenerValor(k, j)), i, j);
            }
        }
    }
    return tiempo;
}

void Grafo::mostrarMatrizPrecios() {
    for (int i = 0; i < precioMatriz->longitudFilas(); ++i) {
        for (int j = 0; j < precioMatriz->longitudColumnas(); ++j) {
            cout << "\t" << precioMatriz->obtenerValor(i, j);
        }
        cout << "\n";
    }
}

void Grafo::mostrarMatrizTiempos() {
    for (int i = 0; i < tiempoMatriz->longitudFilas(); ++i) {
        for (int j = 0; j < tiempoMatriz->longitudColumnas(); ++j) {
            cout << "\t" << tiempoMatriz->obtenerValor(i, j);
        }
        cout << "\n";
    }
}
Grafo::Grafo() {
    this->elementos = 0;
    this->precioMatriz = new Matriz<int>;
    this->tiempoMatriz = new Matriz<float>;
    this->vertices = new Lista<string>;
    precioMatriz->asignarInicializador(E_INFINITO);
    tiempoMatriz->asignarInicializador(F_INFINITO);
}

Grafo::Grafo(Matriz<int> *precio, Matriz<float> *tiempo, int elementos, Lista<string> *vertices) {
    this->tiempoMatriz = tiempo;
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
    bool existe = false;
    if (existeVertice(origen) && existeVertice(destino)) {
        int posicionOrigen = vertices->obtenerPosicion(origen);
        int posicionDestino = vertices->obtenerPosicion(destino);
        if ((tiempoMatriz->obtenerValor(posicionOrigen, posicionDestino) < E_INFINITO) &&
            (precioMatriz->obtenerValor(posicionOrigen, posicionDestino) < F_INFINITO))
            existe = true;
    }
    return existe;
}

bool Grafo::existeVertice(string vertice) {
    bool existe = false;
    if (vertices->obtenerPosicion(vertice) != -1)
        existe = true;
    return  existe;
}

float Grafo::obtenerTiempo(string origen, string destino) {
    float tiempo = F_INFINITO;
    if(existeArista(origen,destino))
        tiempo = tiempoMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    return tiempo;
}

int Grafo::obtenerPrecio(string origen, string destino) {
    int precio = E_INFINITO;
    if(existeArista(origen,destino))
        precio = precioMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    return precio;

}

void Grafo::insertarArista(string origen, string destino, int precio, float tiempo) {
    int posicionDestino;
    int posicionOrigen;

    if(!existeArista(origen,destino)) {

        if(existeVertice(origen) && existeVertice(destino)) {
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
        }

        else if(existeVertice(origen)) {
            precioMatriz->agregarFilasColumnas(1,1);
            tiempoMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(destino);
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else if (existeVertice(destino)) {
            precioMatriz->agregarFilasColumnas(1,1);
            tiempoMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(origen);
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else {
            precioMatriz->agregarFilasColumnas(2,2);
            tiempoMatriz->agregarFilasColumnas(2,2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos += 2;
        }
    }
    else
        cout<<"\n\tYa existe una ruta que conecta " << origen << " con " << destino;
}