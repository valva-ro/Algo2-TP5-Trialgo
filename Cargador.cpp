#include "Cargador.h"

void Cargador::cargadorDeABB(ABB<Diccionario*> &arbolAeropuertos , ifstream& archivo)
{
    string nombre, ciudad, pais, codigoIATA;
    double superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;


    if(!archivo.fail())
    {
        Aeropuerto *pAeropuerto;
        while(!archivo.eof())
        {
            archivo >> codigoIATA;
            archivo >> nombre;
            archivo >> ciudad;
            archivo >> pais;
            archivo >> superficie;
            archivo >> cantidadTerminales;
            archivo >> destinosNacionales;
            archivo >> destinosInternacionales;

            pAeropuerto = new Aeropuerto(codigoIATA,nombre,ciudad,pais,superficie,cantidadTerminales,destinosNacionales,destinosInternacionales);

            Diccionario* dicAeropuerto = new Diccionario(codigoIATA, pAeropuerto);
            arbolAeropuertos.insertar(dicAeropuerto);
        }
        cout << "\n\tSe han cargado los Aeropuertos en el arbol correctamente\n";

    }
    else{
        //Tiro la excepcion
        try {
            throw(Excepcion(EXCEPCION_ABB));
        }
        catch(Excepcion& e) {
            cout << e.what() << endl;
        }
    }
    archivo.close();
}

void Cargador:: cargadorDeGrafo(int &grafo, ifstream &archivo) {
    //TODO
}