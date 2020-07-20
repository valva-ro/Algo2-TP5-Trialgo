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
    cout<<"3. Volver al menu principal"<<endl;
    selectorOpcion();
}

void MenuVuelo::selectorOpcion() {

    cin>>opcion;

    switch (opcion) {
        case 1: menorCosto(); break;
        case 2: menorTiempo(); break;
        case 3: cout<<"Volviendo al menu principal"; break;
        default:cout<< "Valor incorrecto. Debe ingresar un numero del 1 al 3. Volviendo al Menu Vuelo"<<endl; mostrarOpciones(); break;
    }

    if(opcion!=3){
        mostrarOpciones();
    }
}

void MenuVuelo::menorCosto() {
    cout<<endl<<"Entraste al menor costo de Menu vuelo"<<endl;
}

void MenuVuelo::menorTiempo() {
    cout<<endl<<"Entraste al menor tiempo de Menu vuelo"<<endl;
}