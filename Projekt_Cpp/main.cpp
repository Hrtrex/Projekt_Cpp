#include <iostream>
#include <fstream>
#include "Macierz.h"
#include "Algorytm.h"
using namespace std;

int main()
{	
	int s, m = 1, n = 1;
	Macierz tab;
	Algorytm a;
	ifstream dane;
	ofstream wynik;
	streampos pozycja = 0;
	dane.open("dane.txt");
	if (!dane.good())
	{
		cout << "Blad podczas otwarcia pliku do odczytu\n";
	}
	wynik.open("wynik.txt");
	if (!wynik.good())
	{
		cout << "Blad podczas otwarcia pliku do zapisu\n";
	}
	while (1)
	{
		cout << "\n1 - odczyt danych z pliku\n";
		cout << "2 - wprowadzenie danych w konsoli\n";
		cout << "3 - zapis wynikow do pliku\n";
		cout << "4 - wyswietlenie wynikow w konsoli\n";
		cout << "5 - zakoncz\n";
		cin >> s;
		switch (s)
		{
		case 1:
			if (!dane.eof())
			{
				dane.seekg(pozycja, ios::beg);
				dane >> m >> n;
				tab.Resize(m, n);
				dane >> tab;
				cout << "Odczytane dane:" << endl;
				cout << m << " " << n << endl << tab;
				a.Ustaw(tab);
				a.Oblicz();
				pozycja = dane.tellg();
			}
			else
			{
				cout << "Nie ma wiecej danych w pliku" << endl;
			}
			break;
		case 2:
			cout << "Podaj rozmiar macierzy, ilosc wierszy i kolumn: " << endl;
			cin >> m >> n;
			tab.Resize(m, n);
			cout << "\nPodaj dane do wpisania do macierzy:" << endl;
			cin >> tab;
			a.Ustaw(tab);
			a.Oblicz();
			break;
		case 3:
			wynik << a;
			break;
		case 4:
			cout << a;
			break;
		case 5:
			return 0;
		default:
			cout << "Wybrales zla liczbe\n";
			break;
		}
	}
}