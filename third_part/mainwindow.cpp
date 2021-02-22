#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "koszyk.h"
#include "instrumenty_dialog.h"
#include "wyjscie.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Instrumenty_dialog is(instrumenty);
    is.exec();

}


void MainWindow::on_pushButton_3_clicked()
{
    Wyjscie w;
    w.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Koszyk k(instrumenty);
    k.exec();
}
