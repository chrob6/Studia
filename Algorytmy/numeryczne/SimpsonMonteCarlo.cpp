#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

double function(double x);

int main()
{
	srand(time(NULL));
	double resSim, resMC;
	double preResSim = 0, preResMC = 0;
	double dx, x, x0, xN, rest, rest2, rest3;
	int n, preX;
	bool twoORfour = true; // true= 4, false = 2;
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
	
	// Metoda Simpsona
	for (int i = 1; i < n; i++) {
		x = x0 + i * dx;
		if (twoORfour) {
			preResSim += 4 * function(x);
			twoORfour = false;
		}
		else {
			preResSim += 2 * function(x);
			twoORfour = true;
		}
	}
	resSim = (dx / 3)*(function(x0) + preResSim + function(xN));
	cout << "Simpson Method: "; 
	cout << resSim << endl;
	
	// Metoda Monte Carlo
	for (int i = 0 ; i < n; i++) {
		do {
			preX = ((rand() % int(xN-x0)) + x0);
		} while (preX == xN);

		rest = (rand() % 100);
		rest2 = (rand() % 100);
		rest3 = (rand() % 100);
		x = (double)preX + (rest*0.01) + (rest2*0.001) + (rest*0.0001);
		preResMC += (function(x)/n);
	}
	
	resMC = preResMC * (xN - x0);
	cout << "Monte Casino Method: ";
	cout << resMC;

	cin.get();
}

double function(double x) {
	/*
	//dla funkcji wielomianowej
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

	return(sumToreturn);*/ 
	return sin(x);
	//return (1 / x);
	//return (x*x*x + 2);
}
