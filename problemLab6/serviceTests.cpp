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
	RepositoryFile repo("testCars.txt");
	Service serv(repo);
	char* a = new char[10];
	char* b = new char[10];
	char* c = new char[10];
	char* d = new char[10];
	char* e = new char[10];
	char* f = new char[10];
	strcpy_s(a, sizeof "yo", "yo");
	strcpy_s(b, sizeof "BT09LKC", "BT09LKC");
	strcpy_s(c, sizeof "ocupat", "ocupat");
	strcpy_s(d, sizeof "test", "test");
	strcpy_s(e, sizeof "B999LUL", "B999LUL");
	strcpy_s(f, sizeof "liber", "liber");
	Car aCar("yo", "BT09LKC", "ocupat");
	Car carAfterUpdate(d, e, f);
	bool t = serv.addCar(a, b, c);
	repo.saveToFile();
	assert(t == true);
	assert(serv.getAllCars().size() == 2);
	assert(serv.getAllCars().back() == aCar);
	Sleep(1000);
	cout << ".";
	t = serv.updateCar(a, b, c, d, e, f);
	repo.saveToFile();
	assert(serv.getAllCars().back() == carAfterUpdate);
	Sleep(1000);
	cout << ".";
	int s = serv.removeCar(d, e, f);
	repo.saveToFile();
	assert(serv.getAllCars().size() == 1);
	Sleep(1000);
	cout << ".\n";
	delete[]a;
	delete[]b;
	delete[]c;
	delete[]d;
	delete[]e;
	delete[]f;
	char* o = new char[10];
	char* p = new char[10];
	char* q = new char[10];
	strcpy_s(o, sizeof "yo", "yo");
	strcpy_s(p, sizeof "B09LKC", "B09LKC");
	strcpy_s(q, sizeof "liber", "liber");
	s = serv.removeCar(o, p, q);
	delete[]o;
	delete[]p;
	delete[]q;
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(1000);
}