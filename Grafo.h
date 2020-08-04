//
// Created by alexteper on 2/8/20.
//

#ifndef TP5_TRIALGO_GRAFO_H
#define TP5_TRIALGO_GRAFO_H

#include "Lista.h"
#include "Aeropuerto.h"
#include "Matriz.h"

class Grafo {
private:
    Matriz<int>* precioMatriz;
    Matriz<float>* distanciaMatriz;
    int elementos;
    Lista<string>* vertices;


public:

    //DESCRIPCION: Constructor sin parametros
    //PRE: -
    //POST: Crea un grafo vacio
    //Grafo();

    //DESCRIPCION: Constructor con parametros
    //PRE:
    //POST: Crea un objeto grafo asignando los atributos con los valores recibidos
    Grafo(Matriz<int>* precio, Matriz<float>* distancia, int elementos, Lista<string>* vertices);


    //DESCRIPCION: Destructor del grafo
    //PRE:
    //POST:Libera los recursos
    ~Grafo();

    //DESCRIPCION:
    //PRE:
    //POST: Devuelve verdadero si exsiste el vertice
    bool existeVertice(string vertice);


    //DESCRIPCION:
    //PRE:
    //POST: Devuelve verdadero si exsiste la arista entre origen y destino.
    bool existeArista(string origen, string destino);


    //DESCRIPCION:
    //PRE:
    //POST: Insertar una nueva arista de vertice a destino y asigna los costos en la matriz correspondiente
    void insertarArista(string origen, string destino, int precio, float distancia);


    //DESCRIPCION:
    //PRE:
    //POST:
    int obtenerPrecio(string origen, string destino);

    //DESCRIPCION:
    //PRE:
    //POST:
    float obtenerDistancia(string origen, string destino);

};


#endif //TP5_TRIALGO_GRAFO_H
