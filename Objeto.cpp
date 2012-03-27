#include <iostream>
#include "Objeto.h"

Objeto::Objeto(){
    anterior = NULL;
    siguiente = NULL;
}

Objeto* Objeto::getAnterior(){
    return anterior;
}

void Objeto::setAnterior(Objeto* anterior){
    this -> anterior = anterior;
}

Objeto* Objeto::getSiguiente(){
    return siguiente;
}
void Objeto::setSiguiente(Objeto* siguiente){
    this -> siguiente = siguiente;
}

int Objeto::getKey(){
    return key;
}
