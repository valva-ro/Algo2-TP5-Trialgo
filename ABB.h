#ifndef TP5_TRIALGO_ABB_H
#define TP5_TRIALGO_ABB_H

#include "NodoABB.h"
#include "Cola.h"
using namespace std;

template <typename Puntero, typename Dato>
class ABB {

    // Atributos
    private:
        NodoABB<Puntero, Dato>* raiz;

    // Metodos
    public:

        //  PRE: -
        // POST: Construye un objeto de tipo ABB con la raiz apuntando a NULL
        ABB();

        //  PRE: El arbol esta creado
        // POST: Libera los recursos del ABB
        ~ABB();

        //  PRE: -
        // POST: Devuelve la raiz
        NodoABB<Puntero, Dato>* obtenerRaiz();

        //  PRE: El nodo tiene que pertenecer al ABB
        // POST: Devuelve el valor maximo desde el nodo
        NodoABB<Puntero, Dato>* obtenerMax(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El nodo tiene que pertenecer al ABB
        // POST: Devuelve el nodo minimo desde el nodo
        NodoABB<Puntero, Dato>* obtenerMin(NodoABB<Puntero, Dato>* nodo);

        //  PRE: -
        // POST: Devuelve la altura
        int obtenerAltura();

        //  PRE: -
        // POST: Si el dato no existe en el arbol lo agrega
        void insertar(Puntero dato);

        //  PRE: -
        // POST: Si el dato existe en el arbol lo borra
        void borrarDato(Puntero dato);

        //  PRE: -
        // POST: Libera los recursos del ABB
        void borrarTodo();

        //  PRE: -
        // POST: Devuelve true si el arbol esta balanceado, de lo contrario false
        bool estaBalanceado();

        //  PRE: -
        // POST: Devuelve true si el dato existe en el arbol, de lo contrario false
        bool existe(Puntero dato);

        //  PRE: -
        // POST: Si existe el dato, devuelve el sucesor del mismo
        Puntero sucesor(Puntero dato);

        //  PRE: -
        // POST: Si existe el dato, devuelve el predecesor del mismo
        Puntero predecesor(Puntero dato);

        //  PRE: El arbol debe tener al menos un dato
        // POST: Muestra por pantalla el recorrido in order (izquierda, padre, derecha)
        void recorridoInOrder();

        //  PRE: El arbol debe tener al menos un dato
        // POST: Muestra por pantalla el recorrido pre order (padre, izquierda, derecha)
        void recorridoPreOrder();

        //  PRE: El arbol debe tener al menos un dato
        // POST: Muestra por pantalla el recorrido post order (izquierda, derecha, padre)
        void recorridoPostOrder();

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido en ancho
        void recorridoEnAncho();

        //  PRE: -
        // POST: Muestra info basica del ABB
        void mostrarData();

    private:

        //  PRE: El dato no debe estar en el arbol, y ademas tiene que ser el dato del nodo
        // POST: Inserta el dato en el arbol
        NodoABB<Puntero, Dato>* insertar(NodoABB<Puntero, Dato>* nodo, Puntero dato);

        //  PRE: -
        // POST: Devuelve true si el nodo esta balanceado, de lo contrario false
        bool estaBalanceado(NodoABB<Puntero, Dato>* nodo);

        //  PRE: -
        // POST: Devuelve la altura del nodo
        int obtenerAltura(NodoABB<Puntero, Dato>*nodo);

        //  PRE: El dato debe ser el dato del nodo
        // POST: Si el dato existe en el arbol, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoABB<Puntero, Dato>* borrarDato(NodoABB<Puntero, Dato>* nodo, Puntero dato);

        //  PRE: El nodo debe ser hoja
        // POST: Si el dato existe en el arbol, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoABB<Puntero, Dato>* borradoHoja(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El nodo debe tener solo un hijo
        // POST: Si el dato existe en el arbol, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoABB<Puntero, Dato>* borradoUnHijo(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El nodo debe tener ambos hijos
        // POST: Si el dato existe en el arbol, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoABB<Puntero, Dato>* borradoDosHijos(NodoABB<Puntero, Dato>* nodo);

        //  PRE: -
        // POST: Primero borra todos los nodos hijos del nodo recibido, y luego el nodo recibido
        void borrarTodo(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El dato debe ser el dato del nodo
        // POST: Devuelve true si el dato existe en el ABB, de lo contrario false
        NodoABB<Puntero, Dato>* existe(NodoABB<Puntero, Dato>* nodo, Puntero dato);

        //  PRE: El nodo debe existir en el ABB
        // POST: Devuelve el nodo sucesor de nodo
        Puntero sucesor(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El nodo debe existir en el ABB
        // POST: Devuelve el nodo predecesor de nodo
        Puntero predecesor(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido in order
        void recorridoInOrder(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido pre order
        void recorridoPreOrder(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido post order
        void recorridoPostOrder(NodoABB<Puntero, Dato>* nodo);

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido en ancho
        void recorridoEnAncho(NodoABB<Puntero, Dato>* nodo);
};


/* ------------------------------- Metodos Publicos ------------------------------- */

template <typename Puntero, typename Dato>
ABB<Puntero, Dato>:: ABB() {
    raiz = 0;
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
ABB<Puntero, Dato>:: ~ABB() {
    borrarTodo();
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: insertar(Puntero dato) {
    if (!existe(dato))
        raiz = insertar(raiz, dato);
    else
        cout << "\tEl dato " << dato << " ya existe en el arbol!\n";
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
int ABB<Puntero, Dato>:: obtenerAltura() {
    return obtenerAltura(raiz);
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: obtenerRaiz() {
    return raiz;
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: obtenerMax(NodoABB<Puntero, Dato>* nodo) {
    if (nodo != 0) {
        while(nodo->obtenerDerecha())
            nodo = nodo->obtenerDerecha();
    }
    else {
        cout <<  "El nodo no tiene subarbol a la derecha!" << endl;
        nodo = 0;
    }
    return nodo;
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: obtenerMin(NodoABB<Puntero, Dato>* nodo) {
    if (nodo != 0) {
        while(nodo->obtenerIzquierda())
            nodo = nodo->obtenerIzquierda();
    }
    else {
        cout <<  "El nodo no tiene subarbol a la izquierda!" << endl;
        nodo = 0;
    }
    return nodo;
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: borrarDato(Puntero dato) {
    if (existe(dato))
        raiz = borrarDato(raiz, dato);
    else
        cout << "\tEl dato " << dato << " no existe!\n";
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: borrarTodo() {
    borrarTodo(raiz);
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
bool ABB<Puntero, Dato>:: estaBalanceado() {
    return estaBalanceado(raiz);
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
bool ABB<Puntero, Dato>:: existe(Puntero dato) {
    NodoABB<Puntero, Dato>* result = existe(raiz, dato);
    return result != 0;
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
Puntero ABB<Puntero, Dato>::sucesor(Puntero dato) {
    if (existe(dato)) {
        NodoABB<Puntero, Dato> *datoNodo = existe(raiz, dato);
        return sucesor(datoNodo);
    }
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
Puntero ABB<Puntero, Dato>::predecesor(Puntero dato) {
    if (existe(dato)) {
        NodoABB<Puntero, Dato> *datoNodo = existe(raiz, dato);
        return predecesor(datoNodo);
    }
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: recorridoInOrder() {
    recorridoInOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: recorridoPreOrder() {
    recorridoPreOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: recorridoPostOrder() {
    recorridoPostOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: recorridoEnAncho() {
    recorridoEnAncho(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: mostrarData() {

    cout << "\n\n\t__________________________________________\n";
    cout << "\tIn order: ";
    recorridoInOrder();
    cout << "\tPre order: ";
    recorridoPreOrder();
    cout << "\tPost order: ";
    recorridoPostOrder();
    cout << "\tEn amplitud: ";
    recorridoEnAncho();

    cout << "\n\tLa raiz del ABB es: " << raiz->obtenerDato() << "\n";
    cout << "\tLa altura del ABB es: " << obtenerAltura() << "\n";
    cout << "\tMax: " << obtenerMax(raiz)->obtenerDato() << "\n";
    cout << "\tMin: " << obtenerMin(raiz)->obtenerDato() << "\n";

    if (estaBalanceado())
        cout << "\tEl ABB esta balanceado! " << "\n\n";
    else
        cout << "\tEl ABB no esta balanceado! " << "\n";

    cout << "\t__________________________________________\n\n";
}

/* ------------------------------------------------------------------------------ */


/* ------------------------------- Metodos Privados ----------------------------- */

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: insertar(NodoABB<Puntero, Dato>* nodo, Puntero dato) {
    if (nodo == 0)
        nodo = new NodoABB<Puntero, Dato>(dato);

    else if (dato > nodo->obtenerPuntero())
        nodo->asignarDerecha(insertar(nodo->obtenerDerecha(), dato));

    else
        nodo->asignarIzquierda(insertar(nodo->obtenerIzquierda(), dato));

    return nodo;
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
int ABB<Puntero, Dato>:: obtenerAltura(NodoABB<Puntero, Dato>* nodo) {
    if (!nodo)
        return 0;
    return 1 + max(obtenerAltura(nodo->obtenerIzquierda()), obtenerAltura(nodo->obtenerDerecha()));
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
bool ABB<Puntero, Dato>:: estaBalanceado(NodoABB<Puntero, Dato>* nodo) {
    if (!nodo)
        return false;
    return abs(obtenerAltura(nodo->obtenerIzquierda()) - obtenerAltura(nodo->obtenerDerecha())) <= 1;
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: borradoHoja(NodoABB<Puntero, Dato>* nodo) {
    delete nodo;
    return 0;
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: borradoUnHijo(NodoABB<Puntero, Dato>* nodo) {

    if (nodo->soloHijoDerecha()) {
        NodoABB<Puntero, Dato>* nodoDer = nodo->obtenerDerecha();
        nodoDer->asignarPadre(nodo->obtenerPadre());
        NodoABB<Puntero, Dato>* aux = nodo;
        delete aux;
        return nodoDer;
    }

    else if (nodo->soloHijoIzquierda()) {
        NodoABB<Puntero, Dato>* nodoIzq = nodo->obtenerIzquierda();
        nodoIzq->asignarPadre(nodo->obtenerPadre());
        NodoABB<Puntero, Dato>* aux = nodo;
        delete aux;
        return nodoIzq;
    }
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: borradoDosHijos(NodoABB<Puntero, Dato>* nodo) {
    Puntero sucesorDato = sucesor(nodo->obtenerDato());
    nodo->asignarDato(sucesorDato);
    nodo->asignarDerecha(borrarDato(nodo->obtenerDerecha(), sucesorDato));
    return nodo;
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: borrarDato(NodoABB<Puntero, Dato>* nodo, Puntero dato) {

    if (existe(nodo)) {
        if (nodo->obtenerDato() == dato) {

            if (nodo->esHoja())
                nodo = borradoHoja(nodo);

            else if (nodo->soloHijoDerecha() || nodo->soloHijoIzquierda())
                nodo = borradoUnHijo(nodo);

            else
                nodo = borradoDosHijos(nodo);
        }
        else if (nodo->obtenerDato() < dato)
            nodo->asignarDerecha(borrarDato(nodo->obtenerDerecha(), dato));

        else
            nodo->asignarIzquierda(borrarDato(nodo->obtenerIzquierda(), dato));
    }
    return nodo;
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: borrarTodo(NodoABB<Puntero, Dato>* nodo) {
    if(nodo) {
        borrarTodo(nodo->obtenerIzquierda());
        borrarTodo(nodo->obtenerDerecha());
        delete nodo;
    }
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
NodoABB<Puntero, Dato>* ABB<Puntero, Dato>:: existe(NodoABB<Puntero, Dato> *nodo, Puntero dato) {
    if (!nodo || nodo->obtenerPuntero() == dato)
        return nodo;
    if (dato > nodo->obtenerPuntero())
        return existe(nodo->obtenerDerecha(), dato);
    return existe(nodo->obtenerIzquierda(), dato);
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
Puntero ABB<Puntero, Dato>:: sucesor(NodoABB<Puntero, Dato>* nodo) {

    if (!nodo->soloHijoDerecha()) {
        NodoABB<Puntero, Dato>* minNodo = obtenerMinNodo(nodo->obtenerDerecha());
        return minNodo->obtenerDato();
    }

    NodoABB<Puntero, Dato>* sucesor = 0;
    NodoABB<Puntero, Dato>* predecesor = raiz;

    while (predecesor != nodo) {
        if (nodo->obtenerDato() < predecesor->obtenerDato()) {
            sucesor = predecesor;
            predecesor = predecesor->obtenerIzquierda();
        }
        else
            predecesor = predecesor->obtenerDerecha();
    }
    return sucesor->obtenerDato();
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
Puntero ABB<Puntero, Dato>:: predecesor(NodoABB<Puntero, Dato>* nodo) {
    if (!nodo->soloHijoIzquierda())
        return obtenerMinNodo(nodo->soloHijoIzquierda());

    NodoABB<Puntero, Dato>* sucesor = 0;
    NodoABB<Puntero, Dato>* predecesor = raiz;

    while (predecesor != nodo) {
        if (nodo->obtenerDato() < predecesor->obtenerDato()) {
            sucesor = predecesor;
            predecesor = predecesor->obtenerDerecha();
        }
        else
            predecesor = predecesor->obtenerIzquierda();
    }
    return sucesor->obtenerDato();
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: recorridoInOrder(NodoABB<Puntero, Dato>* nodo) {
    if (nodo != 0) {
        recorridoInOrder(nodo->obtenerIzquierda());
        cout << nodo->obtenerDato() << " ";
        recorridoInOrder(nodo->obtenerDerecha());
    }
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: recorridoPreOrder(NodoABB<Puntero, Dato>* nodo) {
    if (nodo != 0) {
        cout << nodo->obtenerDato() << " ";
        recorridoPreOrder(nodo->obtenerIzquierda());
        recorridoPreOrder(nodo->obtenerDerecha());
    }
}

////////////////////////////////////////////////
template<typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: recorridoPostOrder(NodoABB<Puntero, Dato>* nodo) {
    if (nodo != 0) {
        recorridoPostOrder(nodo->obtenerIzquierda());
        recorridoPostOrder(nodo->obtenerDerecha());
        cout << nodo->obtenerDato() << " ";
    }
}

////////////////////////////////////////////////
template <typename Puntero, typename Dato>
void ABB<Puntero, Dato>:: recorridoEnAncho(NodoABB<Puntero, Dato> *nodo) {

    if (nodo != 0) {

        Cola<NodoABB<Puntero, Dato>*> cola;
        cola.encolar(nodo);

        while (!cola.vacia()) {

            nodo = cola.obtenerPrimero();
            cola.desencolar();
            cout << nodo->obtenerDato() << " ";

            if (nodo->obtenerIzquierda() != 0)
                cola.encolar(nodo->obtenerIzquierda());

            if (nodo->obtenerDerecha() != 0)
                cola.encolar(nodo->obtenerDerecha());
        }
    }
}

/* ------------------------------------------------------------------------------ */

#endif //TP5_TRIALGO_ABB_H