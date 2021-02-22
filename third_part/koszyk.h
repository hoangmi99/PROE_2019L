#ifndef KOSZYK_H
#define KOSZYK_H

#include <QDialog>
#include <QVector>
#include "instrumenty_smyczkowe.h"
#include "instrumenty_dialog.h"

namespace Ui {
class Koszyk;
}

class Koszyk : public QDialog
{
    Q_OBJECT

public:
    explicit Koszyk(QVector <Instrumenty_smyczkowe*> &instr,QWidget *parent = nullptr);
    ~Koszyk();
    void wyswietl(QVector <Instrumenty_smyczkowe*> &instrumenty);
    QString wyswietlanie(int i);
    void LoadImage(string lokalizacja);

private slots:
    void on_button_koszyk_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Koszyk *ui;
    QGraphicsScene scene;
    QPixmap image;
    QVector <Instrumenty_smyczkowe*> &instrumenty_ref;
};

#endif // KOSZYK_H
