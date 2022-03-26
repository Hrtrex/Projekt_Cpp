#pragma once
#include <iostream>
using namespace std;

class Macierz
{
private:
	int** tab;
	int kolumny;
	int wiersze;
public:
	Macierz(const int m=1, const int n=1);
	~Macierz();
	Macierz(const Macierz& wzor);
	Macierz& operator=(const Macierz& wzor);
	const int Kolumny() const;
	const int Wiersze() const;
	int** Tab() const;
	void Wypisz() const;
	void Wpisz();
	void UstawObliczenia(const Macierz& wzor); //"ustawia" macierz obliczeñ m_obliczenia, czêœæ algorytmu
	void Resize(const int m, const int n);	   //
	friend ostream& operator<<(ostream& wy, const Macierz& m);
	friend istream& operator>>(istream& we, Macierz& m);
};
