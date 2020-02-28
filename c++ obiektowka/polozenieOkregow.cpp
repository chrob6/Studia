
#include <iostream>
#include <math.h>
#define pi 3.141592653589793238
#include <cstdlib>
#include <ctime>


using namespace std;

class Punkt
{
public:
    double x;
    double y;

    Punkt(double xx=0.,double yy=0.)
    {
        x=xx;
        y=yy;
    };

    void pobierzX(double x)
    {
        cin >> x;
    };

    void PobierzY(double y)
    {
        cin >> y;
    };

    void wypisz()
    {
        cout << "(" << x << "," << y << ")" << endl;
    };

    ~Punkt(){};
};

class Odcinek
{
public:
    Punkt poczatek;
    Punkt koniec;

Odcinek(Punkt po = (0.,0.), Punkt ko = (0.,0.))
        {
            poczatek = po;
            koniec = ko;
        }
//double dlugoscOdcinka(Odcinek od){
  //  double dx = od.koniec.x - od.poczatek.x;
    //double dy = od.koniec.y - od.poczatek.y;
    //return sqrt(dx*dx + dy*dy); }
double dlugoscOdcinka(Punkt po, Punkt ko)
{
    return(sqrt(((ko.x-po.x)*(ko.x-po.x))+((ko.y-po.y)*(ko.y-po.y))));
};

~Odcinek()
{
    //cout<< "Destruktor" << endl;
};
};


class Okrag
{
public:
friend double Odcinek::dlugoscOdcinka(Punkt po, Punkt ko);
friend void wypisz(int);

    static int licznik;
    Punkt srodek;
    double promien;

Okrag(Punkt sr = (0.,0.), double pr = 0.)
{
    srodek = sr;
    promien = pr;
    licznik++;
    //cout << "Konstruktor: " << licznik << endl;
}
double dlugoscOkregu(double pr)
{
    return(2*pi*pr);
}

~Okrag()
{
    licznik--;
    // cout << "Destruktor: "<< licznik << endl;
}

};

int Okrag::licznik = 0;

int przeciecie(Okrag ok1,Okrag ok2){
    Odcinek AB;
    double dlAB = AB.dlugoscOdcinka( ok1.srodek, ok2.srodek);
    //cout << "dl AB:  " << dlAB << endl;
    if((fabs(dlAB))>(ok1.promien+ok2.promien))
        {
           return 1; //cout << "Okregi roz³aczne zewnetrznie"<<endl;
        }
    else if ((fabs(dlAB))==(ok1.promien+ok2.promien))
        {
            return 2;//cout << "Okregi styczne zewnetrznie"<<endl;
        }
    else if (((fabs(ok1.promien-ok2.promien))<(fabs(dlAB)))&&((fabs(dlAB))<(ok1.promien+ok2.promien)))
        {
            return 3;//cout << "Okregi przecinajace sie"<<endl;
        }
    else if ((fabs(dlAB))==(fabs(ok1.promien-ok2.promien)))
        {
            return 4;//cout << "Okregi styczne wewnetrznie"<<endl;
        }
    else if ((fabs(dlAB))<(fabs(ok1.promien-ok2.promien)))
        {
            return 5;//cout << "Okregi roz³aczne wewnetrznie"<<endl;
        }
    else
        {
             return 6;//cout << "Okregi wspolsrodkowe"<<endl;
        }

};

 void wypisz(int a)
 {
    switch (a){
    case 1 : cout << "Okregi roz³aczne zewnetrznie"<<endl;
    break;
    case 2 : cout << "Okregi styczne zewnetrznie"<<endl;
    break;
    case 3 : cout << "Okregi przecinajace sie"<<endl;
    break;
    case 4 : cout << "Okregi styczne wewnetrznie"<<endl;
    break;
    case 5 : cout << "Okregi roz³aczne wewnetrznie"<<endl;
    break;
    case 6 : cout << "Okregi wspolsrodkowe"<<endl;
    break;

    }
 }

int main()
{
    Okrag ok1({0.,0.},5.);
    Okrag ok2({3.,4.},5.);
    cout << ok1.srodek.y << endl;

    wypisz(przeciecie(ok1,ok2));


srand(time(NULL));

    Okrag tablica1[100];
    for (int i = 0; i<100; i++)
        {
            tablica1[i].srodek.x = rand()%21+(-10);
            tablica1[i].srodek.y = rand()%21+(-10);
            tablica1[i].promien = rand()%20+1;
        }

    Okrag tablica2[100];
    for (int i = 0; i<100; i++)
        {
            tablica2[i].srodek.x = rand()%21+(-10);
            tablica2[i].srodek.y = rand()%21+(-10);
            tablica2[i].promien = rand()%20+1;
        }

    for(int i=0; i <100; i++)
        {
           if( przeciecie(tablica1[i],tablica2[i])==3){
            cout << "(" << tablica1[i].srodek.x << "," << tablica1[i].srodek.y << ") promien: " << tablica1[i].promien <<"   (" << tablica2[i].srodek.x << "," << tablica2[i].srodek.y << ") promien: " << tablica2[i].promien <<"  ";
            wypisz(przeciecie(tablica1[i],tablica2[i]));
           }
           else{
            cout << "Nie przecinaja sie" << endl;
           }
        };
		// dopisanie reszty ifow oraz funkcji zeby nie powtarzac kodu..
	system("pause");
return 0;
}
