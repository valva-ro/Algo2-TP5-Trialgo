#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include "Aeropuerto.h"
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

        //PRE: -.
        //POST: DEVUELVE UN DICCIONARIO CON LOS MISMOS ATRIBUTOS QUE EL DICCIONARIO RECIBIDO
        Diccionario& operator = (const Diccionario &diccionario);

        //PRE: -.
        //POST: DEVUELVE TRUE SI EL PRIMER DICCIONARIO ES MAYOR AL RECIBIDO, DE LO CONTRARIO FALSE.
        bool operator > (const Diccionario &diccionario);

        //PRE: -.
        //POST: DEVUELVE TRUE SI EL PRIMER DICCIONARIO ES MENOR AL RECIBIDO, DE LO CONTRARIO FALSE.
        bool operator < (const Diccionario &diccionario);

        //PRE: -.
        //POST: DEVUELVE TRUE SI AMBOS DICCIONARIOS SON IGUALES, DE LO CONTRARIO FALSE.
        bool operator == (const Diccionario &diccionario);

        //PRE: -.
        //POST: SOBRECARGA DEL OPERADOR << PARA MOSTRAR POR PANTALLA LA CLAVE Y EL VALOR DEL DICCIONARIO.
        friend ostream& operator << (ostream &out, const Diccionario &diccionario);
};


#endif //TP5_TRIALGO_DICCIONARIO_H
