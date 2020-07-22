#include "MenuVuelo.h"
#include <iostream>

using namespace std;

const char MENOR_COSTO = '1';
const char MENOR_TIEMPO = '2';
const char VOLVER_MENU = '3';

void MenuVuelo::mostrarOpciones() {
    cout<<endl<<"Menu Vuelo"<<endl;
    cout<<"Ingrese que operacion desea realizar:"<<endl;
    cout<<MENOR_COSTO<<" Menor Costo"<<endl;
    cout<<MENOR_TIEMPO<<" Menor Tiempo"<<endl;
    cout<<VOLVER_MENU<<" Volver al menu principal"<<endl;
    selectorOpcion();
}

void MenuVuelo::selectorOpcion() {

    cin>>opcion;

    switch (opcion) {
        case MENOR_COSTO: menorCosto(); break;
        case MENOR_TIEMPO: menorTiempo(); break;
        case VOLVER_MENU: cout<<"Volviendo al menu principal"; break;
        default:cout<< "Valor incorrecto. Debe ingresar un numero del 1 al 3. Volviendo al Menu Vuelo"<<endl; mostrarOpciones(); break;
    }

    if(opcion!=VOLVER_MENU){
        mostrarOpciones();
    }
}

void MenuVuelo::menorCosto() {
    cout<<endl<<"Entraste al menor costo de Menu vuelo"<<endl;
}

void MenuVuelo::menorTiempo() {
    cout<<endl<<"Entraste al menor tiempo de Menu vuelo"<<endl;
}