#include<stdio.h>
#include<math.h>

double pierwiastek(double arg_liczba, double dokladnosc);

#define ACCURACY (1.e-5) // do przeprowadzania obliczeń i sprawdzenia dokładności wyniku

//double dokladnosc = ACCURACY;

void main( void ) {
  
  double liczba;
  double dokladnosc = 1.e-15; //ACCURACY;
  
  for(;;){
    
    printf("\nPodaj wartość liczby dodatniej (-1 kończy program):\n");
    scanf("%lf",&liczba);
    
    if(liczba<0.0) {
	printf("pierwiastek z liczby ujemnej - koniec funkcji\n");
	 break;
    }
    
    double f_pierwiastek = pierwiastek(liczba, ACCURACY);
	printf("wynik: %lf",pierwiastek(pierwiastek(liczba, ACCURACY), ACCURACY) );
    
    printf("\nliczba %20.15lf, założona dokładność obliczania pierwiastka: %20.15lf\n", 
	   liczba, dokladnosc);
    printf("\tpierwiastek liczby: obliczony %20.15lf, dokładny %20.15lf\n", 
	   pierwiastek(liczba, ACCURACY), sqrt(liczba));
    printf("\tbłąd bezwzględny: %20.15lf, błąd względny: %20.15lf\n",
	   f_pierwiastek-sqrt(liczba), (f_pierwiastek-sqrt(liczba))/sqrt(liczba));
    
  }
}

double pierwiastek(double arg_liczba, double dokladnosc) {

    //double dokladnosc = ACCURACY;
    double pierwiastek = 1.0;
    double temp;
    // obliczenia pierwiastka za pomocą wzoru Herona
    do{
      temp = pierwiastek;
      pierwiastek = 0.5 * (temp + arg_liczba/temp);
    } while(fabs(pierwiastek*pierwiastek - arg_liczba)/arg_liczba > (dokladnosc)); 

    return(pierwiastek);
}

	

// definicja funkcji + komentarze (z komentarzy można tworzyć dokumentację):

// funkcja oblicz_pierwiastek oblicza pierwiastek za pomocą wzoru Herona
//               dla dowolnej liczby podwójnej precyzji większej od zera
// wariant 1. funkcja zakłada, że argument jest nie mniejszy niż zero
// wariant 2. dla liczb mniejszych od zera funkcja zwraca kod błędu: -1
//   implementacja w kodzie, np.
//  if(arg<0){
//    // obsługa błędu wejścia, np.
//    return(-1.0); // wyjaśnienie w dokumentacji
//  }


// wydruki kontrolne do sprawdzenia działania funkcji:

//  printf("aktualna obliczona wartość, \tbłąd względny kolejnych iteracji, \tbłąd wzgledny kwadratu\n"); 
//
//do{ ....
//
//    printf("wartość %20.15lf, \tbłąd  %20.15lf,     błąd kwadratu %20.15lf\n", 
//	   pierwiastek, fabs(pierwiastek - temp)/pierwiastek, 
//	   fabs(pierwiastek*pierwiastek - arg)/arg);
//
//    ....}
