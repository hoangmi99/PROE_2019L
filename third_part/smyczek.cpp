#include <iostream>
#include <string>
#include <fstream>
#include "smyczek.h"

using namespace std;


Smyczek::Smyczek() {
#ifdef _DEBUG  
	cout << "Konstruktor Smyczka" << endl;
#endif
	wlosie = "wlosie konskie";
}
Smyczek::Smyczek(const Smyczek &smyczek) {
#ifdef _DEBUG  
	cout << "Konstruktor kopiujacy Smyczka" << endl;
#endif
	wlosie = smyczek.wlosie;
}
Smyczek::~Smyczek() {
#ifdef _DEBUG  
	cout << "Destruktor Smyczka" << endl;
#endif
}
ostream& operator << (ostream &s, Smyczek &smyczek) {
	s << smyczek.wlosie;
	return s;
}
istream& operator >> (istream &s, Smyczek &smyczek) {
	s >> smyczek.wlosie;
	return s;
}