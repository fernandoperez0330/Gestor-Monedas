#include <iostream>
#include "Lista.h"

Lista::Lista(){
    primero = NULL;
    ultimo = NULL;
}

Objeto* Lista::getPrimero(){
    return primero;
}

int Lista::getSize(){
    return size;
}

Objeto* Lista::getUltimo(){
    return ultimo;
}

void Lista::agregar(Objeto* objeto){
    if (getPrimero() == NULL){
        primero = ultimo = objeto;
    }else{
        ultimo -> setSiguiente(objeto);
        ultimo = objeto;
    }
    size++;
    ultimo -> setSiguiente(NULL);
}

void Lista::remover(int key){
	if(getPrimero()==NULL){
		return false;
	}else{
		Objeto *temporal = this->primero;
		Objeto *temporalDos = NULL;
		while (temporal!=NULL){
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
		size--;
	}

}
