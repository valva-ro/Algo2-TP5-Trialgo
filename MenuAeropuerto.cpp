#include <iostream>
#include "MenuAeropuerto.h"

using namespace std;

const char CONSULTAR = '1';
const char AGREGAR = '2';
const char ELIMINAR = '3';
const char MOSTRAR_IN_ORDER = '4';
const char MOSTRAR_ANCHO = '5';
const char VOLVER_MENU = '0';

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
        default: cout <<  "\tValor incorrecto. Debe ingresar un numero del 0 al 5. Volviendo al Menu Aeropuerto\n"; break;
    }

    if(opcion!=VOLVER_MENU){
        mostrarOpciones();
    }
}

void MenuAeropuerto::consultar() {
    string clave;
    cout << "\n\tEntraste al consultar de Menu Aeropuerto\n";
    cout<<"Ingrese la clave del aeropuerto para obtener los datos"<<endl;
    cin>>clave;

    while (!arbolAeropuertos->existe(clave)){
        cout<<"Esa clave no exsiste en el programa, ingrese una que pertenezca al Diccionario de Aeropuertos"<<endl;
        cin>>clave;
    }

    cout<<endl<<"El aeropuerto que quiere mostrar es: "<<endl;
    cout<<*arbolAeropuertos->obtenerValor(clave);
}

void MenuAeropuerto::agregar() {
    string clave;
    string nombre,  ciudad,  pais;
    double superficie;
    int cantidadTerminales,  destinosNacionales, destinosInternacionales;

    cout << "\n\tEntraste al agregar de Menu Aeropuerto\n";
    cout<<"Ingrese una clave para agregar"<<endl;
    cin >> clave;

    while (arbolAeropuertos->existe(clave)){
        cout<<"Esa clave ya se encuentra cargada, ingrese una nueva"<<endl;
        cin >> clave;
    }

    cout<<"Ingrese la informacion de un nuevo aeropuerto para agregar"<<endl;

    cout<<"Nombre Aeropuerto: ";
    cin >> nombre;
    cout<<"Ciudad: ";
    cin >> ciudad;
    cout<<"Pais: ";
    cin >> pais;
    cout<<"Superficie: ";
    cin >> superficie;
    cout<<"Cantidad de terminales: ";
    cin >> cantidadTerminales;
    cout<<"Destinos Nacionales: ";
    cin >> destinosNacionales;
    cout<<"Destinos interacionales: ";
    cin >> destinosInternacionales;

    Aeropuerto *pAeropuerto = new Aeropuerto(clave, nombre, ciudad, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales);

    cout<<endl<<"Mostrando el aeropuerto recien cargado"<<endl;
    cout<<*pAeropuerto;

    arbolAeropuertos->insertar(clave, pAeropuerto);
    cout<<endl<<"Aeropuerto insertado en el diccionario"<<endl;

}

void MenuAeropuerto::eliminar() {
    string clave;
    cout << "\n\tEntraste al eliminar de Menu Aeropuerto\n";
    cout<<"Ingrese la clave del aeropuerto que desea borrar: ";
    cin >> clave;

    while (!arbolAeropuertos->existe(clave)){
        cout<<"Esa clave no se encuentra cargada, ingrese una clave valida"<<endl;
        cin >> clave;
    }

    arbolAeropuertos->borrarClave(clave);
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
