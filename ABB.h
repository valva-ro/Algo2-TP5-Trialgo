#ifndef TP5_TRIALGO_ABB_H
#define TP5_TRIALGO_ABB_H

#include "NodoABB.h"
#include "Cola.h"
using namespace std;

template <typename Tipo>
class ABB {

    // Atributos
    private:
        NodoABB<Tipo>* raiz;

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
        NodoABB<Tipo>* obtenerRaiz();

        //  PRE: El nodo tiene que pertenecer al ABB
        // POST: Devuelve el valor maximo desde el nodo
        NodoABB<Tipo>* obtenerMax(NodoABB<Tipo>* nodo);

        //  PRE: El nodo tiene que pertenecer al ABB
        // POST: Devuelve el nodo minimo desde el nodo
        NodoABB<Tipo>* obtenerMin(NodoABB<Tipo>* nodo);

        //  PRE: -
        // POST: Devuelve la altura
        int obtenerAltura();

        //  PRE: -
        // POST: Si el dato no existe en el arbol lo agrega
        void insertar(Tipo dato);

        //  PRE: -
        // POST: Si el dato existe en el arbol lo borra
        void borrarDato(Tipo dato);

        //  PRE: -
        // POST: Libera los recursos del ABB
        void borrarTodo();

        //  PRE: -
        // POST: Devuelve true si el arbol esta balanceado, de lo contrario false
        bool estaBalanceado();

        //  PRE: -
        // POST: Devuelve true si el dato existe en el arbol, de lo contrario false
        bool existe(Tipo dato);

        //  PRE: -
        // POST: Si existe el dato, devuelve el sucesor del mismo
        Tipo sucesor(Tipo dato);

        //  PRE: -
        // POST: Si existe el dato, devuelve el predecesor del mismo
        Tipo predecesor(Tipo dato);

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
        NodoABB<Tipo>* insertar(NodoABB<Tipo>* nodo, Tipo dato);

        //  PRE: -
        // POST: Devuelve true si el nodo esta balanceado, de lo contrario false
        bool estaBalanceado(NodoABB<Tipo>* nodo);

        //  PRE: -
        // POST: Devuelve la altura del nodo
        int obtenerAltura(NodoABB<Tipo>*nodo);

        //  PRE: El dato debe ser el dato del nodo
        // POST: Si el dato existe en el arbol, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoABB<Tipo>* borrarDato(NodoABB<Tipo>* nodo, Tipo dato);

        //  PRE: El nodo debe ser hoja
        // POST: Si el dato existe en el arbol, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoABB<Tipo>* borradoHoja(NodoABB<Tipo>* nodo);

        //  PRE: El nodo debe tener solo un hijo
        // POST: Si el dato existe en el arbol, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoABB<Tipo>* borradoUnHijo(NodoABB<Tipo>* nodo);

        //  PRE: El nodo debe tener ambos hijos
        // POST: Si el dato existe en el arbol, lo elimina y devuelve el nodo que lo reemplazaria.
        //       De lo contrario devuelve el nodo recibido
        NodoABB<Tipo>* borradoDosHijos(NodoABB<Tipo>* nodo);

        //  PRE: -
        // POST: Primero borra todos los nodos hijos del nodo recibido, y luego el nodo recibido
        void borrarTodo(NodoABB<Tipo>* nodo);

        //  PRE: El dato debe ser el dato del nodo
        // POST: Devuelve true si el dato existe en el ABB, de lo contrario false
        NodoABB<Tipo>* existe(NodoABB<Tipo>* nodo, Tipo dato);

        //  PRE: El nodo debe existir en el ABB
        // POST: Devuelve el nodo sucesor de nodo
        Tipo sucesor(NodoABB<Tipo>* nodo);

        //  PRE: El nodo debe existir en el ABB
        // POST: Devuelve el nodo predecesor de nodo
        Tipo predecesor(NodoABB<Tipo>* nodo);

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido in order
        void recorridoInOrder(NodoABB<Tipo>* nodo);

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido pre order
        void recorridoPreOrder(NodoABB<Tipo>* nodo);

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido post order
        void recorridoPostOrder(NodoABB<Tipo>* nodo);

