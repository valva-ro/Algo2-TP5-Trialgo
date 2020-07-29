#include <iostream>
#include "MenuAeropuerto.h"

using namespace std;

const char CONSULTAR = '1';
const char AGREGAR = '2';
const char ELIMINAR = '3';
const char MOSTRAR_IN_ORDER = '4';
const char MOSTRAR_ANCHO = '5';
const char VOLVER_MENU = '6';

void MenuAeropuerto::mostrarOpciones(){
    cout << "\n\t---------------- Menu  Aeropuerto ----------------";
    cout << "\n\t" << CONSULTAR<<". Consultar";
    cout << "\n\t" << AGREGAR<<". Agregar";
    cout << "\n\t" << ELIMINAR<<". Eliminar";
    cout << "\n\t" << MOSTRAR_IN_ORDER<<". Mostrar in order";
    cout << "\n\t" << MOSTRAR_ANCHO<<". Mostrar ancho";
    cout << "\n\t" << VOLVER_MENU<<". Volver al menu principal";
    cout << "\n\tIngrese que operacion desea realizar: ";
    selectorOpcion();
}

void MenuAeropuerto::selectorOpcion() {

    cin >> opcion;

    switch (opcion) {
        case CONSULTAR: consultar(); break;
        case AGREGAR: agregar(); break;
        case ELIMINAR: eliminar(); break;
        case MOSTRAR_IN_ORDER: mostrarInOrder(); break;
        case MOSTRAR_ANCHO: mostrarAncho(); break;
        case VOLVER_MENU: cout << "\tVolviendo al menu principal"; break;
        default: cout <<  "\tValor incorrecto. Debe ingresar un numero del 1 al 6. Volviendo al Menu Aeropuerto\n"; break;
    }

    if(opcion!=VOLVER_MENU){
        mostrarOpciones();
    }
}

void MenuAeropuerto::consultar() {
    cout << "\n\tEntraste al consultar de Menu Aeropuerto\n";
}

void MenuAeropuerto::agregar() {
    cout << "\n\tEntraste al agregar de Menu Aeropuerto\n";
}

void MenuAeropuerto::eliminar() {
    cout << "\n\tEntraste al eliminar de Menu Aeropuerto\n";
}

void MenuAeropuerto::mostrarAncho() {
    cout << "\n\tEntraste al mostrarAncho de Menu Aeropuerto\n";
}

void MenuAeropuerto::mostrarInOrder() {
    cout << "\n\tEntraste al mostrar in order de Menu Aeropuerto\n";
}

void MenuAeropuerto::asignarArbolAeropuertos(Diccionario<string, Aeropuerto *> *&arbolAeropuertosOut) {
    this->arbolAeropuertos = arbolAeropuertosOut;
}

