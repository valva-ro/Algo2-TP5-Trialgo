#ifndef TP4_RECOMENDACIONPELICULA_LISTA_H
#define TP4_RECOMENDACIONPELICULA_LISTA_H
#include "Nodo.h"

template <typename Tipo>
class Lista {

private:
    Nodo<Tipo>* primero;
    int elementos;

public:

    // PRE: -
    // POST: Crea una lista con 0 elementos
    Lista();

    // PRE: La lista debe estar creada
    // POST: Libera la memoria que ocupaba la lista
    ~Lista();

    // PRE: La lista debe estar creada y ser distinta de vacia, 0 < posicion <= elementos
    // POST: Devuelve el dato de la posicion recibida por parametro
    Tipo obtenerDato(int posicion);

    // PRE: -
    // POST: Devuelve la cantidad de elementos
    int obtenerCantidadElementos();

    // PRE: -
    // POST: Devuelve la posicion en la que esta el dato
    int obtenerPosicion(Tipo dato);

    // PRE: 0 < posicion <= elementos
    // POST: Agrega el dato recibido como parametro en la posicion recibida como parametro
    void agregarEnPosicion(Tipo datoExterno, int posicionExterno);

    // PRE: -
    // POST: Agrega el dato recibido como parametro al final de la lista
    void agregarAlFinal(Tipo datoExterno);

    // PRE: -
    // POST: Agrega el dato recibido como parametro al principio de la lista
    void agregarAlPrincipio(Tipo datoExterno);

    // PRE: La lista debe estar creada y ser distinta de vacía
    // POST: Saca el elemento de la posicion recibida como parametro de la lista
    void sacar(int posicion);

    // PRE: -
    // POST: Devuelve true si se encontro el dato en la lista, de lo contrario false
    bool existe(Tipo dato);

    // PRE: -
    // POST: Devuelve true si la lista esta vacia, de lo contrario false
    bool vacia();

private:
    // PRE: 0 < posicion <= elementos
    // POST: Devuelve un puntero de tipo nodo correspondiente con la posicion
    Nodo<Tipo>* obtenerNodo(int posicion);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename Tipo>
Lista<Tipo>:: Lista () {
    primero = 0;
    elementos = 0;
}

template <typename Tipo>
Lista<Tipo>:: ~Lista() {
    while (!vacia())
        sacar(0);
}

// <-------------------- Obtenciones
template <typename Tipo>
Tipo Lista<Tipo>:: obtenerDato(int posicion) {
    return obtenerNodo(posicion)->obtenerDato();
}

template <typename Tipo>
int Lista<Tipo>:: obtenerCantidadElementos() {
    return elementos;
}

template <typename Tipo>
int Lista<Tipo>::obtenerPosicion(Tipo dato) {
    if (existe(dato)) {
        for (int i = 0; i < elementos; ++i) {
            if (obtenerDato(i) == dato)
                return i;
        }
    }
    else
        std::cout << "\t\tEl dato " << dato << " no existe en la lista\n";
}

template <typename Tipo>
Nodo<Tipo>* Lista<Tipo>:: obtenerNodo(int posicion) {
    Nodo<Tipo>* aux = primero;
    int i = 0;
    while (i < posicion) {
        aux = aux->obtenerSiguiente();
        i++;
    }
    return aux;
}
// -------------------->

template <typename Tipo>
void Lista<Tipo>:: agregarAlFinal(Tipo datoExterno) {
    if (elementos == 0)
        agregarEnPosicion(datoExterno, elementos);
    else
        agregarEnPosicion(datoExterno, elementos - 1);
}

template <typename Tipo>
void Lista<Tipo>:: agregarAlPrincipio(Tipo datoExterno) {
    agregarEnPosicion(datoExterno, 0);
}

template <typename Tipo>
void Lista<Tipo>:: agregarEnPosicion(Tipo datoExterno, int posicion) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(datoExterno);

    if (posicion == 0) {
        nuevoNodo->asignarSiguiente(primero);
        primero = nuevoNodo;
    }
    else {
        Nodo<Tipo>* anterior = obtenerNodo(posicion - 1);
        nuevoNodo->asignarSiguiente(anterior->obtenerSiguiente());
        anterior->asignarSiguiente(nuevoNodo);
    }
    elementos++;
}

template <typename Tipo>
void Lista<Tipo>:: sacar(int posicion) {
    Nodo<Tipo>* borrar = primero;

    if (posicion == 0) {
        primero = borrar->obtenerSiguiente();
    }

    else {
        Nodo<Tipo>* anterior = obtenerNodo(posicion - 1);
        borrar = anterior->obtenerSiguiente();
        anterior->asignarSiguiente(borrar->obtenerSiguiente());
    }
    delete borrar;
    elementos--;
}

template <typename Tipo>
bool Lista<Tipo>:: existe(Tipo datoExterno) {
    bool encontrado = false;
    int i = 0;
    while((i < elementos) && !encontrado){
        if(datoExterno == obtenerDato(i)){
            encontrado = true;
        }
        i++;
    }
    return encontrado;
}

template <typename Tipo>
bool Lista<Tipo>:: vacia() {
    return primero == 0;
}
#endif //TP4_RECOMENDACIONPELICULA_LISTA_H
