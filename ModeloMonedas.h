#include "Objeto.h"
#include "Moneda.h"
#include <iostream>
#include "Lista.h"
#ifndef MODELOMONEDAS_H
#define MODELOMONEDAS_H
class ModeloMonedas{
    private:
        //moneda actual a gestionar
        Monedas* monedaActual;
        //lista de la monedas
        Lista* monedas;
        //nombre del archivo para persistir los datos
        string nombreArchivo;
        //metodo para persisir los datos actuales de la lista al archivo de datos
        void persistir();
    public:
        //metodo constructor
        ModeloMonedas();
        //metodo para obteber la moneda
        Monedas* getMonedaActual();
        //metodo para agregar moneda
        bool agregar();
        //metodo para obtener la lista de monedas
        Lista* getMonedas();
        //metodo para obtener el total de dinero
        int getTotal();

};
#endif //MODELOMONEDAS_H
