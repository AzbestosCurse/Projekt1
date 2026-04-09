#include "Analiza.h"

Czas Analiza::znajdzNajdluzszy(Harmonogram& h)
{
	int ilosc_czasow = h.podajIlosc();

	if (ilosc_czasow == 0)
	{
		return Czas(0);
	}

	Czas najdluzszy = h[0];

	for (int i = 0; i < ilosc_czasow; i++)
	{
		if (h[i] > najdluzszy)
		{
			najdluzszy = h[i];
		}

	}

	return najdluzszy;
}

int Analiza::zliczDluzszeNiz(Harmonogram& h, Czas limit)
{
	int ilosc_czasow = h.ileCzasow();

	int ile_wiekszych = 0;

	if (ilosc_czasow == 0)
	{
		return 0;
	}

	for (int i = 0; i < ilosc_czasow; i++)
	{
		if (h[i] > limit)
		{
			ile_wiekszych++;
		}
		
	}

	return ile_wiekszych;
}

Czas Analiza::obliczSrednia(Harmonogram& h)
{
	int ilosc_czasow = h.ileCzasow();

	Czas suma = h.sumujCzasy();

	int sek = suma.zmienNaSek();

	int srednia = sek / ilosc_czasow;

	Czas srednia_czas;

	srednia_czas.ustawCzas(srednia);

	return srednia_czas;

}