#ifndef CARGADOR_H
#define CARGADOR_H

//Librerias de C++
#include<fstream>

//Librerias locales
#include "Diccionario.h"
#include "Grafo.h"
#include "Aeropuerto.h"
#include "Excepcion.h"

//Constantes de excepcion
const int EXCEPCION_ABB   = 0;
const int EXCEPCION_GRAFO = 1;

using namespace std;

class Cargador
{
    private:
        //PRE : ABB , archivo ya abierto
        //POST:carga los datos en el arbol binario de busqueda
        void cargadorDeDiccionario(Diccionario<string ,Aeropuerto*> *&arbolAeropuertos, ifstream &archivo);

        //PRE: Grafo , archivo ya abierto
        //POST: carga los datos en el grafo
        void cargadorDeGrafo(Grafo *&grafoVuelos , ifstream &archivo);

    public:
        //PRE : Objeto Arbol, ruta al archivo
        //POST: Abre el archivo y carga los datos , de fallar se ejecuta la excepcion
        void cargarDatos(Diccionario<string ,Aeropuerto*> *&arbolAeropuertos, const string& ruta);

        //PRE :Objeto Grafo, ruta al archivo
        //POST:Abre el archivo y carga los datos , de fallar se ejecuta la excepcion
        void cargarDatos(Grafo *&grafoVuelos, const string& ruta);
};

#endif /*CARGADOR_H*/
