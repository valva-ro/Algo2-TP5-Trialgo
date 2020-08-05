#ifndef EXCEPCION_GRAFO_H
#define EXCEPCION_GRAFO_H

#include <exception>

using namespace std;

class ExcepcionGrafo: public exception
{

    public:
        // Constructor de la excepcion con el nombre del archivo
        //PRE: -
        //POST: Crea un objeto ExcepcionGrafo
        ExcepcionGrafo() throw();


        //PRE: -
        //POST: devuelve un mensaje describiendo la excepcion
        virtual const char* what() const throw();
};

#endif //EXCEPCION_GRAFO_H
