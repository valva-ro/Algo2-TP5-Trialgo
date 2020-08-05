#include "ExcepcionDiccionario.h"

ExcepcionDiccionario::ExcepcionDiccionario() throw()
{
    ///NADA///
}

const char* ExcepcionDiccionario::what() const throw()
{
    return "\tError en la lectura y cargado del diccionario.";
}

