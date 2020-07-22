#include "Menu.h"
#include <iostream>

const char MENU_AEROPUERTO = '1';
const char MENU_VUELO = '2';
const char SALIR = '3';

using namespace std;

void Menu::mostrarOpciones() {
    cout << "\n\n\t================= Menu Principal =================";
    cout << "\n\t" << MENU_AEROPUERTO << ". Acceder al menu del aeropuerto";
    cout << "\n\t" << MENU_VUELO << ". Acceder al menu de vuelos";
    cout << "\n\t" << SALIR << ". Finalizar el programa";
    cout << "\n\tIngrese que operacion desea realizar: ";
    selectorOpcion();
}

void Menu::selectorOpcion() {
    cin >> opcion;

    switch (opcion) {
        case MENU_AEROPUERTO: menuAeropuerto.mostrarOpciones(); break;
        case MENU_VUELO: menuVuelo.mostrarOpciones(); break;
        case SALIR: cout << "\n\tMuchas gracias por utilizar Trialgo\n"; break;
        default: cout <<  "\tValor incorrecto. Debe ingresar un numero del 1 al 3. Volviendo al Menu principal\n"; break;
    }

    if(opcion!=SALIR){
        mostrarOpciones();
    }
}
