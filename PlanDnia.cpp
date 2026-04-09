#include "PlanDnia.h"

void PlanDnia::dodajDoPlanu(Czas& t, bool czyObowiazek)
{
	if (czyObowiazek == true)
	{
		h_obowiazki.czasDoHarmonogramu(t);
	}
	else
	{
		h_relaks.czasDoHarmonogramu(t);
	}
}

Czas PlanDnia::podsumujDzien()
{
	Czas suma_o = h_obowiazki.sumujCzasy();

	Czas suma_r = h_relaks.sumujCzasy();

	Czas caly_dzien = suma_o + suma_r;

	return caly_dzien;
}

void PlanDnia::wyswietlRaport()
{
	std::cout << "========PLAN DNIA========" << std::endl;

	std::cout << "Obowiazki:" << std::endl;
	h_obowiazki.wyswietlHarmonogram();

	std::cout << "Relaks: " << std::endl;
	h_relaks.wyswietlHarmonogram();
}