
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
void quicksort(int* tab, int left, int right) {
	int x = tab[right / 2];
	int temp, p, q;
	p = left;
	q = right;

	do {
		while (tab[p] < x) p++;
		while (tab[q] > x) q--;

		if (p <= q) {
			temp = tab[p];
			tab[p] = tab[q];
			tab[q] = temp;
			p++;
			q--;
		}
	} while (p <= q);

	if (right > q) quicksort(tab, right, q);
	if (left > p) quicksort(tab, p, left);

}
*/
	

int *pom; //tablica pomocnicza, potrzebna przy scalaniu

//scalenie posortowanych podtablic
void scal(int tab[], int lewy, int srodek, int prawy)
{
	int i = lewy, j = srodek + 1;

	//kopiujemy lewą i prawą część tablicy do tablicy pomocniczej
	for (int i = lewy; i <= prawy; i++)
		pom[i] = tab[i];

	//scalenie dwóch podtablic pomocniczych i zapisanie ich 
	//we własciwej tablicy
	for (int k = lewy; k <= prawy; k++)
		if (i <= srodek)
			if (j <= prawy)
				if (pom[j] < pom[i])
					tab[k] = pom[j++];
				else
					tab[k] = pom[i++];
			else
				tab[k] = pom[i++];
		else
			tab[k] = pom[j++];
}

void sortowanie_przez_scalanie(int tab[], int lewy, int prawy)
{
	//gdy mamy jeden element, to jest on już posortowany
	if (prawy <= lewy) return;

	//znajdujemy srodek podtablicy
	int srodek = (prawy + lewy) / 2;

	//dzielimy tablice na częsć lewą i prawa
	sortowanie_przez_scalanie(tab, lewy, srodek);
	sortowanie_przez_scalanie(tab, srodek + 1, prawy);

	//scalamy dwie już posortowane tablice
	scal(tab, lewy, srodek, prawy);
}


	


int main()
{
	int rozmiar_tab;

	srand(time(NULL));

	cout << "Rozmiar tablicy: ";
	cin >> rozmiar_tab;
	int *tab = new int[rozmiar_tab];
	pom = new int[rozmiar_tab];

	
	for (int i = 0; i < rozmiar_tab; i++) {
		tab[i]  = (rand() % 100) + 1;
	}
	
	for (int i = 0; i < rozmiar_tab; i++) {
		cout << tab[i] << endl;
	}

	//	quicksort(tab, 0, rozmiar_tab-1);
	sortowanie_przez_scalanie(tab, 0, rozmiar_tab - 1);

	cout << "Posortowana:" << endl;
	for (int i = 0; i < rozmiar_tab; i++) {
		cout << tab[i] << endl;
	}


	delete [] tab;
	cin.get();
}

