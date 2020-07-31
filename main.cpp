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
    /*
     argc: obtener el numero de argumentos totales pasados en la linea de comando
     argv: es un array con los argumentos pasados en la linea de comando
     */

    switch (argc) {
        case EJECUTABLE: Menu("archivoAeropuertos.txt", "archivoVuelos.txt"); break;
        case AEROPUERTOS_TXT: Menu(argv[1],"archivoVuelos.txt"); break;
        case AEROPUERTO_Y_VUELOS_TXT: Menu(argv[1],argv[2]);
    }


    return 0;
}