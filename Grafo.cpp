#include "Grafo.h"
#include "ExcepcionVuelo.h"

const int   E_INFINITO = 100000;
const float F_INFINITO = 100000.0;
const string     VACIO = "---";

Grafo::Grafo() {
    this->elementos = 0;
    this->precioMatriz = new Matriz<int>;
    this->preciosMinimos = new Matriz<int>;
    this->tiempoMatriz = new Matriz<float>;
    this->tiemposMinimos = new Matriz<float>;
    this->recorridosMinimos = new Matriz<string>;
    this->vertices = new Lista<string>;
    precioMatriz->asignarInicializador(E_INFINITO);
    preciosMinimos->asignarInicializador(E_INFINITO);
    tiempoMatriz->asignarInicializador(F_INFINITO);
    tiemposMinimos->asignarInicializador(F_INFINITO);
    recorridosMinimos->asignarInicializador(VACIO);
}

Grafo::~Grafo() {
    delete precioMatriz;
    delete preciosMinimos;
    delete tiempoMatriz;
    delete tiemposMinimos;
    delete recorridosMinimos;
    delete vertices;
}

bool Grafo::existeArista(string origen, string destino) {
    bool existe = false;

    if (existeVertice(origen) && existeVertice(destino)) {
        int posicionOrigen = vertices->obtenerPosicion(origen);
        int posicionDestino = vertices->obtenerPosicion(destino);
        if ((tiempoMatriz->obtenerValor(posicionOrigen, posicionDestino) < F_INFINITO) && (precioMatriz->obtenerValor(posicionOrigen, posicionDestino) < E_INFINITO))
            existe = true;
    }

    return existe;
}

bool Grafo::existeVertice(string vertice) {
    bool existe = false;
    if (vertices->obtenerPosicion(vertice) != -1)
        existe = true;
    return existe;
}

float Grafo::obtenerTiempo(string origen, string destino) {
    float tiempo = F_INFINITO;
    if (existeArista(origen,destino))
        tiempo = tiempoMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    return tiempo;
}

int Grafo::obtenerPrecio(string origen, string destino) {
    int precio = E_INFINITO;
    if (existeArista(origen,destino))
        precio = precioMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    return precio;
}

