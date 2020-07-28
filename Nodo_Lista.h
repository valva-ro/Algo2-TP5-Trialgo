#ifndef NODO_LISTA_H
#define NODO_LISTA_H


template<typedef Dato>
class NodoLista
{
private:
    Dato dato; // Dato a almacenar
    NodoLista* psig; // Puntero a otro nodo
public:

    // PRE: Ninguna
    // POST: Crea un nodo con el dato d
    // y el puntero a NULL
    NodoLista(Dato d);

    // PRE: Nodo creado
    // POST: No hace nada
    ~NodoLista();

    // PRE: el nodo tiene que estar creado
    // POST: El nodo queda con el dato d
    void setDato(Dato d);

     // PRE: nodo creado
     // POST: devuelve el dato que contiene el nodo
     Dato getDato();

     // PRE: nodo creado
     // POST: el puntero al siguiente nodo apuntará a ps
     void setSiguiente(NodoLista* ps);

     // PRE: nodo creado
     // POST: Devuelve el puntero al siguiente nodo
     NodoLista* getSiguiente();
};


/////////////////////////////////////////////////////////////////
template<typedef Dato>
NodoLista<Dato>::NodoLista(Dato d)
{

    //EL dato es un puntero a objeto
    dato = d;
    psig = 0;

}
NodoLista<Dato>::~NodoLista()
{
    //Como el dato tiene memoria reservada , debo liberarla
    delete dato;
}

template<typedef Dato>
void NodoLista<Dato>::setDato(Dato d)
{
    dato = d; //EL dato es un puntero a objeto
    cout<<dato<<endl;
}

template<typedef Dato>
Dato NodoLista<Dato>::getDato()
{
    return dato;
}

template<typedef Dato>
void NodoLista<Dato>::setSiguiente(NodoLista* ps)
{
    psig = ps;

}

template<typedef Dato>
NodoLista<Dato>* NodoLista<Dato>::getSiguiente()
{
    return psig;
}


#endif // NODO_LISTA_H
