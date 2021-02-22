#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "kontrabas.h"
#include <QMessageBox>

using namespace std;


Kontrabas::Kontrabas() {
#ifdef _DEBUG  
	cout << "Konstruktor Kontrabas" << endl;
#endif
	typ_instrumentu = "kontrabas";
	producent = "domyslny";
	model = "domyslny";
    smyczek = nullptr;
    nozka_kontrabasu = nullptr;
}
Kontrabas::~Kontrabas() {
#ifdef _DEBUG  
	cout << "Destruktor Kontrabas" << endl;
#endif
	if (nozka_kontrabasu != nullptr)
		delete nozka_kontrabasu;
	if (smyczek != nullptr)
		delete smyczek;
}

Kontrabas::Kontrabas(const Kontrabas &kontrabas) {
#ifdef _DEBUG  
	cout << "Konstruktor kopiujacy Kontrabas" << endl;
#endif
	typ_instrumentu = kontrabas.typ_instrumentu;
	producent = kontrabas.producent;
	model = kontrabas.model;
	if (kontrabas.smyczek != nullptr) {
		delete smyczek;
		smyczek = new Smyczek(*(kontrabas.smyczek));//konstruktor kopiujacy smyczka
	}
	else smyczek = nullptr;
	if (kontrabas.nozka_kontrabasu != nullptr) {
		delete nozka_kontrabasu;
		nozka_kontrabasu = new Nozka_kontrabasu(*(kontrabas.nozka_kontrabasu));
	}//konstruktor kopiujacy smyczka
	else nozka_kontrabasu = nullptr;
}

void Kontrabas::graj() {
	if (nozka_kontrabasu != nullptr) {
		if (smyczek != nullptr)
        {
            QMessageBox mb;
            mb.setText("Grasz smyczkiem");
            mb.exec();
        }
		else
        {
            QMessageBox mb;
            mb.setText("Grasz pizzicato");
            mb.exec();
        }

	}
	else
    {
        QMessageBox mb;
        mb.setText("Brak nozki kontrabasu, nie grasz");
        mb.exec();
    }
}
void Kontrabas::odloz_smyczek() {
	if (smyczek != nullptr) {
		delete smyczek;
		smyczek = nullptr;
        cout << "odlozono smyczek" << endl;
	}
	else
        cout << "Juz odlozyles smyczek" << endl;
}
void Kontrabas::siegnij_po_smyczek() {
	if (smyczek != nullptr)
        cout << "Juz siegnales po smyczek"  << endl;
	else {
		smyczek = new Smyczek;
        cout <<  "siegnieto po smyczek"  << endl;
	}
}
void Kontrabas::zainstaluj_element() {
	if (nozka_kontrabasu != nullptr)
        cout << "Juz zainstalowales nozke kontrabasu" << endl;
	else {
		nozka_kontrabasu = new Nozka_kontrabasu;
        cout <<  "zainstalowano nozke kontrabasu" << endl;
	}
}
void Kontrabas::odinstaluj_element() {
	if (nozka_kontrabasu != nullptr) {
		delete nozka_kontrabasu;
		nozka_kontrabasu = nullptr;
		cout << endl << "odinstalowano nozke kontrabasu" << endl << endl;
	}
	else
		cout << endl << "Juz odinstalowales nozke kontrabasu" << endl << endl;
}
void Kontrabas::wyswietl() {
	cout << "Typ instrumentu: " << typ_instrumentu << endl;
	cout << "Producent: " << producent << endl;
	cout << "Model: " << model << endl;
	if (smyczek != nullptr)
		cout << "Smyczek o wlosiu: " << *(smyczek) << endl;
	else
		cout << "Brak smyczka" << endl;
	if (nozka_kontrabasu != nullptr)
		cout << "Nozka kontrabasu: " << *(nozka_kontrabasu)<< " gram" << endl;
	else
		cout << "Brak nozki kontrabasu" << endl;
}
void Kontrabas::zmien_parametr(string nowy_producent, string nowy_model) {
	producent = nowy_producent;
	model = nowy_model;
}

Kontrabas& Kontrabas::operator = (const Kontrabas &kontrabas) {

	if (&kontrabas != this)
	{
		if (kontrabas.smyczek != nullptr) {
			delete smyczek;
			smyczek = new Smyczek(*(kontrabas.smyczek));//konstruktor kopiujacy smyczka
		}
		else smyczek = nullptr;
		if (nozka_kontrabasu != nullptr) {

			delete nozka_kontrabasu;
			nozka_kontrabasu = new Nozka_kontrabasu(*(kontrabas.nozka_kontrabasu));//konstruktor kopiujacy podbrodka
		}
		else nozka_kontrabasu = nullptr;
		typ_instrumentu = kontrabas.typ_instrumentu;
		producent = kontrabas.producent;
		model = kontrabas.model;
	}
	return *this;
}
