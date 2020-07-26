#include "Excepcion.h"

Excepcion::Excepcion(int motivo) throw()
{
    this->motivo = motivo;
}

const char* Excepcion::what() const throw()
{
	switch(motivo)
	{
        case 0 :
            return "\tError en la lectura y cargado del ABB.";

        case 1 :
            return "\tError en la lectura y cargado del grafo.";

        default:
            return "\tError desconocido";
	}
}
