#pragma once
#include <iostream>
#include <string>
#include <QString>

using namespace std;
class Nozka_kontrabasu {
private:
    double masa;
public:
	Nozka_kontrabasu();
	Nozka_kontrabasu(const Nozka_kontrabasu &nozka_kontrabasu);
	~Nozka_kontrabasu();
	friend ostream& operator << (ostream &s, Nozka_kontrabasu &nozka_kontrabasu);
	friend istream& operator >> (istream &s, Nozka_kontrabasu &nozka_kontrabasu);
    QString getMasa(){double masa1=masa;QString Qwlosie=QString::number(masa1); return Qwlosie;}
};
