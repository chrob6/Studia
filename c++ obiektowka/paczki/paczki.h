#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Paczka
{
	int nr_odzialu;

public:
	string nazwa;
	double cena;
	double waga;
	static int licznik;

	double Cena_do_Wagi(Paczka p);
	void add();
	void show();


	Paczka();
	Paczka(const Paczka &pacz);
	~Paczka();
};