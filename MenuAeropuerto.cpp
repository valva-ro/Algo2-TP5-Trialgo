#include <iostream>
#include "MenuAeropuerto.h"

using namespace std;

const char CONSULTAR = '1';
const char AGREGAR = '2';
const char ELIMINAR = '3';
const char MOSTRAR_IN_ORDER = '4';
const char MOSTRAR_ANCHO = '5';
const char VOLVER_MENU = '6';

void MenuAeropuerto::mostrarOpciones(){
    cout << "\n\t---------------- Menu  Aeropuerto ----------------";
    cout << "\n\t" << CONSULTAR<<". Consultar";
    cout << "\n\t" << AGREGAR<<". Agregar";
    cout << "\n\t" << ELIMINAR<<". Eliminar";
    cout << "\n\t" << MOSTRAR_IN_ORDER<<". Mostrar in order";
    cout << "\n\t" << MOSTRAR_ANCHO<<". Mostrar ancho";
    cout << "\n\t" << VOLVER_MENU<<". Volver al menu principal";
    cout << "\n\tIngrese que operacion desea realizar: ";
    selectorOpcion();
}

void MenuAeropuerto::selectorOpcion() {

    cin >> opcion;

    switch (opcion) {
        case CONSULTAR: consultar(); break;
        case AGREGAR: agregar(); break;
        case ELIMINAR: eliminar(); break;
        case MOSTRAR_IN_ORDER: mostrarInOrder(); break;
        case MOSTRAR_ANCHO: mostrarAncho(); break;
        case VOLVER_MENU: cout << "\tVolviendo al menu principal"; break;
        default: cout <<  "\tValor incorrecto. Debe ingresar un numero del 1 al 6. Volviendo al Menu Aeropuerto\n"; break;
    }

    if(opcion!=VOLVER_MENU){
        mostrarOpciones();
    }
}

void MenuAeropuerto::consultar() {
    string clave;
    cout << "\t\n\tEntraste al consultar de Menu Aeropuerto\n";
    cout << "\tIngrese el codigo IATA del aeropuerto: ";
    cin >> clave;

    if (arbolAeropuertos->existe(clave)) {
        cout << "\n\tEl aeropuerto es:\n";
        cout << *arbolAeropuertos->obtenerValor(clave);
    }
    else
        cout << "\tNo se encontro el codigo IATA " << clave << "\n";
}

void MenuAeropuerto::agregar() {
    string claveOut;
    string nombreOut,  ciudadOut,  paisOut;
    double superficieOut;
    int cantidadTerminalesOut,  destinosNacionalesOut, destinosInternacionalesOut;

    cout << "\n\tEntraste al agregar de Menu Aeropuerto\n";
    cout<<"Ingrese una clave para agregar"<<endl;
    cin>>claveOut;

    while (arbolAeropuertos->existe(claveOut)){
        cout<<"Esa clave ya se encuentra cargada, ingrese una nueva"<<endl;
        cin>>claveOut;
    }

    cout<<"Ingrese la informacion de un nuevo aeropuerto para agregar"<<endl;

    cout<<"Nombre Aeropuerto: ";
    cin>>nombreOut;
    cout<<"Ciudad: ";
    cin>>ciudadOut;
    cout<<"Pais: ";
    cin>>paisOut;
    cout<<"Superficie: ";
    cin>>superficieOut;
    cout<<"Cantidad de terminales: ";
    cin>>cantidadTerminalesOut;
    cout<<"Destinos Nacionales: ";
    cin>>destinosNacionalesOut;
    cout<<"Destinos interacionales: ";
    cin>>destinosInternacionalesOut;

    Aeropuerto *pAeropuerto = new Aeropuerto(claveOut,nombreOut,ciudadOut,paisOut,superficieOut,cantidadTerminalesOut,destinosNacionalesOut,destinosInternacionalesOut);

    cout<<endl<<"Mostrando el aeropuerto recien cargado"<<endl;
    cout<<*pAeropuerto;

    arbolAeropuertos->insertar(claveOut, pAeropuerto);
    cout<<endl<<"Aeropuerto insertado en el diccionario"<<endl;

}

void MenuAeropuerto::eliminar() {
    string claveOut;
    cout << "\n\tEntraste al eliminar de Menu Aeropuerto\n";
    cout<<"Ingrese la clave del aeropuerto que desea borrar: ";
    cin>>claveOut;

    while (!arbolAeropuertos->existe(claveOut)){
        cout<<"Esa clave no se encuentra cargada, ingrese una clave valida"<<endl;
        cin>>claveOut;
    }

    arbolAeropuertos->borrarClave(claveOut);
    cout<<endl<<"Clave borrada"<<endl;
}

void MenuAeropuerto::mostrarAncho() {
    cout << "\n\tEntraste al mostrarAncho de Menu Aeropuerto\n";
    arbolAeropuertos->recorridoEnAncho();
}

void MenuAeropuerto::mostrarInOrder() {
    cout << "\n\tEntraste al mostrar in order de Menu Aeropuerto\n";
    arbolAeropuertos->recorridoInOrder();
}


void MenuAeropuerto::asignarArbolAeropuertos(Diccionario<string, Aeropuerto *> *&arbolAeropuertosOut) {
    this->arbolAeropuertos = arbolAeropuertosOut;
}


void MenuAeropuerto::mostrarTodo() {
    this->arbolAeropuertos->mostrarData();
}
