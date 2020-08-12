cmake_minimum_required(VERSION 3.16)
project(TP5_Trialgo)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP5_Trialgo
        src/Validaciones.cpp
        include/Validaciones.h
        "src/Grafo.cpp"
        "include/Grafo.h"
        "include/Lista.h"
        "include/Matriz.h"
        "include/Diccionario.h"
        "include/NodoDiccionario.h"
        "include/Nodo.h"
        "include/Cola.h"
        "include/Pila.h"
        include/Cargador.h
        src/Cargador.cpp
        excepciones/ExcepcionDiccionario.cpp
        excepciones/ExcepcionDiccionario.h
        excepciones/ExcepcionGrafo.cpp
        excepciones/ExcepcionGrafo.h
        excepciones/ExcepcionVuelo.cpp
        excepciones/ExcepcionVuelo.h
        src/Menu.cpp
        include/Menu.h
        src/MenuAeropuerto.cpp
        include/MenuAeropuerto.h
        src/MenuVuelo.cpp
        include/MenuVuelo.h
        src/Aeropuerto.cpp
        include/Aeropuerto.h
        src/main.cpp)
