Cargador::Cargador()
{

}

void Cargador::cargadorDeABB(ABB<Diccionario> &arbolAeropuertos , ifstream archivo)
{
    //char[3] o string para el codigo IATA?
    string nombre ,ciudad ,pais,codigoIATA ;
    double superficie;
    int cantidadTerminales,destinosNacionales,destinosInternacionales ;


    if(!archivo.fail())
    {
        while(!archivo.eof())
        {
            //Puntero a los datos del aeropuerto
            Aeropuerto *pAeropuerto ;

            archivo >> codigoIATA;
            archivo >> nombre;
            archivo >> ciudad;
            archivo >> pais;
            archivo >> superficie;
            archivo >> cantidadTerminales;
            archivo >> destinosNacionales;
            archivo >> destinosInternacionales;

            pAeropuerto = new Aeropuerto(codigoIATA,nombre,ciudad,pais,superficie,cantidadTerminales,destinosNacionales,destinosInternacionales);

            //Creo un diccionario y le paso por parametro el puntero y la clave del codigo
            Diccionario dicAeropuerto(codigoIATA,pAeropuerto);

            //Inserto el nodo en el arbol
            arbolAeropuertos.insertar(dicAeropuerto);
        }
        cout << "Se han cargado los Aeropuertos en el arbol correctamente " << endl;

    }
    else{
        //Tiro la excepcion
        try {

            throw(Excepcion(ExcepcionABB));
        }
        catch(Excepcion& e) {
            cout << e.what() << endl;
        }
    }
    archivo.close();

}
