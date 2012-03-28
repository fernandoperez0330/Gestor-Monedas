#include "ModeloMonedas.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "administrar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui ->btn_Adm,SIGNAL(pressed()),this,SLOT(pressed_btnAdm()));
}

void MainWindow::pressed_btnAdm(){
    this -> setVisible(false);
    Administrar* admin = new Administrar;
    admin -> show();
}



MainWindow::~MainWindow()
{
    delete ui;
}
