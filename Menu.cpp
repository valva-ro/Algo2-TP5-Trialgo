//
// Created by alexteper on 20/7/20.
//

#include "Menu.h"
#include <iostream>
#include "MenuAeropuerto.h"
#include "MenuVuelo.h"
const char MENU_AEROPUERTO = '1';
const char MENU_VUELO = '2';
const char SALIR = '3';

using namespace std;


void Menu::mostrarOpciones() {
    cout<<endl<<endl<<"Menu principal"<<endl;
    cout<<"Ingrese que operacion desea realizar:"<<endl;
    cout<<MENU_AEROPUERTO<<" Acceder al Menu del aeropuerto"<<endl;
    cout<<MENU_VUELO<<" Acceder al Menu de vuelos"<<endl;
    cout<<SALIR<<" Finalizar el programa"<<endl;
    selectorOpcion();
}

void Menu::selectorOpcion() {
    cin>>opcion;

    switch (opcion) {
        case MENU_AEROPUERTO: menuAeropuerto.mostrarOpciones();break;
        case MENU_VUELO: menuVuelo.mostrarOpciones();break;
        case SALIR: cout<<endl<<"Muchas gracias por utilizar Trialgo"<<endl;break;
        default: cout<< "Valor incorrecto. Debe ingresar un numero del 1 al 3. Volviendo al Menu principal"<<endl; break;
    }

    if(opcion!=SALIR){
        mostrarOpciones();
    }
}
