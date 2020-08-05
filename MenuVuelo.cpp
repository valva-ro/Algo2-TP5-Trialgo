#include <iostream>
#include "MenuVuelo.h"

using namespace std;

const char MENOR_COSTO = '1';
const char MENOR_TIEMPO = '2';
const char VOLVER_MENU = '0';

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
    cout << "\n\tEntraste al menor costo de Menu vuelo\n";

    //string origen , destino = validarAeropuertos() ;
    cout << "\nArmando tu mejor opcion...\n";

    grafo->minimoPrecio(origen,destino);
}

void MenuVuelo::menorTiempo() {
    cout << "\n\tEntraste al menor tiempo de Menu vuelo\n";

    //string origen , destino = validarAeropuertos() ;
    cout << "\nArmando tu mejor opcion...\n";

    grafo->minimoTiempo(origen,destino);

}

void MenuVuelo::liberarRecursos() {
    //implementar cuando tengamos el grafo
}
