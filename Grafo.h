#ifndef TP5_TRIALGO_GRAFO_H
#define TP5_TRIALGO_GRAFO_H

#include "Lista.h"
#include "Aeropuerto.h"
#include "Matriz.h"
#include "ExcepcionVuelo.h"

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

        //PRE:  Matriz inicializada con NONE(x)
        //POST: Genera  la matriz de recorrido para el algoritmo
        Matriz<string>* generarRecorrido();


        //PRE:  Matriz cargada
        //POST: Devuelve la matriz con los recorridos minimos y modifica la matriz de tiempo
        Matriz<string>* caminoMinimo(Matriz<float>* &tiempoMatriz);

        //PRE:  Matriz cargada
        //POST: Devuelve la matriz con los recorridos minimos y modifica la matriz de precio
        Matriz<string>* caminoMinimo(Matriz<int>* &precioMatriz;)

        //PRE:  Matriz cargada
        //POST: Devuelve una lista con las escalas del viaje
        Lista<string>* armarEscalas(string origen , string destino , Matriz<string>* &recorridoMatriz);

        //PRE :Recibe el destino y el origen validados
        //POST:Arma el pasaje del vuelo , de no se posible , corre la excepcion de vuelo
        void minimoPrecio(string origen , string destino);

        //PRE :Recibe el destino y el origen ya validados
        //POST:Arma el pasaje del vuelo , de no se posible , corre la excepcion de vuelo
        void minimoTiempo(string origen , string destino );
};

#endif //TP5_TRIALGO_GRAFO_H
