#ifndef TP5_TRIALGO_MENUVUELO_H
#define TP5_TRIALGO_MENUVUELO_H

// TODO:
//      - Agregar *grafo y *diccionario como atribtuos
//      - Agregar metodos asignarGrafo() y asignarDiccionario()
//      - Agregar en liberarRecursos() la liberacion de memoria del grafo (del diccionario no, porque la libera
//        el destructor del Menu con el metodo liberarRecursos() de la clase MenuAeropuerto)
//      - Pedir y validar codigo IATA de origen y destino del vuelo (para los caminos minimos)
//      - ¿Agregar método que reciba el codigo IATA del vuelo y muestre los datos del aeropuerto?

class MenuVuelo {

    private:
        char opcion;

    public:
        //DESCRIPCION: Muestra las opciones del Menu
        //PRE: -
        //POST: Muestra las opciones del Menu y llama al metodo selectorOpcion()
        void mostrarOpciones();

        //DESCRIPCION: Selector las opciones del Menu
        //PRE: -
        //POST: Pide el ingreso de una opcion y abre el metodo correspondiente.
        //      Si la opcion ingresada es distinta de VOLVER_MENU llama al metodo mostrarOpciones().
        void selectorOpcion();

        //DESCRIPCION: Accede a los metodos necesarios para mostrar el camino de menor costo
        //PRE: -
        //POST: Se muestra el camino de menor costo
        void menorCosto();

        //DESCRIPCION: Accede a los metodos necesarios para mostrar el camino de menor tiempo
        //PRE: -
        //POST: Se muesrta el camino de menor tiempo
        void menorTiempo();

        //DESCRIPCION: Libera el grafo de memoria dinamica
        //PRE: El grafo debe estar cargado
        //POST: Libera el grafo de memoria dinamica
        void liberarRecursos();
};

#endif //TP5_TRIALGO_MENUVUELO_H