//
// Created by root-MKevin on 20/7/20.
// codigo_IATA nombre ciudad pais superficie #cantidad_terminales #destinos_nacionales #destinos_internacionales

#ifndef TP5_TRIALGO_AEROPUERTO_H
#define TP5_TRIALGO_AEROPUERTO_H

#include <string>
using namespace std;

class Aeropuerto {

    private:

        //ATRIBUTOS

        string codigoIata, nombre, ciudad, pais;
        double superficie;
        int cantidadTerminales, destinosNacionales, destinosInternacionales;

    public:

        //METODOS

        //CONSTRUCTOR

        //PRE: RECIBE STRINGS VALIDOS Y TANTO EL DOUBLE COMO LOS PARAMETROS INT SON MAYORES QUE CERO.
        //POST: CONSTRUYE UN OBJETO DE TIPO AEROPUERTO.
        Aeropuerto(string codigoIataRecibido, string nombreRecibido, string ciudadRecibida, string paisRecibido,
                double superficieRecibida, int cantidadTerminalesRecibidas, int destinosNacionalesRecibidos,
                int destinosInternacionalesRecibidos);

        // CONSULTORES

        //PRE: NO RECIBE NADA.
        //POST: IMPRIME LOS VALORES DE LOS ATRIBUTOS POR PANTALLA.
        void datosAeropuerto();
};


#endif //TP5_TRIALGO_AEROPUERTO_H
