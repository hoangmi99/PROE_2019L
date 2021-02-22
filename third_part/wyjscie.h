#ifndef WYJSCIE_H
#define WYJSCIE_H

#include <QDialog>

namespace Ui {
class Wyjscie;
}

class Wyjscie : public QDialog
{
    Q_OBJECT

public:
    explicit Wyjscie(QWidget *parent = nullptr);
    ~Wyjscie();

private slots:
    void on_pushButton_clicked();

    void on_button_wyjscie_clicked();

private:
    Ui::Wyjscie *ui;
};

#endif // WYJSCIE_H
