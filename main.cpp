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
    ABB<int*, int> arbolEnteros;
    for (int i = 0; i < 10; ++i) {
        int* pInt = new int(i);
        arbolEnteros.insertar(pInt);
    }
    arbolEnteros.recorridoInOrder();
    arbolEnteros.recorridoPostOrder();
    arbolEnteros.recorridoPreOrder();
    arbolEnteros.recorridoEnAncho();
    return 0;
}