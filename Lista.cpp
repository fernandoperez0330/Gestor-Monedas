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

}
