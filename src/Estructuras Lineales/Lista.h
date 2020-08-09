#ifndef LISTA_H
#define LISTA_H

//Include del paquete Nodo
#include "Nodo.h"

template<class Dato>
class Lista
{
    private:

        // Primer elemento de la lista
        Nodo<Dato>* primero;
        // Tamanio de la lista
        unsigned tam;

     public:
        // Constructor
        // PRE: -
        // POST: Construye una lista vacia
        Lista();

        // Destructor
        // PRE: -
        // POST: Libera todos los recursos de la lista
         ~Lista();

        // PRE: -
        // POST: Devuelve verdadero si la lista es vacia
        bool listaVacia();

        // PRE: -
        // POST: Agrega un dato (dentro de un nodo) al final
        void insertar(Dato d);

        // PRE: -
        // POST: Devuelve el dato que esta en la posicion pos
        Dato obtenerDato(unsigned pos);

        //PRE: -
        //POST: Devuelve la posicion de un objeto , de no existir devuelve -1
        unsigned obtenerPosicion(Dato d);

        // PRE: -
        // POST: libera el nodo que esta en la posici�n pos
        void eliminarDato(unsigned pos);

        // PRE: -
        // POST: Devuelve tam (cantidad de nodos de la lista)
        unsigned obtenerTam();
};


//////////////////////////////////////////////////////////////////////
template<class Dato>
Lista<Dato>::Lista()
{
    primero = 0 ;
    tam = 0;
}
template<class Dato>
Lista<Dato>::~Lista()
{
    while (!(this->listaVacia()))
        this->eliminarDato(0);
}

template<class Dato>
bool Lista<Dato>::listaVacia()
{
    return(primero == 0);
}

template<class Dato>
void Lista<Dato>::insertar(Dato d)
 {
    Nodo<Dato>* pNodo = new Nodo<Dato>(d);
    Nodo<Dato>* pAux = primero;
    if (this->listaVacia()){
        primero = pNodo;
    }
    else{
        while (pAux->obtenerSiguiente() != 0){
            pAux = pAux->obtenerSiguiente();
        }
        pAux->asignarSiguiente(pNodo);
    }
    tam++;
}


template<class Dato>
Dato Lista<Dato>::obtenerDato(unsigned pos)
{
    Nodo<Dato>* pAux = primero;

    unsigned i = 0;
    while (i < pos && pAux->obtenerSiguiente())
    {
        pAux = pAux->obtenerSiguiente();
        i++;
    }

    return pAux->obtenerDato();
}

template<class Dato>
void Lista<Dato>::eliminarDato(unsigned pos)
{
    Nodo<Dato>* pAux = primero;
    if (pos == 0 || !(primero->obtenerSiguiente()))
    {
        primero = pAux->obtenerSiguiente();
    }
    else
    {
        unsigned i = 0;
        Nodo<Dato>* pAnt;
        while (i < pos && pAux->obtenerSiguiente())
        {
            pAnt = pAux;
            pAux = pAux->obtenerSiguiente();
            i++;
        }
        pAnt->asignarSiguiente(pAux->obtenerSiguiente());
    }
    delete pAux;
    tam--;
}

template<class Dato>
unsigned Lista<Dato>::obtenerPosicion(Dato d)
{
    bool estaEnLista  = false;
    unsigned i = 0 ,posicion = -1 ;

    while( i < tam && !estaEnLista)
    {
        Dato datoLista = this->obtenerDato(i);

        if(datoLista == d)
        {
            estaEnLista = true;
            posicion = i  ;
        }

        i++;
    }
    return posicion;
}

template<class Dato>
unsigned Lista<Dato>::obtenerTam()
{
    return tam;
}

#endif // LISTA_H
