#pragma once
#include <iostream>
#include "Harmonogram.h"
#include "Czas.h"

class Analiza
{
public:

	Czas znajdzNajdluzszy(Harmonogram &h);

	int zliczDluzszeNiz(Harmonogram& h, Czas limit);

	Czas obliczSrednia(Harmonogram& h);

};