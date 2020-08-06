#ifndef TP5_TRIALGO_MENUVUELO_H
#define TP5_TRIALGO_MENUVUELO_H

#include "Grafo.h"
#include "Diccionario.h"
#include "Aeropuerto.h"

class MenuVuelo {
private:
    Grafo* vuelos;
    Diccionario<string, Aeropuerto*>* aeropuertos;
    char opcion;

public:
    //DESCRIPCION: Le asigna el puntero recibido al atributo por referencia
    //PRE: -
    //POST: Le asigna el puntero recibido al atributo por referencia
    void asignarGrafoVuelos(Grafo *&grafoVuelosOut);

    //DESCRIPCION: Le asigna el puntero recibido al atributo por referencia
    //PRE: -
    //POST: Le asigna el puntero recibido al atributo por referencia
    void asignarArbolAeropuertos(Diccionario<string, Aeropuerto*> *&arbolAeropuertosOut);

    //DESCRIPCION: Muestra las opciones del Menu
    //PRE: -
    //POST: Muestra las opciones del Menu y llama al metodo selectorOpcion()
    void mostrarOpciones();

    //DESCRIPCION: Selector las opciones del Menu
    //PRE: -
    //POST: Pide el ingreso de una opcion y abre el metodo correspondiente.
    //      Si la opcion ingresada es distinta de VOLVER_MENU llama al metodo mostrarOpciones().
    void selectorOpcion();

    //DESCRIPCION: Accede a los metodos necesarios para mostrar el camino de menor costo
    //PRE: -
    //POST: Se muestra el camino de menor costo
    void menorCosto();

    //DESCRIPCION: Accede a los metodos necesarios para mostrar el camino de menor tiempo
    //PRE: -
    //POST: Se muesrta el camino de menor tiempo
    void menorTiempo();

    //DESCRIPCION: Libera el grafo de memoria dinamica
    //PRE: El grafo debe estar cargado
    //POST: Libera el grafo de memoria dinamica
    void liberarRecursos();
};


#endif //TP5_TRIALGO_MENUVUELO_H
