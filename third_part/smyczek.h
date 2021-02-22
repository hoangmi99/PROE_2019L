#pragma once
#include <iostream>
#include <string>
#include <QString>

using namespace std;
class Smyczek {
private:
    string wlosie;
public:
	Smyczek();
	Smyczek(const Smyczek &smyczek);
	~Smyczek();
	friend ostream& operator << (ostream &s, Smyczek &smyczek);
	friend istream& operator >> (istream &s, Smyczek &smyczek);
    QString getWlosie(){QString Qwlosie=QString::fromStdString(wlosie); return Qwlosie;}
};
