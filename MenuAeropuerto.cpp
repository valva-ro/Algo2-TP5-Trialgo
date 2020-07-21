//
// Created by alexteper on 20/7/20.
//

#include "MenuAeropuerto.h"
#include <iostream>

using namespace std;

const char CONSULTAR = '1';
const char AGREGAR = '2';
const char ELIMINAR = '3';
const char MOSTRAR_IN_ORDER = '4';
const char MOSTRAR_ANCHO = '5';
const char VOLVER_MENU = '6';

void MenuAeropuerto::mostrarOpciones() {
    cout<<endl<<"Menu Aeropuerto"<<endl;
    cout<<"Ingrese que operacion desea realizar:"<<endl;
    cout<<CONSULTAR<<" Consultar"<<endl;
    cout<<AGREGAR<<" Agregar"<<endl;
    cout<<ELIMINAR<<" Eliminar"<<endl;
    cout<<MOSTRAR_IN_ORDER<<" Mostrar in Order"<<endl;
    cout<<MOSTRAR_ANCHO<<" Mostrar ancho"<<endl;
    cout<<VOLVER_MENU<<" Volver al Menu principal"<<endl;
    selectorOpcion();
}

void MenuAeropuerto::selectorOpcion() {

    cin>>opcion;

    switch (opcion) {
        case CONSULTAR: consultar(); break;
        case AGREGAR: agregar(); break;
        case ELIMINAR: eliminar(); break;
        case MOSTRAR_IN_ORDER: mostrarInOrder(); break;
        case MOSTRAR_ANCHO: mostrarAncho(); break;
        case VOLVER_MENU: cout<<"Volviendo al menu principal"; break;
        default: cout<< "Valor incorrecto. Debe ingresar un numero del 1 al 6. Volviendo al Menu Aeropuerto"<<endl; mostrarOpciones();
    }

    if(opcion!=VOLVER_MENU){
        mostrarOpciones();
    }
}

void MenuAeropuerto::consultar() {
    cout<<endl<<"Entraste al consultar de Menu Aeropuerto"<<endl;
}

void MenuAeropuerto::agregar() {
    cout<<endl<<"Entraste al agregar de Menu Aeropuerto"<<endl;
}

void MenuAeropuerto::eliminar() {
    cout<<endl<<"Entraste al eliminar de Menu Aeropuerto"<<endl;
}

void MenuAeropuerto::mostrarAncho() {
    cout<<endl<<"Entraste al mostrarAncho de Menu Aeropuerto"<<endl;
}

void MenuAeropuerto::mostrarInOrder() {
    cout<<endl<<"Entraste al mostrar in order de Menu Aeropuerto"<<endl;
}

