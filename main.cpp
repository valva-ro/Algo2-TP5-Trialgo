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

#include "Grafo.h"

int main(int argc, char *argv[]) {

    Grafo* pVuelos = new Grafo();

    pVuelos->insertarArista("LAX","PAN",22,11);
    cout << boolalpha << "\n\tSE INSERTO LA ARISTA LAX -> PAN CON PRECIO 22 Y TIEMPO 11\n";

    cout << "\n\tExiste vertice LAX: " << pVuelos->existeVertice("LAX");
    cout << "\n\tExiste vertice PAN: " << pVuelos->existeVertice("PAN");
    cout << "\n\tExiste arista LAX -> PAN: " << pVuelos->existeArista("LAX","PAN");
    cout << "\n\tExiste arista PAN -> LAX: " << pVuelos->existeArista("PAN","LAX");
    cout << "\n\tPrecio de LAX -> PAN: " << pVuelos->obtenerPrecio("LAX","PAN");
    cout << "\n\tDistancia de LAX -> PAN: " << pVuelos->obtenerTiempo("LAX","PAN") << endl;

    delete pVuelos;
    return 0;
}