#ifndef BINARYTREESEARCHTEMPLATE_BST_H
#define BINARYTREESEARCHTEMPLATE_BST_H

#include <iostream>
#include "NodoDiccionario.h"
#include "Cola.h"

using namespace std;

template <typename Clave, typename Valor>
class Diccionario {

    private:
        NodoDiccionario<Clave, Valor>* raiz;

    public:

        //  PRE: -
        // POST: Construye un objeto de tipo diccionario con la raiz apuntando a NULL
        Diccionario();

        //  PRE: El diccionario esta creado
        // POST: Libera los recursos del diccionario
        ~Diccionario();

        //  PRE: -
        // POST: Devuelve la altura
        int obtenerAltura();

        //  PRE: La clave debe existir en el diccionario
        // POST: Devuelve el valor asociado a esa clave
        Valor obtenerValor(Clave clave);

        //  PRE: -
        // POST: Devuelve la raiz del diccionario
        NodoDiccionario<Clave, Valor>* obtenerRaiz();

        //  PRE: El nodo tiene que pertenecer al diccionario
        // POST: Devuelve el valor maximo desde el nodo
        NodoDiccionario<Clave, Valor>* obtenerMaxNodo(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo tiene que pertenecer al diccionario
        // POST: Devuelve el nodo minimo desde el nodo
        NodoDiccionario<Clave, Valor>* obtenerMinNodo(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: -
        // POST: Si no existe un nodo la clave recibida, lo inserta en el diccionario
        void insertar(Clave clave, Valor valor);

        //  PRE: Debe existir un nodo con esa clave
        // POST: Borra el nodo
        void borrarClave(Clave clave);

        //  PRE: -
        // POST: Libera los recursos del diccionario
        void borrarTodo();

        //  PRE: -
        // POST: Devuelve true si el diccionario esta balanceado, de lo contrario false
        bool estaBalanceado();

        //  PRE: -
        // POST: Devuelve true si existe en el diccionario un nodo con esa clave, de lo contrario false
        bool existe(Clave clave);

        //  PRE: -
        // POST: Si existe el dato, devuelve el sucesor del mismo
        Clave sucesor(Clave clave);

        //  PRE: -
        // POST: Si existe el dato, devuelve el predecesor del mismo
        Clave predecesor(Clave clave);

        //  PRE: El diccionario debe tener al menos un dato
        // POST: Muestra por pantalla el recorrido in order (izquierda, padre, derecha)
        void recorridoInOrder();

        //  PRE: El diccionario debe tener al menos un dato
        // POST: Muestra por pantalla el recorrido pre order (padre, izquierda, derecha)
        void recorridoPreOrder();

        //  PRE: El diccionario debe tener al menos un dato
        // POST: Muestra por pantalla el recorrido post order (izquierda, derecha, padre)
        void recorridoPostOrder();

        //  PRE: El diccionario debe tener al menos un dato
        // POST: Muestra por pantalla el recorrido en ancho
        void recorridoEnAncho();

        //  PRE: -
        // POST: Muestra info basica del ABB
        void mostrarData();

    private:

        //  PRE: -
        // POST: Devuelve la altura del nodo
        int obtenerAltura(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: La clave no debe existir en el diccionario
        // POST: Inserta el dato en el diccionario
        NodoDiccionario<Clave, Valor>* insertar(NodoDiccionario<Clave, Valor>* nodo, Clave clave, Valor valor);

        //  PRE: -
        // POST: Devuelve true si el nodo esta balanceado, de lo contrario false
        bool estaBalanceado(NodoDiccionario<Clave, Valor>* nodo);
            NodoDiccionario<Clave, Valor>* buscar(NodoDiccionario<Clave, Valor>* nodo, Clave clave);

        //  PRE: La clave debe ser la del nodo
        // POST: Si el dato existe en el diccionario, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoDiccionario<Clave, Valor>* borrarClave(NodoDiccionario<Clave, Valor>* nodo, Clave clave);

        //  PRE: El nodo debe ser hoja
        // POST: Si el dato existe en el diccionario, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoDiccionario<Clave, Valor>* borradoCasoHoja(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo debe tener solo un hijo
        // POST: Si el dato existe en el diccionario, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoDiccionario<Clave, Valor>* borradoCasoUnHijo(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo debe tener ambos hijos
        // POST: Si el dato existe en el diccionario, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoDiccionario<Clave, Valor>* borradoCasoDosHijos(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: -
        // POST: Primero borra todos los nodos hijos del nodo recibido, y luego el nodo recibido
        void borrarTodo(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo debe existir en el diccionario
        // POST: Devuelve el nodo sucesor de nodo
        Clave sucesor(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo debe existir en el diccionario
        // POST: Devuelve el nodo predecesor de nodo
        Clave predecesor(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo debe pertenecer al diccionario
        // POST: Muestra por pantalla el recorrido in order
        void recorridoInOrder(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo debe pertenecer al diccionario
        // POST: Muestra por pantalla el recorrido pre order
        void recorridoPreOrder(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo debe pertenecer al diccionario
        // POST: Muestra por pantalla el recorrido post order
        void recorridoPostOrder(NodoDiccionario<Clave, Valor>* nodo);

        //  PRE: El nodo debe pertenecer al diccionario
        // POST: Muestra por pantalla el recorrido en ancho
        void recorridoEnAncho(NodoDiccionario<Clave, Valor>* nodo);
};

/* ------------------------------- Metodos Publicos ------------------------------- */

template <typename Clave, typename Valor>
Diccionario<Clave, Valor>:: Diccionario() {
    raiz = 0;
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
Diccionario<Clave, Valor>:: ~Diccionario() {
    borrarTodo();
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
int Diccionario<Clave, Valor>:: obtenerAltura() {
    return obtenerAltura(raiz);
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
Valor Diccionario<Clave, Valor>:: obtenerValor(Clave clave) {
    return buscar(raiz, clave)->obtenerValor();
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: obtenerRaiz() {
    return raiz;
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: obtenerMaxNodo(NodoDiccionario<Clave, Valor>* nodo) {
    if (!raiz) {
        cout <<  "The Diccionario is empty!" << endl;
        return 0;
    }
    while(nodo->obtenerDerecha())
        nodo = nodo->obtenerDerecha();
    return nodo;
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: obtenerMinNodo(NodoDiccionario<Clave, Valor>* nodo) {
    if (!raiz) {
        cout <<  "The Diccionario is empty!" << endl;
        return 0;
    }
    while(nodo->obtenerIzquierda())
        nodo = nodo->obtenerIzquierda();

    return nodo;
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: insertar(Clave clave, Valor valor) {
    if (!existe(clave))
        raiz = insertar(raiz, clave, valor);
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: borrarClave(Clave clave) {
    raiz = borrarClave(raiz, clave);
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: borrarTodo() {
    borrarTodo(raiz);
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
bool Diccionario<Clave, Valor>:: estaBalanceado() {
    return estaBalanceado(raiz);
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
bool Diccionario<Clave, Valor>:: existe(Clave clave) {
    NodoDiccionario<Clave, Valor>* result = buscar(raiz, clave);
    return result != 0;
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
Clave Diccionario<Clave, Valor>::sucesor(Clave clave) {
    NodoDiccionario<Clave, Valor>* nodoClave = buscar(raiz, clave);
    if(nodoClave != 0)
        return sucesor(nodoClave);
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
Clave Diccionario<Clave, Valor>::predecesor(Clave clave) {
    NodoDiccionario<Clave, Valor>* nodoClave = buscar(raiz, clave);
    if(nodoClave != 0)
        return predecesor(nodoClave);

}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: recorridoInOrder() {
    recorridoInOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: recorridoPreOrder() {
    recorridoPreOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: recorridoPostOrder() {
    recorridoPostOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: recorridoEnAncho() {
    recorridoEnAncho(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: mostrarData() {
    cout << "\tIn order:\n";
    recorridoInOrder();
    cout << "\tPre order:\n";
    recorridoPreOrder();
    cout << "\tPost order:\n";
    recorridoPostOrder();

    cout << "\n\tThe raiz of this Diccionario is: " << raiz->obtenerClave() << "\n";
    cout << "\tThe height of this Diccionario is: " << obtenerAltura() << "\n";
    cout << "\tMax clave: " << obtenerMaxNodo(raiz)->obtenerClave() << " its valor is: " << obtenerMaxNodo(raiz)->obtenerValor() << "\n";
    cout << "\tMin clave: " << obtenerMinNodo(raiz)->obtenerClave() << " its valor is: " << obtenerMinNodo(raiz)->obtenerValor() << "\n";

    if (estaBalanceado())
        cout << "\tDiccionario is balanced! " << "\n\n";
    else
        cout << "\tDiccionario is not balanced! " << "\n\n";

    cout << "____________________________________\n";
}

/* ------------------------------------------------------------------------------- */


/* ------------------------------- Metodos Privados ------------------------------ */

////////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: insertar(NodoDiccionario<Clave, Valor>* nodo, Clave clave, Valor valor) {
    if (nodo == 0)
        nodo = new NodoDiccionario<Clave, Valor>(clave, valor);

    else if (clave > nodo->obtenerClave())
        nodo->asignarDerecha(insertar(nodo->obtenerDerecha(), clave, valor));

    else
        nodo->asignarIzquierda(insertar(nodo->obtenerIzquierda(), clave, valor));

    return nodo;
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
int Diccionario<Clave, Valor>:: obtenerAltura(NodoDiccionario<Clave, Valor>* nodo) {
    if (!nodo)
        return 0;
    return 1 + max(obtenerAltura(nodo->obtenerIzquierda()), obtenerAltura(nodo->obtenerDerecha()));
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
bool Diccionario<Clave, Valor>:: estaBalanceado(NodoDiccionario<Clave, Valor>* nodo) {
    if (!nodo)
        return false;

    int izqAltura = obtenerAltura(nodo->obtenerIzquierda());
    int derAltura = obtenerAltura(nodo->obtenerDerecha());

    return abs(izqAltura - derAltura) <= 1;
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: borradoCasoHoja(NodoDiccionario<Clave, Valor>* nodo) {
    delete nodo;
    return 0;
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: borradoCasoUnHijo(NodoDiccionario<Clave, Valor>* nodo) {

    if (nodo->soloHijoDerecha()) {
        NodoDiccionario<Clave, Valor>* derNodo = nodo->obtenerDerecha();
        derNodo->asignarPadre(nodo->obtenerPadre());
        NodoDiccionario<Clave, Valor>* aux = nodo;
        delete aux;
        return derNodo;
    }

    else if (nodo->soloHijoIzquierda()) {
        NodoDiccionario<Clave, Valor>* izqNodo = nodo->obtenerIzquierda();
        izqNodo->asignarPadre(nodo->obtenerPadre());
        NodoDiccionario<Clave, Valor>* aux = nodo;
        delete aux;
        return izqNodo;
    }
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: borradoCasoDosHijos(NodoDiccionario<Clave, Valor>* nodo) {
    Clave sucesorClave = sucesor(nodo->obtenerClave());
    nodo->asignarClave(sucesorClave);
    nodo->asignarDerecha(borrarClave(nodo->obtenerDerecha(), sucesorClave));
    return nodo;
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: borrarClave(NodoDiccionario<Clave, Valor>* nodo, Clave clave) {

    if (nodo == 0)
        return 0;

    if(nodo->obtenerClave() == clave) {

        if (nodo->esHoja())
            nodo = borradoCasoHoja(nodo);

        else if (nodo->soloHijoDerecha() || nodo->soloHijoIzquierda())
            nodo = borradoCasoUnHijo(nodo);

        else
            nodo = borradoCasoDosHijos(nodo);
    }

    else if (nodo->obtenerClave() < clave)
        nodo->asignarDerecha(borrarClave(nodo->obtenerDerecha(), clave));

    else
        nodo->asignarIzquierda(borrarClave(nodo->obtenerIzquierda(), clave));

    return nodo;
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: borrarTodo(NodoDiccionario<Clave, Valor>* nodo) {
    if(nodo == 0)
        return;
    borrarTodo(nodo->obtenerIzquierda());
    borrarTodo(nodo->obtenerDerecha());
    delete nodo;
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* Diccionario<Clave, Valor>:: buscar(NodoDiccionario<Clave, Valor> *nodo, Clave clave) {
    if (nodo == 0 || nodo->obtenerClave() == clave)
        return nodo;
    if (clave > nodo->obtenerClave())
        return buscar(nodo->obtenerDerecha(), clave);
    return buscar(nodo->obtenerIzquierda(), clave);
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
Clave Diccionario<Clave, Valor>:: sucesor(NodoDiccionario<Clave, Valor>* nodo) {

    if (!nodo->soloHijoDerecha()) {
        NodoDiccionario<Clave, Valor>* minNodo = obtenerMinNodo(nodo->obtenerDerecha());
        return minNodo->obtenerClave();
    }

    NodoDiccionario<Clave, Valor>* sucesor = 0;
    NodoDiccionario<Clave, Valor>* predecesor = raiz;

    while (predecesor != nodo) {
        if (nodo->obtenerClave() < predecesor->obtenerClave()) {
            sucesor = predecesor;
            predecesor = predecesor->obtenerIzquierda();
        }
        else
            predecesor = predecesor->obtenerDerecha();
    }
    return sucesor->obtenerClave();
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
Clave Diccionario<Clave, Valor>:: predecesor(NodoDiccionario<Clave, Valor>* nodo) {
    if (!nodo->soloHijoIzquierda())
        return obtenerMinNodo(nodo->soloHijoIzquierda());

    NodoDiccionario<Clave, Valor>* sucesor = 0;
    NodoDiccionario<Clave, Valor>* predecesor = raiz;

    while (predecesor != nodo) {
        if (nodo->obtenerClave() < predecesor->obtenerClave()) {
            sucesor = predecesor;
            predecesor = predecesor->obtenerDerecha();
        }
        else
            predecesor = predecesor->obtenerIzquierda();
    }
    return sucesor->obtenerClave();
}

////////////////////////////////////////////////
template<typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: recorridoInOrder(NodoDiccionario<Clave, Valor>* nodo) {
    if (!nodo)
        return;
    recorridoInOrder(nodo->obtenerIzquierda());
    cout << "\tClave: " << nodo->obtenerClave() << "\t\tValor: " << *nodo->obtenerValor() << "\n";
    recorridoInOrder(nodo->obtenerDerecha());
}

/////////////////////////////////////////////////////////////////////////////////////////
template<typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: recorridoPreOrder(NodoDiccionario<Clave, Valor>* nodo) {
    if (!nodo)
        return;
    cout << "\tClave: " << nodo->obtenerClave() << "\t\tValor: " << *nodo->obtenerValor() << "\n";
    recorridoPreOrder(nodo->obtenerIzquierda());
    recorridoPreOrder(nodo->obtenerDerecha());
}

/////////////////////////////////////////////////////////////////////////////////////////
template<typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: recorridoPostOrder(NodoDiccionario<Clave, Valor>* nodo) {
    if (!nodo)
        return;
    recorridoPostOrder(nodo->obtenerIzquierda());
    recorridoPostOrder(nodo->obtenerDerecha());
    cout << "\tClave: " << nodo->obtenerClave() << "\t\tValor: " << *nodo->obtenerValor() << "\n";
}

////////////////////////////////////////////////
template <typename Clave, typename Valor>
void Diccionario<Clave, Valor>:: recorridoEnAncho(NodoDiccionario<Clave, Valor> *nodo) {

    if (nodo != 0) {

        Cola<NodoDiccionario<Clave, Valor>*> cola;
        cola.encolar(nodo);

        while (!cola.vacia()) {

            nodo = cola.obtenerPrimero();
            cola.desencolar();
            cout << "\tClave: " << nodo->obtenerClave() << "\t\tValor: " << *nodo->obtenerValor() << "\n";

            if (nodo->obtenerIzquierda() != 0)
                cola.encolar(nodo->obtenerIzquierda());

            if (nodo->obtenerDerecha() != 0)
                cola.encolar(nodo->obtenerDerecha());
        }
    }
}

/* ------------------------------------------------------------------------------- */



#endif //BINARYTREESEARCHTEMPLATE_BST_H