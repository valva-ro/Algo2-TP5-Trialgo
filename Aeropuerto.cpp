//
// Created by root-MKevin on 20/7/20.
//

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

void Aeropuerto::datosAeropuerto(){
    cout << "\n\tAEROPUERTO: " << nombre << endl;
    cout << "\tCODIGO IATA: " << codigoIata << endl;
    cout << "\tPAIS: " << pais << endl;
    cout << "\tCIUDAD: " << ciudad << endl;
    cout << "\tSUPERFICIE: " << superficie << endl;
    cout << "\tCANTIDAD DE TERMINALES: " << cantidadTerminales << endl;
    cout << "\tTIENE " << destinosNacionales << " DESTINOS NACIONALES" << endl;
    cout << "\tTIENE " << destinosInternacionales << " DESTINOS INTERNACIONALES" << endl;
}