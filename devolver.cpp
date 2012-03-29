#include "mainwindow.h"
#include "ModeloMonedas.h"
#include "Devueltas.h"
#include "devolver.h"
#include "ui_devolver.h"

Devolver::Devolver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Devolver)
{
    ui->setupUi(this);

    connect(ui -> btnCancelar,SIGNAL(pressed()),this,SLOT(pressed_btnCancelar()));
    connect(ui -> btnGenerar,SIGNAL(pressed()),this,SLOT(pressed_btnGenerar()));
    connect(ui -> btnPonerEspera,SIGNAL(pressed()),this,SLOT(pressed_ponerEspera()));
    connect(ui -> btnDevolver,SIGNAL(pressed()),this,SLOT(pressed_devolver()));

}

void Devolver::pressed_btnCancelar(){
    this -> setVisible(false);
    (new MainWindow) -> show();
}

//metodo para generar devueltas
void Devolver::pressed_btnGenerar(){
    int total = ui ->fldTotal -> text().toUInt();
    int totalSum = 0;
    int totalSubsum = 0;
    int b = 0;
    int i = 0;
    char buf[5];
    string result = "";
    ModeloMonedas* modelo = new ModeloMonedas;
    Objeto* objetoActual;
    Objeto* subObjetoActual;
    if (total > modelo ->getTotal()){
        QMessageBox::warning(this,"Error","No hay suficiente dinero en caja para devolverle, estamos en quiebra!!");
    }else{
        //TODO: llevar para modelo
        //proceder a buscar los cambios (en caso de que aplique)
        objetoActual = modelo -> getMonedas() -> getPrimero();
        /*
        //Lista general de Devueltas

        */
        Lista* listaDevueltaGeneral = new Lista;
        Lista* listaCombinacion;
        Devueltas * devuelta;
        while(objetoActual != NULL){
            if (total == ((Monedas*) objetoActual)->getValor()){
                listaCombinacion = new Lista;
                devuelta = new Devueltas;
                devuelta -> setCantidad(1);
                devuelta -> setValor(((Monedas*) objetoActual)->getValor());
                listaCombinacion -> agregar(devuelta);
                listaDevueltaGeneral -> agregar(listaCombinacion);

                //TODO: quitar codigo (es temporal)
                result = "1";
                result+= " moneda de ";
                result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                result+= "\n";
                QMessageBox::information(this,"primero",result.c_str());
                //TODO: quitar codigo (es temporal)
            }else{
                int cantidadTotal = ((Monedas*) objetoActual)->getCantidad();
                totalSum = ((Monedas*) objetoActual)->getValor();
                for(i = 0; i < cantidadTotal; i++){
                    totalSum+= ((Monedas*) objetoActual)->getValor();
                    //romper el ciclo si la suma es mayor que el solicitado
                    if(totalSum > total) break;
                    else if (totalSum == total){
                        listaCombinacion = new Lista;
                        devuelta = new Devueltas;
                        devuelta -> setCantidad(i+2);
                        devuelta -> setValor(((Monedas*) objetoActual)->getValor());
                        listaCombinacion -> agregar(devuelta);
                        listaDevueltaGeneral -> agregar(listaCombinacion);

                        //TODO: quitar codigo (es temporal)
                        result = itoa(i+2,buf,10);
                        result+= " monedas de ";
                        result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                        result+= "\n";
                        QMessageBox::information(this,"segundo",result.c_str());
                        //TODO: quitar codigo (es temporal)
                    }
                    //cuando la sumatoria es menor que el total, buscar las posibles combinaciones
                    else{
                        subObjetoActual = modelo -> getMonedas() -> getPrimero();
                        while(subObjetoActual != NULL){
                            int valor = ((Monedas*) objetoActual) -> getValor();
                            int subValor = ((Monedas*) subObjetoActual) -> getValor();
                            totalSubsum = 0;
                            if (valor != subValor){
                                for(b = 1 ;b <=((Monedas* )subObjetoActual) -> getCantidad(); b++){
                                    totalSubsum = totalSubsum + ((Monedas* )subObjetoActual) -> getValor();
                                    int subTotal = totalSum + totalSubsum;
                                    //romper el ciclo si la suma es mayor que el solicitado
                                    if (subTotal == total){
                                        listaCombinacion = new Lista;
                                        devuelta = new Devueltas;
                                        devuelta -> setCantidad(i+2);
                                        devuelta -> setValor(((Monedas*) objetoActual)->getValor());
                                        listaCombinacion -> agregar(devuelta);

                                        devuelta = new Devueltas;
                                        devuelta -> setCantidad(b);
                                        devuelta -> setValor(((Monedas*) subObjetoActual)->getValor());
                                        listaCombinacion -> agregar(devuelta);

                                        listaDevueltaGeneral -> agregar(listaCombinacion);
                                        //TODO: quitar codigo (es temporal)
                                        result = itoa(i+2,buf,10);
                                        result+= " monedas de ";
                                        result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                                        result+= " y ";
                                        result+= itoa(b,buf,10);
                                        result+= " monedas de ";
                                        result+= itoa(((Monedas*) subObjetoActual)->getValor(),buf,10);
                                        result+= "\n";
                                        QMessageBox::information(this,"tercero",result.c_str());
                                        //TODO: quitar codigo (es temporal)
                                    }
                                }
                            }
                            subObjetoActual = subObjetoActual -> getSiguiente();
                        }
                    }
                }
            }
            objetoActual = objetoActual -> getSiguiente();
        }
        //TODO: llevar para modelo
    }
}
//metodo para poner en cola
void Devolver::pressed_ponerEspera(){

}


//metodo de evneto para realizar la devuelta
void Devolver::pressed_devolver(){

}


Devolver::~Devolver()
{
    delete ui;
}
