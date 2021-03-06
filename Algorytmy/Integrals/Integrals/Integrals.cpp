#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

double function(double x);

int main()
{
	double resultReq = 0, resultTrap = 0;
	double dx, x, x0, xN;
	int n;
	fstream file;

	file.open("dane.txt", ios::in);

	if (file.good() != true) {
		cout << "File failure!";
		exit(0);
	}

	file >> n;
	file >> x0;
	file >> xN;
	dx = (xN - x0) / n;
	double *xpts = new double[n];
	xpts[0] = x0;
	xpts[n] = xN;

	// Metoda Prostokatow
	for (int i = 1; i <= n; i++) {
		x = x0 + i * dx;
		xpts[i] = x;
		resultReq += function(x);
	}
	resultReq *= dx;
	cout << "Reqtangle Method: ";
	cout << resultReq << endl;
	// Metoda Trapezow
	for (int j = 0; j < n; j++) {
		resultTrap += (function(xpts[j]) + function(xpts[j + 1])) / 2;
	}
	resultTrap *= dx;
	cout << "Trapeze Method: ";
	cout << resultTrap;

	cin.get();
}

double function(double x) {

	double sumToreturn = 0;
	double value, a;
	int lines = 0;
	string line;
	fstream functionFile;
	functionFile.open("function.txt", ios::in);

	if (functionFile.good() != true) {
		cout << "File failure!";
		exit(0);
	}
	else {
		while (!functionFile.eof()) {
			getline(functionFile, line);
			lines++;
		}
	}
	functionFile.close();
	functionFile.open("function.txt", ios::in);

	for (int i = 0; i < lines; i++) {
		functionFile >> a;
		value = 1;
		if (i != 0) {
			for (int j = 0; j < i; j++) {
				value *= x;
			}
		}
		value *= a;
		sumToreturn += value;
	}

	return(sumToreturn);
}
