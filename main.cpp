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
    Menu menu("archivoAeropuertos.txt", "archivoVuelos.txt");

    menu.mostrarOpciones();
    return 0;
}