#ifndef EXCEPCION_VUELO_H
#define EXCEPCION_VUELO_H

#include <exception>

using namespace std;

class ExcepcionVuelo: public exception
{


    public:

        //PRE: -
        //POST: devuelve un mensaje describiendo la excepcion
        virtual const char* what() const throw();
};

#endif //EXCEPCION_VUELO_H
