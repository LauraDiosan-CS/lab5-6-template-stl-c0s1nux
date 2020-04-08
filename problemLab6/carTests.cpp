#include <iostream>
#include <assert.h>
#include "Car.h"
#include <Windows.h>
using namespace std;

void creationCarTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for creation of cars.";
	Car car1("xd", "xdd", "xddd");
	Car car2;
	char* a = new char[10];
	strcpy_s(a, sizeof "xd", "xd");
	assert(strcmp(car1.getName(), a) == 0);
	char* b = new char[10];
	strcpy_s(b, sizeof "xdd", "xdd");
	Sleep(1000);
	cout << ".";
	assert(strcmp(car1.getNumber(), b) == 0);
	char* c = new char[10];
	strcpy_s(c, sizeof "xddd", "xddd");
	assert(strcmp(car1.getStatus(), c) == 0);
	Sleep(1000);
	cout << ".";
	delete[]a;
	a = NULL;
	delete[]b;
	b = NULL;
	delete[]c;
	c = NULL;
	car2 = car1;
	assert(car2 == car1);
	Sleep(1000);
	cout << ".\n";
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(1000);
}