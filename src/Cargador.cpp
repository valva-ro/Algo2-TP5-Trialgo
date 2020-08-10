#include <iostream>
#include "Cargador.h"

    /// METODOS PRIVADOS ///

void Cargador::cargarDatos(Diccionario<string, Aeropuerto*> *&arbolAeropuertos, const string& ruta)
{
    ifstream archivo;
    archivo.open(ruta.c_str(),ios::in);

    try {
        if (archivo.fail())
            throw (ExcepcionDiccionario());

        cargadorDeDiccionario(arbolAeropuertos, archivo);
        cout << "\n\tSe han cargado los aeropuertos en el arbol correctamente\n";
    }
    catch(ExcepcionDiccionario &e) {
        cout << e.what() << endl;
    }

    archivo.close();
}

void Cargador::cargarDatos(Grafo *&grafoVuelos, const string &ruta)
{
    ifstream archivo;
    archivo.open(ruta.c_str(),ios::in);

    try {
        if (archivo.fail())
            throw (ExcepcionGrafo());

        cargadorDeGrafo(grafoVuelos, archivo);
        cout << "\n\tSe han cargado los vuelos en el grafo correctamente\n";
    }

    catch(ExcepcionGrafo &e) {
        cout << e.what() << endl;
    }

    archivo.close();
}

    /// METODOS PUBLICOS ///

void Cargador::cargadorDeDiccionario(Diccionario<string, Aeropuerto*> *&arbolAeropuertos, ifstream& archivo)
{
    string nombre, ciudad, pais, codigoIATA;
    double superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;

    Aeropuerto *pAeropuerto;

    while(!archivo.eof()) {

        archivo >> codigoIATA;
        archivo >> nombre;
        archivo >> ciudad;
        archivo >> pais;
        archivo >> superficie;
        archivo >> cantidadTerminales;
        archivo >> destinosNacionales;
        archivo >> destinosInternacionales;

        pAeropuerto = new Aeropuerto(codigoIATA, nombre, ciudad,
                                     pais, superficie, cantidadTerminales,
                                     destinosNacionales, destinosInternacionales);

        arbolAeropuertos->insertar(codigoIATA,pAeropuerto);
    }

}

void Cargador:: cargadorDeGrafo(Grafo *&grafoVuelos, ifstream &archivo)
{
    string origen, destino;
    int precio;
    float horas;

    while(!archivo.eof()) {
        archivo >> origen;
        archivo >> destino;
        archivo >> precio;
        archivo >> horas;
        grafoVuelos->insertarArista(origen, destino, precio, horas);
    }
}

