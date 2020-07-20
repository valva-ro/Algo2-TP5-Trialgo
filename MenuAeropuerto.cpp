//
// Created by alexteper on 20/7/20.
//

#include "MenuAeropuerto.h"

using namespace std;

void MenuAeropuerto::mostrarOpciones() {
    cout<<endl<<"Menu Aeropuerto"<<endl;
    cout<<"Ingrese que operacion desea realizar:"<<endl;
    cout<<"1. Consultar"<<endl;
    cout<<"2. Agregar"<<endl;
    cout<<"3. Eliminar"<<endl;
    cout<<"4. Mostrar in Order"<<endl;
    cout<<"5. Mostrar ancho"<<endl;
    selectorOpcion();
}

void MenuAeropuerto::selectorOpcion() {
    cout<<"Entraste al selector de opcion de Menu Aeropuerto"<<endl;

    cin>>opcion;

    switch (opcion) {
        case 1: consultar(); break;
        case 2: agregar(); break;
        case 3: eliminar(); break;
        case 4: mostrarInOrder(); break;
        case 5: mostrarAncho(); break;
        default: cout<< "Valor incorrecto. Debe ingresar un numero del 1 al 5. Volviendo al Menu Aeropuerto"<<endl; mostrarOpciones();
    }
}

void MenuAeropuerto::consultar() {
    cout<<"Entraste al consultar de Menu Aeropuerto"<<endl;
}

void MenuAeropuerto::agregar() {
    cout<<"Entraste al agregar de Menu Aeropuerto"<<endl;
}

void MenuAeropuerto::eliminar() {
    cout<<"Entraste al eliminar de Menu Aeropuerto"<<endl;
}

void MenuAeropuerto::mostrarAncho() {
    cout<<"Entraste al mostrarAncho de Menu Aeropuerto"<<endl;
}

void MenuAeropuerto::mostrarInOrder() {
    cout<<"Entraste al mostrar in order de Menu Aeropuerto"<<endl;
}

