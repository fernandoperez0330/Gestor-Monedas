#ifndef ADMINISTRAR_H
#define ADMINISTRAR_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Administrar;
}

class Administrar : public QWidget
{
    Q_OBJECT
    
public:
    explicit Administrar(QWidget *parent = 0);
    ~Administrar();

private slots:
    void pressed_agregar();
    void pressed_cancelar();

private:
    Ui::Administrar *ui;
};

#endif // ADMINISTRAR_H
