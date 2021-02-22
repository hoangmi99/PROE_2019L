#include <string>
#include<iostream>
#include <fstream>
#include "nozka kontrabasu.h"

using namespace std;
Nozka_kontrabasu::Nozka_kontrabasu() {
#ifdef _DEBUG  
	cout << "Konstruktor Nozka kontrabasu" << endl;
#endif
	masa =(float) 57.8;
}
Nozka_kontrabasu::Nozka_kontrabasu(const Nozka_kontrabasu &nozka_kontrabasu) {
#ifdef _DEBUG  
	cout << "Konstruktor kopiujacy Nozka kontrabasu" << endl;
#endif
	masa = nozka_kontrabasu.masa;
}
Nozka_kontrabasu::~Nozka_kontrabasu() {
#ifdef _DEBUG  
	cout << "Destruktor Nozka kontrabasu" << endl;
#endif
}
ostream& operator << (ostream &s, Nozka_kontrabasu &nozka_kontrabasu) {
	s << nozka_kontrabasu.masa;
	return s;
}
istream& operator >> (istream &s, Nozka_kontrabasu &nozka_kontrabasu) {
	s >> nozka_kontrabasu.masa;
	return s;
}