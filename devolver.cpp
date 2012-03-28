#include "mainwindow.h"
#include "ModeloMonedas.h"
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
        //proceder a buscar los cambios (en caso de que aplique)
        objetoActual = modelo -> getMonedas() -> getPrimero();
        while(objetoActual != NULL){
            if (total == ((Monedas*) objetoActual)->getValor()){
                result = "1";
                result+= " moneda de ";
                result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                result+= "\n";
                QMessageBox::information(this,"primero",result.c_str());
            }else{
                int cantidadTotal = ((Monedas*) objetoActual)->getCantidad();
                totalSum = ((Monedas*) objetoActual)->getValor();
                for(i = 0; i < cantidadTotal; i++){
                    totalSum+= ((Monedas*) objetoActual)->getValor();
                    //romper el ciclo si la suma es mayor que el solicitado
                    if(totalSum > total) break;
                    else if (totalSum == total){
                        result = itoa(i+2,buf,10);
                        result+= " monedas de ";
                        result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                        result+= "\n";
                        QMessageBox::information(this,"segundo",result.c_str());
                    }
                    else{
                        totalSubsum = 0;
                        subObjetoActual = modelo -> getMonedas() -> getPrimero();
                        if (((Monedas* )objetoActual) -> getValor() == ((Monedas* )subObjetoActual) -> getValor())
                            continue;
                        while(subObjetoActual != NULL){
                            for(b = 0 ;b < ((Monedas* )subObjetoActual) -> getCantidad(); b++){
                                totalSubsum = totalSubsum + ((Monedas* )subObjetoActual) -> getValor();
                                result= "totalsum.: ";
                                result+= itoa(totalSum,buf,10);
                                result+= ", ";
                                result+= "totalSUBsum.: ";
                                result+= itoa(totalSubsum,buf,10);
                                result+= ", ";
                                result+= "totalSUBsum + totalsum.: ";
                               // result+= itoa(((int)totalSubsum + totalSum),buf,10);
                                //QMessageBox::information(this,"mensaje",result.c_str());

                                //romper el ciclo si la suma es mayor que el solicitado
                                if ((totalSum + totalSubsum) == total){
                                    result = itoa(i+2,buf,10);
                                    result+= " monedas de ";
                                    result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                                    result+= " y ";
                                    result+= itoa(b+1,buf,10);
                                    result+= " monedas de ";
                                    result+= itoa(((Monedas*) subObjetoActual)->getValor(),buf,10);
                                    result+= "\n";
                                    QMessageBox::information(this,"tercero",result.c_str());
                                }else continue;
                            }
                            b = 0;
                            subObjetoActual = subObjetoActual -> getSiguiente();
                        }
                    }
                }
                i = 0;
            }
            objetoActual = objetoActual -> getSiguiente();
        }
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
