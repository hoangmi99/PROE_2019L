#ifndef INSTRUMENTY_DIALOG_H
#define INSTRUMENTY_DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include "instrumenty_smyczkowe.h"
#include <QVector>

namespace Ui {
class Instrumenty_dialog;
}

class Instrumenty_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Instrumenty_dialog(QVector <Instrumenty_smyczkowe*> &instr, QWidget *parent = nullptr);
    ~Instrumenty_dialog();
private:
    Ui::Instrumenty_dialog *ui;
    QGraphicsScene scene,scene2,scene3;
    QPixmap image,image2,image3;
    //QVector <Instrumenty_smyczkowe*> instrumenty;
    QVector <Instrumenty_smyczkowe*> &instrumenty_ref;
    QString lokalizacja_pliku = "";

private slots:
    void dodaj_do_wektora_kontrabas();
    void dodaj_do_wektora_skrzypce();
    void dodaj_do_wektora_skrzypce_elektryczne();
    void zobacz_kontrabas();
    void zobacz_skrzypce();
    void zobacz_skrzypce_elektryczne();

};

#endif // INSTRUMENTY_DIALOG_H
