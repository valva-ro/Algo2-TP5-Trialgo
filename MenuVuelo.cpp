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
}