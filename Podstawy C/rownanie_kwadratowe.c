#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

#define SCALAR double
//#define SCALAR float

#define SMALL_NUMBER 1.e-10 // czy wystarczy jedna wartość dla float i dla double?

// Konstrukcje sterujące (nazwy zmiennych, zakresy widoczności i czas życia)
int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  SCALAR a, b, c;
  // rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
  // input - uodpornianie na błędy wczytywania danych 
  printf("\nPodaj parametr a: "); scanf("%lf",&a); // adres! (miejsce na wpisanie wartości)
  printf("Podaj parametr b: "); scanf("%lf", &b);
  printf("Podaj parametr c: "); scanf("%lf", &c);

  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie
    printf("\na i b bliskie 0 \n");
    //exit(-1);

	SCALAR small_a = SMALL_NUMBER;
	SCALAR small_b = SMALL_NUMBER;

	 SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c;
      if(delta<0){ 
		SCALAR wart_bez = fabs(delta);
		SCALAR pier_zesp = sqrt(wart_bez);

		SCALAR z1 = -b/(2*a);
		SCALAR z1i = -pier_zesp/(2*a);

		SCALAR z2 = -b/(2*a);
		SCALAR z2i = pier_zesp/(2*a);

		printf("Dwa pierwiastki zespolone - x1 = %4.4lf + (%4.4lfi), x2 = %4.4lf + (%4.4lfi)\n",
			z1, z1i, z2, z2i);
	}
	
  }
  else{
    if(a==0) { 
		SCALAR liniowe = -c/b;
		printf("Rownanie liniowe - jeden pierwiastek rzeczywisty x  = %20.5lf\n", liniowe);
		


	// równanie liniowe y=bx + c = 0 x = -c/b
      //co mówi kontrakt
    }
    else{
      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c;
      if(delta<0){ 
		SCALAR wart_bez = fabs(delta);
		SCALAR pier_zesp = sqrt(wart_bez);

		SCALAR z1 = -b/(2*a);
		SCALAR z1i = -pier_zesp/(2*a);

		SCALAR z2 = -b/(2*a);
		SCALAR z2i = pier_zesp/(2*a);

		printf("Dwa pierwiastki zespolone - x1 = %4.4lf + (%4.4lfi), x2 = %4.4lf + (%4.4lfi)\n",
			z1, z1i, z2, z2i);


      } else if (delta == 0){
	printf("Jeden pierwiastek rzeczywisty: x = %20.15lf\n", -b/(2*a) );
      } else {
	SCALAR temp = sqrt(delta);
	printf("Dwa pierwiastki rzeczywiste: x1 = %20.15lf, x2 = %20.15lf\n",
	       (-b-temp)/(2*a), (-b+temp)/(2*a) );
      }  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu
  }

  return(0);
}

// Lab 
// Uzupełnienie programu o obsługę wszystkich przypadków liczbowych danych wejściowych
// Różne przypadki kontraktu - uwzględniające lub nie skończoną precyzję
