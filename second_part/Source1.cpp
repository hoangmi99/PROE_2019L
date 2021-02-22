#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "kontrabas.h"
#include "skrzypce.h"
#include "skrzypce elektryczne.h"

using namespace std;
struct Wezel {
	Kontrabas k;
	Wezel *inny_wezel;
};
void wypisz(Wezel *w, int liczba) {
	Wezel *tymczasowy=w;
	for (int i = 0; i < liczba; i++)
	{
		tymczasowy->k.wyswietl();
		tymczasowy->inny_wezel;
		tymczasowy = tymczasowy->inny_wezel;
	}
}
void usun(Wezel *pierwszy, int liczba) {
	Wezel *tymczasowy = pierwszy;
	Wezel *wskaznik_next;
	for (int i = 0; i < liczba; i++) {
		wskaznik_next = tymczasowy->inny_wezel;
		delete tymczasowy;
		tymczasowy = wskaznik_next;

	}
}


int main()
{
	Kontrabas k1;
	Skrzypce s1;
	Skrzypce_elektryczne se1;
	Smyczek sm1;
	Nozka_kontrabasu nk1;
	Podbrodek p1;

	Wezel *w1, *w2, *w3;
	w1 = new Wezel();
	w2 = new Wezel();
	w3 = new Wezel();

	w1->k.siegnij_po_smyczek();
	w1->inny_wezel = w2;
	w2->inny_wezel = w3;
	w3->inny_wezel = w1;

	wypisz(w1,10);
	delete w1;
	delete w2;
	delete w3;


//	Kontrabas k1;
//	Skrzypce s1;
//	Skrzypce_elektryczne se1;
//	Smyczek sm1;
//	Nozka_kontrabasu nk1;
//	Podbrodek p1;
	int x = 0;
	char opcja1, opcja2;///<opcje w menu
	char opcja100, opcja200, opcja300;
	char opcja15;///<opcje w menu
	const int rozmiar = 100;///<ilosc znakow jaka mozna wprowadzic przy zmianie producenta i modelu (wliczajac spacje)
	char nowy_producent[rozmiar], nowy_model[rozmiar];///<parametr wprowadzany przy zmianie producenta i modelu
	vector <Instrumenty_smyczkowe*> instrumenty1;


	do
	{
		cout << "WITAJ PONOWNIE MUZYKU!" << endl << endl;
		cout << "1. Wybierz instrument, ktory dodasz do wektora" << endl;
		cout << "2. Dzialania na wektorze" << endl;
		cout << "3. Demonstracja dzialania polimorfizmu" << endl;
		cout << "-------------------------------" << endl;
		cout << "4. Zamknij program" << endl;
		cout << "opcja: ";
		cin >> opcja1;
		if (opcja1 == '1')
		{
			system("cls");
			do
			{
				cout << "Wybierz instrument, ktory chcesz dodac do wektora: " << endl << endl;
				cout << "1. Kontrabas" << endl;
				cout << "2. Skrzypce" << endl;
				cout << "3. Skrzypce elektryczne" << endl;
				cout << "-------------------------------" << endl;
				cout << "4. Powrot" << endl;
				cout << "opcja: ";
				cin >> opcja2;
				if (opcja2 == '1')
				{
					cin.get();
					//int x = 0;
					//kk[x] = k1;
					instrumenty1.push_back(new Kontrabas);
					//++x;
					cout << "Dodano kontrabas do wektora" << endl;
					cout << "Kliknij [enter], aby zobaczyc ile aktualnie jest obiektow";										cin.get();
					cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size();
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
				if (opcja2 == '2')
				{
					cin.get();
					//int x = 0;
					//kk[x] = k1;
					instrumenty1.push_back(new Skrzypce);
					//++x;
					cout << "Dodano kontrabas do wektora" << endl;
					cout << "Kliknij [enter], aby zobaczyc ile aktualnie jest obiektow";										cin.get();
					cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size();
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
				if (opcja2 == '3')
				{
					cin.get();
					//int x = 0;
					//kk[x] = k1;
					instrumenty1.push_back(new Skrzypce_elektryczne);
					//++x;
					cout << "Dodano kontrabas do wektora" << endl;
					cout << "Kliknij [enter], aby zobaczyc ile aktualnie jest obiektow";										cin.get();
					cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size();
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
				if (opcja2 == '4')
				{
					system("cls");
					break;
				}
				if (opcja2 != '1'&&opcja2 != '2'&&opcja2 != '3'&&opcja2 != '4')
				{
					cin.get();
					cout << "Wprowadzono niepoprawna opcje" << endl;
					cout << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
			} while (opcja2 != '4');
		}
		if (opcja1 == '2')
		{
			system("cls");
			do
			{
				cout << "Dzialania na wektorze: " << endl << endl;
				cout << "1. modyfikacja obiektow wektora" << endl;
				cout << "2. usuwanie ostatniego obiektu z wektora" << endl;
				cout << "3. usuwanie wszystkich obietkow z wektora" << endl;
				cout << "4. Zapis stanu wszystkich obiektow przechowywanych w kontenerze" << endl;
				cout << "5. Odczytanie stanu wszystkich obiektow przechowywanych w kontenerze" << endl;
				cout << "6. Odtworzenie kolekcji" << endl;
				cout << "7. Wypisanie na ekran stanu wszystkich obiektow z wektora" << endl;
				cout << "-------------------------------" << endl;
				cout << "8. Powrot" << endl;
				cout << "opcja: ";
				cin >> opcja15;
				if (opcja15 == '1')
				{
					system("cls");
					do
					{
						cout << "Dzialania na wektorze: " << endl << endl;
						cout << "1. modyfikacja parametrow obiektu" << endl;
						cout << "2. smyczek" << endl;
						cout << "3. element" << endl;
						cout << "4. graj" << endl;
						cout << "-------------------------------" << endl;
						cout << "5. Powrot" << endl;
						cout << "opcja: ";
						cin >> opcja100;
						if (opcja100 == '1')
						{
							cin.get();
							int g;
							cout << "Wybrano modyfikacje obiektow wektora" << endl << endl;
							cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << endl;
							cout << "Pamietaj, ze tablica zaczyna sie od 0" << endl;
							cout << "Wybierz obiekt do modyfikacji." << endl;
							cout << "-------------------------------" << endl;
							cout << "Numer indeksu: ";
							cin >> g;
							cin.get();
							if (!cin)
							{
								cin.clear();
								cin.get();
								cout << "Wprowadz cyfre!" << endl;
								cin.get();
							}
							else if (instrumenty1.size()==0)
							{
								cout << "Wektor jest pusty" << endl;
							}
							else
							{
								if (g<0 || g>instrumenty1.size() - 1)
								{
									cout << "jestes poza zakresem" << endl;
								}
								else
								{
									cout << "Wprowadz nowego producenta: ";
									cin.get(nowy_producent, rozmiar).get();
									cout << "Wprowadz nowy model: ";
									cin.get(nowy_model, rozmiar).get();
									instrumenty1[g]->zmien_parametr(nowy_producent, nowy_model);
									instrumenty1[g]->wyswietl();
								}
							}
							
							
							//}
							cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
							cin.get();
							system("cls");
							//break;
						}
						if (opcja100 == '2')
						{
							system("cls");
							do
							{
								cout << "Wybrano smyczek: " << endl << endl;
								cout << "1. siegnij po smyczek" << endl;
								cout << "2. odloz smyczek" << endl;
								cout << "-------------------------------" << endl;
								cout << "3. Powrot" << endl;
								cout << "opcja: ";
								cin >> opcja200;
								if (opcja200 == '1')
								{
									cin.get();
									int g;
									cout << "Wybrano siegniecie po smyczek" << endl << endl;
									cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << endl;
									cout << "Pamietaj, ze tablica zaczyna sie od 0" << endl;
									cout << "Wybierz obiekt do ktorego chcesz dodac smyczek" << endl;
									cout << "-------------------------------" << endl;
									cout << "Numer indeksu: ";
									cin >> g;
									cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
									cin.get();
									if (instrumenty1.size() == 0)
									{
										cout << "Wektor jest pusty" << endl;
									}
									else
									{
										if (g<0 || g>instrumenty1.size() - 1)
										{
											cout << "jestes poza zakresem" << endl;
										}
										else
										{
											instrumenty1[g]->siegnij_po_smyczek();
											instrumenty1[g]->wyswietl();
										}
									}
									cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
									cin.get();
									system("cls");
								}
								if (opcja200 == '2')
								{
									cin.get();
									int g;
									cout << "Wybrano odlozenie smyczka" << endl << endl;
									cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << endl;
									cout << "Pamietaj, ze tablica zaczyna sie od 0" << endl;
									cout << "Wybierz obiekt z ktorego chcesz odlozyc smyczek" << endl;
									cout << "-------------------------------" << endl;
									cout << "Numer indeksu: ";
									cin >> g;
									cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
									cin.get();
									if (instrumenty1.size() == 0)
									{
										cout << "Wektor jest pusty" << endl;
									}
									else
									{
										if (g<0 || g>instrumenty1.size() - 1)
										{
											cout << "jestes poza zakresem" << endl;
										}
										else
										{
											instrumenty1[g]->odloz_smyczek();
											instrumenty1[g]->wyswietl();
										}
									}
									cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
									cin.get();
									system("cls");
								}
								if (opcja200 == '3')
								{
									system("cls");
									break;
								}
								if (opcja200 != '1'&&opcja200 != '2'&&opcja200 != '3')
								{
									cin.get();
									cout << "Wprowadzono niepoprawna opcje" << endl;
									cout << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
									cin.get();
									system("cls");
								}
							} while (opcja200 != '3');
						}	
						if (opcja100 == '3')
						{
							system("cls");
							do
							{
								cout << "Wybrano element: " << endl << endl;
								cout << "1. zainstaluj element" << endl;
								cout << "2. odinstaluj element" << endl;
								cout << "-------------------------------" << endl;
								cout << "3. Powrot" << endl;
								cout << "opcja: ";
								cin >> opcja300;
								if (opcja300 == '1')
								{
									cin.get();
									int g;
									cout << "Wybrano zainstalowanie elementu" << endl << endl;
									cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << endl;
									cout << "Pamietaj, ze tablica zaczyna sie od 0" << endl;
									cout << "Wybierz obiekt do ktorego chcesz zainstalowac element." << endl;
									cout << "-------------------------------" << endl;
									cout << "Numer indeksu: ";
									cin >> g;
									cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
									cin.get();
									if (instrumenty1.size() == 0)
									{
										cout << "Wektor jest pusty" << endl;
									}
									else
									{
										if (g<0 || g>instrumenty1.size() - 1)
										{
											cout << "jestes poza zakresem" << endl;
										}
										else
										{
											instrumenty1[g]->zainstaluj_element();
											instrumenty1[g]->wyswietl();
										}
									}
									cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
									cin.get();
									system("cls");
								}
								if (opcja300 == '2')
								{
									cin.get();
									int g;
									cout << "Wybrano odinstalowanie elementu" << endl << endl;
									cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << endl;
									cout << "Pamietaj, ze tablica zaczyna sie od 0" << endl;
									cout << "Wybierz obiekt od ktorego chcesz odinstalowac element." << endl;
									cout << "-------------------------------" << endl;
									cout << "Numer indeksu: ";
									cin >> g;
									cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
									cin.get();
									if (instrumenty1.size() == 0)
									{
										cout << "Wektor jest pusty" << endl;
									}
									else
									{
										if (g<0 || g>instrumenty1.size() - 1)
										{
											cout << "jestes poza zakresem" << endl;
										}
										else
										{
											instrumenty1[g]->odinstaluj_element();
											instrumenty1[g]->wyswietl();
										}
									}
									cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
									cin.get();
									system("cls");
								}
								if (opcja300 == '3')
								{
									system("cls");
									break;
								}
								if (opcja300 != '1'&&opcja300 != '2'&&opcja300 != '3')
								{
									cin.get();
									cout << "Wprowadzono niepoprawna opcje" << endl;
									cout << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
									cin.get();
									system("cls");
								}
							} while (opcja300 != '3');
						}
						if (opcja100 == '4')
						{
							cin.get();
							int g;
							cout << "Wybrano granie" << endl << endl;
							cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << endl;
							cout << "Wybierz obiekt na ktorym chcesz grac" << instrumenty1.size() << endl;
							cout << "Pamietaj, ze tablica zaczyna sie od 0" << endl;
							cin >> g;
							cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
							cin.get();
							if (instrumenty1.size() == 0)
							{
								cout << "Wektor jest pusty" << endl;
							}
							else
							{
								if (g<0 || g>instrumenty1.size() - 1)
								{
									cout << "jestes poza zakresem" << endl;
								}
								else
								{
									instrumenty1[g]->graj();
								}
							}
							cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
							cin.get();
							system("cls");
						}

						if (opcja100 == '5')
						{
							system("cls");
							break;
						}
						if (opcja100 != '1'&&opcja100 != '2'&&opcja100 != '3'&&opcja100!='4'&&opcja100!='5')
						{
							cout << "blad" << endl;
							system("cls");
						}
					} while (opcja100 != '5');
				}
				if (opcja15 == '2')
				{
					cin.get();
					cout << "Wybrano usuwanie obiektow wektora" << endl;
					cout << "Kliknij [enter], aby zobaczyc ile aktualnie jest obiektow";
					cin.get();
					cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << "\nKliknij [enter], aby zobaczyc ile obiektow zaraz bedzie";
					cin.get();
					instrumenty1.pop_back();
					cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << endl;
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");

				}
				if (opcja15 == '3')
				{
					cin.get();
					cout << "Wybrano usuwanie wszystkich obiektow wektora" << endl;
					cout << "Kliknij [enter], aby zobaczyc ile aktualnie jest obiektow";
					cin.get();
					cout << "Aktualnie w wektorze znajduje sie obiektow: " << instrumenty1.size() << "\nKliknij [enter], aby zobaczyc ile obiektow zaraz bedzie";
					instrumenty1.clear();
					cin.get();
					cout << "Aktualnie w wektorze znajduja sie obiektow: " << instrumenty1.size() << endl;
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
				if (opcja15 == '4')
				{
					cin.get();
					ofstream out_file("INSTRUMENTY SMYCZKOWE.txt");
					if (out_file.is_open())
					{
						out_file << instrumenty1.size() << endl;
						for (int i = 0; i < instrumenty1.size(); i++)
						{
							Instrumenty_smyczkowe* is = instrumenty1[i];
							if (dynamic_cast<Skrzypce_elektryczne*>(is) != nullptr)
							{
								out_file << "E" << endl;
								is->zapisz_stan(out_file);
							}
							else if (dynamic_cast<Kontrabas*>(is) != nullptr)
							{
								out_file << "K" << endl;
								is->zapisz_stan(out_file);
							}
							else if (dynamic_cast<Skrzypce*>(is) !=nullptr)
							{
								out_file << "S" << endl;
								is->zapisz_stan(out_file);
							}
						}
						out_file.close();
					}
					cout << "Zapisano stan w pliku zewnetrznym" << endl << endl;
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
				if (opcja15 == '5')
				{
					cin.get();

					string linia;
					int w;
					ifstream plik("INSTRUMENTY SMYCZKOWE.txt");
					if (plik.is_open())
					{
						plik >> w;
						for (int i = 0; i < w; i++)
						{
							plik >>linia;
							if (linia == "E")
							{
								se1.wczytaj_stan(plik);
								//instrumenty1.push_back(&se1);
								se1.wyswietl();
								cout << endl;
							}
							else if (linia == "S")
							{
								s1.wczytaj_stan(plik);
								//instrumenty1.push_back(&s1);
								s1.wyswietl();
								cout << endl;
							}
							else
							{
								k1.wczytaj_stan(plik);
								//instrumenty1.push_back(&k1);
								k1.wyswietl();
								cout << endl;
							}
						}
						plik.close();
					}
					else
						cout << "plik nie istnieje" << endl;
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
				if (opcja15 == '6')
				{
					cin.get();
					instrumenty1.clear();
					char linia;
					int w;
					ifstream plik("INSTRUMENTY SMYCZKOWE.txt");
					if (plik.is_open())
					{
						plik >> w;
						for (int i = 0; i < w; i++)
						{
							plik >> linia;
							if (linia == 'E')
							{
								se1.wczytaj_stan(plik);
								instrumenty1.push_back(&se1);
								//se1.wyswietl();
								cout << endl;
							}
							else if (linia == 'S')
							{
								s1.wczytaj_stan(plik);
								instrumenty1.push_back(&s1);
								//s1.wyswietl();
								cout << endl;
							}
							else
							{
								k1.wczytaj_stan(plik);
								instrumenty1.push_back(&k1);
								//k1.wyswietl();
								cout << endl;
							}
						}
						plik.close();
					}
					else
						cout << "blad" << endl;
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
				if (opcja15 == '7')
				{
					cin.get();
					for (int k = 0; k < instrumenty1.size(); k++) {
						cout << k + 1 << ". ";
						instrumenty1[k]->wyswietl();
					}
					cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
				if (opcja15 == '8')
				{
					system("cls");
					break;
				}
				if (opcja15 != '1'&&opcja15 != '2'&&opcja15 != '3'&&opcja15 != '4'&&opcja15 != '5'&&opcja15 != '6'&&opcja15 != '7'&&opcja15 != '8')
				{
					cin.get();
					cout << "Wprowadzono niepoprawna opcje" << endl;
					cout << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
					cin.get();
					system("cls");
				}
			} while (opcja15 != '8');
		}
		if (opcja1 == '3')
		{
			Kontrabas kontrabas1;
			Skrzypce skrzypce1;
			Skrzypce_elektryczne skrzypce_elektryczne1;
			Podbrodek podbrodek1; Smyczek smyczek1; Nozka_kontrabasu nozka_kontrabasu1;
			Instrumenty_smyczkowe* instrumenty2[3];
			instrumenty2[0] = &kontrabas1;
			instrumenty2[1] = &skrzypce1;
			instrumenty2[2] = &skrzypce_elektryczne1;

			cin.get();
			cout << "Wybrano demonstracje dzialania polimorfizmu" << endl;
			cout << "Demonstracja polega na wpisaniu trzy krotnie nowego producenta i nowego modelu instrumentu smyczkowego" << endl;
			cout << "Prosze postepuj wedlug instrukcji" << endl;

			for (int i = 0; i < 3; i++) {
				cout << endl << i + 1 << ". Wprowadz nowego producenta: ";
				cin.get(nowy_producent, rozmiar).get();
				cout << i + 1 << ". Wprowadz nowy model: ";
				cin.get(nowy_model, rozmiar).get();
				instrumenty2[i]->zmien_parametr(nowy_producent, nowy_model);
				instrumenty2[i]->wyswietl();
			}
			cout << endl << "Teraz mozesz wykomentowac lub odkomentowac \"virtual\" z metody zmien_parametr() oraz wyswietl(), aby zobaczyc dzialanie polimorfizmu" << endl;
			cout << endl << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
			cin.get();
			system("cls");
		}
		if (opcja1 == '4')
		{
			exit(0);
		}
		if (opcja1 != '1'&&opcja1 != '2'&&opcja1 != '3')
		{
			cin.get();
			cout << "Wprowadzono niepoprawna opcje" << endl;
			cout << "Nacisnij klawisz [ENTER] aby powrocic do menu." << endl;
			cin.get();
			system("cls");
		}
	} while (opcja1 != '4');
	remove("INSTRUMENTY_SMYCZKOWE.txt");

	return 0;
}
