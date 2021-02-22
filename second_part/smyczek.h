#pragma once
#include <iostream>
#include <string>

using namespace std;
///podklasa klas potomnych
class Smyczek {
private:
	string wlosie;///<pole przechowujace rodzaj wlosia 
public:
	///konstruktor
	Smyczek();
	///konstruktor kopiujacy
	Smyczek(const Smyczek &smyczek);
	///destruktor
	~Smyczek();
	///operatory strumieniowy <<
	friend ostream& operator << (ostream &s, Smyczek &smyczek);
	///operator strumieniowy >>
	friend istream& operator >> (istream &s, Smyczek &smyczek);
};