        //  PRE: El nodo debe pertenecer al arbol
        // POST: Muestra por pantalla el recorrido en ancho
        void recorridoEnAncho(NodoABB<Tipo>* nodo);
};


/* ------------------------------- Metodos Publicos ------------------------------- */

template <typename Tipo>
ABB<Tipo>:: ABB() {
    raiz = 0;
}

////////////////////////////////////////////////
template <typename Tipo>
ABB<Tipo>:: ~ABB() {
    borrarTodo();
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: insertar(Tipo dato) {
    if (!existe(dato))
        raiz = insertar(raiz, dato);
    else
        cout << "\tEl dato " << dato << " ya existe en el arbol!\n";
}

////////////////////////////////////////////////
template <typename Tipo>
int ABB<Tipo>:: obtenerAltura() {
    return obtenerAltura(raiz);
}

////////////////////////////////////////////////
template <typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: obtenerRaiz() {
    return raiz;
}

////////////////////////////////////////////////
template <typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: obtenerMax(NodoABB<Tipo>* nodo) {
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
template <typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: obtenerMin(NodoABB<Tipo>* nodo) {
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
template <typename Tipo>
void ABB<Tipo>:: borrarDato(Tipo dato) {
    if (existe(dato))
        raiz = borrarDato(raiz, dato);
    else
        cout << "\tEl dato " << dato << " no existe!\n";
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: borrarTodo() {
    borrarTodo(raiz);
}

////////////////////////////////////////////////
template <typename Tipo>
bool ABB<Tipo>:: estaBalanceado() {
    return estaBalanceado(raiz);
}

////////////////////////////////////////////////
template <typename Tipo>
bool ABB<Tipo>:: existe(Tipo dato) {
    NodoABB<Tipo>* result = existe(raiz, dato);
    return result != 0;
}

////////////////////////////////////////////////
template <typename Tipo>
Tipo ABB<Tipo>::sucesor(Tipo dato) {
    if (existe(dato)) {
        NodoABB<Tipo> *datoNodo = existe(raiz, dato);
        return sucesor(datoNodo);
    }
}

////////////////////////////////////////////////
template <typename Tipo>
Tipo ABB<Tipo>::predecesor(Tipo dato) {
    if (existe(dato)) {
        NodoABB<Tipo> *datoNodo = existe(raiz, dato);
        return predecesor(datoNodo);
    }
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: recorridoInOrder() {
    recorridoInOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: recorridoPreOrder() {
    recorridoPreOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: recorridoPostOrder() {
    recorridoPostOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: recorridoEnAncho() {
    recorridoEnAncho(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: mostrarData() {

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
template <typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: insertar(NodoABB<Tipo>* nodo, Tipo dato) {
    if (nodo == 0)
        nodo = new NodoABB<Tipo>(dato);

    else if (dato > nodo->obtenerDato())
        nodo->asignarDerecha(insertar(nodo->obtenerDerecha(), dato));

    else
        nodo->asignarIzquierda(insertar(nodo->obtenerIzquierda(), dato));

    return nodo;
}

////////////////////////////////////////////////
template<typename Tipo>
int ABB<Tipo>:: obtenerAltura(NodoABB<Tipo>* nodo) {
    if (!nodo)
        return 0;
    return 1 + max(obtenerAltura(nodo->obtenerIzquierda()), obtenerAltura(nodo->obtenerDerecha()));
}

////////////////////////////////////////////////
template<typename Tipo>
bool ABB<Tipo>:: estaBalanceado(NodoABB<Tipo>* nodo) {
    if (!nodo)
        return false;
    return abs(obtenerAltura(nodo->obtenerIzquierda()) - obtenerAltura(nodo->obtenerDerecha())) <= 1;
}

////////////////////////////////////////////////
template<typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: borradoHoja(NodoABB<Tipo>* nodo) {
    delete nodo;
    return 0;
}

////////////////////////////////////////////////
template<typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: borradoUnHijo(NodoABB<Tipo>* nodo) {

    if (nodo->soloHijoDerecha()) {
        NodoABB<Tipo>* nodoDer = nodo->obtenerDerecha();
        nodoDer->asignarPadre(nodo->obtenerPadre());
        NodoABB<Tipo>* aux = nodo;
        delete aux;
        return nodoDer;
    }

    else if (nodo->soloHijoIzquierda()) {
        NodoABB<Tipo>* nodoIzq = nodo->obtenerIzquierda();
        nodoIzq->asignarPadre(nodo->obtenerPadre());
        NodoABB<Tipo>* aux = nodo;
        delete aux;
        return nodoIzq;
    }
}

////////////////////////////////////////////////
template<typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: borradoDosHijos(NodoABB<Tipo>* nodo) {
    Tipo sucesorDato = sucesor(nodo->obtenerDato());
    nodo->asignarDato(sucesorDato);
    nodo->asignarDerecha(borrarDato(nodo->obtenerDerecha(), sucesorDato));
    return nodo;
}

////////////////////////////////////////////////
template<typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: borrarDato(NodoABB<Tipo>* nodo, Tipo dato) {

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
template <typename Tipo>
void ABB<Tipo>:: borrarTodo(NodoABB<Tipo>* nodo) {
    if(nodo) {
        borrarTodo(nodo->obtenerIzquierda());
        borrarTodo(nodo->obtenerDerecha());
        delete nodo;
    }
}

////////////////////////////////////////////////
template <typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: existe(NodoABB<Tipo> *nodo, Tipo dato) {
    if (!nodo || nodo->obtenerDato() == dato)
        return nodo;
    if (dato > nodo->obtenerDato())
        return existe(nodo->obtenerDerecha(), dato);
    return existe(nodo->obtenerIzquierda(), dato);
}

////////////////////////////////////////////////
template<typename Tipo>
Tipo ABB<Tipo>:: sucesor(NodoABB<Tipo>* nodo) {

    if (!nodo->soloHijoDerecha()) {
        NodoABB<Tipo>* minNodo = obtenerMinNodo(nodo->obtenerDerecha());
        return minNodo->obtenerDato();
    }

    NodoABB<Tipo>* sucesor = 0;
    NodoABB<Tipo>* predecesor = raiz;

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
template<typename Tipo>
Tipo ABB<Tipo>:: predecesor(NodoABB<Tipo>* nodo) {
    if (!nodo->soloHijoIzquierda())
        return obtenerMinNodo(nodo->soloHijoIzquierda());

    NodoABB<Tipo>* sucesor = 0;
    NodoABB<Tipo>* predecesor = raiz;

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
template<typename Tipo>
void ABB<Tipo>:: recorridoInOrder(NodoABB<Tipo>* nodo) {
    if (nodo != 0) {
        recorridoInOrder(nodo->obtenerIzquierda());
        cout << nodo->obtenerDato() << " ";
        recorridoInOrder(nodo->obtenerDerecha());
    }
}

////////////////////////////////////////////////
template<typename Tipo>
void ABB<Tipo>:: recorridoPreOrder(NodoABB<Tipo>* nodo) {
    if (nodo != 0) {
        cout << nodo->obtenerDato() << " ";
        recorridoPreOrder(nodo->obtenerIzquierda());
        recorridoPreOrder(nodo->obtenerDerecha());
    }
}

////////////////////////////////////////////////
template<typename Tipo>
void ABB<Tipo>:: recorridoPostOrder(NodoABB<Tipo>* nodo) {
    if (nodo != 0) {
        recorridoPostOrder(nodo->obtenerIzquierda());
        recorridoPostOrder(nodo->obtenerDerecha());
        cout << nodo->obtenerDato() << " ";
    }
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: recorridoEnAncho(NodoABB<Tipo> *nodo) {

    if (nodo != 0) {

        Cola<NodoABB<Tipo>*> cola;
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