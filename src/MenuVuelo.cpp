#include <iostream>
#include "../include/MenuVuelo.h"
#include "../include/Validaciones.h"

using namespace std;

const char MENOR_COSTO  = '1';
const char MENOR_TIEMPO = '2';
const char VER_AEROPUERTOS = '3';
const char AGREGAR_VUELO = '4';
const char ELIMINAR_VUELO = '5';
const char VOLVER_MENU  = '0';

void MenuVuelo::mostrarOpciones() {
    cout << "\n\t------------------- Menu Vuelo -------------------";
    cout << "\n\t" << MENOR_COSTO << ". Menor costo";
    cout << "\n\t" << MENOR_TIEMPO << ". Menor tiempo";
    cout << "\n\t" << VER_AEROPUERTOS << ". Ver aeropuertos disponibles";
    cout << "\n\t" << AGREGAR_VUELO << ". Agregar vuelo";
    cout << "\n\t" << ELIMINAR_VUELO << ". Eliminar vuelo";
    cout << "\n\t" << VOLVER_MENU << ". Volver al menu principal";
    cout << "\n\tIngrese que operacion desea realizar:  ";
    selectorOpcion();
}

void MenuVuelo::selectorOpcion() {

    cin >> opcion;

    switch (opcion) {
        case MENOR_COSTO: menorCosto(); break;
        case MENOR_TIEMPO: menorTiempo(); break;
        case VER_AEROPUERTOS: mostrarAeropuertos(); break;
        case AGREGAR_VUELO: agregarVuelo(); break;
        case ELIMINAR_VUELO: eliminarVuelo(); break;
        case VOLVER_MENU: cout << "\tVolviendo al menu principal"; break;
        default: cout << "\tValor incorrecto. Debe ingresar un numero del 0 al 2. Volviendo al Menu Vuelo\n"; break;
    }

    if(opcion!=VOLVER_MENU){
        mostrarOpciones();
    }
}

void MenuVuelo::asignarGrafoVuelos(Grafo *&grafoVuelos) {
    this->vuelos = grafoVuelos;
}

void MenuVuelo::asignarArbolAeropuertos(Diccionario<string, Aeropuerto *> *&arbolAeropuertosOut) {
    this->aeropuertos = arbolAeropuertosOut;
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

    if (vuelos->existeVertice(origen) && vuelos->existeVertice(destino))
        vuelos->multiplesPreciosMinimos(origen, destino, aeropuertos);
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

    if (vuelos->existeVertice(origen) && vuelos->existeVertice(destino))
        vuelos->multiplesTiemposMinimos(origen, destino, aeropuertos);
    else
        cout << "\tNo existe el aeropuerto de origen o destino\n";

}

void MenuVuelo:: mostrarAeropuertos() {
    cout << "\n\tLos aeropuertos disponibles son:\n";
    vuelos->mostrarVertices();
}

void MenuVuelo::agregarVuelo() {
    Validaciones validacion;
    string origen, destino, precioStr, horasStr;
    int precio;
    float horas;

    cout << "\n\tIngrese el codigo IATA de origen: ";
    cin >> origen;
    validacion.longitudString(origen, 3);
    validacion.convertirEnMayusculas(origen);

    cout << "\tIngrese el codigo IATA de destino: ";
    cin >> destino;
    validacion.longitudString(destino, 3);
    validacion.convertirEnMayusculas(destino);

    cout << "\tIngrese el precio: ";
    cin >> precioStr;
    precio = validacion.esEntero(precioStr);
    validacion.esPositivo(precio);

    cout << "\tIngrese la duracion: ";
    cin >> horasStr;
    horas = validacion.esFlotante(horasStr);
    validacion.esPositivo(horas);

    vuelos->insertarArista(origen, destino, precio, horas);
}

void MenuVuelo:: eliminarVuelo() {
    Validaciones validacion;
    string origen, destino;

    cout << "\n\tIngrese el codigo IATA de origen: ";
    cin >> origen;
    validacion.longitudString(origen, 3);
    validacion.convertirEnMayusculas(origen);

    cout << "\tIngrese el codigo IATA de destino: ";
    cin >> destino;
    validacion.longitudString(destino, 3);
    validacion.convertirEnMayusculas(destino);

    vuelos->eliminarArista(origen, destino);
}

void MenuVuelo::liberarRecursos() {
    delete vuelos;
}