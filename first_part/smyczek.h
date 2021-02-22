#pragma once
#include <iostream>
#include <string>

using namespace std;

class Smyczek {
private:
	string producent;
	string wlosie;
public:
	static int liczba_obiektow_smyczek;

	Smyczek(); //konstruktor
	~Smyczek();//destruktor
	Smyczek(string, string ); //konstruktor wieloargumentowy
	Smyczek(const Smyczek &smyczek1); // konstruktor kopiujacy

	//operatory, ktore przeszly test (1 operator)
	friend ostream & operator<<(ostream & os, const Smyczek &smyczek1);//operator bitowy dwuargumentowy
};