#include "Aeropuerto.h"

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
    cout << "\n\tAEROPUERTO: " << aeropuerto.nombre << endl;
    cout << "\tCODIGO IATA: " << aeropuerto.codigoIata << endl;
    cout << "\tPAIS: " << aeropuerto.pais << endl;
    cout << "\tCIUDAD: " << aeropuerto.ciudad << endl;
    cout << "\tSUPERFICIE: " << aeropuerto.superficie << endl;
    cout << "\tCANTIDAD DE TERMINALES: " << aeropuerto.cantidadTerminales << endl;
    cout << "\tTIENE " << aeropuerto.destinosNacionales << " DESTINOS NACIONALES" << endl;
    cout << "\tTIENE " << aeropuerto.destinosInternacionales << " DESTINOS INTERNACIONALES" << endl;


}