#include "Harmonogram.h"

Harmonogram::Harmonogram()
{
	czasy = nullptr;

	ilosc_czasow = 0;

	rozmiar = 0;
}

Harmonogram::~Harmonogram()
{
	delete[] czasy;
}

Harmonogram::Harmonogram(const Harmonogram& wzor)
{
	ilosc_czasow = wzor.ilosc_czasow;

	rozmiar = wzor.rozmiar;

	if (wzor.czasy != nullptr && rozmiar > 0)
	{
		czasy = new Czas[rozmiar];

		for (int i = 0; i < ilosc_czasow; i++)
		{
			czasy[i] = wzor.czasy[i];
		}
	}
	else
	{
		czasy = nullptr;
	}
}

int Harmonogram::podajIlosc()
{
	return ilosc_czasow;
}

Harmonogram& Harmonogram::operator=(const Harmonogram& wzor)
{
	if (&wzor == this)
	{
		return *this;
	}

	delete[] czasy;

	ilosc_czasow = wzor.ilosc_czasow;

	rozmiar = wzor.ilosc_czasow;

	czasy = new Czas[ilosc_czasow];

	for (int i = 0; i < ilosc_czasow; i++)
	{
		czasy[i] = wzor.czasy[i];
	}

	return *this;
}

void Harmonogram::powieksz()
{
	int nowy_rozmiar;

	if (rozmiar == 0)
	{
		nowy_rozmiar = 1;
	}
	else
	{
		nowy_rozmiar = rozmiar * 2;
	}

	Czas* nowe_czasy = new Czas[nowy_rozmiar];

	for (int i = 0; i < ilosc_czasow; i++)
	{
		nowe_czasy[i] = czasy[i];
	}

	delete[] czasy;

	czasy = nowe_czasy;

	rozmiar = nowy_rozmiar;
}

void Harmonogram::czasDoHarmonogramu(Czas& t)
{
	if (ilosc_czasow == rozmiar)
	{
		powieksz();
	}

	czasy[ilosc_czasow] = t;
	ilosc_czasow++;
}

int Harmonogram::ileCzasow()
{
	return ilosc_czasow;
}

Czas& Harmonogram::operator[](int idx)
{
	if (idx >= 0 && idx < rozmiar)
	{
		return czasy[idx];
	}

}

void Harmonogram::wyswietlHarmonogram()
{	
	std::cout << "====H A R M O N O G R A M====" << "\n";

	for (int i = 0; i < ilosc_czasow; i++)
	{
		czasy[i].wyswietlCzas();
	}
}

Harmonogram Harmonogram::harmonogramKopiaOgraniczona(Czas& t)
{
	Harmonogram kopia;

	Czas limit, suma;

	limit = t;

	suma.ustawCzas(0, 0, 0);

	for (int i = 0; i < ilosc_czasow; i++)
	{
		Czas sprawdz_sume = suma + czasy[i];

		if (sprawdz_sume <= limit)
		{
			suma = sprawdz_sume;

			kopia.czasDoHarmonogramu(czasy[i]);
		}
		else
		{
			break;
		}
	}

	std::cout << "Utworzone kopie harmonogramu z zadanym limitem" << "\n";

	return kopia;

}

Czas Harmonogram::sumujCzasy()
{
	Czas suma;

	for (int i = 0; i < ilosc_czasow; i++)
	{
		suma += czasy[i];
	}

	return suma;
}

void Harmonogram::usunWydarzenie(int idx)
{
	if (idx < 0 || idx >= ilosc_czasow)
	{
		std::cout << "Bledny index" << std::endl;

		return;
	}

	for (int i = idx; i < ilosc_czasow - 1; i++)
	{
		czasy[i] = czasy[i + 1];
	}

	ilosc_czasow--;
}


Harmonogram& Harmonogram::operator-=(int n)
{
	if (n <= 0)
	{
		return *this;
	}

	if (n >= ilosc_czasow)
	{
		ilosc_czasow = 0;

		rozmiar = 0;

		delete[] czasy;

		czasy = nullptr;

		return *this;
	}

	if (n < ilosc_czasow)
	{
		ilosc_czasow -= n;

		Czas* nowe_czasy = new Czas[ilosc_czasow];

		for (int i = 0; i < ilosc_czasow; i++)
		{
			nowe_czasy[i] = czasy[i];
		}

		delete[] czasy;

		czasy = nowe_czasy;

		return *this;
	}
	
}

Harmonogram Harmonogram::operator+(const Harmonogram& h)
{
	Harmonogram temp(*this);

	for (int i = 0; i < h.ilosc_czasow; i++)
	{
		temp.czasDoHarmonogramu(h.czasy[i]);
	}

	return temp;
}

Harmonogram Harmonogram::flitrujDluzszeNiz(const Czas& limit)
{
	Czas lim = limit;

	Harmonogram h;

	for (int i = 0; i < ilosc_czasow; i++)
	{
		if (czasy[i] > lim)
		{
			h.czasDoHarmonogramu(czasy[i]);
		}
	}
	return h;
}


void Harmonogram::wstaw(int idx, Czas& t)
{
	if (idx < 0 || idx > ilosc_czasow)
	{
		std::cout << "\nPodano bledny indeks\n"; 

		return;
	}



	if (ilosc_czasow > 0 && czasy != nullptr)
	{
		if (ilosc_czasow == rozmiar)
		{
			powieksz();
		}
		
		for (int i = ilosc_czasow; i > idx; i--)
		{
			czasy[i] = czasy[i - 1];
		}

		czasy[idx] = t;

		ilosc_czasow++;
	}
}

void Harmonogram::opoznijWszystko(Czas& opoznienie)
{
	Czas t = opoznienie;

	for (int i = 0; i < ilosc_czasow; i++)
	{
		czasy[i] += t;
	}
}

Harmonogram& Harmonogram::operator+=(const Harmonogram& h)
{	
	for (int i = 0; i < h.ilosc_czasow; i++)
	{
		czasDoHarmonogramu(h.czasy[i]);
	}

	return *this;
}

Harmonogram& Harmonogram::operator+=(Czas& t)
{
	Czas czas = t;

	czasDoHarmonogramu(czas);

	return *this;
}

Harmonogram& Harmonogram::operator-=(Czas& t)
{
	Czas del = t;

	for (int i = 0; i < ilosc_czasow; i++)
	{
		if (czasy[i] == del)
		{
			for (int j = i; j < ilosc_czasow - 1; j++)
			{
				czasy[j] = czasy[j + 1];
			}

			ilosc_czasow--;
			i--;
		}
	}

	return *this;
}

void Harmonogram::sortuj()
{
	for (int i = 0; i < ilosc_czasow; i++)
	{
		for (int j = 0; j < ilosc_czasow - 1; j++)
		{
			if (czasy[j] > czasy[j + 1])
			{
				std::swap(czasy[j], czasy[j+1]);
			}
		}
	}
}

Czas Harmonogram::znajdzNajdluzszy()
{
	Czas najdluzszy(0);

	for(int i = 0; i < ilosc_czasow; i++)
	{
		if (czasy[i] > najdluzszy)
		{
			najdluzszy = czasy[i];
		}
	}

	return najdluzszy;
	
}

void Harmonogram::usunKrotszeNiz(Czas& limit)
{
	for (int i = 0; i < ilosc_czasow; i++)
	{
		if (czasy[i] < limit)
		{
			for (int j = i; j < ilosc_czasow - 1; j++)
			{
				czasy[j] = czasy[j + 1];
			}

			ilosc_czasow--;
			i--;
		}
	}
}
