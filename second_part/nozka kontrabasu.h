#pragma once
#include <iostream>
#include <string>

using namespace std;
///podklasa Kontrabasu
class Nozka_kontrabasu {
private:
	float masa;///<parametr przechowujacy mase nozki kontrabasu
public:
	///konstruktor domyslny
	Nozka_kontrabasu();
	///konstruktor kopiujacy
	Nozka_kontrabasu(const Nozka_kontrabasu &nozka_kontrabasu);
	///destruktor
	~Nozka_kontrabasu();
	///operator strumieniowy <<
	friend ostream& operator << (ostream &s, Nozka_kontrabasu &nozka_kontrabasu);
	///operator strumieniowy >>
	friend istream& operator >> (istream &s, Nozka_kontrabasu &nozka_kontrabasu);
};