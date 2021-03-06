// ConsoleApplication10.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Punkt2d {

public :
	double x;
	double y;

	/*Punkt2d(double x0 = 0 , double y0 = 0) : x(x0), y(y0)
	{
		
	} */

	Punkt2d(double iks = 0, double igrek = 0)
	{
		x = iks;
		y = igrek;
	} 

	Punkt2d(const Punkt2d& pkt) {
		x = pkt.x;
		y = pkt.y;
	}

	void wypisz() {
		cout << "wspolrzedne punktu: (" << x << "," << y << ")" << endl;
	}

	Punkt2d operator+(Punkt2d pkt)
	{
		Punkt2d add;
		add.x = this->x + pkt.x;
		add.y = this->y + pkt.y;
		return add;
	}

	Punkt2d operator-(Punkt2d pkt)
	{
		Punkt2d sub;
		sub.x = this->x - pkt.x;
		sub.y = this->y - pkt.y;
		return sub;
	}

	double odl(Punkt2d& pkt)
	{
		double x0 = (pkt.x - x)*(pkt.x - x);
		double y0 = (pkt.y - y)*(pkt.y - y);
		return sqrt((x0 + y0));
	}

	~Punkt2d() {
		cout << "Destruction's workin'" << endl;
	}

};

int main()
{
	Punkt2d p1(0, 0);
	Punkt2d p2(2, 5);
	Punkt2d p3(5, 9);
	Punkt2d p4 = Punkt2d(p3);
	Punkt2d *p5 = new Punkt2d(2, 2);


	p1.wypisz();
	p2.wypisz();
	p3.wypisz();
	p4.wypisz();
	(*p5).wypisz();

	Punkt2d add = p2 + p3;
	cout << "Dodawanie:" << endl;
	add.wypisz();
	
	cout << "Odejmowanie:" << endl;
	Punkt2d sub = p2 - p3;
	sub.wypisz();


	cout << "Odleglosc od (0,0): " << p3.odl(p1) << endl;
	cout << "Odleglosc miedzy pkt: " << p2.odl(p3) << endl;

	delete p5;
	
	system("pause");

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
