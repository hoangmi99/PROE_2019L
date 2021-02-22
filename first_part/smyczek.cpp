#include <iostream>
#include <string>
#include <fstream>
#include "smyczek.h"

using namespace std;
int Smyczek::liczba_obiektow_smyczek = 0;

Smyczek::Smyczek()
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor domyslny Smyczek" << endl;
#endif
	producent = "GEWA";
	wlosie = "wlosie konskie";
}
Smyczek::~Smyczek()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Smyczek" << endl;
#endif	
}

Smyczek::Smyczek(const Smyczek &smyczek1)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor kopiujacy Smyczek" << endl;
#endif
	producent = smyczek1.producent;
	wlosie = smyczek1.wlosie;

}

Smyczek::Smyczek(string producent1, string wlosie1)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor wieluargumentowy Smyczek" << endl;
#endif
	producent = producent1;
	wlosie = wlosie1;
}
ostream & operator<<(ostream & os, const Smyczek & smyczek)
{
	os << "Producent smyczka: " << smyczek.producent << endl;
	os << "Wlosie smyczka: " << smyczek.wlosie << endl;
	return os;
}
