#include <iostream>
#include <fstream>
#include <string>
#include "instrumenty smyczkowe.h"

using namespace std;
Instrumenty_smyczkowe::Instrumenty_smyczkowe() {
#ifdef _DEBUG  
	cout << "Konstruktor Instrumenty_smyczkowe" << endl;
#endif
	typ_instrumentu = "Instrument smyczkowy";
	producent = "domyslny";
	model = "domyslny";
	smyczek = nullptr;
}

Instrumenty_smyczkowe::~Instrumenty_smyczkowe() {
#ifdef _DEBUG  
	cout << "Destruktor Instrumenty_smyczkowe" << endl;
#endif
	if (smyczek != nullptr)
		delete smyczek;
}
ostream& operator << (ostream &s, Instrumenty_smyczkowe &instrumenty_smyczkowe) {
	s << instrumenty_smyczkowe.typ_instrumentu << endl;
	s << instrumenty_smyczkowe.producent << endl;
	s << instrumenty_smyczkowe.model << endl;
	s << ((instrumenty_smyczkowe.smyczek != nullptr) ? 1 : 0) << endl;
	if (instrumenty_smyczkowe.smyczek != nullptr)
		s << *(instrumenty_smyczkowe.smyczek) << endl;
	return s;
}
istream& operator >> (istream &s, Instrumenty_smyczkowe &instrumenty_smyczkowe) {
	s >> instrumenty_smyczkowe.typ_instrumentu;
	s >> instrumenty_smyczkowe.producent;
	s >> instrumenty_smyczkowe.model;
	int czyistnieje1;
	s >> czyistnieje1;
	if (czyistnieje1 == 1)
	{
		if (instrumenty_smyczkowe.smyczek = nullptr)
			instrumenty_smyczkowe.smyczek = new Smyczek;
		s >> *instrumenty_smyczkowe.smyczek;
	}
	else
	{
		delete instrumenty_smyczkowe.smyczek;
		instrumenty_smyczkowe.smyczek = nullptr;
	}
	return s;
}
void Instrumenty_smyczkowe::wyswietl() {
	cout << "metoda klasy abstrakcyjnej bez virtual" << endl;
}
void Instrumenty_smyczkowe::zmien_parametr(char nowy_producent[], char nowy_model[]) {
	cout << "metoda klasy abstrakcyjnej bez virtual" << endl;
}
void Instrumenty_smyczkowe::zapisz_stan(ofstream &s) {
#ifdef _DEBUG  
	cout << "Zapisano stan obiektu klasy Instrumenty_smyczkowe" << endl;
#endif
	s << *this;
}

void Instrumenty_smyczkowe::wczytaj_stan(ifstream &s) {
#ifdef _DEBUG  
	cout << "Wczytano stan obiektu klasy Kontrabas" << endl;
#endif
	s >> *this;
}