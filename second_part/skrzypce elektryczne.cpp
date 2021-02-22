#include <iostream>
#include <string> 
#include <fstream>
#include "skrzypce elektryczne.h"

using namespace std;
int a = 0;///<parametr do zapisu pliku np. "skrzypce elektryczne 1"

Skrzypce_elektryczne::Skrzypce_elektryczne() {
#ifdef _DEBUG  
	cout << "Konstruktor Skrzypce elektryczne" << endl;
#endif
	typ_instrumentu = "skrzypce_elektryczne";
	producent = "domyslny";
	model = "domyslny";
	smyczek = nullptr;
	podbrodek = nullptr;
	zasilanie = 46;
	wyjscie_sluchawkowe = "hoho";
}
Skrzypce_elektryczne::Skrzypce_elektryczne(const Skrzypce_elektryczne &skrzypce) {
#ifdef _DEBUG  
	cout << "Konstruktor Skrzypce elektryczne" << endl;
#endif
	typ_instrumentu = skrzypce.typ_instrumentu;
	producent = skrzypce.producent;
	model = skrzypce.model;
	zasilanie = skrzypce.zasilanie;
	wyjscie_sluchawkowe = skrzypce.wyjscie_sluchawkowe;
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
Skrzypce_elektryczne::~Skrzypce_elektryczne() {
#ifdef _DEBUG  
	cout << "Destruktor Skrzypce elektryczne" << endl;
#endif
	if (podbrodek != nullptr)
		delete podbrodek;
	if (smyczek != nullptr)
		delete smyczek;
}
void Skrzypce_elektryczne::graj()
{
		if (smyczek != nullptr)
			cout << "Grasz smyczkiem" << endl;
		else
			cout << "Grasz pizzicato" << endl;
}

ostream& operator << (ostream &s, Skrzypce_elektryczne &skrzypce) {
	s << (Skrzypce&)skrzypce;
//	s << skrzypce.typ_instrumentu << endl;
//	s << skrzypce.producent << endl;
//	s << skrzypce.model << endl;
//	s << ((skrzypce.smyczek != nullptr) ? 1 : 0) << endl;
//	if (skrzypce.smyczek != nullptr)
//		s << *(skrzypce.smyczek) << endl;
//	s << ((skrzypce.podbrodek != nullptr) ? 1 : 0) << endl;
//	if (skrzypce.podbrodek != nullptr)
//		s << *(skrzypce.podbrodek) << endl;
	s << skrzypce.zasilanie << endl;
	s << skrzypce.wyjscie_sluchawkowe << endl;
	return s;
}

istream& operator >> (istream& s, Skrzypce_elektryczne &skrzypce) {
	s >> (Skrzypce&)skrzypce;
//	s >> skrzypce.typ_instrumentu;
//	s >> skrzypce.producent;
//	s >> skrzypce.model;
	int czyistnieje1, czyistnieje2;
//	s >> czyistnieje1;
//	if (czyistnieje1 == 1)
//	{
//		if (skrzypce.smyczek = nullptr)
//			skrzypce.smyczek = new Smyczek;
//		s >> *skrzypce.smyczek;
//	}
//	else
//	{
//		delete skrzypce.smyczek;
//		skrzypce.smyczek = nullptr;
//	}
	//s >> czyistnieje2;
	//if (czyistnieje2 == 1)
	//{
	//	if (skrzypce.podbrodek = nullptr)
	//		skrzypce.podbrodek = new Podbrodek;
	//	s >> *skrzypce.podbrodek;
	//}
	//else
	//{
	//	delete skrzypce.podbrodek;
	//	skrzypce.podbrodek = nullptr;
	//}
	s >> skrzypce.zasilanie;
	s >> skrzypce.wyjscie_sluchawkowe;
	return s;
}
void Skrzypce_elektryczne::odloz_smyczek() {
	if (smyczek != nullptr) {
		delete smyczek;
		smyczek = nullptr;
		cout << endl << "odlozono smyczek" << endl << endl;
	}
	else
		cout << endl << "Juz odlozyles smyczek" << endl << endl;
}

void Skrzypce_elektryczne::odinstaluj_element() {
	if (podbrodek != nullptr) {
		delete podbrodek;
		podbrodek = nullptr;
		cout << endl << "odinstalowano podbrodek" << endl << endl;
	}
	else
		cout << endl << "Juz odinstalowales podbrodek" << endl << endl;
}
void Skrzypce_elektryczne::wyswietl() {
	cout << "Typ instrumentu: " << typ_instrumentu << endl;
	cout << "Producent: " << producent << endl;
	cout << "Model: " << model << endl;
	cout << "Zasilanie: " << zasilanie << " W" << endl;
	cout << "Wyjscie sluchawkowe: " << wyjscie_sluchawkowe << endl;
	if (smyczek != nullptr)
		cout << "Smyczek o wlosiu: " << *(smyczek) << endl;
	else
		cout << "Brak smyczka" << endl;
	if (podbrodek != nullptr)
		cout << "Podbrodek: " << *(podbrodek) << " gram" << endl;
	else
		cout << "Brak podbrodka" << endl;
}


void Skrzypce_elektryczne::zmien_parametr(char nowy_producent[], char nowy_model[]) {
	producent = nowy_producent;
	model = nowy_model;
}
void Skrzypce_elektryczne::zapisz_stan(ofstream &s) {
#ifdef _DEBUG  
	cout << "Zapisano stan obiektu klasy Skrzypce elektryczne" << endl;
#endif
	s << *this;
}

void Skrzypce_elektryczne::wczytaj_stan(ifstream &s) {
#ifdef _DEBUG  
	cout << "Wczytano stan obiektu klasy Skrzypce elektryczne" << endl;
#endif
	s >> *this;
}
Skrzypce_elektryczne& Skrzypce_elektryczne::operator = (const Skrzypce_elektryczne &skrzypce) {

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
		model = skrzypce.model;
		producent = skrzypce.producent;
		
	}
	return *this;
}
void Skrzypce_elektryczne::zainstaluj_element() {
	if (podbrodek != nullptr)
		cout << endl << "Juz zainstalowales nozke kontrabasu" << endl << endl;
	else {
		podbrodek = new Podbrodek;
		cout <<endl<< "zainstalowano nozke kontrabasu" << endl << endl;
	}
}
void Skrzypce_elektryczne::siegnij_po_smyczek()
{
	if (smyczek != nullptr)
		cout << endl << "Juz siegnales po smyczek" << endl << endl;
	else {
		smyczek = new Smyczek;
		cout << endl << "siegnieto po smyczek" << endl << endl;
	}
}