/*

 * Es una version inicial de la clase Grafo, que nos permite cargar los datos y mostrar las matrices con los pesos.
   Faltan los metodos necesarios para realizar el camino minimo

 * Estoy asumiendo:
    * Que en la clase Lista existe un metodo 'int getPosicion(Tipo dato)' que devuelve la posicion
      en la que se encuentra el dato recibido
    * Que la clase Matriz tiene un metodo 'Tipo obtenerDato(fila, columna)' que recibe dos enteros, el primero
      se corresponde con la fila y el segundo con la columna, y devuelve el dato que esta en esa posicion
      de la matriz
    * Que la clase Matriz tiene un metodo 'void mostrar()' que muestra toda la matriz de forma ordenada

 */


#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "string.h"
#include "Matriz.h"
#include "Lista.h"

using namespace std;

const int ENT_INFINITO = 9999999;
const float FLO_INFINITO = 9999999.0;

class Grafo {

    private:
        Matriz<float>* aristasTiempo;
        Matriz<int>* aristasPrecio;
        Lista<string>* vertices;
        int elementos;

    public:

        //  PRE: -
        // POST: Crea un grafo con elementos = 0, vertices and matrices apuntando a NULL
        Grafo();

        //  PRE: -
        // POST: Crea un grafo conectando origen y destino con peso precio y tiempo
        Grafo(string origen, string destino, int precio, float tiempo);

        //  PRE: -
        // POST: Libera los recursos del grafo
        ~Grafo();

        //  PRE: No debe existir una arista conectando origen y destino
        // POST: Agrega una nueva arista con el costo precio
        void agregarArista(string origen, string destino, int precio, float tiempo);

        //  PRE: -
        // POST: Devuelve true si el vuelo existe, de lo contrario false
        bool existeVertice(string vuelo);

        //  PRE: -
        // POST: Devuelve true si existe la arista de orgen a destino, de lo contrario false
        bool existeArista(string origen, string destino);

        // PRE: -
        // POST: Devuelve el precio de ir de origen a destino
        int obtenerPrecio(string origen, string destino);

        // PRE: -
        // POST: Devuelve el tiempo de ir de origen a destino
        float obtenerTiempo(string origen, string destino);

        // PRE: -
        // POST: Muestra la matriz con los precios
        void mostrarMatrizPrecios();

        // PRE: -
        // POST: Muestra la matriz con los tiempos
        void mostrarMatrizTiempos();
};

///////////////////////////////////////////// IMPLEMENTACION /////////////////////////////////////////////

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
        int begPos = vertices->getPosicion(origen);
        int destinoPos = vertices->getPosicion(destino);
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
        if (existeVertice(origen) && existeVertice(destino)) {
            aristasPrecio->modificarElemento(precio, vertices->getPosicion(origen), vertices->getPosicion(destino));
            aristasTiempo->modificarElemento(tiempo, vertices->getPosicion(origen), vertices->getPosicion(destino));
        }
        else if (existeVertice(origen)) {
            aristasPrecio->agregarFilasColumnas(elementos + 1, elementos + 1);
            aristasTiempo->agregarFilasColumnas(elementos + 1, elementos + 1);
            vertices->insertar(destino);
            aristasPrecio->modificarElemento(precio, vertices->getPosicion(origen), elementos);
            aristasTiempo->modificarElemento(tiempo, vertices->getPosicion(origen), elementos);
            elementos += 1;
        }
        else if(existeVertice(destino)) {
            aristasPrecio->agregarFilasColumnas(elementos + 1, elementos + 1);
            aristasTiempo->agregarFilasColumnas(elementos + 1, elementos + 1);
            vertices->insertar(origen);
            aristasPrecio->modificarElemento(precio, elementos, vertices->getPosicion(destino));
            aristasTiempo->modificarElemento(tiempo, elementos, vertices->getPosicion(destino));
            elementos += 1;
        }
        else {
            aristasPrecio->agregarFilasColumnas(elementos + 2, elementos + 2);
            aristasTiempo->agregarFilasColumnas(elementos + 2, elementos + 2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            elementos += 2;
            aristasPrecio->modificarElemento(precio, vertices->getPosicion(origen), vertices->getPosicion(destino));
            aristasTiempo->modificarElemento(tiempo, vertices->getPosicion(origen), vertices->getPosicion(destino));
        }
        cout << "\t\tVuelo conectando " << origen << " y " << destino << " con precio " << precio << " y duracion "
             << tiempo <<" agregado con exito!\n";
    }
    else
        cout << "\t\tYa existe un vuelo que conecta " << origen << " y " << destino << "!\n";
}
bool Grafo:: existeVertice(string vuelo) {
    bool existe = false;
    for (int i = 1; i <= vertices->getTam() ; ++i) {
        if (vertices->getDato(i) == vuelo)
            existe = true;
    }
    return existe;
}

bool Grafo:: existeArista(string origen, string destino) {
    bool existe = true;
    if (!existeVertice(origen) || !existeVertice(destino))
        existe = false;
    else {
        if (aristasPrecio->obtenerValor(vertices->getPosicion(origen), vertices->getPosicion(destino)) == ENT_INFINITO)
            existe = false;
    }
    return existe;
}
#endif //GRAPHTEMPLATES_GRAPH_H