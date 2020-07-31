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
const int EJECUTABLE = 1;
const int AEROPUERTOS_TXT = 2;
const int AEROPUERTO_Y_VUELOS_TXT = 3;



int main(int argc, char *argv[]) {

    string archAeropuertos = "archivoAeropuertos.txt";
    string archVuelos = "archivoVuelos.txt";

    switch (argc) {
        case AEROPUERTOS_TXT: archAeropuertos= argv[1]; break;
        case AEROPUERTO_Y_VUELOS_TXT: archAeropuertos= argv[1]; archVuelos=argv[2]; break;
    }

    Menu(archAeropuertos,archVuelos);


    return 0;
}