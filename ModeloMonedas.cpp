#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <fstream>

#include "Objeto.h"
#include "Lista.h"
#include "Monedas.h"
#include "ModeloMonedas.h"

ModeloMonedas::ModeloMonedas(){
    nombreArchivo = "monedas.csv";
    monedas = this -> getTodos();
    separador = ",";
}

Monedas* ModeloMonedas::getMonedaActual(){
    return this -> monedaActual;
}

void ModeloMonedas::setMonedaActual(Monedas* monedaActual){
    this -> monedaActual = monedaActual;
}

void ModeloMonedas::persistir(){
    FILE* file = fopen(this -> nombreArchivo.c_str(),"w");
    string resultado = "";
    char buffer[33];
    Objeto* objetoActual =  monedas ->getPrimero();
    while(objetoActual != NULL){
        resultado+= itoa(((Monedas*) objetoActual) -> getValor(),buffer,10);
        resultado+= this -> separador;
        resultado+= itoa(((Monedas*) objetoActual) -> getCantidad(),buffer,10);
        resultado+= "\n";
        objetoActual = objetoActual -> getSiguiente();
    }
    fputs(resultado.c_str(), file);
    fclose(file);
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
    if (!encontro) this -> monedas -> agregar(monedaActual);
    return true;
}

Lista* ModeloMonedas::getTodos(){
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
        if (countAttr != 0) listaMonedas ->agregar(tmpMoneda);
    }
    return listaMonedas;
    return new Lista;
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
    return this -> monedas;
}

