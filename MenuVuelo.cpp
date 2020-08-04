#include <iostream>
#include "MenuVuelo.h"
#include "Validaciones.h"

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

void MenuVuelo::mostrarDatosAeropuerto(string origenIATA, string destinoIATA) {

    Aeropuerto *origen = 0, *destino = 0;

    if (!aeropuertos->existe(origenIATA))
        cout << "\tNo se puede mostrar informacion sobre el aeropuerto de origen porque no esta cargado en la base de datos\n";
    else
        origen = aeropuertos->obtenerValor(origenIATA);

    if (!aeropuertos->existe(destinoIATA))
        cout << "\tNo se puede mostrar informacion sobre el aeropuerto de destino no esta cargado en la base de datos\n";
    else
        destino = aeropuertos->obtenerValor(destinoIATA);

    if(origen != 0 && destino != 0)
        cout << "\n\tOrigen:\n" << *aeropuertos->obtenerValor(origenIATA) << "\n\tDestino:\n" << *aeropuertos->obtenerValor(destinoIATA);

    else if (origen != 0)
        cout << "\n\tOrigen:\n" << *aeropuertos->obtenerValor(origenIATA) << "\n\tDestino: " << destinoIATA;

    else if (destino != 0)
        cout << "\n\tOrigen: " << origenIATA << "\n\tDestino:\n" << *aeropuertos->obtenerValor(destinoIATA);

    else
        cout << "\n\tOrigen: " << origenIATA << "\n\tDestino: " << destinoIATA;

    cout << "\n";
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

    mostrarDatosAeropuerto(origen, destino);

    //TODO: mostrar el camino con menor costo desde origen hasta destino (a traves de la clase vuelos)
    //      por ahora muestro las matrices con los caminos minimos

    cout << "\n\tMostrando matriz de costos\n";
    vuelos->mostrarCaminosMinimosPrecios();
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

    mostrarDatosAeropuerto(origen, destino);

    //TODO: mostrar el camino con menor duracion desde origen hasta destino (a traves de la clase vuelos)
    //      por ahora muestro las matrices con los caminos minimos

    cout << "\n\tMostrando matriz de tiempos\n";
    vuelos->mostrarCaminosMinimosTiempos();
}

void MenuVuelo::liberarRecursos() {
    delete vuelos;
}