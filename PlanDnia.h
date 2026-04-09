#pragma once
#include <iostream>
#include "Czas.h"
#include "Harmonogram.h"

class PlanDnia 
{
private:

	Harmonogram h_obowiazki;

	Harmonogram h_relaks;


public:

	void dodajDoPlanu(Czas& t, bool czyObowiazek);

	Czas podsumujDzien();

	void wyswietlRaport();
};