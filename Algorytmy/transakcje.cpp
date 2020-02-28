
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct transaction {
	int amount;
	string title;
	int sender;
	int reciver;
	transaction* next;
};

transaction* first = NULL;

void show() {
	transaction *temp = first;
	while (temp != NULL)
	{
		cout << temp->amount << "\n";
		cout << temp->title << "\n";
		cout << temp->reciver << "\n";
		cout << temp->sender << "\n";
		cout << endl;

		temp = temp->next;
	}
	cout << "wykonanie funkcji show" << endl;
}

void choose(transaction *&trans) {
	transaction *temp = first;
	while (temp != NULL) {


		/*
		cout << "test: ";
		cout << temp->amount;
		cout << "<";
		cout << trans->amount;
		cout << endl;
		*/


		if (temp->amount < trans->amount) {

			temp->amount = trans->amount;
			temp->title = trans->title;
			temp->reciver = trans->reciver;
			temp->sender = trans->sender;

		//	cout << "tu zmiana!" << endl;
			
			return;
		}
		temp = temp->next;
	}
}

int main()
{
	//transaction* tab = new transaction[10];


	srand(time(NULL));
	int randomize = rand() % 1000;
	for (int i = 0; i < 2; i++) {
		transaction* trans = new transaction;
		
		
		int randomize = rand() % 1000;
		trans->amount = randomize;
		trans->title = "tytul transakcji";
		trans->reciver = randomize * 1234;
		trans->sender = randomize * 1341;
		trans->next = first;
		first = trans;
	}

	show();
	cout << endl;

	for (int i = 0; i < 2; i++) {
		transaction* trans = new transaction;

		int randomize = rand() % 1000;
		trans->amount = randomize;
		trans->title = "tytul transakcji";
		trans->reciver = randomize * 1234;
		trans->sender = randomize * 1341;
		choose(trans);
	}


	show();
		




	system("pause");
}

