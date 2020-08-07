#include "Grafo.h"
#include "ExcepcionVuelo.h"

const int E_INFINITO   = 100000;
const float F_INFINITO = 100000.0;
const string VACIO     = "X";

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
        if ((tiempoMatriz->obtenerValor(posicionOrigen, posicionDestino) < F_INFINITO) && (precioMatriz->obtenerValor(posicionOrigen, posicionDestino) < E_INFINITO))
            existe = true;
    }

    return existe;
}

bool Grafo::existeVertice(string vertice) {
    bool existe = false;

    if (vertices->obtenerPosicion(vertice) != -1)
    {
        existe = true;
    }

    return existe;
}

float Grafo::obtenerTiempo(string origen, string destino) {
    float tiempo = F_INFINITO;

    if(existeArista(origen,destino))
    {
        tiempo = tiempoMatriz->obtenerValor(vertices->obtenerPosicion(origen),vertices->obtenerPosicion(destino));
    }

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

Matriz<string>* Grafo::generarRecorrido()
{
    Matriz<string>* recorridoMatriz = new Matriz<string>(VACIO,elementos,elementos);//MATRIZ NxN CON TODOS NONE

    for(int i = 0; i < elementos; i++)
    {
        for(int j = 0 ; j < elementos ; j++ )
        {
            if(i != j)
            {
                string aeropuerto = vertices->obtenerDato(j);
                recorridoMatriz->modificarElemento(aeropuerto,i,j);
            }
        }

    }
    return recorridoMatriz;
}

Matriz<string>* Grafo::caminoMinimoPrecio(Matriz<int>* &matrizAux)
{
    precioMatriz->copiarMatriz(matrizAux);
    Matriz<string>* recorridoMatriz = generarRecorrido();

    for(unsigned k = 0 ; k < elementos ; k ++) {
        for(unsigned i = 0 ;  i < elementos ; i ++) {
            for(unsigned j = 0 ; j < elementos ; j++) {

                int distancia = precioMatriz->obtenerValor(i,k) + matrizAux->obtenerValor(k,j);

                if(distancia < matrizAux->obtenerValor(i,j) && i != j) {
                    matrizAux->modificarElemento(distancia,i,j);
                    string aeropuerto = vertices->obtenerDato(k);
                    recorridoMatriz->modificarElemento(aeropuerto,i,j);
                }
            }
        }
    }
    return recorridoMatriz;
}


Matriz<string>* Grafo::caminoMinimoTiempo(Matriz<float>* &matrizAux)
{
    tiempoMatriz->copiarMatriz(matrizAux);
    Matriz<string>* recorridoMatriz = generarRecorrido();

    for(unsigned k = 0 ; k < elementos ; k ++) {
        for(unsigned i = 0 ;  i < elementos ; i ++) {
            for(unsigned j = 0 ; j < elementos ; j++) {

                float distancia = matrizAux->obtenerValor(i,k) + matrizAux->obtenerValor(k,j);

                if(distancia < matrizAux->obtenerValor(i,j) && i!= j) {
                    matrizAux->modificarElemento(distancia,i,j);
                    string aeropuerto = vertices->obtenerDato(k);
                    recorridoMatriz->modificarElemento(aeropuerto,i,j);
                }
            }
        }
    }
    return recorridoMatriz;
}


void Grafo::mostrarEscalas(unsigned posOrigen, unsigned posDestino, Matriz<string>* &recorridoMatriz,Diccionario<string, Aeropuerto*>* &pDiccionario)
{
    string escala = recorridoMatriz->obtenerValor(posOrigen,posDestino);
    while(escala != vertices->obtenerDato(posDestino))
    {
        cout << "\n\tEscala en:";
        if (pDiccionario->existe(escala))
        {
            Aeropuerto *pAeropuerto = pDiccionario->obtenerValor(escala);
            cout << *pAeropuerto;
        }
        else
            cout << "\n\t" << escala;

        unsigned posEscala = vertices->obtenerPosicion(escala);
        escala =  recorridoMatriz->obtenerValor(posEscala , posDestino);
    }
}

void Grafo::minimoTiempo(string origen, string destino, Diccionario<string, Aeropuerto*>* &pDiccionario)
{
    Matriz<float>* matrizAux = new Matriz<float>(F_INFINITO,elementos,elementos);
    Matriz<string>* recorridoMatriz = caminoMinimoTiempo(matrizAux);

    unsigned posOrigen  = vertices->obtenerPosicion(origen);
    unsigned posDestino = vertices->obtenerPosicion(destino);

    float tiempoMinimo = matrizAux->obtenerValor(posOrigen,posDestino);

    try {
        if (tiempoMinimo == F_INFINITO)
            throw (ExcepcionVuelo());

        cout << "\n\tDuracion: " << tiempoMinimo << " hrs\n";
        mostrarEscalas(posOrigen, posDestino,recorridoMatriz,pDiccionario);

    }

    catch(ExcepcionVuelo &e) {
        cout << e.what() << endl;
    }

    delete matrizAux;
    delete recorridoMatriz;
}

void Grafo::minimoPrecio(string origen, string destino, Diccionario<string, Aeropuerto*>* &pDiccionario)
{
    Matriz<int>* matrizAux = new Matriz<int>(E_INFINITO,elementos,elementos);
    Matriz<string>* recorridoMatriz = caminoMinimoPrecio(matrizAux);

    unsigned posOrigen  = vertices->obtenerPosicion(origen);
    unsigned posDestino = vertices->obtenerPosicion(destino);

    int precioMinimo = matrizAux->obtenerValor(posOrigen,posDestino);
    try {
        if (precioMinimo == E_INFINITO)
            throw (ExcepcionVuelo());

        cout << "\n\tPrecio: $" << precioMinimo << "\n";
        mostrarEscalas(posOrigen,posDestino,recorridoMatriz,pDiccionario);

    }

    catch(ExcepcionVuelo &e) {
        cout << e.what() << endl;
    }

    delete matrizAux;
    delete recorridoMatriz;
}
