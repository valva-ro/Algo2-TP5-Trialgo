#include "Excepcion.h"

Excepcion::Excepcion(int motivo)
{
    this->motivo = motivo;
}

const char* ExcepcionLectura::what() const throw()
{
	switch(motivo)
	{
    case 0 : return "Error en la lectura y cargado del ABB."
    case 1 : return "Error en la lectura y cargado del grafo."
	};
}
