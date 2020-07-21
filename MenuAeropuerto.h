//
// Created by alexteper on 20/7/20.
//

#ifndef TP5_TRIALGO_MENUAEROPUERTO_H
#define TP5_TRIALGO_MENUAEROPUERTO_H



class MenuAeropuerto {
private:
    char opcion;

public:
    //DESCRIPCION: Muestra las opciones del MENU
    //PRE:
    //POST: Muestra las opciones del MENU
    void mostrarOpciones();

    //DESCRIPCION: selector las opciones del MENU
    //PRE:
    //POST: selector de las opciones del MENU
    void selectorOpcion();

    //DESCRIPCION:  accede a los metodos necesarios para consultar
    //PRE:
    //POST:
    void consultar();

    //DESCRIPCION: accede a los metodos necesarios para agregar
    //PRE:
    //POST:
    void agregar();

    //DESCRIPCION:  accede a los metodos necesarios para eliminar
    //PRE:
    //POST:
    void eliminar();

    //DESCRIPCION: accede a los metodos necesarios para mostror in order
    //PRE:
    //POST:
    void mostrarInOrder();

    //DESCRIPCION:  accede a los metodos necesarios para mostror en ancho
    //PRE:
    //POST:
    void mostrarAncho();

};


#endif //TP5_TRIALGO_MENUAEROPUERTO_H
