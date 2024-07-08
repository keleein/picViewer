#include "mylabel.h"

mylabel::mylabel(QString str,QMainWindow *parent) : QLabel(parent)
{
    this->setText(str);
}

void mylabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        emit front();
    }else if(ev->button() == Qt::RightButton)
    {
        emit back();
    }else{
        qDebug() << "other mouse button pressed!";
    }
}

