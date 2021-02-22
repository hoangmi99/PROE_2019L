#pragma once
#include <iostream>
#include <string>
#include "struny.h"
#include "smyczek.h"
#include "podbrodek.h"

using namespace std;

class Skrzypce {
private:
	Struny struny; //obiekt automatyczny (bedziemy wymieniac i napinac struny)
	Smyczek * smyczek;//obiekt dynamiczny, wskaznik na klase skrzypce
	Podbrodek * podbrodek;//obiekt dynamiczny, wskaznik na klase skrzypce
	int licznik=liczba_obiektow_skrzypce+1;
	string producent; //parametr
	string model; //parametr
	int ocena;
public:
	static int liczba_obiektow_skrzypce; //zmienna okreslajaca ilosc obiektow typu Skrzypce
	Skrzypce();//konstruktor domyslny
	~Skrzypce(); //destruktor
	Skrzypce(const Skrzypce &skrzypce); //konstruktor kopiujacy
	Skrzypce(string , string );//konstruktor wieloargumentowy

	//operatory
	friend ostream & operator<<(ostream & os, const Skrzypce &skrzypce1);//operator bitowy dwuargumentowy
	Skrzypce& operator ++ ();//dodaje nam jedna strune do skryzpiec
	Skrzypce& operator --();//pekanie struny w skrzypcach
	Skrzypce& operator ++ (int);//dodaje nam jedna strune do wymiany
	Skrzypce& operator -- (int);//wymiana strun
	bool operator < (const Skrzypce &skrzypce);//porownanie skrzypiec pod wzgledem ilosci strun
	bool operator == (const Skrzypce &skrzypce);//porownanie skrzypiec pod wzgledem producenta i modelu
	Skrzypce& operator = (const Skrzypce &skrzypce);//skrzypce lewe beda rowne tym po prawej

	
	//metody
	void graj();
	void odloz_smyczek();
	void siegnij_po_smyczek(const Smyczek smyczek);
	void zainstaluj_podbrodek(const Podbrodek podbrodek);
	void odinstaluj_podbrodek();
	//operatory do testu
	Skrzypce& operator +();//bedzie dodawac do skrzypiec ocene skrzypiec, pierwotnie ocena bedzie zawsze 5/10, ale zeby nie przekroczyc 10, ani nie zejsc ponizej 1
	Skrzypce& operator -();
	operator int();//operator konwersji
};
