#include "ExcepcionVuelo.h"

const char* ExcepcionVuelo::what() const throw()
{
    return "\tTodavia no tenemos conexiones a esos destinos !";
}

