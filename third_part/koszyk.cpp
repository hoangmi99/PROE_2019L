#include "koszyk.h"
#include "ui_koszyk.h"
#include "instrumenty_smyczkowe.h"
#include "instrumenty_dialog.h"
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QLCDNumber>


QString Koszyk::wyswietlanie(int i)
{
    QString text;
    text=instrumenty_ref[i]->wyswietlanie();
    //text=instrumenty_ref[i]->getTypinstrumentu()+"\n"+instrumenty_ref[i]->getProducent()
    //        +"\n"+instrumenty_ref[i]->getModel()+"\n";
    return text;

}
Koszyk::Koszyk(QVector <Instrumenty_smyczkowe*> &instr,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Koszyk),
    instrumenty_ref(instr)
{
    ui->setupUi(this);
    if(instrumenty_ref.size()!=0)
    {

        ui->textEdit->setText(wyswietlanie(0));
        ui->pushButton_4->setEnabled(1);
        ui->pushButton_5->setEnabled(1);
        ui->pushButton_6->setEnabled(1);
        ui->pushButton_7->setEnabled(1);
        ui->pushButton_8->setEnabled(1);
        int indeks=ui->lcdNumber->value();
        if (instrumenty_ref[indeks]->checkSmyczek()==true)
            ui->pushButton_7->setText("Odloz smyczek");
        else {
            ui->pushButton_7->setText("Siegnij po smyczek");
       }
        if (instrumenty_ref[indeks]->checkElement()==true)
            ui->pushButton_8->setText("Odinstaluj element");
        else {
            ui->pushButton_8->setText("Zainstaluj element");
       }
    }
    else {

        ui->pushButton_7->setText("");
        ui->pushButton_8->setText("");
    }
}

Koszyk::~Koszyk()
{
    delete ui;
}


void Koszyk::on_button_koszyk_clicked()
{
    if (instrumenty_ref.size() !=0)
    {
        instrumenty_ref.pop_back();
        if(instrumenty_ref.size()==0)
        {
            ui->pushButton_4->setEnabled(0);
            ui->pushButton_5->setEnabled(0);
            ui->pushButton_6->setEnabled(0);
            ui->pushButton_7->setEnabled(0);
            ui->pushButton_8->setEnabled(0);
            ui->textEdit->clear();
        }

        QMessageBox mb;
        mb.setText(("Usunales jeden ostatni element!"));
        mb.exec();
        if(instrumenty_ref.size()!=0)
        {
            ui->textEdit->setText(wyswietlanie(instrumenty_ref.size()-1));
            ui->lcdNumber->display(instrumenty_ref.size()-1);
            if (instrumenty_ref[instrumenty_ref.size()-1]->checkSmyczek()==true)
                ui->pushButton_7->setText("Odloz smyczek");
            else {
                ui->pushButton_7->setText("Siegnij po smyczek");
           }
            if (instrumenty_ref[instrumenty_ref.size()-1]->checkElement()==true)
                ui->pushButton_8->setText("Odinstaluj element");
            else {
                ui->pushButton_8->setText("Zainstaluj element");
           }
        }
        else {
            {
                ui->pushButton_6->setText("");
                ui->pushButton_7->setText("");
                ui->pushButton_8->setText("");
            }
        }

    }
    else {
        QMessageBox mb;
        mb.setText(("Koszyk jest pusty, nie da sie nic usunac!"));
        mb.exec();
    }
}

void Koszyk::on_pushButton_clicked()
{
    if (instrumenty_ref.size()!=0)
    {
            instrumenty_ref.clear();
            ui->pushButton_4->setEnabled(0);
            ui->pushButton_5->setEnabled(0);
            ui->pushButton_6->setEnabled(0);
            ui->pushButton_7->setEnabled(0);
            ui->pushButton_8->setEnabled(0);
            ui->pushButton_7->setText("");
            ui->pushButton_8->setText("");
            ui->textEdit->clear();
            QMessageBox mb;
            mb.setText(("Usunales wszystkie elementy z koszyka!"));
            mb.exec();
    }
            else {
    {
            instrumenty_ref.clear();
            QMessageBox mb;
            mb.setText(("Koszyk jest pusty, nie da sie nic usunac!"));
            mb.exec();
    }
}

}

void Koszyk::on_pushButton_2_clicked()
{
    ui->lineEdit->setEnabled(1);
    ui->lineEdit_2->setEnabled(1);
    ui->spinBox->setEnabled(1);
    ui->pushButton_3->setEnabled(1);

}

