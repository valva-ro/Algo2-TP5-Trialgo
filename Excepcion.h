#ifndef EXCEPCION_H
#define EXCEPCION_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Excepcion: public exception {

private:
    int motivo;
public:

    // Constructor de la excepcion con el nombre del archivo
	//PRE: Recibe un motivo entero
	//POST: Crea un objeto ExcepcionLectura
    Excepcion(int motivo) throw();

    //Destructor
    //virtual ~Excepcion() throw();

    //PRE: -
    //POST: devuelve un mensaje describiendo la excepcion segun el motivo
    virtual const char* what() const throw();

};

#endif //EXCEPCION_H
