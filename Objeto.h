#ifndef H_OBJETOS
#define H_OBJETOS
class Objeto{
    private:
        //elemento anterior
        Objeto* anterior;
        //elemento siguiente
        Objeto* siguiente;
        //key del elemento
        int key;
    public:
        //metodo constructor
        Objeto();
        //metodo para obtener el indice (key) del objeto
        int getKey();
        //metodo para obtener el elemento anterior del objeto actual
        Objeto* getAnterior();
        //metodo para actualizar el elemento anterior del objeto actual
        void setAnterior(Objeto* anterior);
        //metodo para obtener el elemento siguiente del objeto actual
        Objeto* getSiguiente();
        //metodo para actualizar el elemento anterior del objeto actual
        void setSiguiente(Objeto* siguiente);
};
#endif //H_OBJETOS
