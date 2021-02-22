#pragma once
#include <iostream>
#include "instrumenty_smyczkowe.h"
#include "nozka_kontrabasu.h"

using namespace std;
///klasa potomna
class Kontrabas :public Instrumenty_smyczkowe {
private:
    Nozka_kontrabasu *nozka_kontrabasu;///<obiekt dynamiczny kontrabasu
public:
    ///konstruktor
    Kontrabas();
    ///konstruktor kopiujacy
	Kontrabas(const Kontrabas &kontrabas);
    ///destruktor
    ~Kontrabas();
    ///wyswietlenie informacji o instrumencie
	void wyswietl();
    ///granie na instrumencie
    /**jezeli kontrabas nie ma nozki kontrabasu to nie gra w ogole
    jezeli kontrabas posiadaja smyczek to gra sie smyczkiem
    jezeli nie posiadaja to gra sie pizzicato
    */
    void graj();
    ///zamiana parametrow instrumentu
    /**mozliwe zmiany producenta i modelu*/
    void zmien_parametr(string nowy_producent, string nowy_model);
    ///usuniecie elementu z instrumentu
    /**nozka kontrabasu-element*/
	void odinstaluj_element();
    ///usuniecie smyczka z instrumentu
	void odloz_smyczek();
    ///dodanie smyczka do instrumentu
	void siegnij_po_smyczek();
    ///zapis informacji do pliku
    /**wykorzystany do zapisu wektora*/
    void zapisz_stan(ofstream &s);
    ///odczyt informacji z pliku
    /**wykorzystany do odtworzenia kolekcji*/
    void wczytaj_stan(ifstream &s);
    ///dodanie elementu z instrumentu
    /**nozka kontrabasu-element*/
	void zainstaluj_element();
    ///operator przypisania
	Kontrabas& operator = (const Kontrabas &kontrabas);
    QString wyswietlanie()
    {QString text; text=getTypinstrumentu()+"\n\n"+getProducent()+"\n"+getModel()+"\n\n"+getSmyczek()+"\n"+getNozka(); return text;}
    QString getSmyczek()
    {   QString Qsmyczek;
        if(smyczek!=nullptr)
            Qsmyczek="Smyczek o wlosiu: "+smyczek->getWlosie();
        else {
            Qsmyczek="Brak smyczka";
        }
        return Qsmyczek;
     }
    QString getNozka()
    {   QString Qnozka;
        if(nozka_kontrabasu!=nullptr)
            Qnozka="Nozka kontrabasu masa: "+nozka_kontrabasu->getMasa()+" gram";
        else {
            Qnozka="Brak nozki kontrabasu";
        }
        return Qnozka;
     }
    bool checkSmyczek()
    {
        if (smyczek != nullptr)
            return true;
        else {
            return false;
        }
    }
    bool checkElement()
    {
        if (nozka_kontrabasu != nullptr)
            return true;
        else {
            return false;
        }
    }
    QString getProducent(){QString Qproducent="Producent: "+QString::fromStdString(producent);return Qproducent;}
    QString getModel(){QString Qmodel="Model: "+QString::fromStdString(model);return Qmodel;}
    QString getTypinstrumentu(){QString Qtyp_instrumentu=QString::fromStdString(typ_instrumentu);return Qtyp_instrumentu;}
};
