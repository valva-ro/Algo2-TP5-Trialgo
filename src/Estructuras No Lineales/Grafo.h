#ifndef TP5_TRIALGO_GRAFO_H
#define TP5_TRIALGO_GRAFO_H

#include "../Estructuras Lineales/Lista.h"
#include "Diccionario.h"
#include "../Aeropuerto.h"
#include "Matriz.h"

struct CaminoMinimoPrecio{
    Matriz<int>* precios;
    Matriz<string>* rutas;
};

struct CaminoMinimoTiempo{
    Matriz<float>* tiempos;
    Matriz<string>* rutas;
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

        //DESCRIPCION: Constructor con parametros
        //PRE: -
        //POST: Crea un objeto grafo asignando los atributos con los valores recibidos
        Grafo(Matriz<int>* precio, Matriz<float>* distancia, int elementos, Lista<string>* vertices);

        //DESCRIPCION: Destructor del grafo
        //PRE: Las estructuras (matrices y lista) deben estar en memoria dinamica
        //POST: Libera los recursos
        ~Grafo();

        //DESCRIPCION: Devuelve verdadero si exsiste el vertice
        //PRE: -
        //POST: Devuelve verdadero si exsiste el vertice
        bool existeVertice(string vertice);

        //DESCRIPCION: Devuelve verdadero si exsiste la arista entre origen y destino
        //PRE: -
        //POST: Devuelve verdadero si exsiste la arista entre origen y destino
        bool existeArista(string origen, string destino);

        //DESCRIPCION: Si no existe la arista en el grafo, se inserta una nueva con los valores recibidos
        //PRE:
        //POST: Inserta una nueva arista de vertice a destino y asigna los costos en la matriz correspondiente
        void insertarArista(string origen, string destino, int precio, float distancia);

        //DESCRIPCION: Devuelve el peso "precio" de la arista entre origen y destino
        //PRE: -
        //POST: Si origen y destino pertenecen al grafo y existe una arista que los conecte,
        //      devuelve el precio de la arista. Sino devuelve E_INFINITO
        int obtenerPrecio(string origen, string destino);

        //DESCRIPCION: Devuelve el peso "horas" de la arista entre origen y destino
        //PRE: -
        //POST: Si origen y destino pertenecen al grafo y existe una arista que los conecte,
        //      devuelve el tiempo de la arista. Sino devuelve F_INFINITO
        float obtenerTiempo(string origen, string destino);

        //DESCRIPCION: Muestra por pantalla la matriz los caminos minimos de precios
        //PRE: La matriz debe estar cargada
        //POST: Muestra por pantalla la matriz los caminos minimos de precios
        void mostrarCaminosMinimosPrecios(string origen, string destino, Diccionario<string, Aeropuerto*> *&aeropuertos);

        //DESCRIPCION: Muestra por pantalla la matriz los caminos minimos de tiempos
        //PRE: La matriz debe estar cargada
        //POST: Muestra por pantalla la matriz los caminos minimos de tiempos
        void mostrarCaminosMinimosTiempos(string origen, string destino, Diccionario<string, Aeropuerto*> *&aeropuertos);

    private:

        //DESCRIPCION: Devuelve un struct con las matrices inicializadas
        //PRE: La matriz de precios debe estar cargada
        //POST: Devuelve un struct con las matrices inicializadas
        CaminoMinimoPrecio inicializarMatricesPrecio();

        //DESCRIPCION: Devuelve un struct con las matrices inicializadas
        //PRE: La matriz de tiempos debe estar cargada
        //POST: Devuelve un struct con las matrices inicializadas
        CaminoMinimoTiempo inicializarMatricesTiempo();

        //DESCRIPCION: Devuelve un struct que contiene las matrices con los caminos minimos de precios
        //PRE: La matriz de precios debe estar cargada
        //POST: Devuelve un struct que contiene las matrices con los caminos minimos de precios
        CaminoMinimoPrecio caminoMinimoPrecio();

        //DESCRIPCION: Devuelve un struct que contiene las matrices con los caminos minimos de tiempos
        //PRE: La matriz de tiempos debe estar cargada
        //POST: Devuelve un struct que contiene las matrices con los caminos minimos de tiempos
        CaminoMinimoTiempo caminoMinimoTiempo();
};

#endif //TP5_TRIALGO_GRAFO_H