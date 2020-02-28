#include <stdio.h>

#define rozmiar_tab 15

void main( void ) 
{
	char tablica_char[rozmiar_tab];

	int p, wh_sp=0, inne=0, cyf=0, lit=0;
	int tab_cyf[10]={0};
	int c;

  	while( ( c = getchar()) != EOF) { 	
		if((c-'0')>=0 && (c-'0') <=9){
			tab_cyf[c-'0']++;
		}
		else if((int)c>96 && (int)c<123) {
			lit++;
		}
		else if(c ==' ' || c=='\n' || c=='\t'){
			wh_sp++;
		}
		else{
			inne++;
		}
	}

	printf("\nZliczanie cyfr \n"); 
	int suma = 0;
  	for (int i = 0; i < 10; i++) {

		printf("%d", i);
		suma+= tab_cyf[i];
		int j;
		for(j=0; j<tab_cyf[i]; j++) {
			printf("*");
		}
		printf("\n");			


	}
		printf("\n");
		int k;
		for(k=0; k<10; k++) {
			float percent =  (float)(tab_cyf[k]*100)/suma; 
			printf("%d %1.2f%\n",k, percent);

		}
		printf("\n");

 	 printf("Zliczenie liter = %d\nwhite space = %d\nother =  %d\n",lit , wh_sp, inne);
}



