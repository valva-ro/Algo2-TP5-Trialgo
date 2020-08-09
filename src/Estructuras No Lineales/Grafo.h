#ifndef TP5_TRIALGO_GRAFO_H
#define TP5_TRIALGO_GRAFO_H

#include "../Estructuras Lineales/Lista.h"
#include "../Aeropuerto.h"
#include "Diccionario.h"
#include "Matriz.h"

class Grafo {

    private:
        Matriz<int> *precioMatriz, *preciosMinimos;
        Matriz<float> *tiempoMatriz, *tiemposMinimos;
        Matriz<string> *recorridosMinimos;
        Lista<string> *vertices;
        int elementos;
        bool preciosMinCalculado, tiemposMinCalculados, recorridosMinCalculados;

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

        //PRE:  Matriz inicializada con NONE(x)
        //POST: Genera  la matriz de recorrido para el algoritmo
        void calcularRecorridosMinimos();

        //PRE:  Matriz cargada
        //POST: Devuelve la matriz con los recorridos minimos y modifica la matriz de tiempo
        void calcularTiemposMinimos();

        //PRE:  Matriz cargada
        //POST: Devuelve la matriz con los recorridos minimos y modifica la matriz de precio
        void calcularPreciosMinimos();

        //PRE:  Matriz cargada
        //POST: Devuelve una lista con las escalas del viaje
        void mostrarEscalas(unsigned posOrigen, unsigned posDestino, Matriz<string>* &recorridoMatriz, Diccionario<string, Aeropuerto*>* &pDiccionario);

        //PRE :Recibe el destino y el origen validados
        //POST:Arma el pasaje del vuelo , de no se posible , corre la excepcion de vuelo
        void minimoPrecio(string origen, string destino, Diccionario<string, Aeropuerto*>* &pDiccionario);

        //PRE :Recibe el destino y el origen ya validados
        //POST:Arma el pasaje del vuelo , de no se posible , corre la excepcion de vuelo
        void minimoTiempo(string origen, string destino, Diccionario<string, Aeropuerto*>* &pDiccionario);
};

#endif //TP5_TRIALGO_GRAFO_H
