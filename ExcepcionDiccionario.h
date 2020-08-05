#ifndef EXCEPCION_DICCIONARIO_H
#define EXCEPCION_DICCIONARIO_H

#include <exception>

using namespace std;

class ExcepcionDiccionario: public exception
{

    public:
        // Constructor de la excepcion con el nombre del archivo
        //PRE: -
        //POST: Crea un objeto ExcepcionLectura
        ExcepcionDiccionario() throw();

        //Destructor
        //virtual ~Excepcion() throw();

        //PRE: -
        //POST: devuelve un mensaje describiendo la excepcion
        virtual const char* what() const throw();
};

#endif //EXCEPCION_DICCIONARIO_H
