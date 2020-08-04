/*

 * Es una version inicial de la clase Grafo, que nos permite cargar los datos y mostrar las matrices con los pesos.
   Faltan los metodos necesarios para realizar el camino minimo

 * Estoy asumiendo:
    * Que en la clase Lista existe un metodo 'int getPosicion(Tipo dato)' que devuelve la posicion
      en la que se encuentra el dato recibido
    * Que la clase Matriz tiene un metodo 'Tipo obtenerDato(fila, columna)' que recibe dos enteros, el primero
      se corresponde con la fila y el segundo con la columna, y devuelve el dato que esta en esa posicion
      de la matriz

 */

#ifndef GRAFO_H
#define GRAFO_H

#include <string>
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

#endif //GRAFO_H