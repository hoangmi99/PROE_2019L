#include "instrumenty_dialog.h"
#include "ui_instrumenty_dialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QVector>
#include "instrumenty_smyczkowe.h"
#include "kontrabas.h"
#include "skrzypce.h"
#include "skrzypce_elektryczne.h"
#include <QTimer>
#include <QTimeLine>



Instrumenty_dialog::Instrumenty_dialog(QVector <Instrumenty_smyczkowe*> &instr,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Instrumenty_dialog),
    instrumenty_ref(instr)
{
    ui->setupUi(this);
    connect(ui->pushButton_1,SIGNAL(clicked()),this, SLOT(dodaj_do_wektora_kontrabas()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this, SLOT(dodaj_do_wektora_skrzypce()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this, SLOT(dodaj_do_wektora_skrzypce_elektryczne()));
    connect(ui->zobacz_kontrabas,SIGNAL(clicked()),this, SLOT(zobacz_kontrabas()));
    connect(ui->zobacz_skrzypce,SIGNAL(clicked()),this, SLOT(zobacz_skrzypce()));
    connect(ui->zobacz_skrzypce_elektryczne,SIGNAL(clicked()),this, SLOT(zobacz_skrzypce_elektryczne()));
}
Instrumenty_dialog::~Instrumenty_dialog()
{
delete ui;
}

void Instrumenty_dialog::dodaj_do_wektora_skrzypce()
{
    if (ui->checkBox_4->checkState() == Qt::Checked && ui->checkBox_5->checkState() == Qt::Checked )
    {
        instrumenty_ref.push_back(new Skrzypce);
        instrumenty_ref.back()->zainstaluj_element();
        instrumenty_ref.back()->siegnij_po_smyczek();
    }
    else if (ui->checkBox_4->checkState() == Qt::Unchecked && ui->checkBox_5->checkState() == Qt::Checked)
    {
        instrumenty_ref.push_back(new Skrzypce);
        instrumenty_ref.back()->zainstaluj_element();
    }
    else if (ui->checkBox_4->checkState() == Qt::Checked && ui->checkBox_5->checkState() == Qt::Unchecked)
    {
        instrumenty_ref.push_back(new Skrzypce);
        instrumenty_ref.back()->siegnij_po_smyczek();
    }
    else {
        instrumenty_ref.push_back(new Skrzypce);
    }
    ui->label_5->setText("Dodano!");
    QTimer::singleShot(2000, ui->label_5, &QWidget::hide);
}
void Instrumenty_dialog::dodaj_do_wektora_kontrabas()
{
    if (ui->checkBox_3->checkState() == Qt::Checked && ui->checkBox_2->checkState() == Qt::Checked )
    {
        instrumenty_ref.push_back(new Kontrabas);
        instrumenty_ref.back()->zainstaluj_element();
        instrumenty_ref.back()->siegnij_po_smyczek();
    }
    else if (ui->checkBox_3->checkState() == Qt::Unchecked && ui->checkBox_2->checkState() == Qt::Checked)
    {
        instrumenty_ref.push_back(new Kontrabas);
        instrumenty_ref.back()->zainstaluj_element();
    }
    else if (ui->checkBox_3->checkState() == Qt::Checked && ui->checkBox_2->checkState() == Qt::Unchecked)
    {
        instrumenty_ref.push_back(new Kontrabas);
        instrumenty_ref.back()->siegnij_po_smyczek();
    }
    else {
        instrumenty_ref.push_back(new Kontrabas);
    }
ui->label_4->setText("Dodano!");
QTimer::singleShot(2000, ui->label_4, &QWidget::hide);
}
void Instrumenty_dialog::dodaj_do_wektora_skrzypce_elektryczne()
{
    if (ui->checkBox_7->checkState() == Qt::Checked && ui->checkBox_8->checkState() == Qt::Checked )
    {
        instrumenty_ref.push_back(new Skrzypce_elektryczne);
        instrumenty_ref.back()->zainstaluj_element();
        instrumenty_ref.back()->siegnij_po_smyczek();

    }
    else if (ui->checkBox_7->checkState() == Qt::Unchecked && ui->checkBox_8->checkState() == Qt::Checked)
    {
        instrumenty_ref.push_back(new Skrzypce_elektryczne);
        instrumenty_ref.back()->zainstaluj_element();
    }
    else if (ui->checkBox_7->checkState() == Qt::Checked && ui->checkBox_8->checkState() == Qt::Unchecked)
    {
        instrumenty_ref.push_back(new Skrzypce_elektryczne);
        instrumenty_ref.back()->siegnij_po_smyczek();
    }
    else {
        instrumenty_ref.push_back(new Skrzypce_elektryczne);
    }
ui->label_6->setText("Dodano!");
QTimer::singleShot(2000, ui->label_6, &QWidget::hide);
}
void Instrumenty_dialog::zobacz_kontrabas()
{
    QMessageBox mb;
    mb.setText("na innym komputerze, trzeba nadac inna sciezke na folder \"kontrabas\"\n folder \"build-PROJEKT...\"");
    mb.exec();
    lokalizacja_pliku= QFileDialog::getOpenFileName(this,
                                                    "Wybierz obrazek obiektu kontrabas ",
                                                    "C:\\Users\\Hoang My\\Desktop\\pw\\proe\\build-PROJEKT-Desktop_Qt_5_12_2_MSVC2017_32bit-Debug\\kontrabas",
                                                   tr("Images (*.png *.jpg *.jpeg"));
ui->graphicsView->setScene(&scene);
if (image.load(QString::fromStdString(lokalizacja_pliku.toStdString())))
{
    scene.setSceneRect(image.rect());
    scene.clear();
    scene.addPixmap(image);
    ui->graphicsView->fitInView(image.rect());
}
else
{
    QMessageBox mb;
    mb.setText(("Nie udało się załadować obrazu."));
    mb.exec();
}
}
void Instrumenty_dialog::zobacz_skrzypce()
{
    QMessageBox mb;
    mb.setText("na innym komputerze, trzeba nadac inna sciezke na folder \"skrypce\"\n folder \"build-PROJEKT...\"");
    mb.exec();
    lokalizacja_pliku= QFileDialog::getOpenFileName(this,
                                                    "Wybierz obrazek obiektu skrzypce ",
                                                    "C:\\Users\\Hoang My\\Desktop\\pw\\proe\\build-PROJEKT-Desktop_Qt_5_12_2_MSVC2017_32bit-Debug\\skrzypce",
                                                   tr("Images (*.png *.jpg *.jpeg"));
ui->graphicsView_2->setScene(&scene2);
if (image2.load(QString::fromStdString(lokalizacja_pliku.toStdString())))
{
    scene2.setSceneRect(image2.rect());
    scene2.clear();
    scene2.addPixmap(image2);
    ui->graphicsView_2->fitInView(image2.rect());
}
else
{
    QMessageBox mb;
    mb.setText(("Nie udało się załadować obrazu."));
    mb.exec();
}
}
void Instrumenty_dialog::zobacz_skrzypce_elektryczne()
{
    QMessageBox mb;
    mb.setText("na innym komputerze, trzeba nadac inna sciezke na folder \"skrypce_elektryczne\"\n folder \"build-PROJEKT...\"");
    mb.exec();
    lokalizacja_pliku= QFileDialog::getOpenFileName(this,
                                                    "Wybierz obrazek obiektu skrzypce elektryczne",
                                                    "C:\\Users\\Hoang My\\Desktop\\pw\\proe\\build-PROJEKT-Desktop_Qt_5_12_2_MSVC2017_32bit-Debug\\skrzypce_elektryczne",
                                                   tr("Images (*.png *.jpg *.jpeg"));

    ui->graphicsView_3->setScene(&scene3);
if (image3.load(QString::fromStdString(lokalizacja_pliku.toStdString())))
{
    scene3.setSceneRect(image3.rect());
    scene3.clear();
    scene3.addPixmap(image3);
    ui->graphicsView_3->fitInView(image3.rect());
}
else
{
    QMessageBox mb;
    mb.setText(("Nie udało się załadować obrazu."));
    mb.exec();
}
}
