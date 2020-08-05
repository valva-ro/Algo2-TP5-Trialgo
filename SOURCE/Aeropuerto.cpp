#include "../HEADERS/Aeropuerto.h"

Aeropuerto::Aeropuerto(string codigoIataRecibido, string nombreRecibido, string ciudadRecibida, string paisRecibido,
        double superficieRecibida, int cantidadTerminalesRecibidas, int destinosNacionalesRecibidos,
        int destinosInternacionalesRecibidos){
    codigoIata = codigoIataRecibido;
    nombre = nombreRecibido;
    ciudad = ciudadRecibida;
    pais = paisRecibido;
    superficie = superficieRecibida;
    cantidadTerminales = cantidadTerminalesRecibidas;
    destinosNacionales = destinosNacionalesRecibidos;
    destinosInternacionales = destinosInternacionalesRecibidos;
}

ostream& operator << (ostream& o, Aeropuerto &aeropuerto){
    o << "\n\tAEROPUERTO: " << aeropuerto.nombre << endl;
    o << "\tCODIGO IATA: " << aeropuerto.codigoIata << endl;
    o << "\tPAIS: " << aeropuerto.pais << endl;
    o << "\tCIUDAD: " << aeropuerto.ciudad << endl;
    o << "\tSUPERFICIE: " << aeropuerto.superficie << endl;
    o << "\tCANTIDAD DE TERMINALES: " << aeropuerto.cantidadTerminales << endl;
    o << "\tTIENE " << aeropuerto.destinosNacionales << " DESTINOS NACIONALES" << endl;
    o << "\tTIENE " << aeropuerto.destinosInternacionales << " DESTINOS INTERNACIONALES" << endl;
    return o;
}