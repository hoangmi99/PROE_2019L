#pragma once
#include <iostream>
#include <fstream>
#include "skrzypce.h"
using namespace std;
///klasa potomna
class Skrzypce_elektryczne :public Skrzypce {
private:
	int zasilanie;///<pole przechowujaca wartosc zasilania instrumentu
	string wyjscie_sluchawkowe;///<pole przechowujace informacje o rodzaju wyjscia sluchawkowego
public:
	///konstruktor domyslny
	Skrzypce_elektryczne();
	///konstruktor kopiujacy
	Skrzypce_elektryczne(const Skrzypce_elektryczne &skrzypce_elektryczne);
	///destruktor
	~Skrzypce_elektryczne();
	///granie na instrumencie
	/**jezeli skrypce elektryczne posiadaja smyczek to gra sie smyczkiem
	jezeli nie posiadaja to gra sie pizzicato
	*/
	void graj();
	///zamiana parametrow instrumentu
	/**mozliwe zmiany producenta i modelu*/
	void zmien_parametr(char nowy_producent[], char nowy_model[]);
	///wyswietlenie informacji o instrumencie
	void wyswietl();
	///usuniecie elementu z instrumentu
	/**podbrodek-element*/
	void odinstaluj_element();
	///usuniecie smyczka z instrumentu
	void odloz_smyczek();
	///dodanie smyczka do instrumentu
	void siegnij_po_smyczek();
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
	friend ostream& operator << (ostream &s, Skrzypce_elektryczne &skrzypce_elektryczne);
	///operator strumieniowy >>
	friend istream& operator >> (istream &s, Skrzypce_elektryczne &skrzypce_elektryczne);
	///operator przypisania
	Skrzypce_elektryczne& operator = (const Skrzypce_elektryczne &skrzypce_elektryczne);
};
