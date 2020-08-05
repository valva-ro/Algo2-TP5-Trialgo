#include "ExcepcionGrafo.h"

ExcepcionGrafo::ExcepcionGrafo() throw()
{
    ///NADA///
}

const char* ExcepcionGrafo::what() const throw()
{
    return "\tError en la lectura y cargado del grafo.";
}

