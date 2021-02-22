#pragma once
#include <iostream>
#include <string>
#include <QString>

using namespace std;
///podklasa skrzypcow i skrzypow elektrycnzych
class Podbrodek {
    double masa;///<pole przechowujace mase podbrodka
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
    QString getMasa(){double masa1=masa;QString Qwlosie=QString::number(masa1); return Qwlosie;}
};
