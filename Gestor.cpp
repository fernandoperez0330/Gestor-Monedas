#include <iostream>
#include "Objeto.h"
#include "Lista.h"
#include "Gestor.h"
#include "Monedas.h"

Lista* Gestor::getMonedas(){
    return monedas;
}

int Gestor::getTotal(){
    Objeto* objetoActual = getMonedas() -> getPrimero();
    int total = 0;
    while(objetoActual != NULL){
        total = total + (((Monedas*) objetoActual) -> getCantidad() * ((Monedas*) objetoActual) -> getValor());
        objetoActual = objetoActual -> getSiguiente();
    }
    return total;
}
