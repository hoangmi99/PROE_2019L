#pragma once
#include <iostream>
#include <fstream>
#include "instrumenty_smyczkowe.h"
#include "podbrodek.h"
using namespace std;
///klasa potomna
class Skrzypce :public Instrumenty_smyczkowe {
protected:
	Podbrodek *podbrodek;///<obiket dynamiczny, ktory jest protected, poniewaz skrzypce elektryczne beda je dziedziczyc
public:
	///konstruktor
	Skrzypce();
	///konstruktor kopiujacy
	Skrzypce(const Skrzypce &skrzypce);
	///destruktor
	~Skrzypce();
	///granie na instrumencie
	/**jezeli skrypce posiadaja smyczek to gra sie smyczkiem
	jezeli nie posiadaja to gra sie pizzicato
	*/
	void graj();
	///wyswietlenie informacji o instrumencie
	void wyswietl();
	///zamiana parametrow instrumentu
	/**mozliwe zmiany producenta i modelu*/
    void zmien_parametr(string nowy_producent, string nowy_model);
	///usuniecie smyczka z instrumentu
	void odloz_smyczek();
	///dodanie smyczka do instrumentu
	void siegnij_po_smyczek();
	///usuniecie elementu z instrumentu
	/**podbrodek-element*/
	void odinstaluj_element();
	///zapis informacji do pliku
	/**wykorzystany do zapisu wektora*/
	void zapisz_stan(ofstream &s);
	///odczyt informacji z pliku
	/**wykorzystany do odtworzenia kolekcji*/
	void wczytaj_stan(ifstream &s);
	///dodanie elementu z instrumentu
	/**podbrodek-element*/
    void zainstaluj_element();
	///operator przypisania
    Skrzypce& operator = (const Skrzypce &skrzypce);
    QString wyswietlanie()
    {QString text; text=getTypinstrumentu()+"\n\n"+getProducent()+"\n"+getModel()+"\n\n"+getSmyczek()+"\n"+getPodbrodek(); return text;}
    QString getProducent(){QString Qproducent="Producent: "+QString::fromStdString(producent);return Qproducent;}
    QString getModel(){QString Qmodel="Model: "+QString::fromStdString(model);return Qmodel;}
    QString getPodbrodek()
    {   QString Qpodbrodek;
        if(podbrodek!=nullptr)
            Qpodbrodek="Podbrodek masa: "+podbrodek->getMasa()+" gram";
        else {
            Qpodbrodek="Brak podbrodka";
        }
        return Qpodbrodek;
     }
    QString getSmyczek()
    {   QString Qsmyczek;
        if(smyczek!=nullptr)
            Qsmyczek="Smyczek o wlosiu: "+smyczek->getWlosie();
        else {
            Qsmyczek="Brak smyczka";
        }
        return Qsmyczek;
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
        if (smyczek != nullptr)
            return true;
        else {
            return false;
        }
    }
    QString getTypinstrumentu(){QString Qtyp_instrumentu=QString::fromStdString(typ_instrumentu);return Qtyp_instrumentu;}
};
