#include <iostream>
#include <fstream>
#include <string>
#include "struny.h"

using namespace std;
int Struny::liczba_obiektow_struny = 0;

//konstruktor
Struny::Struny()
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor domyslny Struny" << endl;
#endif
	liczba_obiektow_struny++;
	ilosc_dobrych_strun = 0;
	ilosc_strun_do_wymiany = 0;
	material = "brak";
}

//destruktor
Struny::~Struny()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Struny" << endl;
#endif	
	liczba_obiektow_struny--;
}

Struny::Struny(Struny &struny) {
#ifdef _DEBUG  
	cout << "Wywolano konstruktor kopiujacy Struny" << endl;
#endif
	liczba_obiektow_struny++;
	ilosc_dobrych_strun = struny.ilosc_dobrych_strun;
	ilosc_strun_do_wymiany = struny.ilosc_strun_do_wymiany;
	material = struny.material;
}

Struny::Struny(string material_1, int ilosc_dobrych_strun_1, int ilosc_strun_do_wymiany_1) {
#ifdef _DEBUG  
	cout << "Wywolano konstruktor wieloargumentowy Struny" << endl;
#endif
	liczba_obiektow_struny++;
	ilosc_dobrych_strun = ilosc_dobrych_strun_1;
	ilosc_strun_do_wymiany = ilosc_strun_do_wymiany_1;
	material = material_1;
}

//operatory
ostream& operator<< (ostream &os, const Struny &struny) {
	os << "Ilosc dobrych strun: " << struny.ilosc_dobrych_strun << endl;
	os << "Ilosc strun do wymiany: " << struny.ilosc_strun_do_wymiany << endl;
	os << "Material strun: " << struny.material << endl;
	return os;
}
Struny& Struny::operator++() {
	if ((ilosc_dobrych_strun+ilosc_strun_do_wymiany) < 4) {
		++ilosc_dobrych_strun;
		material = "rdzen syntetyczny";
		cout << "Dodano nowa dobra strune" << endl;
	}
	else
		cout << "nie mozna dodac wiecej strun" << endl;
	return *this;
}
Struny& Struny::operator--() {
	if (ilosc_dobrych_strun != 0) {
		ilosc_dobrych_strun--;
		cout << "Pekla ci jedna struna" << endl;
	}
	return *this;
}
Struny& Struny::operator++(int) {
	if ((ilosc_dobrych_strun + ilosc_strun_do_wymiany) < 4) {
		ilosc_strun_do_wymiany++;
		cout << "Dodano jedna strune do wymiany" << endl;
	}
	else
		cout << "Nie dodano struny do wymiany, poniewaz juz sa 4 struny" << endl;
	return *this;
}
Struny& Struny::operator--(int) {
	cout << "Wymieniono wszystkie struny do wymiany na dobre" << endl;
	ilosc_dobrych_strun += ilosc_strun_do_wymiany;
	ilosc_strun_do_wymiany = 0;
	return *this;
}
bool Struny::czy_dzialaja() {
	if (ilosc_strun_do_wymiany > 0) {
		return false;

	}
	else if (ilosc_dobrych_strun !=4) {
		return false;
	}
	else {
		return true;
	}
}
bool Struny::operator < (const Struny &struny) {
	if (ilosc_dobrych_strun < struny.ilosc_dobrych_strun)
		return true;
	else
		return false;
}



