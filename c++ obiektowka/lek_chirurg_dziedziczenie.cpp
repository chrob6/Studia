
//#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Lekarz {
public:

	static int licznik;
	string imie;
	string nazwisko;
	virtual void lecz();
};


class Chirurg : public Lekarz {
public:


	virtual void lecz() override {
		cout << "Lecze organy" << endl;
	}

	Chirurg() {
		imie = "Zbigniew";
		nazwisko = "Religa";
		cout << "Tworze chirurga" << endl;
		licznik++;
	}

	Chirurg(string im, string naz)
	{
		imie = im;
		nazwisko = naz;
		cout << "Tworze chirurga" << endl;
		licznik++;
	}

	Chirurg(const Chirurg &chirurg)
	{
		imie = chirurg.imie;
		nazwisko = chirurg.nazwisko;
		cout << "Tworze chirurga" << endl;
		licznik++;
	}

	~Chirurg() {
		cout << "destrction nr: " << licznik << endl;
		licznik--;
	}

	void operuj() {
		cout << "Advanced surgery";
	}

};

class Okulista : public Lekarz {
public:

	virtual void lecz() override {
		cout << "Lecze oczy" << endl;
	}

	Okulista() {
		imie = "Zbigniew";
		nazwisko = "Religa";
		cout << "Tworze okuliste" << endl;
		licznik++;
	}

	Okulista(string im, string naz)
	{
		imie = im;
		nazwisko = naz;
		cout << "Tworze okuliste" << endl;
		licznik++;
	}

	Okulista(const Chirurg &okulista)
	{
		imie = okulista.imie;
		nazwisko = okulista.nazwisko;
		cout << "Tworze okuliste" << endl;
		licznik++;
	}

	~Okulista() {
		cout << "destrction nr: " << licznik << endl;
		licznik--;
	}

};


void Lekarz::lecz() {
	cout << "Lecze! ";
}

void wezwijLekarza(Lekarz&) {
	Lekarz lek;
	lek.lecz();
}

int Lekarz::licznik = 0;


ostream& operator<<(ostream &p, const Lekarz &l) {
	p << "Name: " << l.imie << " Surname: " << l.nazwisko;
	return p;
}

int main()
{
	Chirurg ch_def;

	string pod_imie, pod_naz;
	cout << "POdaj imie chirurga: "; cin >> pod_imie;
	cout << "POdaj nazwisko chirurga : "; cin >> pod_naz;
	Chirurg ch_par(pod_imie, pod_naz);

	cout << endl;
	Okulista ok_def;

	cout << "POdaj imie okulisty: "; cin >> pod_imie;
	cout << "POdaj nazwisko okulisty : "; cin >> pod_naz;
	Okulista ok_par(pod_imie, pod_naz);

	Chirurg copy_ch_def = Chirurg(ch_def);
	Okulista copy_ok_par = Okulista(ok_par);

	ch_def.lecz();
	ok_par.lecz();

	cout << ch_def << endl;
	cout << ch_par;




	system("pause");


	return 0;
}

