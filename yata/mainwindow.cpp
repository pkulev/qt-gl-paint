#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pb_exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(&timer, SIGNAL(timeout()), ui->glview, SLOT(updateGL()));

    timer.start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}
