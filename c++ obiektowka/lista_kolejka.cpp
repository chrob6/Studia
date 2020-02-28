#include <iostream>

using namespace std;



struct element {
	int value;
	element* next;
	int prio;
};



class List {

public:
	element* head;

	List() {
		head = NULL;
	}



	void show() {
		element *temp = head;
		while (temp != NULL)
		{
			cout << temp->value << "\n";
			
			temp = temp->next;
		}
		cout << "wykonanie funkcji show" << endl;
	}


	void add(int value) {
		element* temp = new element;
		temp->value = value;
		temp->next = head;
		head = temp;
	}


	void remove() {
		element* temp = head;
		if (temp) {
			head = temp->next;
			delete temp;
		}
	}


private:
	
	void removePos(int x)                                                   
	{
		element * p = head;
		element *temp = head;
		int i = 1;

		while (temp)
		{
			if (i == x) break;
			temp = temp->next;
			i++;
		}

		if (head == temp)
		{
			head = temp->next;
			delete temp;
		}

		else
		{
			while (p->next != temp) p = p->next;
			p->next = temp->next;
			delete temp;
		}
	}
};


class Stack : public List {

public:
	


};

class Queue : public List {

public:

	void addQue(int value)                                                
	{

		element *temp = new element;
		element *p = head;
		
		temp->next = NULL;
		temp->value = value;

		if (p)
		{
			while (p->next) 
				p = p->next;  
			p->next = temp;

		}
		else head = temp;
	}

};

class PQ : public List {

public:
	element* tail;

	PQ() {
		tail = NULL;
	}

	void addPQ(int value, int prio)
	{
		element *e = new element;
		e->next = NULL;
		e->value = value;
		e->prio = prio;

		if (!head) head = e;
		else if (head->prio < prio)         
		{
			e->next = head;					
			head = e;
		}
		else
		{
			element *r = head;
			while ((r->next) && (r->next->prio >= prio))		
				r = r->next;										
			e->next = r->next;
			r->next = e;
			if (!e->next) tail = e;                                
		}
	}

};



int main() {
	PQ pq;

	pq.addPQ(5, 1);
	pq.addPQ(1, 5);
	pq.addPQ(3, 3);
	pq.addPQ(2, 2);
	pq.show();
	pq.remove();
	pq.show();
	



	cin.get();





	return 0;
}