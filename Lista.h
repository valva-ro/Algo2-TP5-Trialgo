#ifndef LISTA_H
#define LISTA_H

//Include del paquete Nodo
#include"Nodo_Lista.h"

//Libria iostream
#include<iostream>


template<typedef Dato>
class Lista
{

private:

    // Primer elemento de la lista
    NodoLista<Dato>* primero;

    // Tamaño de la lista
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

    // PRE: - lista creada y no vacia
    // POST: libera el nodo que esta en la posición pos
    void delDato(unsigned pos);

    // PRE: Lista creada
    // POST: Devuelve tam (cantidad de nodos de la lista)
    unsigned getTam();
};



//////////////////////////////////////////////////////////////////////
template<typedef Dato>
Lista<Dato>::Lista()
{
    primero = 0 ;
    tam = 0;
}
template<typedef Dato>
Lista<Dato>::~Lista()
{
    while (!(this->lista_vacia()))
        this->del_dato(1);
}

template<typedef Dato>
bool Lista<Dato>::listaVacia()
{
    return(primero == 0);
}

template<typedef Dato>
void Lista<Dato>::insertar(Dato d)
 {
    NodoLista<Dato>* pnodo = new NodoLista<Dato>(d);
    NodoLista<Dato>* paux = primero;
    if (this->listaVacia()){
        primero = pnodo;
    }
    else{
        while (paux->getSiguiente() != 0){
            paux = paux->getSiguiente();
        }
        paux->setSiguiente(pnodo);
 }
 tam++;
}


template<typedef Dato>
Dato Lista::getDato(unsigned pos)
{
    NodoLista<Dato>* paux = primero;

    unsigned i = 1;
    while (i < pos && paux->getSiguiente())
    {
        paux = paux->getSiguiente();
        i++;
    }

    return paux->getDato();
}

template<typedef Dato>
void Lista::delDato(unsigned pos)
{
    NodoLista<Dato>* paux = primero;
    if (pos == 1 || !(primero->getSiguiente()))
    {
        primero = paux->getSiguiente();
    }
    else
    {
        unsigned i = 1;
        NodoLista<Dato>* pant;
        while (i < pos && paux->getSiguiente())
        {
            pant = paux;
            paux = paux->getSiguiente();
            i++;
        }
        pant->setSiguiente(paux->getSiguiente());
    }
    delete paux;
    tam--;
}

template<typedef Dato>
unsigned Lista::getTam()
{
    return tam;
}

#endif // LISTA_H
