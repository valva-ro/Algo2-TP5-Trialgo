#ifndef TP5_TRIALGO_ABB_H
#define TP5_TRIALGO_ABB_H

#include "NodoABB.h"
using namespace std;

template <typename Tipo>
class ABB {

    private:
        NodoABB<Tipo>* raiz;

    public:
        ABB();
        ~ABB();
        NodoABB<Tipo>* obtenerRaiz();
        NodoABB<Tipo>* obtenerMaxNode(NodoABB<Tipo>* nodo);
        NodoABB<Tipo>* obtenerMinNode(NodoABB<Tipo>* nodo);
        int obtenerAltura();
        void insertar(Tipo dato);
        void borrarDato(Tipo dato);
        void borrarTodo();
        bool estaBalanceado();
        bool existe(Tipo dato);
        Tipo sucesor(Tipo dato);
        Tipo predecesor(Tipo dato);
        void inOrder(); // izq, padre, der
        void preOrder(); // padre, izq, der
        void postOrder(); // izq, der, padre
        void mostrarData();

    private:
        NodoABB<Tipo>* insertar(NodoABB<Tipo>* nodo, Tipo dato);
        bool estaBalanceado(NodoABB<Tipo>* nodo);
        int obtenerAltura(NodoABB<Tipo>*nodo);
        NodoABB<Tipo>* borrarDato(NodoABB<Tipo>* nodo, Tipo dato);
        NodoABB<Tipo>* borradoHoja(NodoABB<Tipo>* nodo);
        NodoABB<Tipo>* borradoUnHijo(NodoABB<Tipo>* nodo);
        NodoABB<Tipo>* borradoDosHijos(NodoABB<Tipo>* nodo);
        void borrarTodo(NodoABB<Tipo>* nodo);
        NodoABB<Tipo>* existe(NodoABB<Tipo>* nodo, Tipo dato);
        Tipo sucesor(NodoABB<Tipo>* nodo);
        Tipo predecesor(NodoABB<Tipo>* nodo);
        void inOrder(NodoABB<Tipo>* nodo);
        void preOrder(NodoABB<Tipo>* nodo);
        void postOrder(NodoABB<Tipo>* nodo);
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
    raiz = insertar(raiz, dato);
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
NodoABB<Tipo>* ABB<Tipo>:: obtenerMaxNode(NodoABB<Tipo>* nodo) {
    if (!raiz) {
        cout <<  "El ABB esta vacio!" << endl;
        return 0;
    }
    while(nodo->obtenerDerecha())
        nodo = nodo->obtenerDerecha();
    return nodo;
}

////////////////////////////////////////////////
template <typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: obtenerMinNode(NodoABB<Tipo>* nodo) {
    if (!raiz) {
        cout <<  "El ABB esta vacio!" << endl;
        return 0;
    }
    while(nodo->obtenerIzquierda())
        nodo = nodo->obtenerIzquierda();

    return nodo;
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: borrarDato(Tipo dato) {
    cout << "Deleting dato: " << dato << "\n";
    raiz = borrarDato(raiz, dato);
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

    NodoABB<Tipo>* datoNode = existe(raiz, dato);

    if(datoNode == 0)
        return -1;
    else
        return sucesor(datoNode);
}

////////////////////////////////////////////////
template <typename Tipo>
Tipo ABB<Tipo>::predecesor(Tipo dato) {

    NodoABB<Tipo>* datoNode = existe(raiz, dato);

    if(datoNode == 0)
        return -1;
    else
        return predecesor(datoNode);

}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: inOrder() {
    inOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: preOrder() {
    preOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: postOrder() {
    postOrder(raiz);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Tipo>
void ABB<Tipo>:: mostrarData() {

    cout << "\n\n\t__________________________________________\n";
    cout << "\tIn order: ";
    inOrder();
    cout << "\tPre order: ";
    preOrder();
    cout << "\tPost order: ";
    postOrder();

    cout << "\n\tLa raiz del ABB es: " << raiz->obtenerDato() << "\n";
    cout << "\tLa altura del ABB es: " << obtenerAltura() << "\n";
    cout << "\tMax: " << obtenerMaxNode(raiz)->obtenerDato() << "\n";
    cout << "\tMin: " << obtenerMinNode(raiz)->obtenerDato() << "\n";

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

    if (nodo->onlyRightChildren()) {
        NodoABB<Tipo>* rightNode = nodo->obtenerDerecha();
        rightNode->setParent(nodo->obtenerParent());
        NodoABB<Tipo>* aux = nodo;
        delete aux;
        return rightNode;
    }

    else if (nodo->onlyLeftChildren()) {
        NodoABB<Tipo>* leftNode = nodo->obtenerIzquierda();
        leftNode->setParent(nodo->obtenerParent());
        NodoABB<Tipo>* aux = nodo;
        delete aux;
        return leftNode;
    }
}

////////////////////////////////////////////////
template<typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: borradoDosHijos(NodoABB<Tipo>* nodo) {
    Tipo sucesordato = sucesor(nodo->obtenerDato());
    nodo->setdato(sucesordato);
    nodo->asignarDerecha(borrarDato(nodo->obtenerDerecha(), sucesordato));
    return nodo;
}

////////////////////////////////////////////////
template<typename Tipo>
NodoABB<Tipo>* ABB<Tipo>:: borrarDato(NodoABB<Tipo>* nodo, Tipo dato) {

    if (!nodo)
        return nodo;

    if(nodo->obtenerDato() == dato) {

        if (nodo->esHoja())
            nodo = borradoHoja(nodo);

        else if (nodo->onlyRightChildren() || nodo->onlyLeftChildren())
            nodo = borradoUnHijo(nodo);

        else
            nodo = borradoDosHijos(nodo);
    }

    else if (nodo->obtenerDato() < dato)
        nodo->asignarDerecha(borrarDato(nodo->obtenerDerecha(), dato));

    else
        nodo->asignarIzquierda(borrarDato(nodo->obtenerIzquierda(), dato));

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

    if (!nodo->onlyRightChildren()) {
        NodoABB<Tipo>* minNode = obtenerMinNode(nodo->obtenerDerecha());
        return minNode->obtenerDato();
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
    if (!nodo->onlyLeftChildren())
        return obtenerMinNode(nodo->onlyLeftChildren());

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
void ABB<Tipo>:: inOrder(NodoABB<Tipo>* nodo) {
    if (!nodo)
        return;
    inOrder(nodo->obtenerIzquierda());
    cout << nodo->obtenerDato() << " " ;
    inOrder(nodo->obtenerDerecha());
}

////////////////////////////////////////////////
template<typename Tipo>
void ABB<Tipo>:: preOrder(NodoABB<Tipo>* nodo) {
    if (!nodo)
        return;
    cout << nodo->obtenerDato() << " ";
    preOrder(nodo->obtenerIzquierda());
    preOrder(nodo->obtenerDerecha());
}

////////////////////////////////////////////////
template<typename Tipo>
void ABB<Tipo>:: postOrder(NodoABB<Tipo>* nodo) {
    if (!nodo)
        return;
    postOrder(nodo->obtenerIzquierda());
    postOrder(nodo->obtenerDerecha());
    cout << nodo->obtenerDato() << " ";
}
/* ------------------------------------------------------------------------------ */

#endif //TP5_TRIALGO_ABB_H