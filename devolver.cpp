#include "devolver.h"
#include "ui_devolver.h"

Devolver::Devolver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Devolver)
{
    ui->setupUi(this);
}

Devolver::~Devolver()
{
    delete ui;
}
