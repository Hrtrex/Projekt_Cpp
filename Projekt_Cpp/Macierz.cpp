#include "Macierz.h"

Macierz::Macierz(const int m, const int n) :wiersze(m), kolumny(n)
{
	//cout << "konstruktor\n";
	tab = new int* [wiersze];
	for (int i = 0; i < wiersze; i++)
	{
		tab[i] = new int[kolumny]();
	}
}

Macierz::~Macierz()
{
	//cout << "destruktor\n";
	for (int i = 0; i < wiersze; i++)
	{
		delete[] tab[i];
	}
	wiersze = 0;
	kolumny = 0;
	delete[] tab;
}

Macierz::Macierz(const Macierz& wzor) :wiersze(wzor.wiersze), kolumny(wzor.kolumny)
{
	//cout << "konstruktor kopiujacy\n";
	tab = new int* [wiersze];
	for (int i = 0; i < wiersze; i++)
	{
		tab[i] = new int[kolumny]();
		
	}
	//memcpy(&tab, &wzor.tab, sizeof(tab));
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			tab[i][j] = wzor.tab[i][j];
		}
	}
	
}

Macierz& Macierz::operator=(const Macierz& wzor)
{
	if (this != &wzor)
	{
		//cout << "operator przypisania\n";
		this->~Macierz();
		wiersze = wzor.wiersze;
		kolumny = wzor.kolumny;
		tab = new int* [wiersze];
		for (int i = 0; i < wiersze; i++)
		{
			tab[i] = new int[kolumny]();
		}
		//memcpy(&tab, &wzor.tab, sizeof(tab));
		for (int i = 0; i < wiersze; i++)
		{
			for (int j = 0; j < kolumny; j++)
			{
				tab[i][j] = wzor.tab[i][j];
			}
		}
	}
	return *this;
}

const int Macierz::Kolumny() const
{
	return this->kolumny;
}

const int Macierz::Wiersze() const
{
	return this->wiersze;
}

int** Macierz::Tab() const
{
	return this->tab;
} 

void Macierz::Wpisz()
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			cin >> tab[i][j];
		}
	}
}

void Macierz::UstawObliczenia(const Macierz& wzor)
{
	int** tab2 = wzor.Tab();
	int m = wzor.wiersze;
	int n = wzor.kolumny;
	for (int i = 0; i < m; i++)
	{
		tab[i][0] = tab2[i][0];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			tab[i][j] = tab[i][j - 1] + tab2[i][j];
		}
	}
}

void Macierz::Resize(const int m, const int n)
{
	this->~Macierz();
	wiersze = m;
	kolumny = n;
	tab = new int* [wiersze];
	for (int i = 0; i < wiersze; i++)
	{
		tab[i] = new int[kolumny]();
	}
}

void Macierz::Wypisz() const
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

ostream& operator<<(ostream& wy, const Macierz& m)
{
	for (int i = 0; i < m.wiersze; i++)
	{
		for (int j = 0; j < m.kolumny; j++)
		{
			wy << m.tab[i][j] << " ";
		}
		wy << endl;
	}
	return wy;
}

istream& operator>>(istream& we, Macierz& m)
{
	for (int i = 0; i < m.wiersze; i++)
	{
		for (int j = 0; j < m.kolumny; j++)
		{
			we >> m.tab[i][j];
		}
	}
	return we;
}
