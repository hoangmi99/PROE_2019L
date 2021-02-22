#pragma once
#include <iostream>
#include "instrumenty smyczkowe.h"
#include "nozka kontrabasu.h"

using namespace std;
///klasa potomna 
class Kontrabas :public Instrumenty_smyczkowe {
private:
	Nozka_kontrabasu *nozka_kontrabasu;///<obiekt dynamiczny kontrabasu
public:
	///konstruktor
	Kontrabas();
	///konstruktor kopiujacy
	Kontrabas(const Kontrabas &kontrabas);
	///destruktor
	~Kontrabas();
	///wyswietlenie informacji o instrumencie
	void wyswietl();
	///granie na instrumencie
	/**jezeli kontrabas nie ma nozki kontrabasu to nie gra w ogole
	jezeli kontrabas posiadaja smyczek to gra sie smyczkiem
	jezeli nie posiadaja to gra sie pizzicato
	*/
	void graj();
	///zamiana parametrow instrumentu
	/**mozliwe zmiany producenta i modelu*/
	void zmien_parametr(char nowy_producent[], char nowy_model[]);
	///usuniecie elementu z instrumentu
	/**nozka kontrabasu-element*/
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
	/**nozka kontrabasu-element*/
	void zainstaluj_element();
	///operator strumieniowy <<
	friend ostream& operator << (ostream &s, Kontrabas &kontrabas);
	///operator strumieniowy >>
	friend istream& operator >> (istream &s, Kontrabas &kontrabas);
	///operator przypisania
	Kontrabas& operator = (const Kontrabas &kontrabas);
};