// ConsoleApplication7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "paczki.h"
#include <cstdlib>

using namespace std;

int main()
{
	Paczka testObiekt;
	testObiekt.add();
	testObiekt.show();

	Paczka nowyobiekt = Paczka(testObiekt);
	cout << nowyobiekt.nazwa << endl;
	double wynik = nowyobiekt.Cena_do_Wagi(nowyobiekt);
	cout << wynik;

	system("pause");
}
