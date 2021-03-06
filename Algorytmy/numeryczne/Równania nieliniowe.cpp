
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

//double precision = 0.1;
double precision = 0.001;
//double precision = 0.0000000001;

double function(double x);
double dfunction(double x);
int GetDegreeOfPoly();

int main()
{
	double a, b, x, resX, aBisection, bBisection, x_next;

	do {
		cout << "Range" << endl;
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	} while(!(function(a)*function(b) < 0));

	aBisection = a;
	bBisection = b;

	while (1) {
		x = (aBisection + bBisection) / 2;
		resX = function(x);
		if (resX == 0) {
			cout << "Solution Bisection: " << x;
			break;
		}
		if (fabs(aBisection - bBisection) < precision) {
			cout << "Solution Bisection: " << x;
			break;
		}
		if (function(x)*function(aBisection) < 0) {
			bBisection = x;
		}
		if (function(x)*function(bBisection) < 0) {
			aBisection = x;
		}
	}
	
	cout << endl;
	x = a;
	//x = b;
	x = 1;
	while (1) {
		if (fabs(function(x)) <= precision) {
			cout << "Solution N-R: " << x;
			break;
		}
		x_next = x - function(x) / dfunction(x);
		if (fabs(x_next - x) <= precision) {
			cout << "Solution N-R: " << x;
			break;
		}
		x = x_next;
	}

	return 0;
}

double function(double x) {
	
	double sumToreturn = 0;
	double value, a;
	fstream functionFile;
	int lines = GetDegreeOfPoly();
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
	functionFile.close();
	return(sumToreturn);
	return sin(x+1) + x;
	//return pow(2.71828182, 3*x) - 5;
}

double dfunction(double x) {
	

	double sumToreturn = 0;
	double value, a;
	fstream functionFile;
	int lines = GetDegreeOfPoly();
	functionFile.open("function.txt", ios::in);

	for (int i = 0; i < lines; i++) {
		functionFile >> a;
		if (i == 0)	a = 0;
		if (a == 0) continue;	
		a = a * i;
		value = 1;
		if (i != 0) {
			for (int j = 0; j < i-1; j++) {
				value *= x;
			}
		}
		value *= a;
		sumToreturn += value;
	}
	functionFile.close();
	return(sumToreturn);*/
	//return cos(x+1) + 1;
	//return 3*pow(2.71828182, 3 * x);
}

int GetDegreeOfPoly() {

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

	return lines;
}