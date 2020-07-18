/*
  75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
  Trabajo Practico Grupal N5
  Hecho por
            Alejo Villores
            Alex Teper
            Kevin Meaca
            Valentina Varela Rodriguez
*/

#include "ABB.h"
int main() {

    ABB<int> arbol;
    for (int i = 1; i < 10; i++) {
        arbol.insertar(i);
    }

    arbol.mostrarData();

    cout << "\tExiste 4: " << arbol.existe(4) << "\n";
    cout << "\tExiste 12: " << arbol.existe(12) << "\n";

    return 0;
}