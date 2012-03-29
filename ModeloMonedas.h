#include <iostream>
#include "Objeto.h"
#include "Devueltas.h"
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
        //variable
        Lista* listaDevueltas;
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
        Lista* generarListaDevueltas(int total);
        //metodo para controlar que no se inserte combinaciones iguales (solo en algunos casos)
        bool agregarDevueltas(Lista* combinacionAgregar);
        //metodo para generar las combinaciones de devueltas organizadas
        Lista* generarDevueltasOrganizadas(Lista *listaAOrganizar);

};
#endif //MODELOMONEDAS_H
