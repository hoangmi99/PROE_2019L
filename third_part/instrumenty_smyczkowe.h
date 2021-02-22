#pragma once
#include <iostream>
#include <sstream>
#include <QString>
#include "smyczek.h"

using namespace std;
class Instrumenty_smyczkowe {
protected:
    Smyczek *smyczek;
    string typ_instrumentu;
    string producent;
    string model;
    string obrazek;
public:
    Instrumenty_smyczkowe();
    virtual ~Instrumenty_smyczkowe();
    ///granie na instrumencie
    virtual void graj() = 0;
    ///usuniecie elementu z instrumentu
    virtual void odinstaluj_element()=0;
    ///zainstalowanie elementu
    virtual void zainstaluj_element() = 0;
    ///dodanie smyczka do instrumentu
    virtual void siegnij_po_smyczek()=0;
    ///usuniecie smyczka z instrumentu
    virtual void odloz_smyczek()=0;
    virtual void wyswietl() = 0;
    virtual void zmien_parametr(string nowy_producent, string nowy_model) = 0;
    ///////
    virtual QString getProducent()=0;
    virtual QString getModel()=0;
    virtual QString getTypinstrumentu()=0;
    virtual QString wyswietlanie()=0;
    virtual bool checkSmyczek()=0;
    virtual bool checkElement()=0;
    string getObrazek() { return obrazek; }
    void setObrazek(string sciezka_pliku) { obrazek = sciezka_pliku;}

};
