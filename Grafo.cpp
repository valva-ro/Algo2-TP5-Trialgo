#include "Grafo.h"

Grafo:: Grafo() {
    aristasPrecio = 0;
    aristasTiempo = 0;
    vertices = 0;
    elementos = 0;
}

Grafo:: Grafo(string origen, string destino, int precio, float tiempo) {
    elementos = 0;
    vertices = new Lista<string>;
    aristasPrecio = new Matriz<int>(ENT_INFINITO, elementos, elementos);
    aristasTiempo = new Matriz<float>(FLO_INFINITO, elementos, elementos);
    agregarArista(origen, destino, precio, tiempo);
}

Grafo:: ~Grafo() {
    delete aristasPrecio;
    delete aristasTiempo;
    delete vertices;
}

int Grafo:: obtenerPrecio(string origen, string destino) {
    int precio = ENT_INFINITO;
    if (existeArista(origen, destino)) {
        int begPos = vertices->obtenerPosicion(origen);
        int destinoPos = vertices->obtenerPosicion(destino);
        precio = aristasPrecio->obtenerValor(begPos, destinoPos);
    }
    return precio;
}

void Grafo:: mostrarMatrizPrecios() {
    cout << "\n\t\tPrecios\n";
    for (int i = 0; i < aristasPrecio->longitudFilas(); ++i) {
        for (int j = 0; j < aristasPrecio->longitudColumnas(); ++j) {
            cout << "\t\t" << aristasPrecio->obtenerValor(i, j) << "\t";
        }
        cout << "\n";
    }
}

void Grafo:: mostrarMatrizTiempos() {
    cout << "\n\t\tTiempos\n";
    for (int i = 0; i < aristasTiempo->longitudFilas(); ++i) {
        for (int j = 0; j < aristasTiempo->longitudColumnas(); ++j) {
            cout << "\t\t" << aristasTiempo->obtenerValor(i, j) << "\t";
        }
        cout << "\n";
    }
}

void Grafo:: agregarArista(string origen, string destino, int precio, float tiempo) {

    if (!existeArista(origen, destino)) {

        int posOrigen;
        int posDestino;

        if (existeVertice(origen) && existeVertice(destino)) {
            posOrigen = vertices->obtenerPosicion(origen);
            posDestino = vertices->obtenerPosicion(destino);
            aristasPrecio->modificarElemento(precio, posOrigen, posDestino);
            aristasTiempo->modificarElemento(tiempo, posOrigen, posDestino);
        }
        else if (existeVertice(origen)) {
            aristasPrecio->agregarFilasColumnas(elementos + 1, elementos + 1);
            aristasTiempo->agregarFilasColumnas(elementos + 1, elementos + 1);
            vertices->insertar(destino);
            posOrigen = vertices->obtenerPosicion(origen);
            posDestino = vertices->obtenerPosicion(destino);
            aristasPrecio->modificarElemento(precio, posOrigen, posDestino);
            aristasTiempo->modificarElemento(tiempo, posOrigen, posDestino);
            elementos += 1;
        }
        else if(existeVertice(destino)) {
            aristasPrecio->agregarFilasColumnas(elementos + 1, elementos + 1);
            aristasTiempo->agregarFilasColumnas(elementos + 1, elementos + 1);
            vertices->insertar(origen);
            posOrigen = vertices->obtenerPosicion(origen);
            posDestino = vertices->obtenerPosicion(destino);
            aristasPrecio->modificarElemento(precio, elementos, vertices->obtenerPosicion(destino));
            aristasTiempo->modificarElemento(tiempo, elementos, vertices->obtenerPosicion(destino));
            elementos += 1;
        }
        else {
            aristasPrecio->agregarFilasColumnas(elementos + 2, elementos + 2);
            aristasTiempo->agregarFilasColumnas(elementos + 2, elementos + 2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            posOrigen = vertices->obtenerPosicion(origen);
            posDestino = vertices->obtenerPosicion(destino);
            aristasPrecio->modificarElemento(precio, posOrigen, posDestino);
            aristasTiempo->modificarElemento(tiempo, posOrigen, posDestino);
            elementos += 2;
        }
        cout << "\t\tVuelo conectando " << origen << " y " << destino << " con precio " << precio << " y duracion "
             << tiempo <<" agregado con exito!\n";
    }
    else
        cout << "\t\tYa existe un vuelo que conecta " << origen << " y " << destino << "!\n";
}
bool Grafo:: existeVertice(string vuelo) {
    bool existe = false;
    if (vertices->obtenerTam() > 0) {
        for (int i = 1; i <= vertices->obtenerTam(); ++i) {
            if (vertices->obtenerDato(i) == vuelo)
                existe = true;
        }
    }
    return existe;
}

bool Grafo:: existeArista(string origen, string destino) {
    bool existe = true;
    if (!existeVertice(origen) || !existeVertice(destino))
        existe = false;
    else {
        if (aristasPrecio->obtenerValor(vertices->obtenerPosicion(origen), vertices->obtenerPosicion(destino)) == ENT_INFINITO)
            existe = false;
    }
    return existe;
}