#include <iostream>
#include <fstream>
#include "skrzypce.h"
#include <QMessageBox>

using namespace std;

Skrzypce::Skrzypce() {
#ifdef _DEBUG  
	cout << "Konstruktor Skrzypce" << endl;
#endif
	typ_instrumentu = "skrzypce";
	producent = "domyslny";
	model = "domyslny";
	smyczek = nullptr;
	podbrodek = nullptr;
}
Skrzypce::Skrzypce(const Skrzypce &skrzypce) {
#ifdef _DEBUG  
	cout << "Konstruktor kopiujacy Skrzypce" << endl;
#endif
	typ_instrumentu = skrzypce.typ_instrumentu;
	producent = skrzypce.producent;
	model = skrzypce.model;
	if (skrzypce.smyczek != nullptr) {
		delete smyczek;
		smyczek = new Smyczek(*(skrzypce.smyczek));//konstruktor kopiujacy smyczka
	}
	else smyczek = nullptr;
	if (skrzypce.podbrodek != nullptr) {
		delete podbrodek;
		podbrodek = new Podbrodek(*(skrzypce.podbrodek));//konstruktor kopiujacy smyczka
	}
	else podbrodek = nullptr;
}
Skrzypce::~Skrzypce() {
#ifdef _DEBUG  
	cout << "Destruktor Skrzypce" << endl;
#endif
	if (podbrodek != nullptr)
		delete podbrodek;
	if (smyczek != nullptr)
		delete smyczek;
}
void Skrzypce::graj()
{
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

void Skrzypce::odloz_smyczek() {
	if (smyczek != nullptr) {
		delete smyczek;
		smyczek = nullptr;
		cout <<endl<< "odlozono smyczek" << endl << endl;
	}
	else
		cout <<endl<< "Juz odlozyles smyczek" << endl << endl;
}
void Skrzypce::siegnij_po_smyczek() {
	if (smyczek != nullptr)
        cout << "Juz siegnales po smyczek" << endl;
	else {
		smyczek = new Smyczek;
        cout <<  "siegnieto po smyczek" << endl;
	}
}
void Skrzypce::odinstaluj_element() {
	if (podbrodek != nullptr) {
		delete podbrodek;
		podbrodek = nullptr;
		cout << endl << "odinstalowano podbrodek" << endl << endl;
	}
	else
		cout << endl << "Juz odinstalowales podbrodek" << endl << endl;
}
void Skrzypce::wyswietl() {
	cout << "Typ instrumentu: " << typ_instrumentu << endl;
	cout << "Producent: " << producent << endl;
	cout << "Model: " << model << endl;
	if (smyczek != nullptr)
		cout << "Smyczek o wlosiu: " <<*(smyczek) << endl;
	else
		cout << "Brak smyczka" << endl;
	if (podbrodek != nullptr)
		cout << "Podbrodek: " << *(podbrodek) << " gram" << endl;
	else
		cout << "Brak podbrodka" << endl;
}
void Skrzypce::zmien_parametr(string nowy_producent, string nowy_model) {
	producent = nowy_producent;
	model = nowy_model;
}
Skrzypce& Skrzypce::operator = (const Skrzypce &skrzypce) {

	if (&skrzypce != this)
	{
		if (skrzypce.smyczek != nullptr) {
			delete smyczek;
			smyczek = new Smyczek(*(skrzypce.smyczek));//konstruktor kopiujacy smyczka
		}
		else smyczek = nullptr;
		if (skrzypce.podbrodek != nullptr) {
			delete podbrodek;
			podbrodek = new Podbrodek(*(skrzypce.podbrodek));//konstruktor kopiujacy podbrodka
		}
		else podbrodek = nullptr;
		typ_instrumentu = skrzypce.typ_instrumentu;
		producent = skrzypce.producent;
		model = skrzypce.model;
	}
	return *this;
}
void Skrzypce::zainstaluj_element() {
	if (podbrodek != nullptr)
        cout << "Juz zainstalowales nozke kontrabasu"<< endl;
	else {
		podbrodek = new Podbrodek;
        cout << "zainstalowano nozke kontrabasu" << endl;
	}
}
