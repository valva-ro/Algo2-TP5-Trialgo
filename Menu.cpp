//
// Created by alexteper on 20/7/20.
//

#include "Menu.h"



void Menu::mostrarOpciones() {
    cout<<endl<<"Menu principal"<<endl;
    cout<<"Ingrese que operacion desea realizar:"<<endl;
    cout<<"1. Acceder al Menu del aeropuerto"<<endl;
    cout<<"2. Acceder al Menu de vuelos"<<endl;
    cout<<"3. Finalizar el programa"<<endl;
    selectorOpcion();
}

void Menu::selectorOpcion() {
    cin>>opcion;

    switch (opcion) {
        case 1: menuAeropuerto.mostrarOpciones();break;
        case 2: menuVuelo.mostrarOpciones();break;
        case 3: cout<<endl<<"Muchas gracias por utilizar Trialgo"<<endl;break;
        default: cout<< "Valor incorrecto. Debe ingresar un numero del 1 al 3. Volviendo al Menu principal"<<endl; break;
    }

    if(opcion!=3){
        mostrarOpciones();
    }
}
