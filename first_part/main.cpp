#include <iostream>
#include "skrzypce.h"
/*UWAGA licznik nie dziala tak jak powinien :D
jak tworze skrzypce w oddzielnej funkcji to nalicza mi od poczatku od 2,
bo w mainie mam juz jedne skrzypce, ktore zawsze maja numer 1.
Moglabym tworzyc wszystkie obiekty Skrzypce w mainie, wtedy licznik by sie zgadzal.
*/
using namespace std;
/*moja instrukcja, dla ulatwienia pracy
OPERATORY
1. dodawanie dobrych strun do skrzypiec ++(preinkrementacja)
2. pekanie struny --(predekrementacja)
3. dodawanie strun do wymiany ++(posinkrementacja)
4. wymiana strun w skrzypcach --(posinkrementacja)
5. porownanie ilosci strun <
6. porownanie pod wzgledem producenta i modelu skrzypiec ==
7. przypisanie skrzypiec =
8. zwiekszanie oceny skrzypiec o 1 +
9. zmniejszenie ocney skrzypiec o 1 -
10. ostream operator <<

METODY
1.siegnij_po_smyczek();
2.odloz_smyczek()
3.zainstaluj_podbrodek()
4.odinstaluj_podbrodek()
5.graj()
*/
void test_strun(Skrzypce &skrzypce1) {
	cout << "**************TEST STRUN*********************" << endl;
	cout << skrzypce1 << endl;
	++skrzypce1;
	++skrzypce1;
	++skrzypce1;
	++skrzypce1;
	++skrzypce1;
	cout << skrzypce1 << endl;
	--skrzypce1;
	--skrzypce1;
	skrzypce1++;
	cout << skrzypce1 << endl;
	skrzypce1--;
	cout << skrzypce1 << endl;
	++skrzypce1;
	cout << skrzypce1 << endl;
	cout << "*************KONIEC TEST STRUN***************" << endl;
}
void test_podbrodka_i_smyczka(Skrzypce &skrzypce1, Smyczek &smyczek1, Podbrodek &podbrodek1) {
	cout << "*************TEST PODBRODKA I SMYCZKA********" << endl;
	skrzypce1.siegnij_po_smyczek(smyczek1);
	skrzypce1.zainstaluj_podbrodek(podbrodek1);
	cout << skrzypce1 << endl;
	skrzypce1.odloz_smyczek();
	skrzypce1.odinstaluj_podbrodek();
	cout << skrzypce1 << endl;
	cout << "*****KONIEC TEST PODBRODKA I SMYCZKA*********" << endl;
}
void test_gry(Skrzypce &skrzypce1, Smyczek &smyczek1, Podbrodek podbrodek1) {
	cout << "******************TEST GRY*******************" << endl;
	cout << skrzypce1 << endl;
	skrzypce1.graj(); 
	skrzypce1.siegnij_po_smyczek(smyczek1);
	skrzypce1.graj(); 
	skrzypce1.zainstaluj_podbrodek(podbrodek1);
	skrzypce1.graj(); 
	skrzypce1.odloz_smyczek();
	skrzypce1.graj();
	--skrzypce1;
	skrzypce1.graj();
	skrzypce1++;
	skrzypce1.graj();

	cout << "**************KONIEC TEST GRY****************" << endl;
}
void test_porownanie() {
	cout << "***************TEST POROWNANIA***************" << endl;
	Skrzypce skrzypce2;
	Skrzypce skrzypce3;
	Skrzypce skrzypce4("producent", "model");
	++skrzypce3;
	cout << skrzypce2 << endl;
	cout << skrzypce3 << endl;
	cout << skrzypce4 << endl;
	skrzypce3 < skrzypce2;
	skrzypce3 == skrzypce2;
	skrzypce4 == skrzypce2;
	skrzypce2 = skrzypce3;//skrzypce2 beda teraz takie jak skrzypce3
	cout << skrzypce2;
	cout << "**********KONIEC TEST POROWNANIA*************" << endl;

}
void test_konstruktorow() {
	cout << "**************TEST KONSTRUKTOROW*************" << endl;
	//analogicznie mozna dla podbrodka i smyczka i dodac je po prostu do skrzypiec,
	//ale nie bede juz tego robic.
	Skrzypce skrzypce5;
	Skrzypce skrzypce6("Stradivarius", "96-GGH");
	Skrzypce skrzypce7(skrzypce6);
	cout << skrzypce5 << endl;
	cout << skrzypce6 << endl;
	cout << skrzypce7 << endl;
	cout << "*********KONIEC TESTU KONSTRUKTOROW**********" << endl;
}
void test_oceny(Skrzypce &skrzypce1) {
	cout << "****************TEST OCENY*******************"<<endl;
	+skrzypce1;
	+skrzypce1;
	cout << skrzypce1 << endl;
	-skrzypce1;
	cout << skrzypce1 << endl;
	cout << "**************KONIEC TESTU OCENY*************" << endl;
}
int main() {
	Skrzypce skrzypce1;
	Struny struny1;
	Podbrodek podbrodek1;
	Smyczek smyczek1;
	test_strun(skrzypce1);
	test_podbrodka_i_smyczka(skrzypce1, smyczek1, podbrodek1);
	test_gry(skrzypce1, smyczek1, podbrodek1);
	test_porownanie();
	test_konstruktorow();
	test_oceny(skrzypce1);
	return 0;
}