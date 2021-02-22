#pragma once
#include <iostream>
#include <string>

using namespace std;
///podklasa skrzypcow i skrzypow elektrycnzych
class Podbrodek {
	float masa;///<pole przechowujace mase podbrodka
public:
	///konstruktor domyslny
	Podbrodek();
	///konstruktor kopiujacy
	Podbrodek(const Podbrodek &podbrodek);
	///destruktor
	~Podbrodek();
	///operator strumieniowy <<
	friend ostream& operator << (ostream &s, Podbrodek &podbrodek);
	///operator strumieniowy >>
	friend istream& operator >> (istream &s, Podbrodek &podbrodek);
};