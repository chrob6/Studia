#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class Punkt2d
{
public:
    double x;
    double y;
    Punkt2d(double x0=0., double y0=0.)
    {
        x=x0;
        y=y0;
    };

    //Punkt2d(double x00 = 0, double y00 = 0) : x(x00), y(y00) {}


    Punkt2d(const Punkt2d& wzor)
    {
        x=wzor.x;
        y=wzor.y;
    };

    void wypisz()
    {
        cout << "(" << x << "."<< y <<")"<<endl;
    }

    double odleglosc(Punkt2d& koniec){
        double dx = koniec.x - x;
        double dy = koniec.y -y;
        return sqrt((dx*dx)+(dy*dy));
    }

    Punkt2d operator+(Punkt2d p)
    {
        Punkt2d punkt;
        punkt.x = this->x+p.x;
        punkt.y = this->y+p.y;
        return punkt;
    };

    Punkt2d operator-(Punkt2d p)
    {
        Punkt2d punkt;
        punkt.x = this->x-p.x;
        punkt.y = this->y-p.y;
        return punkt;
    };

    ~Punkt2d()
    {
    cout << "Destruktor"<<endl;
    }

};

int main()
{
    Punkt2d p1;
    Punkt2d p2(2,5);
    Punkt2d p3(5,9);
    Punkt2d p4 = Punkt2d(p3);
    Punkt2d* p5 = new Punkt2d(2,2);

    p1.wypisz();
    p2.wypisz();
    p3.wypisz();
    p4.wypisz();
    (*p5).wypisz();

    Punkt2d sum = p2 + p3;
    Punkt2d roz = p2 - p3;
    cout<<"Suma punktow p2 i p3 wynosi:" << "(" << sum.x << ","<< sum.y <<")"<< endl;
    cout<<"Roznica punktow p2 i p3 wynosi:" << "(" << roz.x << ","<< roz.y <<")"<< endl;
    cout<<"Odleglosc punktu p3 od poczatku ukladu wspolrzednych wynosi: " << p3.odleglosc(p1)<<endl;
    cout<<"Odleglosc punktu p3 od p2 wynosi: " << p3.odleglosc(p2)<<endl;
    delete p5;

	system("pause");
    return 0;
}
