#include "Grafo.h"

const int E_INFINITO = 100000;
const float F_INFINITO = 100000.0;
const string VACIO = "X" ;

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
        existe = true;
    return existe;
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


Matriz<string>* Grafo::caminoMinimo(Matriz<int>* &precioMatriz)
{
    //Inicializo la matriz de Recorrido ...
    Matriz<string>* recorridoMatriz = generarRecorrido();  ///LIBERAR DESPUES

    //k = es el intermediario -> la letra de base
    for(int k = 0 ; k < elementos ,k ++)
    {
        for(int i = 0 ;  i < elementos ; i ++)
        {
            for(int j = 0 ; j < elementos ; j++)
            {
                //Distancia acumulada
                int distancia = precioMatriz->obtenerValor(i,k) + precioMatriz->obtenerValor(k,j);

                if(distancia < precioMatriz->obtenerValor(i,j))
                {
                    precioMatriz->modificarElemento(distancia,i,j);

                    string aeropuerto = vertices->obtenerDato(k);
                    recorridoMatriz->modificarElemento(aeropuerto,i,j);
                }
            }
        }
    }
    return recorridoMatriz;

}


Matriz<string>* Grafo::caminoMinimo(Matriz<float>* &tiempoMatriz)
{
    //Inicializo la matriz de Recorrido ...
    Matriz<string>* recorridoMatriz = generarRecorrido();  ///LIBERAR DESPUES

    //k = es el intermediario -> la letra de base
    for(int k = 0 ; k < elementos ,k ++)
    {
        for(int i = 0 ;  i < elementos ; i ++)
        {
            for(int j = 0 ; j < elementos ; j++)
            {
                //Distancia acumulada
                int distancia = tiempoMatriz->obtenerValor(i,k) + tiempoMatriz->obtenerValor(k,j);

                if(distancia < tiempoMatriz->obtenerValor(i,j))
                    tiempoMatriz->modificarElemento(distancia,i,j); //Modifico la el valor

                    aeropuerto = vertices->obtenerDato(k);
                    recorridoMatriz->modificarElemento(aeropuerto,i,j) //Modifico el aeropuerto

            }
        }
    }

    return recorridoMatriz;
}

Lista<string>* Grafo::armarEscalas(int posOrigen , int posDestino , Matriz<string>* &recorridoMatriz)
{
    Lista<string>* escalas = new Lista<string> ; //Lista que posee las escalas

    string escala = recorridoMatriz->obtenerValor(posOrigen,posDestino);

    while(escala != VACIO)
    {
        escalas->insertar(escala);
        int posEscala = vertices->obtenerPosicion(escala);
        escala =  recorridoMatriz->obtenerValor(posEscala , posicionDestino);
    }

    return escalas;

}

void Grafo::minimoTiempo(string origen , string destino)
{
    Matriz<string>* recorridoMatriz = caminoMinimo(this->tiempoMatriz);


    //Posiciones de los aeropuertos
    unsigned posOrigen  = vertices->obtenerPosicion(origen);
    unsigned posDestino = vertices->obtenerPosicion(destino);

    int tiempoMinimo = tiempoMatriz->obtenerValor(posOrigen,posDestino); //Aca tengo el tiempo minimo entre el origen y destino

    try {
        if (tiempoMinimo == E_INFINITO)
            throw (ExcepcionVuelo());


        cout << "\nTiempo de vuelo:\t"<<tiempoMinimo<<"\n";
        Lista<string>* escalas = armarEscalas(string origen , string destino, recorridoMatriz) ;

        cout << "Escalas:";
        for(int i = 0 ; i < escalas->obtenerTam() ; i++)
        {
            cout << "\t"<<escalas->obtenerDato(i);
        }
        delete escalas;
    }

    catch(ExcepcionVuelo &e) {
        cout << e.what() << endl;
    }
    //Elimino la memoria reservada (Matriz de recorrido y escalas)

    delete recorridoMatriz;
}

void Grafo::minimoPrecio(string origen , string destino)
{
    Matriz<string>* recorridoMatriz = caminoMinimo(this->precioMatriz);


    //Posiciones de los aeropuertos
    unsigned posOrigen  = vertices->obtenerPosicion(origen);
    unsigned posDestino = vertices->obtenerPosicion(destino);

    int precioMinimo = precioMatriz->obtenerValor(posOrigen,posDestino); //Aca tengo el tiempo minimo entre el origen y destino

    try {
        if (precioMinimo == F_INFINITO)
            throw (ExcepcionVuelo());


        cout << "\nPrecio:\t"<<precioMinimo<<"\n";
        Lista<string>* escalas = armarEscalas(string origen , string destino, recorridoMatriz) ;

        cout << "Escalas:";
        for(int i = 0 ; i < escalas->obtenerTam() ; i++)
        {
            cout << "\t"<<escalas->obtenerDato(i);
        }
        delete escalas;
    }

    catch(ExcepcionVuelo &e) {
        cout << e.what() << endl;
    }
    //Elimino la memoria reservada (Matriz de recorrido y escalas)
    delete recorridoMatriz;
}
