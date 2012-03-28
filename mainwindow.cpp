#include "ModeloMonedas.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "administrar.h"
#include "devolver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui ->btn_Adm,SIGNAL(pressed()),this,SLOT(pressed_btnAdm()));
    connect(ui -> btn_devolver,SIGNAL(pressed()),this,SLOT(pressed_btnDevolver()));
}

void MainWindow::pressed_btnAdm(){
    this -> setVisible(false);
    (new Administrar) -> show();
}

void MainWindow::pressed_btnDevolver(){
    this -> setVisible(false);
    (new Devolver) -> show();
}


MainWindow::~MainWindow()
{
    delete ui;
}
