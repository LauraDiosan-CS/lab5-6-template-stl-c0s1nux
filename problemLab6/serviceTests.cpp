#include "Service.h"
#include <assert.h>
#include <cstring>
#include <iostream>
#include <Windows.h>
#include <list>
using namespace std;

void serviceTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for service.";
	Service serv;
	char* a = new char[10];
	char* b = new char[10];
	char* c = new char[10];
	char* d = new char[10];
	char* e = new char[10];
	char* f = new char[10];
	strcpy_s(a, sizeof "yo", "yo");
	strcpy_s(b, sizeof "B09LKC", "B09LKC");
	strcpy_s(c, sizeof "liber", "liber");
	strcpy_s(d, sizeof "test", "test");
	strcpy_s(e, sizeof "B999LUL", "B999LUL");
	strcpy_s(f, sizeof "ocupat", "ocupat");
	Car aCar("yo", "B09LKC", "liber");
	Car carAfterUpdate(d, e, f);
	bool t = serv.addCar(a, b, c);
	assert(t == true);
	assert(serv.getAllCars().size() == 3);
	assert(serv.getAllCars().back() == aCar);
	Sleep(1000);
	cout << ".";
	t = serv.updateCar(a, b, c, d, e, f);
	assert(serv.getAllCars().back() == carAfterUpdate);
	Sleep(1000);
	cout << ".";
	t = serv.removeCar(d, e, f);
	assert(serv.getAllCars().size() == 2);
	Sleep(1000);
	cout << ".\n";
	delete[]a;
	delete[]b;
	delete[]c;
	delete[]d;
	delete[]e;
	delete[]f;
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(1000);
}