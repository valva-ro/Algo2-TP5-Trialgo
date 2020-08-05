#ifndef EXCEPCION_VUELO_H
#define EXCEPCION_VUELO_H

#include <exception>

using namespace std;

class ExcepcionVuelo: public exception
{


    public:
        // Constructor de la excepcion con el nombre del archivo
        //PRE: -
        //POST: Crea un objeto ExcepcionLectura
        ExcepcionVuelo() throw();

        //Destructor
        //virtual ~Excepcion() throw();

        //PRE: -
        //POST: devuelve un mensaje describiendo la excepcion
        virtual const char* what() const throw();
};

#endif //EXCEPCION_VUELO_H
