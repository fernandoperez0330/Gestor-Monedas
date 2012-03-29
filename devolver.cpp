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
    if (total > modelo ->getTotal()){
        QMessageBox::warning(this,"Error","No hay suficiente dinero en caja para devolverle, estamos en quiebra!!");
    }else{
            modelo->listaDevueltas(total);
        }
        //TODO: llevar para modelo
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
