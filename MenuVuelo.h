#ifndef TP5_TRIALGO_MENUVUELO_H
#define TP5_TRIALGO_MENUVUELO_H

class MenuVuelo {
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

    //DESCRIPCION: accede a los metodos necesarios para mostrar el camino de menor costo
    //PRE:
    //POST: se muestra el camino de menor costo
    void menorCosto();

    //DESCRIPCION: accede a los metodos necesarios para mostrar el camino de menor tiempo
    //PRE:
    //POST: se muesrta el camino de menor tiempo
    void menorTiempo();
};


#endif //TP5_TRIALGO_MENUVUELO_H