void Koszyk::on_pushButton_3_clicked()
{
    int indeks;
    indeks=ui->spinBox->value();
if (ui->lineEdit->text().isEmpty() ||ui->lineEdit_2->text().isEmpty())
{
    QMessageBox mb;
    mb.setText("Wypelnij wszystkie pola!");
    mb.exec();
}
else if(instrumenty_ref.size()==0) {
    QMessageBox mb;
    mb.setText("Nie mozna zmodyfikowac zadnego obiektu, koszyk jest pusty!");
    mb.exec();
}
else if (instrumenty_ref.size()<=indeks)
{

    QMessageBox mb;
    mb.setText("Wyszedles poza zakres! ");
    mb.exec();
}
else
    {
        QString nowy_producent,nowy_model;
        string nowy_producent1,nowy_model1;
        //try {
        //    instrumenty_ref.size()<indeks;
        //} catch (...) {
        //  QMessageBox mb;
        //    mb.setText("Jestem poza zakresem!");
        //    mb.exec();
        //}
        //if(instrumenty_ref.size()<indeks)
        nowy_producent=ui->lineEdit->text();
        nowy_model=ui->lineEdit_2->text();
        nowy_producent1=nowy_producent.toStdString();
        nowy_model1=nowy_model.toStdString();
        instrumenty_ref[indeks]->zmien_parametr(nowy_producent1, nowy_model1);
        ui->textEdit->setText(wyswietlanie(indeks));
        ui->lcdNumber->display(indeks);
        if (instrumenty_ref[indeks]->checkSmyczek()==true)
            ui->pushButton_7->setText("Odloz smyczek");
        else {
            ui->pushButton_7->setText("Siegnij po smyczek");
       }
        if (instrumenty_ref[indeks]->checkElement()==true)
            ui->pushButton_8->setText("Odinstaluj element");
        else {
            ui->pushButton_8->setText("Zainstaluj element");
       }
        QMessageBox mb;
        mb.setText("Zmodyfikowano obiekt, zmiany mozna obejrzec w oknie obok! ");
        mb.exec();
    }

}

void Koszyk::on_pushButton_5_clicked()
{
    double now;
    now=ui->lcdNumber->value();
    if(instrumenty_ref.size()==1)
        ;
    else if(instrumenty_ref.size()>now)
    {
        if(ui->lcdNumber->value()==instrumenty_ref.size()-1)
        {return;}
        ui->lcdNumber->display(now+1);
        ui->textEdit->setText(wyswietlanie(now+1));
        if (instrumenty_ref[now+1]->checkSmyczek()==true)
            ui->pushButton_7->setText("Odloz smyczek");
        else {
            ui->pushButton_7->setText("Siegnij po smyczek");
       }
        if (instrumenty_ref[now+1]->checkElement()==true)
            ui->pushButton_8->setText("Odinstaluj element");
        else {
            ui->pushButton_8->setText("Zainstaluj element");
       }

    }

}

void Koszyk::on_pushButton_4_clicked()
{
    double now;
    now=ui->lcdNumber->value();
    if(instrumenty_ref.size()==0)
        ;
    else if(instrumenty_ref.size()>=now)
    {
        if(ui->lcdNumber->value()==0)
        {return;}
        ui->lcdNumber->display(now-1);
        ui->textEdit->setText(wyswietlanie(now-1));
        if (instrumenty_ref[now-1]->checkSmyczek()==true)
            ui->pushButton_7->setText("Odloz smyczek");
        else {
            ui->pushButton_7->setText("Siegnij po smyczek");
       }
        if (instrumenty_ref[now-1]->checkElement()==true)
            ui->pushButton_8->setText("Odinstaluj element");
        else {
            ui->pushButton_8->setText("Zainstaluj element");
       }
    }
}
void Koszyk::LoadImage(string lokalizacja)
{
    scene.clear();
    ui->graphicsView->setScene(&scene);

    if(image.load(QString::fromStdString(lokalizacja)))
    {
        scene.setSceneRect(image.rect());
        scene.clear();
        scene.addPixmap(image);
        ui->graphicsView->fitInView(image.rect());
    }
}


void Koszyk::on_pushButton_6_clicked()
{

    int indeks=ui->lcdNumber->value();
    instrumenty_ref[indeks]->graj();
}

void Koszyk::on_pushButton_7_clicked()
{
    int indeks=ui->lcdNumber->value();
    if(instrumenty_ref[indeks]->checkSmyczek()==true)
    {
        instrumenty_ref[indeks]->odloz_smyczek();
        QMessageBox mb;
        mb.setText("Odlozono smyczek, zmiany mozna obejrzec w oknie obok");
        mb.exec();
        ui->textEdit->setText(wyswietlanie(indeks));
        ui->pushButton_7->setText("Siegnij po smyczek");
    }
    else {
        {
            instrumenty_ref[indeks]->siegnij_po_smyczek();
            QMessageBox mb;
            mb.setText("Siegnieto po smyczek, zmiany mozna obejrzec w oknie obok");
            mb.exec();
            ui->textEdit->setText(wyswietlanie(indeks));
            ui->pushButton_7->setText("Odloz smyczek");
        }
    }
}

void Koszyk::on_pushButton_8_clicked()
{
    int indeks=ui->lcdNumber->value();
    if(instrumenty_ref[indeks]->checkElement()==true)
    {
        instrumenty_ref[indeks]->odinstaluj_element();
        QMessageBox mb;
        mb.setText("Odinstalowano element, zmiany mozna obejrzec w oknie obok");
        mb.exec();
        ui->textEdit->setText(wyswietlanie(indeks));
        ui->pushButton_8->setText("Zainstaluj element");
    }
    else {
        {
            instrumenty_ref[indeks]->zainstaluj_element();
            QMessageBox mb;
            mb.setText("Zainstalowano element, zmiany mozna obejrzec w oknie obok");
            mb.exec();
            ui->textEdit->setText(wyswietlanie(indeks));
            ui->pushButton_8->setText("Odinstaluj element");
        }
    }
}
