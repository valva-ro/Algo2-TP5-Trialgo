#include "ExcepcionDiccionario.h"

const char* ExcepcionDiccionario::what() const throw()
{
    return "\tError en la lectura y cargado del diccionario.";
}

