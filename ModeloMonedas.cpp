#include "Lista.h"
#include "ModeloMonedas.h"

ModeloMonedas::ModeloMonedas(){
    nombreArchivo = "monedas.csv";
    monedaActual = NULL;
    this -> monedas = this -> getAll();
}

Monedas* ModeloMonedas::getMonedaActual(){
    return this -> monedaActual;
}

void ModeloMonedas::persistir(){
    Objeto* objetoActual = this -> monedas -> getPrimero();
    while(objetoActual != NULL){
        objetoActual = objetoActual -> getSiguiente();
    }
}

bool ModeloMonedas::agregar(){
    Objeto* objetoActual = this -> monedas -> getPrimero();
    bool encontro = false;
    while(objetoActual != NULL){
        //si hay otra moneda de ese mismo valor, procedera a sumar la cantidad
        if (monedaActual -> getValor() ==  ((Monedas*) objetoActual) -> getValor()){
            ((Monedas*) objetoActual) -> setCantidad(monedaActual -> getCantidad() + ((Monedas*) objetoActual) -> getCantidad());
            encontro = true;
        }
        objetoActual = objetoActual -> getSiguiente();
    }
    //cuando no encontro moneda del mismo valor
    if (!encontro) this -> monedas -> agregar(monedas);
    return true;
}

Lista* ModeloMonedas::getAll(){
    string linea;
    string elemento;
    int countAttr = 0;
    ifstream inFile (nombreArchivo.c_str());
    Lista* listaMonedas = new Lista;
    Monedas* tmpMoneda;
    while (getline (inFile, linea)){
        istringstream linestream(linea);
        tmpMoneda = new Monedas;
        countAttr = 0;
        while (getline (linestream, elemento, ',')){
            switch(++countAttr){
                case 1: tmpMoneda -> setValor(atoi(elemento.c_str())); break;
                case 2: tmpMoneda -> setCantidad(atoi(elemento.c_str())); break;
            }
        }
        if (countAttr != 0) listaMonedas ->agrega(tmpMoneda);
    }
    return listaMonedas;
}

int ModeloMonedas::getTotal(){
    Objeto* objetoActual = this -> getMonedas() -> getPrimero();
    int total = 0;
    while(objetoActual != NULL){
        total = total + (((Monedas*) objetoActual) -> getCantidad() * ((Monedas*) objetoActual) -> getValor());
        objetoActual = objetoActual -> getSiguiente();
    }
    return total;
}

Lista* ModeloMonedas::getMonedas(){
    return monedas;
}

