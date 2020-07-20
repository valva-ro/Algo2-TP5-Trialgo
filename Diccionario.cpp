//
// Created by daseos on 20/7/20.
//

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