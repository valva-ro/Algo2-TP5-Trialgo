#ifndef CARGADOR_H
#define CARGADOR_H

#include<fstream>
#include<iostream>
#include<string>

#include "ABB.h"
#include "Dicionario.h"
#include "Aeropuerto.h"
#include "Excepcion"

const string rutaABB   = "Aeropuertos.txt";
const string rutaGrafo = "Vuelos.txt"

using namespace std;

class Cargador
{

public://Metodos

    //Constructor
    Cargador();

    //PRE : nombre de archivo
    //POST:carga los datos en el arbol binario de busqueda
    void cargadorDeABB(ABB<Diccionario> &arbolAeropuertos , ifstream archivo);

    //PRE: nombre de archivo
    //POST: carga los datos en el grafo
    void cargadorDeGafro(Grafo &grafo , ifstream archivo);

};

#endif /*CARGADOR_H*/
