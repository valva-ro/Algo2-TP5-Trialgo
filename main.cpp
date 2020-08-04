/*
  75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
  Trabajo Practico Grupal N5
  Hecho por
            Alejo Villores
            Alex Teper
            Kevin Meaca
            Valentina Varela Rodriguez

  Si al ejecutar por consola se recibe:
    - Un argumento ----> los nombres de los archivos seran "archivoAeropuertos.txt" y
                         "archivoVuelos.txt"
    - Dos argumentos --> los nombres de los archivos seran el segundo argumento para
                         los aeropuertos y "archivoVuelos.txt"
    - Tres argumentos -> los nombres de los archivos seran el segundo argumento para
                         los aeropuertos y el tercer argumento para los vuelos
*/
/*
#include "Menu.h"
const int AEROPUERTOS_TXT = 2;
const int AEROPUERTO_Y_VUELOS_TXT = 3;

int main(int argc, char *argv[]) {

    string archAeropuertos = "archivoAeropuertos.txt";
    string archVuelos = "archivoVuelos.txt";

    switch (argc) {
        case AEROPUERTOS_TXT:
            archAeropuertos = argv[1];
            break;
        case AEROPUERTO_Y_VUELOS_TXT:
            archAeropuertos = argv[1];
            archVuelos = argv[2];
            break;
    }

    Menu menu(archAeropuertos,archVuelos);
    menu.mostrarOpciones();



    return 0;
}
*/

#include "Menu.h"
#include "Grafo.h"
#include "Matriz.h"
#include "Lista.h"

const int AEROPUERTOS_TXT = 2;
const int AEROPUERTO_Y_VUELOS_TXT = 3;

int main(int argc, char *argv[]) {

    Grafo* pVuelos = new Grafo();


    pVuelos->insertarArista("LAX","PAN",22,11);
    cout<<endl<<"YA INSERTE ENTRE LAX Y PAN"<<endl;

    cout<<pVuelos->existeArista("LAX","PAN");
    cout<<pVuelos->existeVertice("LAX");
    cout<<pVuelos->existeVertice("PAN");
    cout<<endl<<"Hasta aca todo bien si hay 3 unos"<<endl;

    //ERROR
  //  cout<<pVuelos->existeArista("PAN","LAX");




    //cout<<pVuelos->existeArista("PAN","LAX");











    return 0;
}