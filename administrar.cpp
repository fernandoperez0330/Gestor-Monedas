#include "Monedas.h"
#include "ModeloMonedas.h"
#include "administrar.h"
#include "ui_administrar.h"
#include "mainwindow.h"

Administrar::Administrar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrar)
{
    ui->setupUi(this);
    connect(ui -> btnAgregar,SIGNAL(pressed()),this,SLOT(pressed_agregar()));
    connect(ui -> btnCancelar,SIGNAL(pressed()),this,SLOT(pressed_cancelar()));
}

//metodo del evento cancelar
void Administrar::pressed_cancelar(){
    this ->setVisible(false);
    (new MainWindow) -> show();
}

//metodo del evento agregar
void Administrar::pressed_agregar(){
    if (ui -> fldValor ->text() == ""){
        QMessageBox::warning(this,"Información","El valor de la moneda esta en blanco");
        ui -> fldValor -> setFocus();
    }else if (ui -> fldCantidad ->text() == ""){
        QMessageBox::warning(this,"Información","El cantidad de la moneda esta en blanco");
        ui -> fldCantidad -> setFocus();
    }else{
        ModeloMonedas* modelo = new ModeloMonedas(NULL);
        Monedas* monedaActual = new Monedas;
        //convertir el valor de la moneda de string a entero
        monedaActual -> setValor(ui -> fldValor -> text().toUInt());
        //convertir la cantidad de la moneda de string a entero
        monedaActual -> setCantidad(ui -> fldCantidad -> text().toUInt());
        modelo -> setMonedaActual(monedaActual);
        modelo -> agregar();
        modelo -> persistir();

        QMessageBox::information(this,"Correctamente","La moneda se ha agregado correctamente");
        this -> setVisible(false);
        (new MainWindow) -> show();
    }
}

Administrar::~Administrar()
{
    delete ui;
}
