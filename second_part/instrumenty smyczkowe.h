#pragma once
#include <iostream>
#include <sstream>
#include "smyczek.h"

using namespace std;
///klasa abstrakcyjna
class Instrumenty_smyczkowe {
protected:
	Smyczek *smyczek; ///<wskaznik na obiekt dynamiczny
	string typ_instrumentu;///<pole przechowujace typ instrumentu
	string producent;///<pole przechowujace producenta instrumentow
	string model;///pole przechowujace model instrumentu
public:
	///konstruktor domyslny
	Instrumenty_smyczkowe();
	///destruktor wirtualny
	/**aby umozliwic usuniecie obiektu z wykorzystaniem
	 polimorfizmu destruktor musi byæ wirtualny
	 */
	virtual ~Instrumenty_smyczkowe();
	///granie na instrumencie
	virtual void graj() = 0;
	///usuniecie elementu z instrumentu
	virtual void odinstaluj_element()=0;
	///zainstalowanie elementu
	virtual void zainstaluj_element() = 0;
	///dodanie smyczka do instrumentu
	virtual void siegnij_po_smyczek()=0;
	///usuniecie smyczka z instrumentu
	virtual void odloz_smyczek()=0;
	///wyswietlenie informacji o instrumencie
	/**1. wyswietla informacje o instrumencie (parametry oraz obecnosc obiektow dynamicznych)
	 2. nalezy zakomentowac slowo virtual i "=0;" metode, w trakcie sprawdzania polimorfizmu
	 3. nalezy odkomentowac slowo virtual i "=0;" po sprawdzeniu polimorfizmu */
	virtual void wyswietl() = 0;
	///zamiana parametrow instrumentu
	/**mozliwe zmiany producenta i modelu*/
	virtual void zmien_parametr(char nowy_producent[], char nowy_model[]) = 0;
	///zapis informacji do pliku
	/**wykorzystany do zapisu wektora*/
	virtual void zapisz_stan(ofstream &s);
	///wypisanie na konsole informacji z pliku
	virtual void wczytaj_stan(ifstream &s);
	///operator strumieniowy <<
	friend ostream& operator << (ostream &s, Instrumenty_smyczkowe &instrumenty_smyczkowe);
	///operator strumieniowy >>
	friend istream& operator >> (istream &s, Instrumenty_smyczkowe &instrumenty_smyczkowe);
};