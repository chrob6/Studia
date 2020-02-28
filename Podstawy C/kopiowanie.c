#include <stdio.h>
#define rozmiar_tab 15

void main( void ) // program kopiowania z stdin na stdout
{
	srand(time(NULL));
	int tablica_int[rozmiar_tab]={0};
	char tablica_char[rozmiar_tab]={0};
	int i=0;
	
	for(i=0; i<rozmiar_tab; i++){
		int c;
		c='a' + rand()%('z'-'a'+1);
		tablica_int[i]=c;
		tablica_char[i]=c;
	}
	
	for(int i=0; i<rozmiar_tab; i++){
		printf("Iteracja %d: tablica_int[%d] = %d     %c\n  ", i, i, tablica_int[i], tablica_char[i]);
	}
}



