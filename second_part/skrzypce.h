#pragma once
#include <iostream>
#include <fstream>
#include "instrumenty smyczkowe.h"
#include "podbrodek.h"
using namespace std;
///klasa potomna
class Skrzypce :public Instrumenty_smyczkowe {
protected:
	Podbrodek *podbrodek;///<obiket dynamiczny, ktory jest protected, poniewaz skrzypce elektryczne beda je dziedziczyc
public:
	///konstruktor
	Skrzypce();
	///konstruktor kopiujacy
	Skrzypce(const Skrzypce &skrzypce);
	///destruktor
	~Skrzypce();
	///granie na instrumencie
	/**jezeli skrypce posiadaja smyczek to gra sie smyczkiem
	jezeli nie posiadaja to gra sie pizzicato
	*/
	void graj();
	///wyswietlenie informacji o instrumencie
	void wyswietl();
	///zamiana parametrow instrumentu
	/**mozliwe zmiany producenta i modelu*/
	void zmien_parametr(char nowy_producent[], char nowy_model[]);
	///usuniecie smyczka z instrumentu
	void odloz_smyczek();
	///dodanie smyczka do instrumentu
	void siegnij_po_smyczek();
	///usuniecie elementu z instrumentu
	/**podbrodek-element*/
	void odinstaluj_element();
	///zapis informacji do pliku
	/**wykorzystany do zapisu wektora*/
	void zapisz_stan(ofstream &s);
	///odczyt informacji z pliku
	/**wykorzystany do odtworzenia kolekcji*/
	void wczytaj_stan(ifstream &s);
	///dodanie elementu z instrumentu
	/**podbrodek-element*/
	void zainstaluj_element();
	///operator strumieniowy <<
	friend ostream& operator << (ostream &s, Skrzypce &skrzypce);
	///operator strumieniowy >>
	friend istream& operator >> (istream &s, Skrzypce &skrzypce);
	///operator przypisania
	Skrzypce& operator = (const Skrzypce &skrzypce);
};
