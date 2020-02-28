#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// utworzenie losowego grafu, podanie stopnia danego wieszcholka
// nastepnie przejscia grafu wglab i wrzesz rozpoczynajac od wieszcholkow 0,1,2

struct list
{
	list* next;
	int v;
};

int w;
list ** Tab;
bool * visitedDFS;
bool * visitedBFS;

void DFS(int v)
{
	list * temp;

	visitedDFS[v] = true;     // mark visited node
	cout << setw(3) << v;  

  // rekurencja

	for (temp = Tab[v]; temp; temp = temp->next) {
		if (!visitedDFS[temp->v]) {
			DFS(temp->v);
		}
	}
		
}

void BFS(int v)
{
	list *p, *q, *head, *tail; 

	q = new list;   
	q->next = NULL;
	q->v = v;
	head = tail = q;

	visitedBFS[v] = true; 

	while (head)
	{
		v = head->v;        

		q = head;           // usuwanie odczytanych
		head = head->next;
		if (!head) {
			tail = NULL;
		}
		delete q;

		cout << setw(3) << v;

		for (p = Tab[v]; p; p = p->next)
			if (!visitedBFS[p->v])
			{
				q = new list; // nieodwiedzeni
				q->next = NULL;
				q->v = p->v;

				if (!tail) {
					head = q;
				}
				else {
					tail->next = q;
				}
				tail = q;
				visitedBFS[p->v] = true;
			}
	}
}



int main()
{
	int i, w1, w2, k, stp;
	list * p, *r;

	srand(time(NULL));
	w = 7;
	k = 7;

	Tab = new list *[w];      
	visitedDFS = new bool[w];
	visitedBFS = new bool[w];
		
		//tablica list sasiedztwa

	for (i = 0; i < w; i++) {
		Tab[i] = NULL;
		visitedDFS[i] = false;
		visitedBFS[i] = false;
	}


	for (i = 0; i < k; i++)
	{
		int w1 = rand() % 7;
		int w2 = rand() % 7;
		//cout << "w1: " << w1 << endl;
		//cout << "w2: " << w2 << endl << endl;


		p = new list;
		p->v = w2;
		p->next = Tab[w1];                                                   //dodawanie na poczatek 
		Tab[w1] = p;
	}
	cout << endl;

	for (i = 0; i < w; i++)
	{
		cout << "LIST [ " << i << " ] =";
		stp = 0;
		p = Tab[i];
		while (p)
		{
			cout << setw(3) << p->v;
			p = p->next;
			stp++;
		}
		cout << "               Stp: " << stp << endl;
	}

	cout << endl;
	cout << "Wglab: " << endl;
	cout << "Od 0:";
	DFS(0);
	cout << endl;
	cout << "Od 1:";
	DFS(1);
	cout << endl;
	cout << "Od 2:";
	DFS(2);
	cout << endl;

	cout << "Wrzesz: " << endl;
	cout << "Od 0:";
	BFS(0);
	cout << endl;
	cout << "Od 1:";
	BFS(1);
	cout << endl;
	cout << "Od 2:";
	BFS(2);


	// Usuwamy tablicê list s¹siedztwa

	for (i = 0; i < w; i++)
	{
		p = Tab[i];
		while (p)
		{
			r = p;
			p = p->next;
			delete r;
		}
	}
	delete[] Tab;
	delete[] visitedDFS;
	delete[] visitedBFS;

	cout << endl;
	
	
	cin.get();
}