#ifndef EXCEPCION_DICCIONARIO_H
#define EXCEPCION_DICCIONARIO_H

#include <exception>

using namespace std;

class ExcepcionDiccionario: public exception
{

    public:
        //PRE: -
        //POST: devuelve un mensaje describiendo la excepcion
        virtual const char* what() const throw();
};

#endif //EXCEPCION_DICCIONARIO_H
