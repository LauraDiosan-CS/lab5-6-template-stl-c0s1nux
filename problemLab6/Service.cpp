#include "Service.h"
#include <iostream>

using namespace std;

Service::Service() {
	currentParkingLotSize = 0;
	
}

Service::Service(const RepositoryFile<Car>& repo)
{
	currentParkingLotSize = 0;
	repositoryFile = repo;
}

void Service::setParkingLotSpaceSize(int size) {
	parkingLotSpaceSize = size;
}

bool Service::addCar(char* name, char* number, char* status) {
	Car newCar(name, number, status);
	bool carIsOk = repositoryFile.checkIfCarIsOk(newCar);
	if (carIsOk == true)
	{
		repositoryFile.addElem(newCar);
		repositoryFile.saveToFile();
		return true;
	}
	else
		return false;
}

int Service::removeCar(char* name, char* number, char* status) {
	Car carWeAreRemoving(name, number, status);
	int result = repositoryFile.removeElem(carWeAreRemoving);
	if (result == 1)
	{
		repositoryFile.saveToFile();
		return 1;
	}
	else
		if (result == 2)
			return 2;
		else
			if (result == 3)
				return 3;
}

bool Service::updateCar(char* oldName, char* oldNumber, char* oldStatus, char* newName, char* newNumber, char* newStatus) {
	Car carWeAreUpdating(oldName, oldNumber, oldStatus);
	bool wasUpdated = repositoryFile.updateElem(carWeAreUpdating, newName, newNumber, newStatus);
	if (wasUpdated == true)
	{
		repositoryFile.saveToFile();
		return true;
	}
	else
		return false;
}

int Service::setCurrentParkingLotSize() {
	list<Car> myList = getAllCars();
	int counter = 0;
	list<Car>::iterator it = myList.begin();
	while (it != myList.end())
	{
		if (strcmp(it->getStatus(), "ocupat") == 0)
			counter += 1;
		it++;
	}
	currentParkingLotSize = counter;
	return counter;
}

int Service::parkingSystemEnter(Car aCar) {
	if (strcmp(aCar.getStatus(), "ocupat") == 0)
		return 10;
	else
	{
		int counter = 0;
		bool carWasFound = false;
		list<Car> myList = getAllCars();
		list<Car>::iterator it = myList.begin();
		while (it != myList.end())
		{
			if (strcmp(it->getStatus(), "ocupat") == 0)
				counter += 1;
			it++;
		}
		if (counter == parkingLotSpaceSize)
			return 20;
		else
		{
			char* a = new char[10];
			strcpy_s(a, sizeof "ocupat", "ocupat");
			currentParkingLotSize += 1;
			repositoryFile.updateElem(aCar, aCar.getName(), aCar.getNumber(), a);
			repositoryFile.saveToFile();
			delete[]a;
			return 30;
		}
	}

}

int Service::parkingSystemExit(Car aCar) {
	if (strcmp(aCar.getStatus(), "liber") == 0)
		return 10;
	else {
		char* a = new char[10];
		strcpy_s(a, sizeof "liber", "liber");
		repositoryFile.updateElem(aCar, aCar.getName(), aCar.getNumber(), a);
		repositoryFile.saveToFile();
		currentParkingLotSize -= 1;
		return 20;
		delete[] a;
	}
}

int Service::currentSpaceInParkingLot() {
	list<Car> myList = getAllCars();
	int counter = 0;
	list<Car>::iterator it = myList.begin();
	while (it != myList.end())
	{
		if (strcmp(it->getStatus(), "ocupat") == 0)
			counter += 1;
		it++;
	}
	return parkingLotSpaceSize - counter;
}

list<Car> Service::getAllCars() {
	return repositoryFile.getAll();
}

Service::~Service() {
}