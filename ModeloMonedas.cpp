#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "Devueltas.h"

#include "Objeto.h"
#include "Lista.h"
#include "Monedas.h"
#include "ModeloMonedas.h"

ModeloMonedas::ModeloMonedas(){
    nombreArchivo = "monedas.csv";
    monedas = this -> getTodos();
    separador = ",";
    listaDevueltas = new Lista;
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

bool ModeloMonedas::agregarDevueltas(Lista* combinacionAgregar){
    bool encontro = false;
    int countEncontrado = 0;
    Objeto* combinaciones = this -> listaDevueltas -> getPrimero();
    while(combinaciones != NULL){
        Lista* combinacionActual = (Lista*) combinaciones;
        Objeto* combinacionElemento = combinacionActual -> getPrimero();
        countEncontrado = 0;
        while(combinacionElemento != NULL){
            Devueltas* devElemento = ((Devueltas*) combinacionElemento);
            Objeto* combinacionElementoComparar = combinacionAgregar -> getPrimero();
            while(combinacionElementoComparar != NULL){
                Devueltas* devElementoComparar = ((Devueltas*) combinacionElementoComparar);
                if (devElemento -> getValor() == devElementoComparar -> getValor() && devElemento -> getCantidad() == devElementoComparar -> getCantidad())
                    countEncontrado++;
                combinacionElementoComparar = combinacionElementoComparar -> getSiguiente();
            }
            combinacionElemento = combinacionElemento -> getSiguiente();
        }

        if (countEncontrado == combinacionActual -> getSize()){
            encontro = true;
            break;
        }
        combinaciones = combinaciones -> getSiguiente();
    }

    if (!encontro) {
        this -> listaDevueltas -> agregar(combinacionAgregar);
        return true;
    }else return false;
}

Lista* ModeloMonedas::generarListaDevueltas(int total){
    Lista* listaCombinacion = new Lista;
    Devueltas * devuelta = new Devueltas;
    int totalSum = 0;
    int totalSubsum = 0;
    Objeto* objetoActual;
    Objeto* subObjetoActual;

    //proceder a buscar los cambios (en caso de que aplique)
    objetoActual = this -> getMonedas() -> getPrimero();
    while(objetoActual != NULL){
        if (total == ((Monedas*) objetoActual)->getValor()){
            listaCombinacion = new Lista;
            devuelta = new Devueltas;
            devuelta -> setCantidad(1);
            devuelta -> setValor(((Monedas*) objetoActual)->getValor());
            listaCombinacion -> agregar(devuelta);
            this -> listaDevueltas -> agregar(listaCombinacion);
        }else{
            int cantidadTotal = ((Monedas*) objetoActual)->getCantidad();
            totalSum = ((Monedas*) objetoActual)->getValor();
            for(int i = 0; i < cantidadTotal; i++){
                totalSum+= ((Monedas*) objetoActual)->getValor();
                //romper el ciclo si la suma es mayor que el solicitado
                if(totalSum > total) break;
                else if (totalSum == total){
                    listaCombinacion = new Lista;
                    devuelta = new Devueltas;
                    devuelta -> setCantidad(i+2);
                    devuelta -> setValor(((Monedas*) objetoActual)->getValor());
                    listaCombinacion -> agregar(devuelta);
                    this -> listaDevueltas -> agregar(listaCombinacion);

                }
                //cuando la sumatoria es menor que el total, buscar las posibles combinaciones
                else{
                    subObjetoActual = this -> getMonedas() -> getPrimero();
                    while(subObjetoActual != NULL){
                        int valor = ((Monedas*) objetoActual) -> getValor();
                        int subValor = ((Monedas*) subObjetoActual) -> getValor();
                        totalSubsum = 0;
                        if (valor != subValor){
                            for(int b = 1 ;b <=((Monedas* )subObjetoActual) -> getCantidad(); b++){
                                totalSubsum = totalSubsum + ((Monedas* )subObjetoActual) -> getValor();
                                int subTotal = totalSum + totalSubsum;
                                //romper el ciclo si la suma es mayor que el solicitado
                                if (subTotal == total){
                                    listaCombinacion = new Lista;
                                    devuelta = new Devueltas;
                                    devuelta -> setCantidad(i+2);
                                    devuelta -> setValor(((Monedas*) objetoActual)->getValor());
                                    listaCombinacion -> agregar(devuelta);

                                    devuelta = new Devueltas;
                                    devuelta -> setCantidad(b);
                                    devuelta -> setValor(((Monedas*) subObjetoActual)->getValor());
                                    listaCombinacion -> agregar(devuelta);
                                    this -> agregarDevueltas(listaCombinacion);
                                }
                            }
                        }
                        subObjetoActual = subObjetoActual -> getSiguiente();
                    }
                }
            }
        }
        objetoActual = objetoActual -> getSiguiente();
    }
    return this -> listaDevueltas;
}
