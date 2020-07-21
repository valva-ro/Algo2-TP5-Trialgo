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

        //PRE: RECIBE UN STRING ALFABETICO DE SOLO TRES CARACTERES Y EN MAYUSCULA Y, UN PUNTERO DE TIPO AEROPUERTO.
        //POST: CONSTRUYE UN OBJETO DE TIPO DICCIONARIO.
        Diccionario( string claveRecibida, Aeropuerto *valorRecibido);

        //CONSULTORES

        //PRE: -.
        //POST: DEVUELVE EL VALOR DEL ATRIBUTO clave.
        string obtenerClave();

        //PRE: -.
        //POST: DEVUELVE UN PUNTERO DE TIPO AEROPUERTO DIRECCIONADO AL MISMO LUGAR QUE EL ATRIBUTO valor.
        Aeropuerto* obtenerValor();

        //PRE: -.
        //POST: LIBERA LA MEMORIA ALOJADA EN EL ATRIBUTO valor.
        ~Diccionario();
};


#endif //TP5_TRIALGO_DICCIONARIO_H
