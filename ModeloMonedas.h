#include <iostream>
#include "Objeto.h"
#include "Monedas.h"
#include "Lista.h"

using namespace std;

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
    public:
        //elemento separador de los elementos del archivo
        string separador;
        //metodo constructor (privado)
        ModeloMonedas();
        //metodo para obteber la moneda
        Monedas* getMonedaActual();
        //metodo para actualizar la moneda actual del modelo
        void setMonedaActual(Monedas* monedaActual);
        //metodo para agregar moneda
        bool agregar();
        //metodo para obtener la lista de monedas
        Lista* getMonedas();
        //metodo para obtener el total de dinero
        int getTotal();
        //metodo par obtener todas las monedas actuales
        Lista* getTodos();
        //metodo para persisir los datos actuales de la lista al archivo de datos
        void persistir();
        //metodo para retornar una lista con otra lista
        Lista* listaDevueltas(int total);
};
#endif //MODELOMONEDAS_H
