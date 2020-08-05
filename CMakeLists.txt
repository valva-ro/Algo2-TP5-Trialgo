cmake_minimum_required(VERSION 3.16)
project(TP5_Trialgo)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP5_Trialgo
        SOURCE/Validaciones.cpp
        HEADERS/Validaciones.h
        SOURCE/Grafo.cpp
        HEADERS/Grafo.h
        HEADERS/Lista.h
        HEADERS/Matriz.h
        HEADERS/Diccionario.h
        HEADERS/NodoDiccionario.h
        HEADERS/Nodo.h
        HEADERS/Cola.h
        HEADERS/Cargador.h
        SOURCE/Cargador.cpp
        EXCEPTIONS/ExcepcionDiccionario.cpp
        EXCEPTIONS/ExcepcionDiccionario.h
        EXCEPTIONS/ExcepcionGrafo.cpp
        EXCEPTIONS/ExcepcionGrafo.h
        EXCEPTIONS/ExcepcionVuelo.cpp
        EXCEPTIONS/ExcepcionVuelo.h
        SOURCE/Menu.cpp
        HEADERS/Menu.h
        SOURCE/MenuAeropuerto.cpp
        HEADERS/MenuAeropuerto.h
        SOURCE/MenuVuelo.cpp
        HEADERS/MenuVuelo.h
        SOURCE/Aeropuerto.cpp
        HEADERS/Aeropuerto.h
        SOURCE/main.cpp)

