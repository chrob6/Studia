#include <stdio.h>
#include <stdlib.h>

struct Man{

	char *name;
	int age;
        double height;
	};

struct extra{

	int tab[3];
	struct inextra { int a; int b; };
	};

void fun_struct(struct Man whoever);  
struct Man fun_struct_out(struct Man whoever);
void fun_struct_wsk(struct Man* whoever); 
struct Man fun_struct_wsk_copy(struct Man* whoever);
void fun_struct_wsk_inout(struct Man* whoever);



void main(void)
{
	
	struct Man me = { "Marcin", 20, 1.72 } ;
	struct Man* wsk_me = &me;
	printf("Start\n");
	printf("Name: %s , Age: %d Height: %1.2lf\n",me.name, me.age, me.height);
	
	printf("fun_struct :  ");
	fun_struct(me);
	printf("Name: %s , Age: %d Height: %1.2lf\n",me.name, me.age, me.height);
	printf("\n");

	printf("fun_struct_out:  ");
	struct Man obiekt3 = fun_struct_out(me);
	printf("Name: %s , Age: %d Height: %1.2lf\n",me.name, me.age, me.height);

	struct Man sone = { "John", 23, 1.86 } ;
	struct Man* wsk_man = &sone;
	printf("Start\n");
	printf("Name: %s , Age: %d Height: %1.2lf\n",sone.name , wsk_man->age, wsk_man->height);
	printf("\n");

	printf("fun_struct_wsk:  ");
	fun_struct_wsk(wsk_man);
	printf("Name: %s , Age: %d Height: %1.2lf\n",sone.name , wsk_man->age, wsk_man->height);
	printf("\n");

	printf("fun_struct_wsk_copy:   ");
	struct Man obiekt4 = fun_struct_wsk_copy(wsk_man);
	printf("Name: %s , Age: %d Height: %1.2lf\n",  sone.name , wsk_man->age, wsk_man->height);
	printf("\n");

	printf("fun_struct_wsk_inout:  ");
	fun_struct_wsk_inout(wsk_man);
	printf("Name: %s , Age: %d Height: %1.2lf\n",sone.name , wsk_man->age, wsk_man->height);

	struct inextra inobiekt = {1,2};
	struct extra obiekt = { {1,2,3} , inobiekt } ;

	printf("TAB: %d , A: %d B: %d", obiekt.tab[1] , inobiekt.a , inobiekt.a);
	
}


void fun_struct(struct Man whoever)
	{
		(whoever).age++;

		printf("Name: %s , Age: %d Height: %1.2lf\n",whoever.name, whoever.age, whoever.height);
	}

void fun_struct_wsk(struct Man* whoever)
	{
		whoever->age+=2;

		printf("Name: %s , Age: %d Height: %1.2lf\n", (*whoever).name, (*whoever).age, (*whoever).height);
	}

struct Man fun_struct_out(struct Man whoever)
	{
		whoever.height+=0.4;

		printf("Name: %s , Age: %d Height: %1.2lf\n",whoever.name, whoever.age, whoever.height);

	return whoever;
	}

struct Man fun_struct_wsk_copy(struct Man* whoever)
	{
		struct Man temp = (*whoever);
		temp.height-=0.3;
		temp.age--;

		printf("Name: %s , Age: %d Height: %1.2lf\n", temp.name, temp.age, temp.height);

	return temp;
	}

void fun_struct_wsk_inout(struct Man* whoever)
	{
		struct Man temp = (*whoever);

		temp.age=+100;
		printf("Name: %s , Age: %d Height: %1.2lf\n",temp.name, temp.age, temp.height);

		temp = (*whoever);
	
	}




