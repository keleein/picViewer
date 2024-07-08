#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    index = 0;
    len = 0;

    fileMenu = menuBar()->addMenu("file");

    openDir = new QAction("open the folder");
    openDir->setIcon(QIcon(":/icon/openfile.png"));
    openDir->setShortcut(QKeySequence::Open);

    exitProg = new QAction("exit");
    exitProg->setIcon(QIcon(":/icon/exit.png"));
    exitProg->setShortcut(QKeySequence::fromString("ctrl+shift+e"));

    fileMenu->addAction(openDir);
    fileMenu->addSeparator();
    fileMenu->addAction(exitProg);

    aboutMenu = menuBar()->addMenu("about");

    author = new QAction("author");
    author->setIcon(QIcon(":/icon/authority.png"));
    author->setShortcut(QKeySequence::fromString("ctrl+shift+a"));

    aboutMenu->addAction(author);

    pb1 = new QPushButton(QIcon(":/icon/left-arrow.png"),"");
    pb2 = new QPushButton(QIcon(":/icon/right-arrow.png"),"");

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb1);
    hbox->addWidget(pb2);

    la = new mylabel("please select photo...",this);
    la->setScaledContents(true);
    la->setFixedSize(1200,800);
    la->setAlignment(Qt::AlignCenter);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(la);
    vbox->addLayout(hbox);

    gbox = new QGroupBox;
    gbox->setLayout(vbox);

    setCentralWidget(gbox);

    connect(openDir,SIGNAL(triggered(bool)),this,SLOT(open_dir_files()));
    connect(exitProg,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(author,SIGNAL(triggered(bool)),this,SLOT(author_msg()));
    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(front_page()));
    connect(pb2,SIGNAL(clicked(bool)),this,SLOT(back_page()));
    connect(la,SIGNAL(front()),this,SLOT(front_page()));
    connect(la,SIGNAL(back()),this,SLOT(back_page()));
}

MainWindow::~MainWindow() {}

void MainWindow::open_dir_files()
{
    strl = QFileDialog::getOpenFileNames();
    if(!strl.isEmpty())
    {
        len = strl.length();
        la->setPixmap(QPixmap(strl.at(index)));
    }
}

void MainWindow::author_msg()
{
    QMessageBox::about(this,"about","author: gang \n 2024-7-8");
}

void MainWindow::front_page()
{
    if(len)
    {
        index = (index-1+len)%len;
        qDebug() << index;
        la->setPixmap(QPixmap(strl.at(index)));
    }
}

void MainWindow::back_page()
{
    if(len)
    {
        index = (index+1)%len;
        qDebug() << index;
        la->setPixmap(QPixmap(strl.at(index)));
    }
}



