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
    ModeloMonedas* modelo = new ModeloMonedas;
    Objeto* objetoActual;
    if (total > modelo ->getTotal()){
        QMessageBox::warning(this,"Error","No hay suficiente dinero en caja para devolverle, estamos en quiebra!!");
    }else{
        //obtener las devueltas de este monto
        Lista* combinaciones = modelo->generarListaDevueltas(total);
        if (combinaciones -> getSize() == 0){
            QMessageBox::information(this,"Error","No se encontraron devueltas disponibles");
        }
        Objeto* combinacionActual = combinaciones -> getPrimero();
        //organizar los elementos de menor a mayor
        ui -> tableWidget -> setRowCount(combinaciones -> getSize());
        string strCombinacion;
        while(combinacionActual != NULL){
            Objeto* combinacionElemento = ((Lista*) combinacionActual) -> getPrimero();
            strCombinacion = "";
            while(combinacionElemento != NULL){
                strCombinacion+= itoa(((Devueltas*) combinacionElemento) -> getCantidad(),new char[33],10);
                strCombinacion+= " monedas de RD$";
                strCombinacion+= itoa(((Devueltas*) combinacionElemento) -> getValor(),new char[33],10);
                combinacionElemento = combinacionElemento -> getSiguiente();
                if (combinacionElemento != NULL) strCombinacion+= " y ";
            }
            objetoActual = objetoActual -> getSiguiente();
        }
    }
}


//metodo para poner en cola
void Devolver::pressed_ponerEspera(){
    //QMessageBox::information(this, "Puesto en espera", ui->fldTotal->text());

}


//metodo de evneto para realizar la devuelta
void Devolver::pressed_devolver(){

}


Devolver::~Devolver()
{
    delete ui;
}
