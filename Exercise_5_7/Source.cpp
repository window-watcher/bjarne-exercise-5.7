/*
	Project: Exercise 5.7
	By: Adrian Rodriguez
	Date: 8/20/20
	Objective: Create a program the solves quadratic equations. This program should be have some error handling.
	Version 1.0

	Change log
	version 1.0 :

*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }

void prompt() { cout << "Enter values for a, b, and c \n"; }
int error() { cerr << "No real roots" << endl; runtime_error; return 3; }
void print_result(double r1, double r2) {cout << "Root 1 is : " << r1 << "\n" << "Root 2 is : " << r2 << endl;}

void quadratic_equation() {
	double a = 0, b = 0, c = 0, root_1 = 0, root_2 = 0;

	prompt();
	cin >> a >> b >> c;

	double temp = pow(b, 2) - (4 * a * c);
	cout << temp <<" 4ac: " << (4 * a * c) << endl;
	if (temp < 0) { throw error(); }

	root_1 = (-b + sqrt(temp)) / (2 * a);
	root_2 = (-b - sqrt(temp)) / (2 * a);
	
	print_result(root_1, root_2);
}

int main() //C++ programs start by executing the function main
{
	try {
		quadratic_equation();
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
	keep_window_open();//wait for a character to be enter
	return 0;
}