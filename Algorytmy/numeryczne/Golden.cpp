
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

double precision = 0.001;
double fi = 0.61803398;

double function(double x);

int main()
{
	double a, b, xl, xp, res;
	do {
		cout << "Range" << endl;
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	} while (a > b);
	
	//xl = b - fi * (b - a);
	//xp = a + fi * (b - a);

	while (1) {

		xl = b - fi * (b - a);
		xp = a + fi * (b - a);
		
		if (fabs(b - a) <= precision) {
			cout << "Local Minimum: " << endl;
			cout << "x: " << (a + b) / 2 << endl;
			cout << "y: " << function((a + b) / 2);
			break;
		}

		if (function(xl) < function(xp)) {
			b = xp;
			xp = xl;
			//xl = b - fi*(b - a);
		}
		else {
			a = xl;
			xl = xp;
			//xp = a + fi * (b - a);
		}
	}
	return 0;
}

double function(double x) {

	/*double sumtoreturn = 0;
	double value, a;
	fstream functionfile;
	int lines = 0;
	string line;
	functionfile.open("function.txt", ios::in);

	if (functionfile.good() != true) {
		cout << "file failure!";
		exit(0);
	}
	else {
		while (!functionfile.eof()) {
			getline(functionfile, line);
			lines++;
		}
	}
	functionfile.close();


	functionfile.open("function.txt", ios::in);

	for (int i = 0; i < lines; i++) {
		functionfile >> a;
		value = 1;
		if (i != 0) {
			for (int j = 0; j < i; j++) {
				value *= x;
			}
		}
		value *= a;
		sumtoreturn += value;
	}
	functionfile.close();
	return(sumtoreturn);*/
	//return sin(x + 4) + 10;
	return pow(2.71828182, x) + 4;
}

