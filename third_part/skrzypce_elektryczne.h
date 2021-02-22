#pragma once
#include <iostream>
#include <fstream>
#include <QString>
#include "skrzypce.h"
using namespace std;
///klasa potomna
class Skrzypce_elektryczne :public Skrzypce {
private:
	int zasilanie;///<pole przechowujaca wartosc zasilania instrumentu
	string wyjscie_sluchawkowe;///<pole przechowujace informacje o rodzaju wyjscia sluchawkowego
public:
	///konstruktor domyslny
	Skrzypce_elektryczne();
	///konstruktor kopiujacy
	Skrzypce_elektryczne(const Skrzypce_elektryczne &skrzypce_elektryczne);
	///destruktor
	~Skrzypce_elektryczne();
	///granie na instrumencie
	/**jezeli skrypce elektryczne posiadaja smyczek to gra sie smyczkiem
	jezeli nie posiadaja to gra sie pizzicato
	*/
	void graj();
	///zamiana parametrow instrumentu
	/**mozliwe zmiany producenta i modelu*/
    void zmien_parametr(string nowy_producent, string nowy_model);
	///wyswietlenie informacji o instrumencie
	void wyswietl();
	///usuniecie elementu z instrumentu
	/**podbrodek-element*/
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
	/**podbrodek-element*/
	void zainstaluj_element();
	///operator przypisania
    Skrzypce_elektryczne& operator = (const Skrzypce_elektryczne &skrzypce_elektryczne);
    QString wyswietlanie()
    {QString text; text=getTypinstrumentu()+"\n\n"+getProducent()+"\n"+getModel()+"\n"+getZasilanie()+"\n"+getWyjsciesluchawkowe()+"\n\n"+getSmyczek()+"\n"+getPodbrodek(); return text;}
    QString getProducent(){QString Qproducent="Producent: "+QString::fromStdString(producent);return Qproducent;}
    QString getModel(){QString Qmodel="Model: "+QString::fromStdString(model);return Qmodel;}
    QString getWyjsciesluchawkowe(){QString Qwyjscie="Wyjscie sluchawkowe: "+QString::fromStdString(wyjscie_sluchawkowe); return Qwyjscie;}
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

        if (podbrodek != nullptr)
            return true;
        else {
            return false;
        }
    }
    QString getZasilanie()
    {QString Qzasilanie, Qzasilanie1; int zasilanie1=zasilanie; Qzasilanie1=QString::number(zasilanie1); Qzasilanie="Zasilanie: "+Qzasilanie1+" V"; return Qzasilanie;}
    QString getTypinstrumentu(){QString Qtyp_instrumentu=QString::fromStdString(typ_instrumentu);return Qtyp_instrumentu;}
};
