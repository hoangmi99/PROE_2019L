#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "kontrabas.h"

using namespace std;
int b = 0;///<parametr do zapisu pliku np. "kontrabas 1"

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
ostream& operator << (ostream &s, Kontrabas &kontrabas) {
	s << (Instrumenty_smyczkowe&)kontrabas;
//	s <<kontrabas.typ_instrumentu << endl;
//	s <<kontrabas.producent << endl;
//	s << kontrabas.model << endl;
//	s << ((kontrabas.smyczek != nullptr) ? 1 : 0) << endl;
//	if (kontrabas.smyczek != nullptr)
//		s << *(kontrabas.smyczek) << endl;
	s << ((kontrabas.nozka_kontrabasu != nullptr) ? 1 : 0) << endl;
	if (kontrabas.nozka_kontrabasu != nullptr)
		s << *(kontrabas.nozka_kontrabasu) << endl;
	
	return s;
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

istream& operator >> (istream& s, Kontrabas &kontrabas) {
	s >> (Instrumenty_smyczkowe&)kontrabas;
//	s >> kontrabas.typ_instrumentu;
//	s >> kontrabas.producent;
//	s >> kontrabas.model;
	int czyistnieje1, czyistnieje2;
//	s >> czyistnieje1;
//	if (czyistnieje1 == 1)
//	{
//		if (kontrabas.smyczek = nullptr)
//			kontrabas.smyczek = new Smyczek;
//		s >> *kontrabas.smyczek;
//	}
//	else
//	{
//		delete kontrabas.smyczek;
//		kontrabas.smyczek = nullptr;
//	}
	s >> czyistnieje2;
	if (czyistnieje2 == 1)
	{
		if (kontrabas.nozka_kontrabasu = nullptr)
			kontrabas.nozka_kontrabasu = new Nozka_kontrabasu;
		s >> *kontrabas.nozka_kontrabasu;
	}
	else
	{
		delete kontrabas.nozka_kontrabasu;
		kontrabas.nozka_kontrabasu = nullptr;
	}
	return s;
}
void Kontrabas::graj() {
	if (nozka_kontrabasu != nullptr) {
		if (smyczek != nullptr)
			cout << "Grasz smyczkiem" << endl;
		else
			cout << "Grasz pizzicato" << endl;
	}
	else
		cout << "Brak nozki kontrabasu, nie grasz" << endl;
}
void Kontrabas::odloz_smyczek() {
	if (smyczek != nullptr) {
		delete smyczek;
		smyczek = nullptr;
		cout <<endl<< "odlozono smyczek" << endl << endl;
	}
	else
		cout <<endl<< "Juz odlozyles smyczek" << endl << endl;
}
void Kontrabas::siegnij_po_smyczek() {
	if (smyczek != nullptr)
		cout <<endl<< "Juz siegnales po smyczek" << endl << endl;
	else {
		smyczek = new Smyczek;
		cout << endl << "siegnieto po smyczek" << endl << endl;
	}
}
void Kontrabas::zainstaluj_element() {
	if (nozka_kontrabasu != nullptr)
		cout << endl << "Juz zainstalowales nozke kontrabasu" << endl << endl;
	else {
		nozka_kontrabasu = new Nozka_kontrabasu;
		cout << endl << "zainstalowano nozke kontrabasu" << endl << endl;
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
void Kontrabas::zmien_parametr(char nowy_producent[], char nowy_model[]) {
	producent = nowy_producent;
	model = nowy_model;
}
void Kontrabas::zapisz_stan(ofstream &s) {
#ifdef _DEBUG  
	cout << "Zapisano stan obiektu klasy Kontrabas" << endl;
#endif
	s << *this;
}

void Kontrabas::wczytaj_stan(ifstream &s) {
#ifdef _DEBUG  
	cout << "Wczytano stan obiektu klasy Kontrabas" << endl;
#endif
	s >> *this;
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