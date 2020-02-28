
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


struct footballer {
	string name;
	string date;
	string club;
	string nationality;
	int times;
	footballer* next;
};


footballer* byNat(string n,footballer* f) {

		footballer* Nat = new footballer;
		Nat = NULL;

		footballer *temp = f;
		while (temp != NULL)
		{
			footballer* temp2 = new footballer;
			if (temp->nationality == (" " +n) ) {

				temp2->name = temp->name;
				temp2->date = temp->date;
				temp2->club = temp->club;
				temp2->next = Nat;
				Nat = temp2;
				//cout << Nat->name  + ", " + Nat->date + ", " + Nat->club << endl;
			}

			temp = temp->next;
		}

		return Nat;
}

footballer* clubList(footballer* f) {
	
	string clubs[50];

	footballer* ClubList = new footballer;
	ClubList = NULL;
	footballer* temp = f;
	int times = 0;
	int i = 0;
	
 
	while (temp != NULL) {
		bool access = true;
		string club = temp->club;

		for (int j = 0; j <= i; j++) {

			if (clubs[j] == club) {
				access = false;
			}

		}
		
		if (access) {
			
			footballer* temp2 = temp;
			times = 0;
			footballer* tempClub = new footballer;

			while (temp2 != NULL) {

				if (club == temp2->club) {
					times++;
				}
				temp2 = temp2->next;

			}

			tempClub->times = times;
			tempClub->club = club;

			tempClub->next = ClubList;
			ClubList = tempClub;
			//	cout << ClubList->club << ClubList->times << endl;

			
		}
		temp = temp->next;
		clubs[i] = club;
		i++;
	}	

	return ClubList;
}

void showNat(footballer* f) {

		footballer *temp = f;
		while (temp != NULL)
		{
			cout << temp->name  +' '+  temp->date + temp->club << "\n";
			temp = temp->next;
		}
}


void showCL(footballer* f) {


	footballer *temp = f;
	while (temp != NULL)
	{
		cout << temp->times;
		cout << temp->club << endl;

		temp = temp->next;
	}

}


string ByYear(string y, footballer* f) {

	string res;
	string preresult;
	footballer *temp = f;
	while (temp != NULL) {

		if (temp->date == (" "+y)) {

			 res = temp->name.erase(0, temp->name.find(" ")+1) + temp->club;
		}
		temp = temp->next;
	}
	return res;
	
}


int main() {

	ifstream file("data3.txt");

	if (!file) {
		cout << "problem z plikiem";
	}
	string line;

	footballer* first = new footballer;
	first = NULL;
	

	while (!file.eof()) {

		footballer* temp = new footballer;
		getline(file, line, ',' );
		temp->name = line;
		getline(file, line, ',');
		temp->date = line;
		getline(file, line, ',');
		temp->club = line;
		getline(file, line, '\n');
		temp->nationality = line;
		//cout << temp->name << endl;
		//cout<< temp->date << endl;
		//cout<< temp->club << endl;
		//cout<< temp->nationality << endl;
		temp->next = first;
		first = temp;
	}

	

	cout << "Zadanie 1 - pokazanie zawodniow z Anglii" << endl;
	footballer* eng = byNat("England",first);
	showNat(eng);
	cout << endl;
	cout << endl;

	cout << "Zadanie 2 - spis klubow z iloscia laureatow" << endl;
	footballer* clublist = clubList(first);
	showCL(clublist);
	cout << endl;
	cout << endl;

	cout << "Zadanie 3 - zwrocenie po dacie, nazwiska oraz klubu laureata" << endl;
	cout << ByYear("1975", first);
	cout << ByYear("1959", first);
	




	cin.get();


};

