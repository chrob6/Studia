#include "pch.h"
#include <iostream>
#include <string>
#include "paczki.h"

using namespace std;

void Paczka::add() {
	cout << "Nr oddzialu: " << endl;
	cin >> nr_odzialu;

	cout << "Nazwa paczki: " << endl;
	cin >> nazwa;

	cout << "Cena paczki: " << endl;
	cin >> cena;

	cout << "Waga paczki: " << endl;
	cin >> waga;
}

void Paczka::show() {

	cout << "Nr oddzialu: " << nr_odzialu << endl << "Nazwa paczki: " << nazwa << endl << "Cena paczki: " << cena << endl << "Waga paczki: " << waga << endl;

}

double Paczka::Cena_do_Wagi(Paczka p) {

	double wynik = p.waga / p.cena;
	return wynik;
}
/*
Paczka::Paczka(int nr_o = 1, string n = "paczka", double c = 1.00, double w = 10.0) {
	nr_odzialu = nr_o;
	nazwa = n;
	cena = c;
	waga = w;
	licznik++;

	cout << "Konstruktor domyslny" << endl;
};
*/

Paczka::Paczka() {
	nr_odzialu = 1;
	nazwa = "paczka";
	cena = 1.00;
	waga = 10.0;
	licznik++;

	cout << "Konstruktor domyslny" << endl;
};

Paczka::Paczka(const Paczka &pacz) {
	nr_odzialu = pacz.nr_odzialu;
	nazwa = pacz.nazwa;
	cena = pacz.cena;
	waga = pacz.waga;

	cout << "Konstruktor copy" << endl;
}

Paczka::~Paczka() {
	licznik--;
	cout << "Destruction" << endl;
}


int Paczka::licznik = 0;