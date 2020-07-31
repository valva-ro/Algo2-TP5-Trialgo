/*

 * Es una version inicial de la clase Grafo, que nos permite cargar los datos y mostrar las matrices con los pesos.
   Faltan los metodos necesarios para realizar el camino minimo

 * Estoy asumiendo:
    * Que en la clase Lista existe un metodo 'int obtenerPosicion(Tipo dato)' que devuelve la posicion
      en la que se encuentra el dato recibido
    * Que la clase Matriz tiene un metodo 'Tipo obtenerDato(fila, columna)' que recibe dos enteros, el primero
      se corresponde con la fila y el segundo con la columna, y devuelve el dato que esta en esa posicion
      de la matriz
    * Que la clase Matriz tiene un metodo 'void mostrar()' que muestra toda la matriz de forma ordenada

 */


#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Vuelo.h"
#include "Matriz.h"
#include "Lista.h"

using namespace std;

const int ENT_INFINITO = 9999999;
const float FLO_INFINITO = 9999999.0;

class Grafo {

    private:
        Matriz<float>* aristasTiempo;
        Matriz<int>* aristasPrecio;
        Lista<Vuelo>* vertices;
        int elementos;

    public:

        //  PRE: -
        // POST: Crea un grafo con elementos = 0, vertices and matrices apuntando a NULL
        Grafo();

        //  PRE: -
        // POST: Crea un grafo conectando origen y destino con peso precio y tiempo
        Grafo(Vuelo origen, Vuelo destino, int precio, float tiempo);

        //  PRE: -
        // POST: Libera los recursos del grafo
        ~Grafo();

        //  PRE: No debe existir una arista conectando origen y destino
        // POST: Agrega una nueva arista con el costo precio
        void agregarArista(Vuelo origen, Vuelo destino, int precio, float tiempo);

        //  PRE: -
        // POST: Devuelve true si el vuelo existe, de lo contrario false
        bool existeVertice(Vuelo vuelo);

        //  PRE: -
        // POST: Devuelve true si existe la arista de orgen a destino, de lo contrario false
        bool existeArista(Vuelo origen, Vuelo destino);

        // PRE: -
        // POST: Devuelve el precio de ir de origen a destino
        int obtenerPrecio(Vuelo origen, Vuelo destino);

        // PRE: -
        // POST: Devuelve el tiempo de ir de origen a destino
        float obtenerTiempo(Vuelo origen, Vuelo destino);

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
    aristasTiempo = 0
    vertices = 0;
    elementos = 0;
}

Grafo:: Grafo(Vuelo origen, Vuelo destino, int precio, float tiempo) {
    elementos = 0;
    vertices = new Lista<Vuelo>;
    aristasPrecio = new Matriz<int>(elementos, ENT_INFINITO);
    aristasTiempo = new Matriz<float>(elementos, FLO_INFINITO);
    agregarArista(origen, destino, precio);
    agregarArista(origen, destino, tiempo);
}

Grafo:: ~Grafo() {
    delete aristasPrecio;
    delete aristasTiempo;
    delete vertices;
}

int Grafo:: obtenerPrecio(Vuelo origen, Vuelo destino) {
    int precio = ENT_INFINITO;
    if (existeArista(origen, destino)) {
        int begPos = vertices->obtenerPosicion(origen);
        int destinoPos = vertices->obtenerPosicion(destino);
        precio = aristasPrecio->obtenerDato(begPos, destinoPos);
    }
    return precio;
}

void Grafo:: mostrarMatrizPrecios() {
    cout << "\n\t\tPrecios\n";
    aristasPrecio->mostrar();
}

void Grafo:: mostrarMatrizTiempos() {
    cout << "\n\t\tTiempos\n";
    aristasTiempo->mostrar();
}

void Grafo:: agregarArista(Vuelo origen, Vuelo destino, int precio, float tiempo) {
    if (!existeArista(origen, destino)) {
        if (existeVertice(origen) && existeVertice(destino)) {
            aristasPrecio->insertar(precio, vertices->obtenerPosicion(origen), vertices->obtenerPosicion(destino));
            aristasTiempo->insertar(tiempo, vertices->obtenerPosicion(origen), vertices->obtenerPosicion(destino));
        }
        else if (existeVertice(origen)) {
            aristasPrecio->redimensionar(elementos + 1);
            aristasTiempo->redimensionar(elementos + 1);
            vertices->insertar(destino);
            aristasPrecio->insertar(precio, vertices->obtenerPosicion(origen), elementos);
            aristasTiempo->insertar(tiempo, vertices->obtenerPosicion(origen), elementos);
            elementos += 1;
        }
        else if(existeVertice(destino)) {
            aristasPrecio->redimensionar(elementos + 1);
            aristasTiempo->redimensionar(elementos + 1);
            vertices->insertar(origen);
            aristasPrecio->insertar(precio, elementos, vertices->obtenerPosicion(destino));
            aristasTiempo->insertar(tiempo, elementos, vertices->obtenerPosicion(destino));
            elementos += 1;
        }
        else {
            aristasPrecio->redimensionar(elementos + 2);
            aristasTiempo->redimensionar(elementos + 2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            elementos += 2;
            aristasPrecio->insertar(precio, vertices->obtenerPosicion(origen), vertices->obtenerPosicion(destino));
            aristasTiempo->insertar(tiempo, vertices->obtenerPosicion(origen), vertices->obtenerPosicion(destino));
        }
        cout << "\t\tVuelo conectando " << origen << " y " << destino << " con precio " << precio << " y duracion "
             << tiempo <<" agregado con exito!\n";
    }
    else
        cout << "\t\tYa existe un vuelo que conecta " << origen << " y " << destino << "!\n";
}
bool Grafo:: existeVertice(Vuelo vuelo) {
    bool existe = false;
    for (int i = 1; i <= vertices->getTam() ; ++i) {
        if (vertices->getDato(i) == vuelo)
            existe = true;
    }
    return existe;
}

bool Grafo:: existeArista(Vuelo origen, Vuelo destino) {
    bool existe = true;
    if (!existeVertice(origen) || !existeVertice(destino))
        existe = false;
    else {
        if (aristasPrecio->obtenerDato(vertices->obtenerPosicion(origen), vertices->obtenerPosicion(destino)) == ENT_INFINITO)
            existe = false;
    }
    return existe;
}
#endif //GRAPHTEMPLATES_GRAPH_H