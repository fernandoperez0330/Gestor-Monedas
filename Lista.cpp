#include <iostream>
#include "Lista.h"

Lista::Lista(){
    primero = NULL;
    ultimo = NULL;
    size = 0;
}

Objeto* Lista::getPrimero(){
    return primero;
}

int Lista::getSize(){
    return this -> size;
}

Objeto* Lista::getUltimo(){
    return ultimo;
}

void Lista::agregar(Objeto* objeto){
    if (getPrimero() == NULL){
        primero = ultimo = objeto;
    }else{
        objeto -> setAnterior(ultimo);
        ultimo -> setSiguiente(objeto);
        ultimo = objeto;
    }
    this -> size++;
    ultimo -> setSiguiente(NULL);
}

void Lista::remover(int key){
    Objeto *temporal;
	Objeto *temporalDos;
	if(getPrimero() != NULL){
		temporal = this->primero;
		temporalDos = NULL;
		while (temporal != NULL){
			if(key == temporal->getKey()){
				if(temporalDos== NULL){
					primero = temporal ->getSiguiente();
				}else{
					temporalDos ->setSiguiente(temporal->getSiguiente());
					if(temporal->getSiguiente() == NULL){
						ultimo = temporalDos;
					}
				}
			}
			temporalDos = temporal;
			temporal = temporal->getSiguiente();
			
		}
        this -> size--;
	}
}
