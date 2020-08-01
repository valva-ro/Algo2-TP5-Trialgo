#ifndef LISTA_H
#define LISTA_H

//Include del paquete Nodo
#include"Nodo.h"

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
    // PRE: ninguna
    // POST: construye una lista vacia
    Lista();

    // Destructor
    // PRE: lista creada
    // POST: Libera todos los recursos de la lista
     ~Lista();

    // PRE: lista creada
    // POST: devuelve verdadero si la lista es vacia
    bool listaVacia();

    // PRE: lista creada
    // POST: agrega un dato (dentro de un nodo) al final
    void insertar(Dato d);

    // PRE: - lista creada y no vacia
    // POST: devuelve el dato que esta en la posicion pos
    Dato getDato(unsigned pos);

    //PRE:- Lista creada y no vacia
    //POST: Devuelve la posicion de un objeto , de no existir devuelve -1
    using getPosicion(Dato d);

    // PRE: - lista creada y no vacia
    // POST: libera el nodo que esta en la posici�n pos
    void delDato(unsigned pos);

    // PRE: Lista creada
    // POST: Devuelve tam (cantidad de nodos de la lista)
    unsigned getTam();
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
        this->delDato(1);
}

template<class Dato>
bool Lista<Dato>::listaVacia()
{
    return(primero == 0);
}

template<class Dato>
void Lista<Dato>::insertar(Dato d)
 {
    Nodo<Dato>* pnodo = new Nodo<Dato>(d);
    Nodo<Dato>* paux = primero;
    if (this->listaVacia()){
        primero = pnodo;
    }
    else{
        while (paux->obtenerSiguiente() != 0){
            paux = paux->obtenerSiguiente();
        }
        paux->asignarSiguiente(pnodo);
 }
 tam++;
}


template<class Dato>
Dato Lista<Dato>::getDato(unsigned pos)
{
    Nodo<Dato>* paux = primero;

    unsigned i = 1;
    while (i < pos && paux->obtenerSiguiente())
    {
        paux = paux->obtenerSiguiente();
        i++;
    }

    return paux->obtenerDato();
}

template<class Dato>
void Lista<Dato>::delDato(unsigned pos)
{
    Nodo<Dato>* paux = primero;
    if (pos == 1 || !(primero->obtenerSiguiente()))
    {
        primero = paux->obtenerSiguiente();
    }
    else
    {
        unsigned i = 1;
        Nodo<Dato>* pant;
        while (i < pos && paux->obtenerSiguiente())
        {
            pant = paux;
            paux = paux->obtenerSiguiente();
            i++;
        }
        pant->asignarSiguiente(paux->obtenerSiguiente());
    }
    delete paux;
    tam--;
}

template<class Dato>
unsigned Lista<Dato>::getPosicion(Dato d)
{
    bool estaEnLista  = false;
    unsigned i = 1 ,posicion ;

    while( i <= this->getTam() || !estaEnLista)
    {
        Dato datoLista = this->getDato(i);

        if(datoLista == d)
        {
            estaEnLista = true;
            posicion = i;
        }

        i++;
    }

    if(!estaEnLista)
        posicion = -1;


    return posicion
}

template<class Dato>
unsigned Lista<Dato>::getTam()
{
    return tam;
}

#endif // LISTA_H
