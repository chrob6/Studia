
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Pracownik {
protected: 
	int id;
	string imie, nazwisko;
	int stawka = 10;

public:
	static int licznik;

	Pracownik()
	{
		id = 1;
		imie = "Adam";
		nazwisko = "Nowak";
		licznik++;
	}

	Pracownik(int i, string im, string na)
	{
		id = i;
		imie = im;
		nazwisko = na;
	}

	Pracownik(const Pracownik& prac) {
		id = prac.id;
		imie = prac.imie;
		nazwisko = prac.nazwisko;
		stawka = prac.stawka;
	}
	
	~Pracownik() {
		cout << "Destr prac";
		licznik--;
	}
	
	friend ostream& operator << (ostream& prac, Pracownik p);
};

class Kierownik : public Pracownik {
public:
	double przelicznik = 5;

	Kierownik()
	{
		id = 10;
		imie = "Jan";
		nazwisko = "kr.Kowalski";
		stawka = stawka * przelicznik;
		licznik++;
	}

	Kierownik(int i, string im, string na, int staw)
	{
		id = i;
		imie = im;
		nazwisko = na;
		stawka = staw * przelicznik;

	}

	Kierownik(const Kierownik& prac) {
		id = prac.id;
		imie = prac.imie;
		nazwisko = prac.nazwisko;
		stawka = prac.stawka;
	}

	~Kierownik() {
		cout << "Destr kier";
		licznik--;
	}

	friend ostream& operator << (ostream& prac, Kierownik p);

};

class Informatyk : public Pracownik {
public:
	double przelicznik = 3.5;

	Informatyk()
	{
		id = 100;
		imie = "Michal";
		nazwisko = "inf.Aniol";
		stawka = stawka * przelicznik;
		licznik++;
	}

	Informatyk(int i, string im, string na, int staw)
	{
		id = i;
		imie = im;
		nazwisko = na;
		stawka = staw * przelicznik;

	}

	Informatyk(const Informatyk& prac) {
		id = prac.id;
		imie = prac.imie;
		nazwisko = prac.nazwisko;
		stawka = prac.stawka;
	}

	~Informatyk() {
		cout << "Destr inf";
		licznik--;
	}

	friend ostream& operator << (ostream& prac, Informatyk p);
};

int Pracownik::licznik = 0;

ostream& operator << (ostream& prac, Pracownik p) {
	prac << "Id: " << p.id << " Imie: " << p.imie << " Nazwisko: " << p.nazwisko << " stawka: " << p.stawka;
	return prac;
}

ostream& operator << (ostream& prac, Informatyk p) {
	prac << "Id: " << p.id << " Imie: " << p.imie << " Nazwisko: " << p.nazwisko << " stawka: " << p.stawka;
	return prac;
}

ostream& operator << (ostream& prac, Kierownik p) {
	prac << "Id: " << p.id << " Imie: " << p.imie << " Nazwisko: " << p.nazwisko << " stawka: " << p.stawka;
	return prac;
}

int main()
{
	Pracownik pracownik_domyslny;
	Pracownik pracownik_marcin(2, "Marcin", "Chrobak");
	Informatyk it_worker;
	Informatyk copy_it_worker = Informatyk(it_worker);
	Kierownik kieroooo;

	cout << endl << pracownik_domyslny << endl << pracownik_marcin << endl << it_worker << endl << copy_it_worker << endl << kieroooo << endl;

	Pracownik zespol[3]{ kieroooo, it_worker, pracownik_marcin };



	return 0;
}
