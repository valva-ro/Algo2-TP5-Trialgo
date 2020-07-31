#ifndef TP5_TRIALGO_MENU_H
#define TP5_TRIALGO_MENU_H

#include "MenuAeropuerto.h"
#include "MenuVuelo.h"
#include "Cargador.h"
#include "Aeropuerto.h"
#include "Diccionario.h"

class Menu {
private:
    char opcion;
    MenuAeropuerto menuAeropuerto;
    MenuVuelo menuVuelo;

public:
    //DESCRIPCION:Constructor del Menu
    //PRE: Recibe los archivos aeropuertos y vuelos
    //POST: Crea el ABB y el grafo y llama a los metodos necesarios para completarlos con los archivos.
    Menu(const string& rutaArchAeropuertos, const string& rutaArchVuelos);

    ~Menu();

    //DESCRIPCION: Muestra las opciones del MENU
    //PRE:
    //POST: Muestra las opciones del MENU
    void mostrarOpciones();

    //DESCRIPCION: selector de las opciones del MENU
    //PRE:
    //POST: selector de las opciones del MENU
    void selectorOpcion();
};

#endif //TP5_TRIALGO_MENU_H