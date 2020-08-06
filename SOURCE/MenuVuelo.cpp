#include <iostream>
#include "../HEADERS/MenuVuelo.h"
#include "../HEADERS/Validaciones.h"

using namespace std;

const char MENOR_COSTO = '1';
const char MENOR_TIEMPO = '2';
const char VOLVER_MENU = '0';

void MenuVuelo::asignarGrafoVuelos(Grafo *&grafoVuelos) {
    this->vuelos = grafoVuelos;
}

void MenuVuelo::asignarArbolAeropuertos(Diccionario<string, Aeropuerto *> *&arbolAeropuertosOut) {
    this->aeropuertos = arbolAeropuertosOut;
}

void MenuVuelo::mostrarOpciones() {
    cout << "\n\t------------------- Menu Vuelo -------------------\n";
    cout << "\n\t" << MENOR_COSTO << ". Menor costo";
    cout << "\n\t" << MENOR_TIEMPO << ". Menor tiempo";
    cout << "\n\t" << VOLVER_MENU << ". Volver al menu principal";
    cout << "\n\tIngrese que operacion desea realizar:  ";
    selectorOpcion();
}

void MenuVuelo::selectorOpcion() {

    cin >> opcion;

    switch (opcion) {
        case MENOR_COSTO: menorCosto(); break;
        case MENOR_TIEMPO: menorTiempo(); break;
        case VOLVER_MENU: cout << "\tVolviendo al menu principal"; break;
        default: cout << "\tValor incorrecto. Debe ingresar un numero del 0 al 2. Volviendo al Menu Vuelo\n"; break;
    }

    if(opcion!=VOLVER_MENU){
        mostrarOpciones();
    }
}

void MenuVuelo::menorCosto() {

    Validaciones validacion;
    string origen, destino;

    cout << "\tIngrese la clave IATA del origen: ";
    cin >> origen;
    validacion.longitudString(origen, 3);
    validacion.convertirEnMayusculas(origen);

    cout << "\tIngrese la clave IATA del destino: ";
    cin >> destino;
    validacion.longitudString(destino, 3);
    validacion.convertirEnMayusculas(destino);

    if (vuelos->existeVertice(origen) && vuelos->existeVertice(destino)) {
        cout << "\n\t--- Origen ---" << *aeropuertos->obtenerValor(origen);
        cout << "\n\t--  Destino --" << *aeropuertos->obtenerValor(destino);
        vuelos->mostrarCaminosMinimosPrecios(origen, destino, aeropuertos);
    }
    else
        cout << "\tNo existe el aeropuerto de origen o destino\n";
}

void MenuVuelo::menorTiempo() {

    Validaciones validacion;
    string origen, destino;

    cout << "\tIngrese la clave IATA del origen: ";
    cin >> origen;
    validacion.longitudString(origen, 3);
    validacion.convertirEnMayusculas(origen);

    cout << "\tIngrese la clave IATA del destino: ";
    cin >> destino;
    validacion.longitudString(destino, 3);
    validacion.convertirEnMayusculas(destino);

    if (vuelos->existeVertice(origen) && vuelos->existeVertice(destino)) {
        cout << "\n\t--- Origen ---" << *aeropuertos->obtenerValor(origen);
        cout << "\n\t--  Destino --" << *aeropuertos->obtenerValor(destino);
        vuelos->mostrarCaminosMinimosTiempos(origen, destino, aeropuertos);
    }
    else
        cout << "\tNo existe el aeropuerto de origen o destino\n";
}

void MenuVuelo::liberarRecursos() {
    delete vuelos;
}