#include <iostream>
#include <fstream>
#include "podbrodek.h"

using namespace std;
Podbrodek::Podbrodek() {
#ifdef _DEBUG  
	cout << "Konstruktor Podbrodek" << endl;
#endif
    masa = (double) 437.84;
}
Podbrodek::~Podbrodek() {
#ifdef _DEBUG  
	cout << "Destruktor Podbrodek" << endl;
#endif
}
ostream& operator << (ostream &s, Podbrodek &podbrodek) {
	s << podbrodek.masa;
	return s;
}
Podbrodek:: Podbrodek( const Podbrodek &podbrodek) {
#ifdef _DEBUG  
	cout << "Konstruktor kopiujacy Podbrodek" << endl;
#endif
	masa = podbrodek.masa;
}

istream& operator >> (istream &s, Podbrodek &podbrodek) {
	s >> podbrodek.masa;
	return s;
}
