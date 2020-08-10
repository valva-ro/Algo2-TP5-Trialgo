#include <iostream>
#include "../Menu/MenuAeropuerto.h"
#include "../Validaciones.h"

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
    Validaciones validacion;
    string clave;
    cout << "\n\tIngrese la clave del aeropuerto para obtener los datos: ";
    cin >> clave;

    validacion.longitudString(clave, 3);
    validacion.convertirEnMayusculas(clave);

    if (!arbolAeropuertos->existe(clave))
        cout << "\tEsa clave no exsiste en el programa, volviendo al menu aeropuertos\n";

    else {
        cout<<endl<<"\tEl aeropuerto que quiere mostrar es: \n";
        cout<<*arbolAeropuertos->obtenerValor(clave);
    }

}

void MenuAeropuerto::agregar() {
    Validaciones validacion;
    string codigoIATA, nombre, ciudad, pais, superficieAux, cdadTerminalesAux, destNacionalesAux, destInternacionalesAux;
    float superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;

    cout<<"\tIngrese un codigo IATA para agregar: ";
    cin >> codigoIATA;
    validacion.longitudString(codigoIATA, 3);
    validacion.convertirEnMayusculas(codigoIATA);

    if (arbolAeropuertos->existe(codigoIATA))
        cout<<"\n\tEse codigo ya se encuentra cargado, volviendo al menu aeropuerto\n";

    else {
        cout<<"\tIngrese la informacion de un nuevo aeropuerto para agregar\n";

        cout << "\tNombre Aeropuerto: ";
        cin >> nombre;
        cout << "\tCiudad: ";
        cin >> ciudad;
        cout << "\tPais: ";
        cin >> pais;

        cout << "\tSuperficie: ";
        cin >> superficieAux;
        superficie = validacion.esFlotante(superficieAux);
        validacion.esPositivo(superficie);

        cout << "\tCantidad de terminales: ";
        cin >> cdadTerminalesAux;
        cantidadTerminales = validacion.esEntero(cdadTerminalesAux);
        validacion.esPositivo(cantidadTerminales);

        cout << "\tDestinos Nacionales: ";
        cin >> destNacionalesAux;
        destinosNacionales = validacion.esEntero(destNacionalesAux);
        validacion.esPositivo(destinosNacionales);

        cout << "\tDestinos interacionales: ";
        cin >> destInternacionalesAux;
        destinosInternacionales = validacion.esEntero(destInternacionalesAux);
        validacion.esPositivo(destinosInternacionales);

        Aeropuerto *pAeropuerto = new Aeropuerto(codigoIATA, nombre, ciudad, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales);

        cout << endl << "\tMostrando el aeropuerto recien cargado\n";
        cout << *pAeropuerto;

        arbolAeropuertos->insertar(codigoIATA, pAeropuerto);
        cout << endl << "\tAeropuerto insertado en el diccionario\n";
    }
}

void MenuAeropuerto::eliminar() {
    Validaciones validacion;
    string clave;
    cout << "\n\tEntraste al eliminar de Menu Aeropuerto\n";
    cout<<"\tIngrese la clave del aeropuerto que desea borrar: ";
    cin >> clave;

    validacion.longitudString(clave, 3);
    validacion.convertirEnMayusculas(clave);

    if (!arbolAeropuertos->existe(clave))
        cout<<"\n\tEsa clave no se encuentra cargada, volviendo al menu aeropuertos\n";

    else {
        arbolAeropuertos->borrarClave(clave);
        cout<<endl<<"\tClave borrada\n";
    }
}

void MenuAeropuerto::mostrarAncho() {
    arbolAeropuertos->recorridoEnAncho();
}

void MenuAeropuerto::mostrarInOrder() {
    arbolAeropuertos->recorridoInOrder();
}

void MenuAeropuerto::asignarArbolAeropuertos(Diccionario<string, Aeropuerto *> *&arbolAeropuertosOut) {
    this->arbolAeropuertos = arbolAeropuertosOut;
}

void MenuAeropuerto::liberarRecursos() {
    delete this->arbolAeropuertos;
}