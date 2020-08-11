#ifndef TP5_TRIALGO_GRAFO_H
#define TP5_TRIALGO_GRAFO_H

#include "../Estructuras Lineales/Lista.h"
#include "Diccionario.h"
#include "../Aeropuerto.h"
#include "Matriz.h"

class Grafo {

    private:
        Matriz<int>* precioMatriz;
        Matriz<float>* tiempoMatriz;
        Lista<string>* vertices;
        int elementos;

    public:

        //DESCRIPCION: Constructor sin parametros
        //PRE: -
        //POST: Crea un grafo vacio reservando memoria para las estructuras
        Grafo();

        //DESCRIPCION: Destructor del grafo
        //PRE: Las estructuras (matrices y lista) deben estar en memoria dinamica
        //POST: Libera los recursos
        ~Grafo();

        //DESCRIPCION: Devuelve verdadero si exsiste el vertice
        //PRE: -
        //POST: Devuelve verdadero si exsiste el vertice
        bool existeVertice(const string &vertice);

        //DESCRIPCION: Devuelve verdadero si exsiste la arista entre origen y destino
        //PRE: -
        //POST: Devuelve verdadero si exsiste la arista entre origen y destino
        bool existeArista(const string &origen, const string &destino);

        //DESCRIPCION: Si no existe la arista en el grafo, se inserta una nueva con los valores recibidos
        //PRE:
        //POST: Inserta una nueva arista de vertice a destino y asigna los costos en la matriz correspondiente
        void insertarArista(const string &origen, const string &destino, int precio, float distancia);

        //DESCRIPCION: Devuelve el peso "precio" de la arista entre origen y destino
        //PRE: -
        //POST: Si origen y destino pertenecen al grafo y existe una arista que los conecte,
        //      devuelve el precio de la arista. Sino devuelve E_INFINITO
        int obtenerPrecio(const string &origen, const string &destino);

        //DESCRIPCION: Devuelve el peso "horas" de la arista entre origen y destino
        //PRE: -
        //POST: Si origen y destino pertenecen al grafo y existe una arista que los conecte,
        //      devuelve el tiempo de la arista. Sino devuelve F_INFINITO
        float obtenerTiempo(const string &origen, const string &destino);

        //PRE: La matriz debe estar cargada
        //POST: Muestra por pantalla la matriz los caminos minimos de precios
        void mostrarCaminosMinimos(const string &origen, const string &destino, unsigned distancias[], string recorrido[], Diccionario<string, Aeropuerto*> *&aeropuertos);
        void mostrarRuta(string recorrido[], unsigned pos, Diccionario<string, Aeropuerto *> *&aeropuertos);

        unsigned distanciaMinima(unsigned distancias[], bool visitados[]);

        //PRE: La matriz de precios debe estar cargada
        //POST: Devuelve una lista que contiene las precios minimos de origen a destino
        void caminoMinimoPrecio(const string &origen, const string &destino, Diccionario<string, Aeropuerto *> *&aeropuertos);

        //PRE: La matriz de tiempos debe estar cargada
        //POST: Devuelve una lista que contiene las tiempos minimos de origen a destino
        void caminoMinimoTiempo(const string &origen, const string &destino, Diccionario<string, Aeropuerto *> *&aeropuertos);
};

#endif //TP5_TRIALGO_GRAFO_H