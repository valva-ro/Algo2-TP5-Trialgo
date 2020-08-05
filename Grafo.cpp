#include "Grafo.h"

const int E_INFINITO = 999999;
const float F_INFINITO = 999998.9;


void Grafo::mostrarCaminosMinimosPrecios(string origen, string destino) {
    CaminoMinimoPrecio minPrecio = caminoMinimoPrecio();
    bool encontrado = false;
    if(existeVertice(origen) && existeVertice(destino)) {
        int posOrigen = vertices->obtenerPosicion(origen);
        int posDestino = vertices->obtenerPosicion(destino);
        cout << "\tPrecio Minimo:\t" << minPrecio.precios->obtenerValor(posOrigen, posDestino);
        while (!encontrado) {
            if (minPrecio.rutas->obtenerValor(posOrigen, posDestino) == destino)
                encontrado = true;
            cout << "\t" << minPrecio.rutas->obtenerValor(posOrigen, posDestino) << "\n";
            posOrigen = vertices->obtenerPosicion(minPrecio.rutas->obtenerValor(posOrigen, posDestino));
        }
    }
    delete minPrecio.precios;
    delete minPrecio.rutas;
}

void Grafo::mostrarCaminosMinimosTiempos(string origen, string destino) {
    CaminoMinimoTiempo minTiempo = caminoMinimoTiempo();
    if(existeVertice(origen) && existeVertice(destino)) {
        int posOrigen = vertices->obtenerPosicion(origen);
        int posDestino = vertices->obtenerPosicion(destino);
        cout << "\tTiempo Minimo:\t" << minTiempo.tiempos->obtenerValor(posOrigen, posDestino);
        cout << "\tA traves de:\n";
        while (minTiempo.rutas->obtenerValor(posOrigen, posDestino) != destino) {
            cout << "\t" << minTiempo.rutas->obtenerValor(posOrigen, posDestino) << "\n";
            posOrigen = vertices->obtenerPosicion(minTiempo.rutas->obtenerValor(posOrigen, posDestino));
        }
    }
    delete minTiempo.tiempos;
    delete minTiempo.rutas;
}

CaminoMinimoPrecio Grafo::caminoMinimoPrecio() {

    CaminoMinimoPrecio minPrecio;

    minPrecio.precios = new Matriz<int>(precioMatriz->obtenerInicializador(), precioMatriz->longitudFilas(), precioMatriz->longitudColumnas());
    Matriz<string>* rutasK = new Matriz<string>("-", precioMatriz->longitudFilas(), precioMatriz->longitudColumnas());
    Matriz<string>* rutasI = new Matriz<string>("-", precioMatriz->longitudFilas(), precioMatriz->longitudColumnas());
    Matriz<string>* rutasJ = new Matriz<string>("-", precioMatriz->longitudFilas(), precioMatriz->longitudColumnas());

    for (int i = 0; i < precioMatriz->longitudFilas(); i++) {
        for (int j = 0; j < precioMatriz->longitudColumnas(); j++) {
            minPrecio.precios->modificarElemento(precioMatriz->obtenerValor(i,j), i, j);
        }
    }

    for(int k = 0; k < minPrecio.precios->longitudFilas(); k++) {
        for (int i = 0; i < minPrecio.precios->longitudFilas(); i++) {
            for (int j = 0; j < minPrecio.precios->longitudFilas(); j++) {
                if (i != j && minPrecio.precios->obtenerValor(i, k) + minPrecio.precios->obtenerValor(k, j) < minPrecio.precios->obtenerValor(i, j)) {
                    minPrecio.precios->modificarElemento((minPrecio.precios->obtenerValor(i, k) + minPrecio.precios->obtenerValor(k, j)), i, j);
                    rutasK->modificarElemento(vertices->obtenerDato(k), i, j);
                    rutasI->modificarElemento(vertices->obtenerDato(i), i, j);
                    rutasJ->modificarElemento(vertices->obtenerDato(j), i, j);
                }
            }
        }
    }

    cout << "\n------------- RUTAS K -------------\n";
    for (int i = 0; i < rutasK->longitudFilas(); ++i) {
        for (int j = 0; j < rutasK->longitudColumnas(); ++j) {
            cout << "\t" << rutasK->obtenerValor(i,j);
        }
        cout << "\n";
    }
    cout << "\n------------- RUTAS I -------------\n";
    for (int i = 0; i < rutasI->longitudFilas(); ++i) {
        for (int j = 0; j < rutasI->longitudColumnas(); ++j) {
            cout << "\t" << rutasI->obtenerValor(i,j);
        }
        cout << "\n";
    }
    cout << "\n------------- RUTAS J -------------\n";
    for (int i = 0; i < rutasJ->longitudFilas(); ++i) {
        for (int j = 0; j < rutasJ->longitudColumnas(); ++j) {
            cout << "\t" << rutasJ->obtenerValor(i,j);
        }
        cout << "\n";
    }
    return minPrecio;
}

CaminoMinimoTiempo Grafo::caminoMinimoTiempo() {

    CaminoMinimoTiempo minTiempo;

    minTiempo.tiempos = new Matriz<float>(tiempoMatriz->obtenerInicializador(), tiempoMatriz->longitudFilas(), tiempoMatriz->longitudColumnas());
    minTiempo.rutas = new Matriz<string>("-", precioMatriz->longitudFilas(), precioMatriz->longitudColumnas());
    for (int i = 0; i < minTiempo.tiempos->longitudFilas(); i++) {
        for (int j = 0; j < minTiempo.tiempos->longitudColumnas(); j++) {
            minTiempo.tiempos->modificarElemento(tiempoMatriz->obtenerValor(i,j), i, j);
        }
    }

    for(int k = 0; k < minTiempo.tiempos->longitudFilas(); k++) {
        for (int i = 0; i < minTiempo.tiempos->longitudFilas(); i++) {
            for (int j = 0; j < minTiempo.tiempos->longitudFilas(); j++) {
                if (i != j && minTiempo.tiempos->obtenerValor(i, k) + minTiempo.tiempos->obtenerValor(k, j) < minTiempo.tiempos->obtenerValor(i, j)) {
                    minTiempo.tiempos->modificarElemento((minTiempo.tiempos->obtenerValor(i, k) + minTiempo.tiempos->obtenerValor(k, j)), i, j);
                    minTiempo.rutas->modificarElemento(vertices->obtenerDato(k),i,j);
                }
            }
        }
    }
    return minTiempo;
}

void Grafo::mostrarMatrizPrecios() {
    for (int i = 0; i < precioMatriz->longitudFilas(); i++) {
        for (int j = 0; j < precioMatriz->longitudColumnas(); j++) {
            cout << "\t" << precioMatriz->obtenerValor(i, j);
        }
        cout << "\n";
    }
}

void Grafo::mostrarMatrizTiempos() {
    for (int i = 0; i < tiempoMatriz->longitudFilas(); i++) {
        for (int j = 0; j < tiempoMatriz->longitudColumnas(); j++) {
            cout << "\t" << tiempoMatriz->obtenerValor(i, j);
        }
        cout << "\n";
    }
}
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