//
// Created by alexteper on 20/7/20.
//

#ifndef TP5_TRIALGO_MENU_H
#define TP5_TRIALGO_MENU_H

#include <iostream>
#include "MenuAeropuerto.h"
#include "MenuVuelo.h"

using namespace std;

class Menu {
private:
    int opcion;
    MenuAeropuerto menuAeropuerto;
    MenuVuelo menuVuelo;

public:
    void mostrarOpciones();
    void selectorOpcion();
    void aeropuerto();
    void vuelos();




};


#endif //TP5_TRIALGO_MENU_H
