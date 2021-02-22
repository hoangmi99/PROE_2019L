#include <iostream>
#include <string>
#include "skrzypce.h"

using namespace std;

int Skrzypce::liczba_obiektow_skrzypce = 0;

Skrzypce::Skrzypce()
{
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Skrzypce" << endl;
#endif
	++liczba_obiektow_skrzypce;

	smyczek = nullptr;
	podbrodek = nullptr;
	producent = "YAMAHA";
	model = "V7-SG 4/4";
	ocena = 5;
}

Skrzypce::Skrzypce(const Skrzypce &skrzypce) {
#ifdef _DEBUG  
	cout << "Wywolano konstruktor kopiujacy Skrzypce" << endl;
#endif
	++liczba_obiektow_skrzypce;
	struny = skrzypce.struny;
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
	producent = skrzypce.producent;
	model = skrzypce.model;
	ocena = skrzypce.ocena;
}
Skrzypce::Skrzypce(string producent_1, string model_1) {
#ifdef _DEBUG  
	cout << "Wywolano konstruktor wieloargumentowy Skrzypce" << endl;
#endif
	++liczba_obiektow_skrzypce;
	producent = producent_1;
	model = model_1;
	ocena = 5;
}
Skrzypce::~Skrzypce()
{
#ifdef _DEBUG  
	cout << "Wywolano destruktor Skrzypce" << endl;
#endif
	liczba_obiektow_skrzypce--;

	if (smyczek != nullptr) {
		delete smyczek;
	}
	if (podbrodek != nullptr) {
		delete podbrodek;
	}
}
//operatory
ostream & operator<<(ostream & os, const Skrzypce & skrzypce1)
{
	os << "--------------Skrzypce " << skrzypce1.licznik << "---------------------" << endl;
	os << "Producent skrzypiec: " << skrzypce1.producent << endl;
	os << "model skrzypiec: " << skrzypce1.model << endl << endl;
	os <<  skrzypce1.struny << endl;
	if (skrzypce1.smyczek != nullptr) {
		os << *(skrzypce1.smyczek)  << endl;
	}
	else os << "Brak smyczka" << endl << endl;
	if (skrzypce1.podbrodek != nullptr) {
		os << *(skrzypce1.podbrodek) << endl;
	}
	else os << "Brak podbrodka" << endl << endl;
	os << "Ocena: " << skrzypce1.ocena << "/10" << endl;
	os << "---------------------------------------------" << endl;
	return os;
}
Skrzypce& Skrzypce:: operator ++ () {
	++struny;
	return *this;
}
Skrzypce& Skrzypce:: operator -- () {
	--struny;
	return *this;
}
Skrzypce& Skrzypce::operator ++ (int) {
	struny++;
	return *this;
}
Skrzypce& Skrzypce::operator -- (int) {
	struny--;
	return *this;
}
bool Skrzypce:: operator == (const Skrzypce &skrzypce) {
	if (model != skrzypce.model &&producent != skrzypce.producent) {
		cout << "Skrzypcec " << skrzypce.licznik << " roznia sie od Skrzypce " << licznik << endl;
		return false;
	}
	else {
		cout << "skrzypce " << skrzypce.licznik << " nie roznia sie od Skrzypce " << licznik << endl;
		return true;
	}
}
bool Skrzypce::operator < (const Skrzypce &skrzypce) {
	if (struny < skrzypce.struny) {
		cout << "Skrzypce " << skrzypce.licznik << " maja wiecej dobrych strun od Skrzype " << licznik << endl;
		return true;
	}
	else {
		cout << "Skrzypce " << skrzypce.licznik << " maja mniej lub tyle samo dobrych strun co Skrzype " << licznik << endl;
		return false;
	}
}
Skrzypce& Skrzypce::operator = (const Skrzypce &skrzypce) {

	if (&skrzypce != this)
	{
		struny = skrzypce.struny;
		if (skrzypce.smyczek != nullptr) {
			delete smyczek;
			smyczek = new Smyczek(*(skrzypce.smyczek));//konstruktor kopiujacy smyczka
		}
		else smyczek = nullptr;
		if (podbrodek != nullptr) {
			delete podbrodek;
			podbrodek = new Podbrodek(*(skrzypce.podbrodek));//konstruktor kopiujacy podbrodka
		}
		else podbrodek = nullptr;
		producent = skrzypce.producent;
		model = skrzypce.model;
		cout << "Przypisano Skrzypcom" << licznik << " Skrzypce" << skrzypce.licznik << ". Od teraz beda takie same" << endl;
	}
	return *this;
}
Skrzypce& Skrzypce::operator +() {
	if (ocena < 10) {
		ocena += 1;
		cout << "zwiekszono ocene Skrzypiec "<<licznik<<" o 1" << endl;
	}
	return *this;
}
Skrzypce& Skrzypce::operator -() {
	if (ocena != 1) {
		ocena -= 1;
		cout << "zmniejszono ocene Skrzypiec "<<licznik<<" o 1" << endl;
	}
	return *this;
}
//metody
void Skrzypce::graj() {
	if (struny.czy_dzialaja() == false) {
		cout << "Skrzypce nie graja" << endl;
	}
	else if (smyczek == nullptr) {
		if (podbrodek == nullptr)
			cout << "Grasz pizzicato i bez podbrodka" << endl;
		else
			cout << "Grasz pizzicato z podbrodkiem" << endl;
	}
	else
		if (podbrodek == nullptr)
			cout << "Grasz ze smyczkiem i bez podbrodka" << endl;
		else
			cout << "Grasz ze smyczkiem i z podbrodkiem" << endl;
}
void Skrzypce::odloz_smyczek() {
	delete smyczek;
	smyczek = nullptr;
	cout << "odlozono smyczek" << endl;
}
void Skrzypce::siegnij_po_smyczek(const Smyczek smyczek2) {
	smyczek = new Smyczek(smyczek2);
	cout << "siegnieto po smyczek" << endl;
}
void Skrzypce::zainstaluj_podbrodek(const Podbrodek podbrodek2) {
	podbrodek = new Podbrodek(podbrodek2);
	cout << "zainstalowano podbrodek" << endl;
}
void Skrzypce::odinstaluj_podbrodek() {
	delete podbrodek;
	podbrodek = nullptr;
	cout << "odinstalowano podbrodek" << endl;
}