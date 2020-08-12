#include "../include/Grafo.h"
#include "../include/Pila.h"

const int E_INFINITO = 999999;
const float F_INFINITO = 999998.3;
const string VACIO = "-", TIEMPO = "tiempo", PRECIO = "precio";

Grafo::Grafo() {
    this->elementos = 0;
    this->precioMatriz = new Matriz<int>;
    this->tiempoMatriz = new Matriz<float>;
    this->vertices = new Lista<string>;
    precioMatriz->asignarInicializador(E_INFINITO);
    tiempoMatriz->asignarInicializador(F_INFINITO);
}

Grafo::~Grafo() {
    delete precioMatriz;
    delete tiempoMatriz;
    delete vertices;
}

bool Grafo::existeArista(const string &origen, const string &destino) {
    bool existe = false;
    if (existeVertice(origen) && existeVertice(destino)) {
        unsigned int posicionOrigen = vertices->obtenerPosicion(origen);
        unsigned int posicionDestino = vertices->obtenerPosicion(destino);
        if ((tiempoMatriz->obtenerValor(posicionOrigen, posicionDestino) < E_INFINITO) &&
            (precioMatriz->obtenerValor(posicionOrigen, posicionDestino) < F_INFINITO))
            existe = true;
    }
    return existe;
}

bool Grafo::existeVertice(const string &vertice) {
    bool existe = false;
    if (vertices->obtenerPosicion(vertice) != -1)
        existe = true;
    return  existe;
}

float Grafo::obtenerTiempo(const string &origen, const string &destino) {
    float tiempo = F_INFINITO;
    if(existeArista(origen,destino))
        tiempo = tiempoMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    return tiempo;
}

int Grafo::obtenerPrecio(const string &origen, const string &destino) {
    int precio = E_INFINITO;
    if(existeArista(origen,destino))
        precio = precioMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    return precio;
}