void Grafo::insertarArista(string origen, string destino, int precio, float tiempo) {

    int posicionDestino;
    int posicionOrigen;

    if (!existeArista(origen, destino)) {

        if (existeVertice(origen) && existeVertice(destino)) {
            posicionOrigen = vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
        }

        else if (existeVertice(origen)) {
            precioMatriz->agregarFilasColumnas(1, 1);
            tiempoMatriz->agregarFilasColumnas(1, 1);
            tiempoMatriz->agregarFilasColumnas(1, 1);
            preciosMinimos->agregarFilasColumnas(1, 1);
            recorridosMinimos->agregarFilasColumnas(1, 1);
            vertices->insertar(destino);
            posicionOrigen = vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos++;
        }

        else if (existeVertice(destino)) {
            precioMatriz->agregarFilasColumnas(1, 1);
            tiempoMatriz->agregarFilasColumnas(1, 1);
            preciosMinimos->agregarFilasColumnas(1, 1);
            tiemposMinimos->agregarFilasColumnas(1, 1);
            recorridosMinimos->agregarFilasColumnas(1, 1);
            vertices->insertar(origen);
            posicionOrigen = vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos++;
        }

        else {
            precioMatriz->agregarFilasColumnas(2, 2);
            tiempoMatriz->agregarFilasColumnas(2, 2);
            preciosMinimos->agregarFilasColumnas(2, 2);
            tiemposMinimos->agregarFilasColumnas(2, 2);
            recorridosMinimos->agregarFilasColumnas(2, 2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            posicionOrigen = vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos += 2;
        }
    }
    else
        cout << "\n\tYa existe una ruta que conecta " << origen << " con " << destino;
}

void Grafo::calcularRecorridosMinimos() {
    for (int i = 0; i < elementos; i++) {
        for (int j = 0; j < elementos; j++) {
            if (i != j) {
                string aeropuerto = vertices->obtenerDato(j);
                recorridosMinimos->modificarElemento(aeropuerto, i, j);
            }
        }
    }
}

void Grafo::calcularPreciosMinimos() {

    precioMatriz->copiarMatriz(preciosMinimos);
    calcularRecorridosMinimos();

    for (unsigned k = 0; k < elementos; k++) {
        for (unsigned i = 0;  i < elementos; i++) {
            for (unsigned j = 0; j < elementos; j++) {

                int distancia = preciosMinimos->obtenerValor(i,k) + preciosMinimos->obtenerValor(k,j);

                if (distancia < preciosMinimos->obtenerValor(i,j) && i != j) {
                    preciosMinimos->modificarElemento(distancia,i,j);
                    string aeropuerto = vertices->obtenerDato(k);
                    recorridosMinimos->modificarElemento(aeropuerto,i,j);
                }
            }
        }
    }
}

void Grafo::calcularTiemposMinimos() {

    tiempoMatriz->copiarMatriz(tiemposMinimos);
    calcularRecorridosMinimos();

    for (unsigned k = 0; k < elementos; k++) {
        for (unsigned i = 0;  i < elementos; i++) {
            for (unsigned j = 0; j < elementos; j++) {

                float distancia = tiemposMinimos->obtenerValor(i, k) + tiemposMinimos->obtenerValor(k, j);

                if (distancia < tiemposMinimos->obtenerValor(i, j) && i != j) {
                    tiemposMinimos->modificarElemento(distancia, i, j);
                    string aeropuerto = vertices->obtenerDato(k);
                    recorridosMinimos->modificarElemento(aeropuerto, i, j);
                }
            }
        }
    }
}

void Grafo::mostrarEscalas(unsigned posOrigen, unsigned posDestino, Matriz<string>* &recorridoMatriz, Diccionario<string, Aeropuerto*>* &pDiccionario) {

    string escala = recorridoMatriz->obtenerValor(posOrigen,posDestino);
    while (escala != vertices->obtenerDato(posDestino)) {
        cout << "\t--Escala en:";
        if (pDiccionario->existe(escala)) {
            Aeropuerto *pAeropuerto = pDiccionario->obtenerValor(escala);
            cout << "\n\t" << *pAeropuerto;
        }
        else
            cout << "\n\t" << escala ;

        unsigned posEscala = vertices->obtenerPosicion(escala);
        escala =  recorridoMatriz->obtenerValor(posEscala , posDestino);
    }
}

void Grafo::minimoTiempo(string origen, string destino, Diccionario<string, Aeropuerto*>* &pDiccionario) {

    unsigned posOrigen  = vertices->obtenerPosicion(origen);
    unsigned posDestino = vertices->obtenerPosicion(destino);

    float tiempoMinimo = tiemposMinimos->obtenerValor(posOrigen, posDestino);
    try {
        if (tiempoMinimo == F_INFINITO)
            throw (ExcepcionVuelo());

        cout << "\n\tDuracion: " << tiempoMinimo << "hrs\n";
        mostrarEscalas(posOrigen, posDestino, recorridosMinimos, pDiccionario);
    }

    catch(ExcepcionVuelo &e) {
        cout << e.what() << endl;
    }
}

void Grafo::minimoPrecio(string origen, string destino, Diccionario<string, Aeropuerto*>* &pDiccionario) {

    unsigned posOrigen  = vertices->obtenerPosicion(origen);
    unsigned posDestino = vertices->obtenerPosicion(destino);

    int precioMinimo = preciosMinimos->obtenerValor(posOrigen, posDestino);
    try {
        if (precioMinimo == E_INFINITO)
            throw (ExcepcionVuelo());

        cout << "\n\tPrecio: $" << precioMinimo << "\n";
        mostrarEscalas(posOrigen, posDestino, recorridosMinimos,pDiccionario);
    }

    catch(ExcepcionVuelo &e) {
        cout << e.what() << endl;
    }
}
