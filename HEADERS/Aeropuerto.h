#ifndef TP5_TRIALGO_AEROPUERTO_H
#define TP5_TRIALGO_AEROPUERTO_H

#include <iostream>
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

        //PRE: -.
        //POST: SOBRECARGA DEL OPERADOR << PARA MOSTRAR LOS DATOS DEL AEROPUERTO POR PANTALLA.
        friend ostream& operator << (ostream& o, Aeropuerto &aeropuerto);
};


#endif //TP5_TRIALGO_AEROPUERTO_H
