#ifndef CARGADOR_H
#define CARGADOR_H

//Librerias de C++
#include<fstream>
#include<iostream>
#include<string>

//Librerias locales
#include "ABB.h"
#include "Dicionario.h"
#include "Aeropuerto.h"
#include "Excepcion.h"

//Constantes de excepcion
const int EXCEPCION_ABB   = 0;
const int EXCEPCION_GRAFO = 1;

using namespace std;

class Cargador
{

public://Metodos

    //PRE : nombre de archivo
    //POST:carga los datos en el arbol binario de busqueda
    void cargadorDeABB(ABB<Diccionario*> &arbolAeropuertos , ifstream &archivo);

    //PRE: nombre de archivo
    //POST: carga los datos en el grafo
    void cargadorDeGrafo(Grafo<Vuelo*> &grafo , ifstream &archivo);

};

#endif /*CARGADOR_H*/
