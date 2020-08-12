#ifndef TP5_TRIALGO_GRAFO_H
#define TP5_TRIALGO_GRAFO_H

#include "Lista.h"
#include "Diccionario.h"
#include "Aeropuerto.h"
#include "Matriz.h"

const int MAX_VERTICES = 999;

struct RecorridoMinimoPrecio {
    string rutaMinima[MAX_VERTICES];
    int precioMinimo[MAX_VERTICES];
};

struct RecorridoMinimoTiempo {
    string rutaMinima[MAX_VERTICES];
    float tiempoMinimo[MAX_VERTICES];
};

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

        //  PRE: La matriz de precios debe estar cargada
        // POST: Devuelve el puntero a la matriz de precios
        Matriz<int>*& obtenerPrecioMatriz();

        //  PRE: La matriz de tiempos debe estar cargada
        // POST: Devuelve el puntero a la matriz de tiempos
        Matriz<float>*& obtenerTiempoMatriz();

        //  PRE: La matriz de precios debe estar cargada
        // POST: Calcula el camino minimo desde origen hasta todos los destinos posibles, y muestra por pantalla el camino minimo a destino
        RecorridoMinimoPrecio dijkstra(const string &origen, Matriz<int> *&precios, Diccionario<string, Aeropuerto *> *&aeropuertos);

        //  PRE: La matriz de tiempos debe estar cargada
        // POST: Calcula el camino minimo desde origen hasta todos los destinos posibles, y muestra por pantalla el camino minimo a destino
        RecorridoMinimoTiempo dijkstra(const string &origen, Matriz<float> *&tiempos, Diccionario<string, Aeropuerto *> *&aeropuertos);

        //  PRE: La matriz de tiempos debe estar cargada
        // POST: Calcula todos los caminos minimos con igual precio desde origen hasta todos los destinos posibles y
        //       muestra por pantalla solo los caminos minimos a destino
        void multiplesPreciosMinimos(const string &origen, const string &destino, Diccionario<string, Aeropuerto *> *&aeropuertos);

        //  PRE: La matriz de tiempos debe estar cargada
        // POST: Calcula todos los caminos minimos con igual tiempo desde origen hasta todos los destinos posibles y
        //       muestra por pantalla solo los caminos minimos a destino
        void multiplesTiemposMinimos(const string &origen, const string &destino, Diccionario<string, Aeropuerto *> *&aeropuertos);

    private:

        //  PRE: distancias[] y recorrido[] deben tener una longitud igual a 'elementos'
        // POST: Devuelve la posicion que corresponde al valor minimo del vector distancias[]
        int distanciaMinima(float distancias[], bool visitados[]);

        //  PRE: distancias[] y recorrido[] deben tener una longitud igual a 'elementos'
        // POST: Devuelve la posicion que corresponde al valor minimo del vector distancias[]
        int distanciaMinima(int distancias[], bool visitados[]);

        //  PRE: - distancias[] y recorrido[] deben tener una longitud igual a 'elementos'
        //       - distancias[] debe tener 0 en la posicion de origen y el resto de las posiciones deben tener
        //         el peso minimo que requiere llegar al vertice
        //       - recorrido[] debe tener VACIO en la posicion de origen y el resto de las posiciones deben tener
        //         cada una el vertice inmediatamente anterior para llegar a esa posicion
        // POST: Muestra el camino minimo desde origen hasta destino
        void mostrarCaminoMinimo(const string &origen, const string &destino, float distancias[],
                                 string recorrido[], Diccionario<string, Aeropuerto*> *&aeropuertos);

        //  PRE: - distancias[] y recorrido[] deben tener una longitud igual a 'elementos'
        //       - distancias[] debe tener 0 en la posicion de origen y el resto de las posiciones deben tener
        //         el peso minimo que requiere llegar al vertice
        //       - recorrido[] debe tener VACIO en la posicion de origen y el resto de las posiciones deben tener
        //         cada una el vertice inmediatamente anterior para llegar a esa posicion
        // POST: Muestra el camino minimo desde origen hasta destino
        void mostrarCaminoMinimo(const string &origen, const string &destino, int distancias[],
                                 string recorrido[], Diccionario<string, Aeropuerto*> *&aeropuertos);

        //  PRE: - distancias[] y recorrido[] deben tener una longitud igual a 'elementos'
        //       - distancias[] debe tener 0 en la posicion de origen y el resto de las posiciones deben tener
        //         el peso minimo que requiere llegar al vertice
        //       - recorrido[] debe tener VACIO en la posicion de origen y el resto de las posiciones deben tener
        //         cada una el vertice inmediatamente anterior para llegar a esa posicion
        //       - tipo debe ser PRECIO o TIEMPO
        // POST: Muestra las rutas entre origen y destino
        void mostrarRuta(const string& tipo, string recorrido[], unsigned posOrigen, unsigned posDestino,
                         Diccionario<string, Aeropuerto *> *&aeropuertos);
    };

#endif //TP5_TRIALGO_GRAFO_H