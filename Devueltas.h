#include "Objeto.h"

#ifndef DEVUELTAS_H
#define DEVUELTAS_H

class Devueltas: public Objeto{
    private:
        int valor;
        int cantidad;
public:
    int getValor();
    void setValor(int valor);
    int getCantidad();
    void setCantidad(int cantidad);

};

#endif // DEVUELTAS_H
