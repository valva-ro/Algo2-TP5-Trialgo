#include <regex>    // Se utiliza en validarEntero() y validarDouble()
#include <iostream>

#include "../HEADERS/Validaciones.h"

int Validaciones:: esEntero(string num) {

    regex entero("^(\\+|-)?[[:digit:]]+");

    while (!regex_match(num, entero)) {
        cout << "\tError, el tipo de dato que ingreso no es valido.\n\tPor favor reingrese (solo numeros enteros): ";
        cin >> num;
    }
    return atoi(num.c_str());
}

float Validaciones:: esFlotante(string num) {

    regex real("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");

    while (!regex_match(num, real)) {
        cout << "\tError, el tipo de dato que ingreso no es valido.\n\tPor favor reingrese (numeros enteros o reales): ";
        cin >> num;
    }

    return atof(num.c_str());
}

void Validaciones:: esPositivo(int &num) {
    string strEntero;
    while (num <= 0) {
        cout << "\tEl numero que ingreso es menor o igual a cero, por favor reingrese: ";
        cin >> strEntero;
        num = esEntero(strEntero);
    }
}

void Validaciones:: esPositivo(float &num) {
    string strDouble;
    while (num <= 0) {
        cout << "\tEl numero que ingreso es menor o igual a cero, por favor reingrese: ";
        cin >> strDouble;
        num = esFlotante(strDouble);
    }
}

void Validaciones:: estaEnRango(int &num, int min, int max) {
    string strNum;
    while (num < min || num > max) {
        cout << "\tEl numero que ingreso esta fuera de rango, por favor reingrese: ";
        cin >> strNum;
        num = esEntero(strNum);
    }
}

void Validaciones:: estaEnRango(float &num, float min, float max) {
    string strNum;
    while (num < min || num > max) {
        cout << "\tEl numero que ingreso esta fuera de rango, por favor reingrese: ";
        cin >> strNum;
        num = esFlotante(strNum);
    }
}

void Validaciones:: esLetra(char &c) {
    while (!isalpha(c)) {
        cout << "\tError, lo que ingreso no es una letra.\n\tPor favor reingrese: ";
        cin >> c;
    }
}

void Validaciones:: longitudString(string &s, int longitud) {
    while (s.length() != longitud) {
        cout << "\tError, la longitud de la palabra que ingreso es incorrecta\n\tPor favor reingrese [LONG = " << longitud << "]: ";
        cin >> s;
    }
}

void Validaciones:: convertirEnMayusculas(string &palabra) {
    string palabraEnMayusculas;
    for (int i = 0; i < palabra.length(); i++){
        palabraEnMayusculas += toupper(palabra[i]);
    }
    palabra = palabraEnMayusculas;
}