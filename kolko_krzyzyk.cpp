
#include "pch.h"
#include <iostream>

using namespace std;

void Podajpole() {
	cout << "1. Prawy gorny" << endl;
	cout << "2. Gorny" << endl;
	cout << "3. Lewy gorny" << endl;
	cout << "4. Lewy srodek" << endl;
	cout << "5. srodek" << endl;
	cout << "6. Prawy srodek" << endl;
	cout << "7. Lewy Dol" << endl;
	cout << "8. Dol" << endl;
	cout << "9. Prawy dol" << endl << endl;

};

int main()
{

	int choice;
	char xoro;
	char xo[9] = { '1','2','3','4','5','6','7','8','9' };



	for (int i = 0; i < 9; i++) {
		int correct = 1;

		if (i == 0) {

			while (1) {
				cout << "kolko: o czy krzyzyk: x" << endl;
				cin >> xoro;
				if (xoro == 'x' || xoro == 'o') {
					break;
				}
			}

			cout << "  " << xo[0] << "  |  " << xo[1] << "  |  " << xo[2] << "  \n" << "_____|_____|_____\n" << "  " << xo[3] << "  |  " << xo[4] << "  |  " << xo[5] << "  \n" << "_____|_____|_____\n" << "  " << xo[6] << "  |  " << xo[7] << "  |  " << xo[8] << "\n\n";
		}

		while (correct) {

		Podajpole();
		cin >> choice;

		switch (choice) {
		case 1: if (xo[0] == '1') { xo[0] = xoro; correct = 0; }; break;
		case 2: if (xo[1] == '2') { xo[1] = xoro; correct = 0; }; break;
		case 3: if (xo[2] == '3') { xo[2] = xoro; correct = 0; }; break;
		case 4: if (xo[3] == '4') { xo[3] = xoro; correct = 0; }; break;
		case 5: if (xo[4] == '5') { xo[4] = xoro; correct = 0; }; break;
		case 6: if (xo[5] == '6') { xo[5] = xoro; correct = 0; }; break;
		case 7: if (xo[6] == '7') { xo[6] = xoro; correct = 0; }; break;
		case 8: if (xo[7] == '8') { xo[7] = xoro; correct = 0; }; break;
		case 9: if (xo[8] == '9') { xo[8] = xoro; correct = 0; }; break;
		default: cout << "zla liczba!" << endl;
		}

		cout << "  " << xo[0] << "  |  " << xo[1] << "  |  " << xo[2] << "  \n" << "_____|_____|_____\n" << "  " << xo[3] << "  |  " << xo[4] << "  |  " << xo[5] << "  \n" << "_____|_____|_____\n" << "  " << xo[6] << "  |  " << xo[7] << "  |  " << xo[8] << "\n\n";

		}

		if (xoro == 'x') {
			xoro = 'o';
		}
		else {
			xoro = 'x';
		}
	}


	return 0;
}

