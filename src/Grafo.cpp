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

Matriz<int>*& Grafo::obtenerPrecioMatriz() {
    return precioMatriz;
}

Matriz<float>*& Grafo::obtenerTiempoMatriz() {
    return tiempoMatriz;
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

RecorridoMinimoPrecio Grafo::dijkstra(const string &origen, Matriz<int> *&precios, Diccionario<string, Aeropuerto *> *&aeropuertos) {

    RecorridoMinimoPrecio recorridoMin;
    bool visitados[elementos];

    for (unsigned i = 0; i < elementos; i++) {
        recorridoMin.precioMinimo[i] = E_INFINITO;
        recorridoMin.rutaMinima[i] = VACIO;
        visitados[i] = false;
    }

    recorridoMin.precioMinimo[vertices->obtenerPosicion(origen)] = 0;

    for (unsigned i = 0; i < elementos - 1; i++) {
        unsigned posMin = distanciaMinima(recorridoMin.precioMinimo, visitados);
        visitados[posMin] = true;
        for (unsigned j = 0; j < elementos; j++){
            int minDist = recorridoMin.precioMinimo[posMin] + precios->obtenerValor(posMin, j);
            if (!visitados[j] && recorridoMin.precioMinimo[posMin] != E_INFINITO && minDist < recorridoMin.precioMinimo[j]) {
                recorridoMin.precioMinimo[j] = minDist;
                recorridoMin.rutaMinima[j] = vertices->obtenerDato(posMin);
            }
        }
    }
    return recorridoMin;
}

RecorridoMinimoTiempo Grafo::dijkstra(const string &origen, Matriz<float> *&tiempos, Diccionario<string, Aeropuerto *> *&aeropuertos) {

    RecorridoMinimoTiempo recorridoMin;
    bool visitados[elementos];

    for (unsigned i = 0; i < elementos; i++) {
        recorridoMin.tiempoMinimo[i] = F_INFINITO;
        recorridoMin.rutaMinima[i] = VACIO;
        visitados[i] = false;
    }

    recorridoMin.tiempoMinimo[vertices->obtenerPosicion(origen)] = 0;

    for (unsigned i = 0; i < elementos - 1; i++) {
        unsigned posMin = distanciaMinima(recorridoMin.tiempoMinimo, visitados);
        visitados[posMin] = true;
        for (unsigned j = 0; j < elementos; j++){
            float minDist = recorridoMin.tiempoMinimo[posMin] + tiempos->obtenerValor(posMin, j);
            if (!visitados[j] && recorridoMin.tiempoMinimo[posMin] != E_INFINITO && minDist < recorridoMin.tiempoMinimo[j]) {
                recorridoMin.tiempoMinimo[j] = minDist;
                recorridoMin.rutaMinima[j] = vertices->obtenerDato(posMin);
            }
        }
    }
    return recorridoMin;
}

void Grafo::multiplesPreciosMinimos(const string &origen, const string &destino, Diccionario<string, Aeropuerto *> *&aeropuertos) {

    RecorridoMinimoPrecio recorridoMinActual, recorridoMinNuevo;
    string escalaAnterior = origen;
    int precioMinimoActual, precioMinimoNuevo,
        posDestino = vertices->obtenerPosicion(destino),
        posEscalaAnterior, i = 1;

    Matriz<int>* auxiliar = new Matriz<int>(E_INFINITO, elementos, elementos);
    precioMatriz->copiarMatriz(auxiliar);

    recorridoMinActual = dijkstra(origen, auxiliar, aeropuertos);
    precioMinimoActual = recorridoMinActual.precioMinimo[posDestino];
    recorridoMinNuevo = recorridoMinActual;
    escalaAnterior = recorridoMinActual.rutaMinima[posDestino];
    posEscalaAnterior = vertices->obtenerPosicion(escalaAnterior);

    do {
        cout << "\n\tOPCION " << i << ":\n";
        mostrarCaminoMinimo(origen, destino, recorridoMinNuevo.precioMinimo, recorridoMinNuevo.rutaMinima, aeropuertos);

        auxiliar->modificarElemento(E_INFINITO, posEscalaAnterior, posDestino);

        recorridoMinNuevo = dijkstra(origen, auxiliar, aeropuertos);
        precioMinimoNuevo = recorridoMinNuevo.precioMinimo[posDestino];
        escalaAnterior = recorridoMinNuevo.rutaMinima[posDestino];
        posEscalaAnterior = vertices->obtenerPosicion(escalaAnterior);
        i++;
    } while (precioMinimoActual == precioMinimoNuevo && escalaAnterior != destino && escalaAnterior != VACIO);

    delete auxiliar;
}

void Grafo::multiplesTiemposMinimos(const string &origen, const string &destino, Diccionario<string, Aeropuerto *> *&aeropuertos) {

    RecorridoMinimoTiempo recorridoMinActual, recorridoMinNuevo;

    string escalaAnterior = origen;
    float tiempoMinimoActual, tiempoMinimoNuevo;
    int posDestino = vertices->obtenerPosicion(destino), posEscalaAnterior, i = 1;

    Matriz<float>* auxiliar = new Matriz<float>(F_INFINITO, elementos, elementos);
    tiempoMatriz->copiarMatriz(auxiliar);

    recorridoMinActual = dijkstra(origen, auxiliar, aeropuertos);
    tiempoMinimoActual = recorridoMinActual.tiempoMinimo[posDestino];
    recorridoMinNuevo = recorridoMinActual;
    escalaAnterior = recorridoMinActual.rutaMinima[posDestino];
    posEscalaAnterior = vertices->obtenerPosicion(escalaAnterior);


    do {
        cout << "\n\tOPCION " << i << ":\n";
        mostrarCaminoMinimo(origen, destino, recorridoMinNuevo.tiempoMinimo, recorridoMinNuevo.rutaMinima, aeropuertos);

        auxiliar->modificarElemento(E_INFINITO, posEscalaAnterior, posDestino);

        recorridoMinNuevo = dijkstra(origen, auxiliar, aeropuertos);
        tiempoMinimoNuevo = recorridoMinNuevo.tiempoMinimo[posDestino];
        escalaAnterior = recorridoMinNuevo.rutaMinima[posDestino];
        posEscalaAnterior = vertices->obtenerPosicion(escalaAnterior);
        i++;
    } while (tiempoMinimoActual == tiempoMinimoNuevo && escalaAnterior != destino && escalaAnterior != VACIO);

    delete auxiliar;
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

int Grafo::distanciaMinima(int distancias[], bool visitados[]) {
    int min = E_INFINITO;
    int indiceMin = 0;
    for (int i = 0; i < elementos; i++) {
        if (!visitados[i] && distancias[i] <= min) {
            min = distancias[i];
            indiceMin = i;
        }
    }
    return indiceMin;
}

void Grafo::mostrarCaminoMinimo(const string &origen, const string &destino, float distancias[],
                                string recorrido[], Diccionario<string, Aeropuerto *> *&aeropuertos) {
    unsigned posDestino = vertices->obtenerPosicion(destino);
    unsigned posOrigen = vertices->obtenerPosicion(origen);
    mostrarRuta(TIEMPO, recorrido, posOrigen, posDestino, aeropuertos);
    cout << "\n\tDuracion total: " << distancias[posDestino] << " hs\n";
}

void Grafo::mostrarCaminoMinimo(const string &origen, const string &destino, int distancias[],
                                string recorrido[], Diccionario<string, Aeropuerto *> *&aeropuertos) {
    unsigned posDestino = vertices->obtenerPosicion(destino);
    unsigned posOrigen = vertices->obtenerPosicion(origen);
    mostrarRuta(PRECIO, recorrido, posOrigen, posDestino, aeropuertos);
    cout << "\n\tPrecio total: $" << distancias[posDestino] << "\n";
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
        while (recorrido[posEscala] != origen && recorrido[posEscala] != "-") {
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