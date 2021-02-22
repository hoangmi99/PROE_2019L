#include <iostream>
#include <fstream>
#include <string>
#include "instrumenty_smyczkowe.h"

using namespace std;
Instrumenty_smyczkowe::Instrumenty_smyczkowe() {
#ifdef _DEBUG  
	cout << "Konstruktor Instrumenty_smyczkowe" << endl;
#endif
	typ_instrumentu = "Instrument smyczkowy";
	producent = "domyslny";
	model = "domyslny";
	smyczek = nullptr;
    //obrazek ="";
}

Instrumenty_smyczkowe::~Instrumenty_smyczkowe() {
#ifdef _DEBUG  
	cout << "Destruktor Instrumenty_smyczkowe" << endl;
#endif
	if (smyczek != nullptr)
		delete smyczek;
}

void Instrumenty_smyczkowe::wyswietl() {
	cout << "metoda klasy abstrakcyjnej bez virtual" << endl;
}
void Instrumenty_smyczkowe::zmien_parametr(string nowy_producent, string nowy_model) {
	cout << "metoda klasy abstrakcyjnej bez virtual" << endl;
}
