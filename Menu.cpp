//
// Created by alexteper on 20/7/20.
//

#include "Menu.h"

using namespace std;

void Menu::mostrarOpciones() {
    cout<<endl<<"Bienvenido al menu principal"<<endl;
    cout<<"Ingrese que operacion desea realizar:"<<endl;
    cout<<"1. Acceder al Menu del aeropuerto"<<endl;
    cout<<"2. Acceder al Menu de vuelos"<<endl;
    cout<<"3. Finalizar el programa"<<endl;
    selectorOpcion();
}

void Menu::selectorOpcion() {
    cin>>opcion;

    switch (opcion) {
        case 1:

    }


}
