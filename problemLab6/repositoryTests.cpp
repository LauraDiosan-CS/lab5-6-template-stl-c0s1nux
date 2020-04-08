#include "repository.h"
#include <assert.h>
#include <cstring>
#include <iostream>
#include <Windows.h>
#include <list>
using namespace std;

void repositoryTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for repository.";
	Repository repo;
	bool yo;
	Car car1("1", "2", "3");
	Car car2("4", "5", "6");
	Car car3("Alex", "BT06LNB", "ocupat");
	Car car4("AlexA", "BT06LNT", "liber");
	Car car5("yo", "BT09LBV", "yoooo");
	repo.addElem(car1);
	repo.addElem(car2);
	repo.addElem(car4);
	assert(repo.getAll().front() == car1);
	assert(repo.getAll().back() == car4);
	Sleep(1000);
	cout << ".";
	yo = repo.removeElem(car4);
	assert(repo.getAll().back() == car2);
	Sleep(1000);
	cout << ".";
	char* a = new char[10];
	char* b = new char[10];
	char* c = new char[10];
	strcpy_s(a, sizeof "yo", "yo");
	strcpy_s(b, sizeof "B09LKC", "B09LKC");
	strcpy_s(c, sizeof "liber", "liber");
	bool t = repo.updateElem(car2, a, b, c);
	delete[]a;
	delete[]b;
	delete[]c;
	assert(strcmp(repo.getAll().back().getName(), "yo") == 0);
	assert(strcmp(repo.getAll().back().getNumber(), "B09LKC") == 0);
	assert(strcmp(repo.getAll().back().getStatus(), "liber") == 0);
	assert(repo.checkIfCarIsOk(car3) == true);
	assert(repo.checkIfCarIsOk(car4) == true);
	assert(repo.checkIfCarIsOk(car5) == false);
	Sleep(1000);
	cout << ".\n";
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(1000);
}