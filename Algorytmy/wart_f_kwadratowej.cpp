
#include "pch.h"
#include <iostream>

using namespace std;

// tablica przy podaniu liczby 4 od -1..2, dla 6 od -1..4 - argumenty funkcji
// wartosci a, b, c - wspolczynniki funkcji kwadratowej
// wyliczenie wartosci tej funkcji dla danych argumentow z tablicy oraz posortowanie ich

/*
void sortowanie_babelkowe(int tab[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (tab[j - 1] > tab[j])
				swap(tab[j - 1], tab[j]);
}
*/

int* sortowanie(int* tab, int ax, int bx, int cx, int ilx) {
	int y, p;
	int* wynik = new int[ilx];

	p = (-bx / (2*ax));

	if (ax >= 0) {
		for (int i = 0; i < ilx; i++) {
			y = ax * tab[i] * tab[i] + bx * tab[i] + cx;
			wynik[i] = y;
		}
	}
	else {
		for (int i = ilx; i > 0; i--) {
			y = ax * tab[ilx-i] * tab[ilx-i] + bx * tab[ilx-i] + cx;
			wynik[ilx-i] = y;
		}
	}
	return wynik;
}



int main() {
	int il, a, b, c;

	cout << "Ilosc w tab: ";
	cin >> il;
	int *arr = new int[il];
	for (int i = 0; i < il; i++) {
		arr[i] = i - 1;
		cout << arr[i];
	}
	cout << "parametry funkcji:" << endl << "a: ";
	cin >> a;
	cout << endl << "b: ";
	cin >> b;
	cout << endl << "c: ";
	cin >> c;
	arr = sortowanie(arr, a, b, c, il);

	for (int i = 0; i < il; i++) {
		cout << arr[i] << endl;
	}




	cin.get();

}

