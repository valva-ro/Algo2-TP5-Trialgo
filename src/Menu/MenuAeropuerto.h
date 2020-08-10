#ifndef TP5_TRIALGO_MENUAEROPUERTO_H
#define TP5_TRIALGO_MENUAEROPUERTO_H

#include "../Cargador.h"
#include "../Aeropuerto.h"
#include "../Estructuras No Lineales/Diccionario.h"

class MenuAeropuerto {
private:
    char opcion;
    Diccionario<string, Aeropuerto*> *arbolAeropuertos;

public:
    //DESCRIPCION: Le asigna el puntero recibido al atributo por referencia
    //PRE: -
    //POST: Le asigna el puntero recibido al atributo por referencia
    void asignarArbolAeropuertos(Diccionario<string, Aeropuerto*> *&arbolAeropuertosOut);

    //DESCRIPCION: Muestra las opciones del Menu
    //PRE: -
    //POST: Muestra las opciones del Menu y llama al metodo selectorOpcion()
    void mostrarOpciones();

    //DESCRIPCION: selector las opciones del Menu
    //PRE: -
    //POST: Pide el ingreso de una opcion y abre el metodo correspondiente.
    //      Si la opcion ingresada es distinta de VOLVER_MENU llama al metodo mostrarOpciones().
    void selectorOpcion();

    //DESCRIPCION: Pide el ingreso de una clave y accede a los metodos del Diccionario necesarios para consultar
    //PRE: -
    //POST: En el caso de existir la clave ingresada, muestra por pantalla los datos del Aeropuerto correspondiente
    void consultar();

    //DESCRIPCION: Accede a los metodos del Diccionario necesarios para agregar
    //PRE: -
    //POST: Si no existe en el diccionario la clave que se quiere agregar, se piden los datos de un nuevo aeropuerto
    //      y se agrega al diccionario
    void agregar();

    //DESCRIPCION: Pide el ingreso de una clave y accede a los metodos del Diccionario necesarios para eliminarla
    //PRE: -
    //POST: En el caso de existir la clave ingresada, elimina el nodo correspondiente del diccionario
    void eliminar();

    //DESCRIPCION: Accede a los metodos del Diccionario necesarios para mostrar in order
    //PRE: -
    //POST: Muestra el recorrido in order del diccionario
    void mostrarInOrder();

    //DESCRIPCION: Accede a los metodos del Diccionario necesarios para mostrar en ancho
    //PRE:
    //POST: Muestra el recorrido en ancho del diccionario
    void mostrarAncho();

    //DESCRIPCION: Libera el diccionario de memoria dinamica
    //PRE: El Diccionario debe estar cargado
    //POST: Libera el diccionario de memoria dinamica
    void liberarRecursos();

};


#endif //TP5_TRIALGO_MENUAEROPUERTO_H
