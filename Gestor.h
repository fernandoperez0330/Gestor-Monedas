#ifndef H_GESTOR
#define H_GESTOR
/**
 * Clase para gestionar las monedas
 */
class Gestor{
    private:
        Lista* monedas;
    public:
        //metodo para obtener la lista actual de las monedas
        Lista* getMonedas();
        //metodo para obtener el total en dinero
        int getTotal();
};
#endif //H_GESTOR