void Grafo::insertarArista(const string &origen, const string &destino, int precio, float tiempo) {

    unsigned int posicionDestino, posicionOrigen;

    if(!existeArista(origen,destino)) {

        if(existeVertice(origen) && existeVertice(destino)) {
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
        }

        else if(existeVertice(origen)) {
            precioMatriz->agregarFilasColumnas(1,1);
            tiempoMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(destino);
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else if (existeVertice(destino)) {
            precioMatriz->agregarFilasColumnas(1,1);
            tiempoMatriz->agregarFilasColumnas(1,1);
            vertices->insertar(origen);
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos ++;
        }

        else {
            precioMatriz->agregarFilasColumnas(2,2);
            tiempoMatriz->agregarFilasColumnas(2,2);
            vertices->insertar(origen);
            vertices->insertar(destino);
            posicionOrigen= vertices->obtenerPosicion(origen);
            posicionDestino = vertices->obtenerPosicion(destino);
            precioMatriz->modificarElemento(precio, posicionOrigen, posicionDestino);
            tiempoMatriz->modificarElemento(tiempo, posicionOrigen, posicionDestino);
            elementos += 2;
        }
    }
    else
        cout<<"\n\tYa existe una ruta que conecta " << origen << " con " << destino;
}

void Grafo::caminoMinimoPrecio(const string &origen, const string &destino, Diccionario<string, Aeropuerto *> *&aeropuertos) {

    float distancias[elementos];
    bool visitados[elementos];
    string recorrido[elementos];

    for (unsigned i = 0; i < elementos; i++) {
        distancias[i] = E_INFINITO;
        visitados[i] = false;
        recorrido[i] = VACIO;
    }

    distancias[vertices->obtenerPosicion(origen)] = 0;

    for (unsigned i = 0; i < elementos - 1; i++) {
        unsigned posMin = distanciaMinima(distancias, visitados);
        visitados[posMin] = true;
        for (unsigned j = 0; j < elementos; j++){
            float minDist = distancias[posMin] + precioMatriz->obtenerValor(posMin, j);
            if (!visitados[j] && distancias[posMin] != E_INFINITO && minDist < distancias[j]) {
                distancias[j] = minDist;
                recorrido[j] = vertices->obtenerDato(posMin);
            }
        }
    }
    mostrarCaminoMinimo(PRECIO, origen, destino, distancias, recorrido, aeropuertos);
}

void Grafo::caminoMinimoTiempo(const string &origen, const string &destino, Diccionario<string, Aeropuerto *> *&aeropuertos) {
    float distancias[elementos];
    bool visitados[elementos];
    string recorrido[elementos];

    for (unsigned i = 0; i < elementos; i++) {
        distancias[i] = F_INFINITO;
        visitados[i] = false;
        recorrido[i] = VACIO;
    }

    distancias[vertices->obtenerPosicion(origen)] = 0;

    for (unsigned i = 0; i < elementos - 1; i++) {
        unsigned posMin = distanciaMinima(distancias, visitados);
        visitados[posMin] = true;
        for (unsigned j = 0; j < elementos; j++){
            float minDist = distancias[posMin] + tiempoMatriz->obtenerValor(posMin, j);
            if (!visitados[j] && distancias[posMin] != E_INFINITO && minDist < distancias[j]) {
                distancias[j] = minDist;
                recorrido[j] = vertices->obtenerDato(posMin);
            }
        }
    }
    mostrarCaminoMinimo(TIEMPO, origen, destino, distancias, recorrido, aeropuertos);
}

int Grafo::distanciaMinima(float distancias[], bool visitados[]) {
    float min = F_INFINITO;
    int indiceMin = 0;
    for (int i = 0; i < elementos; i++) {
        if (!visitados[i] && distancias[i] <= min) {
            min = distancias[i];
            indiceMin = i;
        }
    }
    return indiceMin;
}

void Grafo::mostrarCaminoMinimo(const string &tipo, const string &origen, const string &destino, float distancias[],
                                string recorrido[], Diccionario<string, Aeropuerto *> *&aeropuertos) {
    unsigned posDestino = vertices->obtenerPosicion(destino);
    unsigned posOrigen = vertices->obtenerPosicion(origen);
    if (tipo == PRECIO) {
        mostrarRuta(PRECIO, recorrido, posOrigen, posDestino, aeropuertos);
        cout << "\n\tPrecio total: $" << distancias[posDestino] << "\n";
    }
    else if(tipo == TIEMPO) {
        mostrarRuta(TIEMPO, recorrido, posOrigen, posDestino, aeropuertos);
        cout << "\n\tDuracion total: " << distancias[posDestino] << " hs\n";
    }
}

void Grafo::mostrarRuta(const string& tipo, string recorrido[], unsigned posOrigen, unsigned posDestino,
                        Diccionario<string, Aeropuerto *> *&aeropuertos) {

    string origen = vertices->obtenerDato(posOrigen),
           destino = vertices->obtenerDato(posDestino),
           escala = destino,
           escalaAnterior = origen;
    unsigned posEscalaAnterior = posOrigen,
             posEscala = posDestino;

    cout << "\n\tOrigen:";
    if (aeropuertos->existe(origen))
        cout << *aeropuertos->obtenerValor(origen);
    else
        cout << "\n\t" << origen << "\n";

    if (recorrido[posEscala] != origen) {
        Pila<string> escalas;
        while (recorrido[posEscala] != origen) {
            escala = recorrido[vertices->obtenerPosicion(escala)];
            posEscala = vertices->obtenerPosicion(escala);
            escalas.agregar(escala);
        }
        while (!escalas.vacia()) {
            escala = escalas.obtenerUltimo();
            escalas.eliminar();
            posEscala = vertices->obtenerPosicion(escala);

            cout << "\n\tEscala en:";
            if (aeropuertos->existe(escala))
                cout << *aeropuertos->obtenerValor(escala);
            else
                cout << "\n\t" << escala << "\n";

            if (tipo == PRECIO)
                cout << "\n\tPrecio del tramo " << escalaAnterior << " - " << escala << ": $" << precioMatriz->obtenerValor(posEscalaAnterior, posEscala) << "\n";
            else if(tipo == TIEMPO)
                cout << "\n\tDuracion del tramo " << escalaAnterior << " - " << escala << ": " << tiempoMatriz->obtenerValor(posEscalaAnterior, posEscala) << " hs\n";

            posEscalaAnterior = vertices->obtenerPosicion(escala);
            escalaAnterior = vertices->obtenerDato(posEscalaAnterior);}
    }

    cout << "\n\tDestino:";
    if (aeropuertos->existe(destino))
        cout << *aeropuertos->obtenerValor(destino);
    else
        cout << "\n\t" << destino << "\n";

    if (tipo == PRECIO)
        cout << "\n\tPrecio del tramo " << escalaAnterior << " - " << destino << ": $" << precioMatriz->obtenerValor(posEscalaAnterior, posDestino) << "\n";
    else if(tipo == TIEMPO)
        cout << "\n\tDuracion del tramo " << escalaAnterior << " - " << destino << ": " << tiempoMatriz->obtenerValor(posEscalaAnterior, posDestino) << " hs\n";
}