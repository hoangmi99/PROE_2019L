#include <iostream>
#include <string>
#include <fstream>
#include "podbrodek.h"

using namespace std;

Podbrodek::Podbrodek()
{
	drewno = "drewno swierkowe";
	waga = (float)56.7;
#ifdef _DEBUG  
	cout << "Wywolano konstruktor domyslny Podbrodek" << endl;
#endif
}

Podbrodek::~Podbrodek()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Podbrodek" << endl;
#endif	
}

Podbrodek::Podbrodek(const Podbrodek &podbrodek1) {
#ifdef _DEBUG  
	cout << "Wywolano konstruktor kopiujacy Podbrodek" << endl;
#endif
	drewno = podbrodek1.drewno;
	waga = podbrodek1.waga;
}

Podbrodek::Podbrodek(const string drewno1, float waga1)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor wieloargumentowy Podbrodek" << endl;
#endif
	drewno = drewno1;
	waga = waga1;

}
ostream & operator<<(ostream & os, const Podbrodek & podbrodek)
{
	os << "Podbrodek wykonany z: " << podbrodek.drewno << endl;
	os << "Waga podbrodka: " << podbrodek.waga << endl;
	return os;
}
