#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    mylabel(QString str,QMainWindow *parent);

protected:
    void mousePressEvent(QMouseEvent *ev);

signals:
    void front();
    void back();
};

#endif // MYLABEL_H
