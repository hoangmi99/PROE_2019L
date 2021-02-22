#include "wyjscie.h"
#include "ui_wyjscie.h"

Wyjscie::Wyjscie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wyjscie)
{
    ui->setupUi(this);
     connect(ui->button_wyjscie, SIGNAL(clicked()), this, SLOT(wyjscie()));
}

Wyjscie::~Wyjscie()
{
    delete ui;
}

void Wyjscie::on_pushButton_clicked()
{
}

void Wyjscie::on_button_wyjscie_clicked()
{
    QApplication::quit();
}
