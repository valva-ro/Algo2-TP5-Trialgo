#ifndef TP5_TRIALGO_NODODICCIONARIO_H
#define TP5_TRIALGO_NODODICCIONARIO_H

using namespace std;

template <typename Clave, typename Valor>
class NodoDiccionario {

    private:
        NodoDiccionario<Clave, Valor>* izquierda;
        NodoDiccionario<Clave, Valor>* derecha;
        NodoDiccionario<Clave, Valor>* padre;
        Clave clave;
        Valor valor;

    public:

    //  PRE: -
    // POST: Construye el nodo con la clave y el valor recibidos, los punteros izquierda, derecha y padre apuntan a null
    NodoDiccionario(Clave clave, Valor valor);

    //  PRE: -
    // POST: Construye el nodo con los parametros recibidos
    NodoDiccionario(Clave clave, Valor valor, NodoDiccionario* izquierda, NodoDiccionario* derecha);

    //  PRE: -
    // POST: Libera la memoria del dato
    ~NodoDiccionario();

    //  PRE: -
    // POST: Devuelve la clave
    Clave obtenerClave();

    //  PRE: -
    // POST: Devuelve el valor
    Valor obtenerValor();

    //  PRE: -
    // POST: Devuelve el puntero al nodo de la izquierda
    NodoDiccionario<Clave, Valor>* obtenerIzquierda();

    //  PRE: -
    // POST: Devuelve el puntero al nodo de la derecha
    NodoDiccionario<Clave, Valor>* obtenerDerecha();

    //  PRE: -
    // POST: Devuelve el puntero al nodo padre
    NodoDiccionario<Clave, Valor>* obtenerPadre();

    //  PRE: -
    // POST: Asigna al atributo clave la clave recibida
    void asignarClave(Clave clave);

    //  PRE: -
    // POST: Asigna al atributo izquierda el puntero recibido
    void asignarIzquierda(NodoDiccionario<Clave, Valor>* izquierda);

    //  PRE: -
    // POST: Asigna al atributo derecha el puntero recibido
    void asignarDerecha(NodoDiccionario<Clave, Valor>* derecha);

    //  PRE: -
    // POST: Asigna al atributo padre el puntero recibido
    void asignarPadre(NodoDiccionario<Clave, Valor>* padre);

    //  PRE: -
    // POST: Devuelve true si el nodo no tiene hijos, de lo contrario false
    bool esHoja();

    //  PRE: -
    // POST: Devuelve true si el nodo tiene unicamente un hijo a derecha, de lo contrario false
    bool soloHijoDerecha();

    //  PRE: -
    // POST: Devuelve true si el nodo tiene unicamente un hijo a izquierda, de lo contrario false
    bool soloHijoIzquierda();
};

/* ------------------------------- Metodos Publicos ------------------------------- */
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>:: NodoDiccionario(Clave clave, Valor valor) {
    this->clave = clave;
    this->valor = valor;
    izquierda = 0;
    derecha = 0;
    padre = 0;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>:: NodoDiccionario(Clave clave, Valor valor, NodoDiccionario* izquierda, NodoDiccionario* derecha) {
    this->clave = clave;
    this->valor = valor;
    this->izquierda = izquierda;
    this->derecha = derecha;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>:: ~NodoDiccionario<Clave, Valor>() {
    delete valor;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
Clave NodoDiccionario<Clave, Valor>:: obtenerClave() {
    return clave;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
Valor NodoDiccionario<Clave, Valor>:: obtenerValor() {
    return valor;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* NodoDiccionario<Clave, Valor>:: obtenerIzquierda() {
    return izquierda;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* NodoDiccionario<Clave, Valor>:: obtenerDerecha() {
    return derecha;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
NodoDiccionario<Clave, Valor>* NodoDiccionario<Clave, Valor>:: obtenerPadre() {
    return padre;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
void NodoDiccionario<Clave, Valor>:: asignarClave(Clave clave) {
    this->clave = clave;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
void NodoDiccionario<Clave, Valor>:: asignarIzquierda(NodoDiccionario<Clave, Valor>* izquierda) {
    this->izquierda = izquierda;
}


/////////////////////////////////////////////
template <typename Clave, typename Valor>
void NodoDiccionario<Clave, Valor>:: asignarDerecha(NodoDiccionario<Clave, Valor>* derecha) {
    this->derecha = derecha;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
void NodoDiccionario<Clave, Valor>:: asignarPadre(NodoDiccionario<Clave, Valor>* padre) {
    this->padre = padre;
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
bool NodoDiccionario<Clave, Valor>:: esHoja() {
    return (derecha == 0 && izquierda == 0);
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
bool NodoDiccionario<Clave, Valor>:: soloHijoIzquierda() {
    return (derecha == 0 && izquierda != 0);
}

/////////////////////////////////////////////
template <typename Clave, typename Valor>
bool NodoDiccionario<Clave, Valor>:: soloHijoDerecha() {
    return (derecha != 0 && izquierda == 0);
}
/* ------------------------------------------------------------------------------ */

#endif //TP5_TRIALGO_NODODICCIONARIO_H