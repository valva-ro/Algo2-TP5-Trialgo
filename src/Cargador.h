#ifndef CARGADOR_H
#define CARGADOR_H

//Librerias de C++
#include <fstream>

//Librerias locales
#include "Estructuras No Lineales/Diccionario.h"
#include "Estructuras No Lineales/Grafo.h"
#include "Aeropuerto.h"
#include "../excepciones/ExcepcionGrafo.h"
#include "../excepciones/ExcepcionDiccionario.h"



using namespace std;

class Cargador
{
    private:
        //PRE : -
        //POST: Carga los datos del archivo en el diccionario
        void cargadorDeDiccionario(Diccionario<string, Aeropuerto*> *&arbolAeropuertos, ifstream &archivo);

        //PRE : -
        //POST: Carga los datos del archivo en el grafo
        void cargadorDeGrafo(Grafo *&grafoVuelos, ifstream &archivo);

    public:
        //PRE : El string es la ruta al archivo
        //POST: Abre el archivo y carga los datos, de fallar se lanza la excepcion
        void cargarDatos(Diccionario<string, Aeropuerto*> *&arbolAeropuertos, const string& ruta);

        //PRE : El string es la ruta al archivo
        //POST: Abre el archivo y carga los datos, de fallar se lanza la excepcion
        void cargarDatos(Grafo *&grafoVuelos, const string& ruta);
};

#endif /*CARGADOR_H*/
