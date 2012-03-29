#include "Objeto.h"

#ifndef COLA_H
#define COLA_H

class Cola
{

    private:
        int montoEnEspera;

    public:
        Cola();
        int getMontoEnEspera();
        void setMontoEnEspera(int montoEnEspera);

};

#endif // COLA_H
