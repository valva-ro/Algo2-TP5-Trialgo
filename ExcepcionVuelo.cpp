#include "ExcepcionVuelo.h"

ExcepcionGrafo::ExcepcionVuelo() throw()
{
    ///NADA///
}

const char* ExcepcionVuelo::what() const throw()
{
    return "\tTodavia no tenemos conexiones a esos destinos !";
}

