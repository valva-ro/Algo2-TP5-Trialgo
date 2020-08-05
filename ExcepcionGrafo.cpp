#include "ExcepcionGrafo.h"

const char* ExcepcionGrafo::what() const throw()
{
    return "\tError en la lectura y cargado del grafo.";
}

