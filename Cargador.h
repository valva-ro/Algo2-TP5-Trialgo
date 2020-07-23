#ifndef CARGADOR_H
#define CARGADOR_H

//Librerias de C++
#include<fstream>
#include<iostream>
#include<string>

//Librerias locales
#include "ABB.h"
#include "Diccionario.h"
#include "Aeropuerto.h"
#include "Excepcion.h"

//Constantes de excepcion
const int EXCEPCION_ABB   = 0;
const int EXCEPCION_GRAFO = 1;

using namespace std;

class Cargador
{
private:
    //PRE : nombre de archivo
    //POST:carga los datos en el arbol binario de busqueda
    void cargadorDeABB(ABB<Diccionario*> &arbolAeropuertos , ifstream &archivo);

    //PRE: nombre de archivo
    //POST: carga los datos en el grafo
    void cargadorDeGrafo(Grafo<Vuelo*> &grafoVuelos , ifstream &archivo);

public://Metodos

    //PRE :Objeto Arbol, ruta al archivo
    //POST: Abre el archivo y si este no falla ejecuta el cargadorDeABB y luego lo cierra , sino tira una excepcion
    void cargarDatos(ABB<Diccionario*> &arbolAeropuertos,string ruta);

    //PRE :Objeto Grafo, ruta al archivo
    //POST: Abre el archivo y si este no falla ejecuta el cargadorDeGrafo y luego lo cierra , sino tira una excepcion
    void cargarDatos(Grafo<Vuelo*> &grafoVuelos,string ruta);

};

#endif /*CARGADOR_H*/
