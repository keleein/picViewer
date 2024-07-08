#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFileDialog>
#include <QMessageBox>
#include "mylabel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    int index;
    int len;
    QStringList strl;
    QMenu *fileMenu;
    QMenu *aboutMenu;
    QAction *openDir;
    QAction *exitProg;
    QAction *author;
    QPushButton *pb1,*pb2;
    mylabel *la;
    QGroupBox *gbox;

private slots:
    void open_dir_files();
    void author_msg();
    void front_page();
    void back_page();
};
#endif // MAINWINDOW_H
