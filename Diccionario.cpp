#include "Diccionario.h"

Diccionario::Diccionario(string claveRecibida, Aeropuerto *valorRecibido){
    clave = claveRecibida;
    valor = valorRecibido;
}

string Diccionario::obtenerClave(){
    return clave;
}

Aeropuerto* Diccionario::obtenerValor(){
    return valor;
}

Diccionario::~Diccionario(){
    delete valor;
}

Diccionario& Diccionario:: operator = (const Diccionario &diccionario) {
    this->valor = diccionario.valor;
    this->clave = diccionario.clave;
    return *this;
}

bool Diccionario:: operator > (const Diccionario &diccionario) {
    return this->valor > diccionario.valor;
}

bool Diccionario:: operator < (const Diccionario &diccionario) {
    return this->valor < diccionario.valor;
}

bool Diccionario:: operator == (const Diccionario &diccionario) {
    return (this->valor == diccionario.valor && this->clave == diccionario.clave);
}

ostream& operator << (ostream &out, const Diccionario &diccionario) {
    out << "Clave: " << diccionario.clave << " Valor: " << diccionario.valor;
    return out;
}