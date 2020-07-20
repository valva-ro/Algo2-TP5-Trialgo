//
// Created by root-MKevin on 20/7/20.
//

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Aeropuerto.h"
#include<string>
using namespace std;

class Diccionario {

    private:

        //ATRIBUTOS
        string clave;
        Aeropuerto *valor;

    public:

        //METODOS

        //CONSTRUCTOR

        //PRE: RECIBE UN STRING VALIDO Y UN PUNTERO DE TIPO AEROPUERTO.
        //POST: CONSTRUYE UN OBJETO DE TIPO DICCIONARIO.
        Diccionario( string claveRecibida, Aeropuerto *valorRecibido);

        //CONSULTORES

        //PRE: NO RECIBE NADA.
        //POST: DEVUELVE EL VALOR DE LA CAVE.
        string obtenerClave();

        //PRE: NO RECIBE NADA.
        //POST: DEVUELVE UN PUNTERO DE TIPO AEROPUERTO DIRECCIONADO AL MISMO LUGAR QUE EL ATRIBUTO VALOR.
        Aeropuerto* obtenerValor();
};


#endif //TP5_TRIALGO_DICCIONARIO_H
