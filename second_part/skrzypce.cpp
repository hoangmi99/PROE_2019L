#include <iostream>
#include <fstream>
#include "skrzypce.h"

using namespace std;
int c = 0; ///<parametr do zapisu pliku np. "skrzypce 1"

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
		cout << "Grasz smyczkiem" << endl;
	else
		cout << "Grasz pizzicato" << endl;
}
ostream& operator << (ostream &s, Skrzypce &skrzypce) {
	s << (Instrumenty_smyczkowe&)skrzypce;
//	s << skrzypce.typ_instrumentu << endl;
//	s << skrzypce.producent << endl;
//	s << skrzypce.model << endl;
//	s << ((skrzypce.smyczek != nullptr) ? 1 : 0) << endl;
//	if (skrzypce.smyczek != nullptr)
//		s << *(skrzypce.smyczek) << endl;
	s << ((skrzypce.podbrodek != nullptr) ? 1 : 0) << endl;
	if (skrzypce.podbrodek != nullptr)
		s << *(skrzypce.podbrodek) << endl;
//	s << (Instrumenty_smyczkowe&)skrzypce;
	return s;
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
		cout << endl << "Juz siegnales po smyczek" << endl << endl;
	else {
		smyczek = new Smyczek;
		cout << endl << "siegnieto po smyczek" << endl << endl;
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

istream& operator >> (istream &s, Skrzypce &skrzypce) {
	s >> (Instrumenty_smyczkowe&)skrzypce;
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
	s >> czyistnieje2;
	if (czyistnieje2 == 1)
	{
		if (skrzypce.podbrodek = nullptr)
			skrzypce.podbrodek = new Podbrodek;
		s >> *skrzypce.podbrodek;
	}
	else
	{
		delete skrzypce.podbrodek;
		skrzypce.podbrodek = nullptr;
	}
	return s;
}

void Skrzypce::zmien_parametr(char nowy_producent[], char nowy_model[]) {
	producent = nowy_producent;
	model = nowy_model;
}
void Skrzypce::zapisz_stan(ofstream &s) {
#ifdef _DEBUG  
	cout << "Zapisano stan obiektu klasy Skrzypce" << endl;
#endif
	s << *this;
}

void Skrzypce::wczytaj_stan(ifstream &s) {
#ifdef _DEBUG  
	cout << "Wczytano stan obiektu klasy Skrzypce" << endl;
#endif
	s >> *this;
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
		cout << endl << "Juz zainstalowales nozke kontrabasu" << endl << endl;
	else {
		podbrodek = new Podbrodek;
		cout <<endl<< "zainstalowano nozke kontrabasu" << endl << endl;
	}
}