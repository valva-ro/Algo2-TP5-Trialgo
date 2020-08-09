cmake_minimum_required(VERSION 3.16)
project(TP5_Trialgo)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP5_Trialgo
        src/Validaciones.cpp
        src/Validaciones.h
        "src/Estructuras No Lineales/Grafo.cpp"
        "src/Estructuras No Lineales/Grafo.h"
        "src/Estructuras Lineales/Lista.h"
        "src/Estructuras No Lineales/Matriz.h"
        "src/Estructuras No Lineales/Diccionario.h"
        "src/Estructuras No Lineales/NodoDiccionario.h"
        "src/Estructuras Lineales/Nodo.h"
        "src/Estructuras Lineales/Cola.h"
        src/Cargador.h
        src/Cargador.cpp
        excepciones/ExcepcionDiccionario.cpp
        excepciones/ExcepcionDiccionario.h
        excepciones/ExcepcionGrafo.cpp
        excepciones/ExcepcionGrafo.h
        excepciones/ExcepcionVuelo.cpp
        excepciones/ExcepcionVuelo.h
        src/Menu/Menu.cpp
        src/Menu/Menu.h
        src/Menu/MenuAeropuerto.cpp
        src/Menu/MenuAeropuerto.h
        src/Menu/MenuVuelo.cpp
        src/Menu/MenuVuelo.h
        src/Aeropuerto.cpp
        src/Aeropuerto.h
        src/main.cpp)