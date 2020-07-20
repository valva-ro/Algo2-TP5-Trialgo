//
// Created by alexteper on 20/7/20.
//

#include "MenuVuelo.h"

using namespace std;

void MenuVuelo::mostrarOpciones() {
    cout<<endl<<"Menu Vuelo"<<endl;
    cout<<"Ingrese que operacion desea realizar:"<<endl;
    cout<<"1. Menor Costo"<<endl;
    cout<<"2. Menor Tiempo"<<endl;
    selectorOpcion();
}

void MenuVuelo::selectorOpcion() {
    cout<<"Entraste al selector de opcion de Menu Vuelo"<<endl;

    cin>>opcion;

    switch (opcion) {
        case 1: menorCosto(); break;
        case 2: menorTiempo(); break;
        default:cout<< "Valor incorrecto. Debe ingresar un numero del 1 al 2. Volviendo al Menu Vuelo"<<endl; mostrarOpciones(); break;
    }
}

void MenuVuelo::menorCosto() {
    cout<<"Entraste al menor costo de Menu vuelo"<<endl;
}

void MenuVuelo::menorTiempo() {
    cout<<"Entraste al menor tiempo de Menu vuelo"<<endl;
}