#pragma once
#include <iostream>
#include <string>

using namespace std;

class Podbrodek {
private:
	string drewno;
	float waga;

public:
	Podbrodek(); //konstruktor
	~Podbrodek();//destruktor
	Podbrodek(const string, float ); //konstruktor wieloargumentowy
	Podbrodek(const Podbrodek &podbrodek1); // konstruktor kopiujacy

	//operatory
	friend ostream & operator<<(ostream & os, const Podbrodek &podbrodek);
};
