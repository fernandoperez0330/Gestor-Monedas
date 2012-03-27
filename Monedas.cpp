#include "Monedas.h"

int Monedas::getValor(){
    return valor;
}

int Monedas::getCantidad(){
    return cantidad;
}
void Monedas::setValor(int valor){
    this -> valor = valor;
}
void Monedas::setCantidad(int cantidad){
    this -> cantidad = cantidad;
}
