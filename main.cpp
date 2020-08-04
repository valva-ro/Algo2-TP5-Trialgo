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
#include "Grafo.h"

int main() {

    Grafo vuelos;
    vuelos.insertarArista("EZE", "BRC", 1,5.0);
    cout << "\t\tDistancia entre EZE y BRC: " << vuelos.obtenerDistancia("EZE", "BRC") << endl;
    cout << "\t\tPrecio entre EZE y BRC: " << vuelos.obtenerPrecio("EZE", "BRC") << endl;

    return 0;
}