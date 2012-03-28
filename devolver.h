#ifndef DEVOLVER_H
#define DEVOLVER_H

#include <QWidget>

namespace Ui {
class Devolver;
}

class Devolver : public QWidget
{
    Q_OBJECT
    
public:
    explicit Devolver(QWidget *parent = 0);
    ~Devolver();
    
private:
    Ui::Devolver *ui;
};

#endif // DEVOLVER_H
