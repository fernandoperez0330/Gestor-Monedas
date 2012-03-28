#include "Objeto.h"

#ifndef COLA_H
#define COLA_H

class Cola
{

    private:
        Objeto* anterior;
        Objeto* siguiente;
        int montoEnEspera;

    public:
        Cola();
        getAnterior();
        setAnterior(Objeto* objeto);
        getSiguiente();
        setSiguiente(Objeto* objeto);
        getMontoEnEspera();
        setMontoEnEspera(int montoEnEspera);

};

#endif // COLA_H
