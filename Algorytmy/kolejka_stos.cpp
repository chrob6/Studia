
/*
#include "pch.h"
#include <iostream>

using namespace std;

struct Stack {

	int data = 0;
	Stack* below = NULL;

};



void add(int d, Stack* &t) {

	Stack* element = new Stack;
	element->data = d;
	element->below = t;
	t = element;

}

void show(Stack* top) {

	while (top != NULL) {
		cout << top->data << endl;
		top = top->below;
	}
	cout << "NULL" << endl;

}

void remove(Stack* &t) {
	Stack* temp = new Stack;
	temp = t;
	t = t->below;
	delete temp;

}


int main()
{
	Stack* top = NULL;

	show(top);
	add(2, top);
	add(3, top);
	show(top);
	remove(top);
	show(top);


	return 0;
}

*/


#include "pch.h"
#include <iostream>

using namespace std;

struct Que {
	int data;
	Que* behind;
};

void add(int d, Que* &f, Que* &l) {
	Que* ele = new Que;
	if (f == NULL ) {
		ele->data = d;
		f = ele;
		l = ele;
		ele->behind = NULL;
	}
	else {
		l->behind = ele;
		ele->data = d;
		ele->behind = NULL;
	}

}

void showw(Que* f) {

	while (f != NULL) {
		cout << f->data;
		f = f->behind;
	}

	cout << "show" << endl;
}

void rmv(Que* &f) {
	Que* temp = new Que;
	temp = f;
	f = f->behind;
	delete temp;
}




int main() {

	Que* first = NULL;
	Que* last = NULL;


	showw(first);

	add(2, first, last);
	add(3, first, last);

	showw(first);

	rmv(first);

	showw(first);


	return 0;
}