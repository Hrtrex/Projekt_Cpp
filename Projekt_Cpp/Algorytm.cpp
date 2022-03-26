#include "Algorytm.h"

Algorytm::Algorytm(const Macierz& wzor)
	:m_wzorzec(wzor), m_obliczenia(wzor.Wiersze(), wzor.Kolumny()), 
	m_poprzednicy(wzor.Wiersze(), wzor.Kolumny()), m_mini(INT_MAX), m_gdzie(0)
{
	m_droga = new int[wzor.Kolumny()];
	m_obliczenia.UstawObliczenia(wzor);
} 

Algorytm::Algorytm(const int m, const int n) 
	:m_wzorzec(m, n), m_obliczenia(m, n), m_poprzednicy(m, n)
{
	m_mini = INT_MAX;
	m_gdzie = 0;
	m_droga = new int[n]();
}

Algorytm::~Algorytm()
{
	//cout << "destruktor alg\n";
	delete[] m_droga;
}

void Algorytm::Ustaw(const Macierz& wzor)
{
	int m = wzor.Wiersze();
	int n = wzor.Kolumny();
	this->m_wzorzec.Resize(m, n);
	this->m_obliczenia.Resize(m, n);
	this->m_poprzednicy.Resize(m, n);
	m_mini = INT_MAX;
	delete[] m_droga;
	m_droga = new int[n]();
	m_wzorzec = wzor;
	this->m_obliczenia.UstawObliczenia(m_wzorzec);
}

void Algorytm::Wypisz() const
{
	cout << "macierz wzorcowa:" << endl;
	m_wzorzec.Wypisz();
	cout << endl<< "macierz obliczen:" << endl;
	m_obliczenia.Wypisz();
	cout << endl << "macierz poprzednikow:" << endl;
	m_poprzednicy.Wypisz();
}

void Algorytm::Oblicz()
{
	int** tab = m_obliczenia.Tab();
	int** tab2 = m_wzorzec.Tab();
	int** pop = m_poprzednicy.Tab();
	int m = m_wzorzec.Wiersze();
	int n = m_wzorzec.Kolumny();
	//poczatek algorytmu
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (i == 0) // jeœli to pierwszy wiersz (trzeba zawin¹æ)
			{
				if (tab[i][j] + tab2[m - 1][j + 1] < tab[m - 1][j + 1]) // góra
				{
					tab[m - 1][j + 1] = tab[i][j] + tab2[m - 1][j + 1];
					pop[m - 1][j + 1] = i;
				}
			}
			else if (tab[i][j] + tab2[i - 1][j + 1] < tab[i - 1][j + 1]) // góra
			{
				tab[i - 1][j + 1] = tab[i][j] + tab2[i - 1][j + 1];
				pop[i - 1][j + 1] = i;
			}

			if (tab[i][j] + tab2[i][j + 1] < tab[i][j + 1]) // prawo
			{
				tab[i][j + 1] = tab[i][j] + tab2[i][j + 1];
				pop[i][j + 1] = i;
			}

			if (i == m - 1) // jeœli to ostatni wiersz (trzeba zawin¹æ)
			{
				if (tab[i][j] + tab2[0][j + 1] < tab[0][j + 1]) // dó³
				{
					tab[0][j + 1] = tab[i][j] + tab2[0][j + 1];
					pop[0][j + 1] = i;
				}
			}
			else if (tab[i][j] + tab2[i + 1][j + 1] < tab[i + 1][j + 1]) // dó³
			{
				tab[i + 1][j + 1] = tab[i][j] + tab2[i + 1][j + 1];
				pop[i + 1][j + 1] = i;
			}
		}
	}
	//koniec algorytmu
	// znalezienie d³ugoœci najkrótszej œcie¿ki i jej lokalizacji 
	for (int i = 0; i < m; i++)
	{
		if (tab[i][n - 1] < m_mini)
		{
			m_mini = tab[i][n - 1];
			m_gdzie = i;
		}
	}
	// wyznaczenie dok³adnej drogi najkrótszej œcie¿ki
	int temp;
	m_droga[n - 1] = m_gdzie + 1;
	temp = m_gdzie;
	for (int i = n - 2; i >= 0; i--)
	{
		m_droga[i] = pop[temp][i + 1] + 1;
		temp = m_droga[i] - 1;
	}
}

ostream& operator<<(ostream& wy, const Algorytm& a)
{
	if (&wy == &cout)
	{
		wy << "Wprowadzona macierz:" << endl << a.m_wzorzec << endl;
		wy << "Dlugosc najkrotszej drogi:" << endl << a.m_mini << endl;
		wy << "Numery wierszy opisujace najkrotsza droge:" << endl;
		for (int i = 0; i < a.m_wzorzec.Kolumny(); i++)
		{
			wy << a.m_droga[i] << " ";
		}
		wy << endl;
	}
	else
	{
		wy << a.m_mini << endl;
		for (int i = 0; i < a.m_wzorzec.Kolumny(); i++)
		{
			wy << a.m_droga[i] << " ";
		}
		wy << endl;
	}
	return wy;
}
