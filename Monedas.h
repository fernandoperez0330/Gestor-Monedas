#include "Objeto.h"
#ifndef H_MONEDAS
#define H_MONEDAS
/**
 * Clase para objeto tipo moneda
 */
class Monedas: public Objeto{
    private:
        //valor de la moneda
        int valor;
        //cantidad disponible
        int cantidad;
    public:
        //metodo para obtener el valor de la moneda
        int getValor();
        //metodo para obtener la cantidad disponible de la moneda
        int getCantidad();
        //metodo para actualizar el valor de la moneda
        void setValor(int valor);
        //metodo para actualizar la cantidad disponible de la moneda
        void setCantidad(int cantidad);
};
#endif //H_MONEDAS
