#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>

using namespace std;

class Validaciones {

    public:

        // PRE: -
        // POST: Si num no es un entero, pide el reingreso hasta que lo sea y luego lo devuelve
        int esEntero(string num);

        // PRE: -
        // POST: Si num no es float, pide el reingreso hasta que lo sea y luego lo devuelve
        float esFlotante(string num);

        // PRE: -
        // POST: Si num es menor o igual a cero, pide el reingreso hasta que lo sea y luego lo devuelve
        void esPositivo(int &num);

        // PRE: -
        // POST: Si num es menor o igual a cero, pide el reingreso hasta que lo sea y luego lo devuelve
        void esPositivo(float &num);

        // PRE: min < max
        // POST: Si no se cumple que min <= num <= max le pide al usuario que reingrese el valor
        void estaEnRango(int &num, int min, int max);

        // PRE: min < max
        // POST: Si no se cumple que min <= num <= max le pide al usuario que reingrese el valor
        void estaEnRango(float &num, float min, float max);

        // PRE: -
        // POST: Si c no es una letra, pide el reingreso hasta que lo sea
        void esLetra(char &c);

        // PRE: -
        // POST: Si s tiene una longitud distinta de longitud, pide el reingreso hasta que sean iguales
        void longitudString(string &s, int longitud);

        // PRE: El string debe contener unicamente letras
        // POST: Convierte cada letra del string a mayuscula
        void convertirEnMayusculas(string &s);
};

#endif //VALIDACIONES_H