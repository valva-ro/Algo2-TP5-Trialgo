/*
  75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
  Trabajo Practico Grupal N5
  Hecho por
            Alejo Villores
            Alex Teper
            Kevin Meaca
            Valentina Varela Rodriguez
*/
#include "Menu.h"
int main() {

    Menu("archivoAeropuertos.txt", "archivoVuelos.txt");

/*

    Cargador cargador;
    Diccionario<string, Aeropuerto*> *pDiccionario;
    Diccionario<string, Aeropuerto*> DiccionarioOut;
    pDiccionario = &DiccionarioOut;
    string claveOut;
    string codigoIataOut,  nombreOut,  ciudadOut,  paisOut;
    double superficieOut;
    int cantidadTerminalesOut,  destinosNacionalesOut, destinosInternacionalesOut;

    cargador.cargarDatos(pDiccionario, "archivoAeropuertos.txt");



    cout << "\n\tEntraste al agregar de Menu Aeropuerto\n";
    cout<<"Ingrese una clave para agregar"<<endl;
    cin>>claveOut;

    while (pDiccionario->existe(claveOut)){
        cout<<"Esa clave ya se encuentra cargada, ingrese una nueva"<<endl;
        cin>>claveOut;
    }

    cout<<"Ingrese la informacion de un nuevo aeropuerto para agregar"<<endl;
    cout<<"Codigo IATA: "; cin>> codigoIataOut;
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
    cin>>destinosInternacionalesOut;
    cout<<"Destinos interacionales: ";
    cin>>destinosInternacionalesOut;


    Aeropuerto aeropuertoOut(codigoIataOut,nombreOut,ciudadOut,paisOut,superficieOut,cantidadTerminalesOut,destinosNacionalesOut,destinosInternacionalesOut);

    pDiccionario->insertar(claveOut, &aeropuertoOut);
    cout<<endl<<"El aeropuerto que acaba de agregar es: "<<endl;
    cout<<*pDiccionario->obtenerValor("PPP");
    */
    return 0;
}