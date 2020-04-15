#include "Service.h"
#include <assert.h>
#include <cstring>
#include <iostream>
#include <Windows.h>
#include <list>

void parkingTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for parking system.";
	RepositoryFile<Car> repo("testCars.txt");
	Service serv(repo);
	Car aCar("Alex", "B09LKC", "liber");
	Car anotherCar("Alex", "BT09LKC", "ocupat");
	Car yetAnotherCar("Alex", "BN09LKC", "liber");
	char* ab = new char[10];
	char* bb = new char[10];
	char* cb = new char[10];
	char* db = new char[10];
	char* eb = new char[10];
	char* fb = new char[10];
	char* mb = new char[10];
	strcpy_s(ab, sizeof "Alex", "Alex");
	strcpy_s(bb, sizeof "B09LKC", "B09LKC");
	strcpy_s(cb, sizeof "BT09LKC", "BT09LKC");
	strcpy_s(db, sizeof "BN09LKC", "BN09LKC");
	strcpy_s(eb, sizeof "liber", "liber");
	strcpy_s(fb, sizeof "ocupat", "ocupat");
	strcpy_s(mb, sizeof "B999LLL", "B999LLL");
	serv.addCar(ab, bb, eb);
	repo.saveToFile();
	int xd = serv.setCurrentParkingLotSize();
	serv.addCar(ab, cb, fb);
	repo.saveToFile();
	xd = serv.setCurrentParkingLotSize();
	serv.addCar(ab, db, eb);
	Sleep(1000);
	cout << ".";
	repo.saveToFile();
	xd = serv.setCurrentParkingLotSize();
	Car oneLastCar("Alex", "B999LLL", "liber");
	serv.addCar(ab, mb, eb);
	repo.saveToFile();
	xd = serv.setCurrentParkingLotSize();
	serv.setParkingLotSpaceSize(3);
	int a = serv.parkingSystemEnter(aCar);
	assert(a == 30);
	a = serv.parkingSystemEnter(anotherCar);
	assert(a == 10);
	a = serv.parkingSystemEnter(yetAnotherCar);
	assert(a == 30);
	Sleep(1000);
	cout << ".";
	a = serv.parkingSystemEnter(oneLastCar);
	assert(a == 20);
	Car aCarAfterModification(ab, bb, fb);
	Car anotherCarAfterModification(ab, cb, fb);
	Car yetAnotherCarAfterModification(ab, db, fb); 
	a = serv.parkingSystemExit(aCarAfterModification);
	assert(a == 20);
	assert(serv.currentSpaceInParkingLot() == 1);
	a = serv.parkingSystemExit(anotherCarAfterModification);
	assert(a == 20);
	Sleep(1000);
	cout << ".";
	assert(serv.currentSpaceInParkingLot() == 2);
	a = serv.parkingSystemExit(yetAnotherCarAfterModification);
	assert(a == 20);
	assert(serv.currentSpaceInParkingLot() == 3);
	serv.removeCar(ab, bb, eb);
	serv.removeCar(ab, cb, eb);
	serv.removeCar(ab, db, eb);
	serv.removeCar(ab, mb, eb);
	Sleep(1000);
	cout << ".";
	delete[]ab;
	delete[]bb;
	delete[]cb;
	delete[]db;
	delete[]eb;
	delete[]fb;
	delete[]mb;
	cout << "\nSuccess!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(1000);
}