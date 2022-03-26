#pragma once
#include "Macierz.h"

class Algorytm
{
private:
	Macierz m_wzorzec;
	Macierz m_obliczenia;
	Macierz m_poprzednicy;
	int m_mini;
	int m_gdzie;
	int* m_droga;
public:
	Algorytm(const Macierz& wzor);
	Algorytm(const int m=1, const int n=1);
	~Algorytm();
	void Ustaw(const Macierz& wzor);
	void Wypisz() const;
	void Oblicz();
	friend ostream& operator<<(ostream& wy, const Algorytm& a);
};

