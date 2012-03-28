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
    int totalCantidad = 0;
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
            result = "";
            if (total == ((Monedas*) objetoActual)->getValor()){
                result+= "1";
                result+= " moneda de ";
                result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                result+= "\n";
                QMessageBox::information(this,"titulo",result.c_str());
            }else{
                int cantidadTotal = ((Monedas*) objetoActual)->getCantidad();
                totalSum = ((Monedas*) objetoActual)->getValor();
                for(int i = 0; i < cantidadTotal; i++){
                    totalSum = ((Monedas*) objetoActual)->getValor() + totalSum;
                    if (totalSum == total){
                        result+= itoa(i+2,buf,10);
                        result+= " monedas de ";
                        result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                        result+= "\n";
                        QMessageBox::information(this,"titulo",result.c_str());
                    }
                    subObjetoActual = modelo -> getMonedas() -> getPrimero();
                    while(subObjetoActual != NULL){
                        QMessageBox::information(this,"titulo","entro aqui");
                        if (total == (totalSum + ((Monedas*) subObjetoActual) -> getValor())){
                            result+= itoa(i+2,buf,10);
                            result+= " monedas de ";
                            result+= itoa(((Monedas*) objetoActual)->getValor(),buf,10);
                            result+= "\n";
                            QMessageBox::information(this,"titulo",result.c_str());
                        }
                        subObjetoActual = subObjetoActual -> getSiguiente();
                    }

                }



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
