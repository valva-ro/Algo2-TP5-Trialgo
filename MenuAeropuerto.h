//
// Created by alexteper on 20/7/20.
//

#ifndef TP5_TRIALGO_MENUAEROPUERTO_H
#define TP5_TRIALGO_MENUAEROPUERTO_H

#include <iostream>

class MenuAeropuerto {
private:
    int opcion;

public:
    void mostrarOpciones();
    void selectorOpcion();
    void consultar();
    void agregar();
    void eliminar();
    void mostrarInOrder();
    void mostrarAncho();

};


#endif //TP5_TRIALGO_MENUAEROPUERTO_H
