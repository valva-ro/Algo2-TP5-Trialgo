#include "Grafo.h"

const int E_INFINITO = 999999;
const float F_INFINITO = 999998.3;
const string NULO = "---";

Grafo::Grafo() {
    this->elementos = 0;
    this->precioMatriz = new Matriz<int>;
    this->tiempoMatriz = new Matriz<float>;
    this->vertices = new Lista<string>;
    precioMatriz->asignarInicializador(E_INFINITO);
    tiempoMatriz->asignarInicializador(F_INFINITO);
}

Grafo::Grafo(Matriz<int> *precio, Matriz<float> *tiempo, int elementos, Lista<string> *vertices) {
    this->tiempoMatriz = tiempo;
    this->elementos = vertices->obtenerTam();
    this->precioMatriz = precio;
    this->vertices = vertices;
}

Grafo::~Grafo() {
    delete precioMatriz;
    delete tiempoMatriz;
    delete vertices;
}

bool Grafo::existeArista(string origen, string destino) {
    bool existe = false;
    if (existeVertice(origen) && existeVertice(destino)) {
        int posicionOrigen = vertices->obtenerPosicion(origen);
        int posicionDestino = vertices->obtenerPosicion(destino);
        if ((tiempoMatriz->obtenerValor(posicionOrigen, posicionDestino) < E_INFINITO) &&
            (precioMatriz->obtenerValor(posicionOrigen, posicionDestino) < F_INFINITO))
            existe = true;
    }
    return existe;
}

bool Grafo::existeVertice(string vertice) {
    bool existe = false;
    if (vertices->obtenerPosicion(vertice) != -1)
        existe = true;
    return  existe;
}

float Grafo::obtenerTiempo(string origen, string destino) {
    float tiempo = F_INFINITO;
    if(existeArista(origen,destino))
        tiempo = tiempoMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    return tiempo;
}

int Grafo::obtenerPrecio(string origen, string destino) {
    int precio = E_INFINITO;
    if(existeArista(origen,destino))
        precio = precioMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    return precio;
}

void Grafo::insertarArista(string origen, string destino, int precio, float tiempo) {
    int posicionDestino;
    int posicionOrigen;

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

void Grafo::mostrarRuta(string recorrido[], unsigned pos,
                        Diccionario<string, Aeropuerto *> *&aeropuertos) {
    if (recorrido[pos] == "-")
        return;
    mostrarRuta(recorrido, pos, aeropuertos);
    cout << "\n\tEscala:";
    string escala = vertices->obtenerDato(pos);
    if (aeropuertos->existe(escala))
        cout << *aeropuertos->obtenerValor(escala);
    else
        cout << "\n\t" << escala << "\n";
}

void Grafo::mostrarCaminosMinimos(string origen, string destino, unsigned distancias[], string recorrido[],
                                  Diccionario<string, Aeropuerto *> *&aeropuertos) {
    cout << "\n\tOrigen:";
    if (aeropuertos->existe(origen))
        cout << *aeropuertos->obtenerValor(origen);
    else
        cout << "\n\t" << origen << "\n";

    cout << "\n\tDestino:";
    if (aeropuertos->existe(destino))
        cout << *aeropuertos->obtenerValor(destino);
    else
        cout << "\n\t" << destino << "\n";

    unsigned posDestino = vertices->obtenerPosicion(destino);
    cout << "\n\tPrecio min: $" << distancias[posDestino] << "\n";
    mostrarRuta(recorrido, posDestino, aeropuertos);
}

unsigned Grafo::distanciaMinima(unsigned *distancias, bool visitados[]) {
    unsigned min = E_INFINITO, indiceMin = 0;
    for (unsigned i = 0; i < elementos; i++) {
        if (!visitados[i] && distancias[i] <= min) {
            min = distancias[i];
            indiceMin = i;
        }
    }
    return indiceMin;
}

void Grafo::caminoMinimoPrecio(string origen, string destino, Diccionario<string, Aeropuerto *> *&aeropuertos) {

    unsigned distancias[elementos];
    bool visitados[elementos];
    string recorrido[elementos];

    for (unsigned i = 0; i < elementos; i++) {
        distancias[i] = E_INFINITO;
        visitados[i] = false;
        recorrido[i] = "-";
    }

    distancias[vertices->obtenerPosicion(origen)] = 0;

    for (unsigned i = 0; i < elementos - 1; i++) {
        unsigned posMin = distanciaMinima(distancias, visitados);
        visitados[posMin] = true;
        for (unsigned j = 0; j < elementos; j++){
            unsigned minDist = distancias[posMin] + precioMatriz->obtenerValor(posMin, j);
            if (!visitados[j] && distancias[posMin] != E_INFINITO && minDist < distancias[j]) {
                distancias[j] = minDist;
                recorrido[j] = posMin;
            }
        }
    }
    cout << "\n\tVector de distancias:\n";
    for (int i = 0; i < elementos; ++i)
        cout << "\t" << vertices->obtenerDato(i) << " --> " << distancias[i] << "\n";

    mostrarCaminosMinimos(origen, destino, distancias, recorrido, aeropuertos);
}

void Grafo::caminoMinimoTiempo(string origen, string destino, Diccionario<string, Aeropuerto *> *&aeropuertos) {
    //TODO
}