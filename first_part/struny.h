#pragma once
#include <iostream>
#include <string>

using namespace std;

class Struny {
private:
	string material;
	int ilosc_dobrych_strun;
	int ilosc_strun_do_wymiany;

public:
	static int liczba_obiektow_struny;
	Struny();//konstruktor
	~Struny();//destruktor
	Struny(Struny &struny); //konstruktor kopiujacy
	Struny(string, int, int);//konstruktor wieloargumentowy
	

	//operatory
	friend ostream& operator<< (ostream &os, const Struny &s);
	Struny& operator++(); //dodaje nam jedna dobra strune
	Struny& operator--();//pekla jedna dobra struna
	Struny& operator++(int);//dodaje nam struny do wymiany
	Struny& operator--(int);//wymienia nam wszystkie struny do wymiany na struny dobre
	bool operator < (const Struny &struny);//porownuje dobre struny pod wzgledem ilosci
	//metody
	bool czy_dzialaja();//sprawdza czy struny dzialaja
};