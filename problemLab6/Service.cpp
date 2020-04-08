#include "Service.h"
#include <iostream>

using namespace std;

Service::Service() {
	Car car1("Alex", "BT06LNB", "liber"), car2("yo", "BT07LNB", "ocupat");
	repository.addElem(car1);
	repository.addElem(car2);
}

bool Service::addCar(char* name, char* number, char* status) {
	Car newCar(name, number, status);
	bool carIsOk = repository.checkIfCarIsOk(newCar);
	if (carIsOk == true)
	{
		repository.addElem(newCar);
		return true;
	}
	else
		return false;
}

bool Service::removeCar(char* name, char* number, char* status) {
	Car carWeAreRemoving(name, number, status);
	bool wasRemoved = repository.removeElem(carWeAreRemoving);
	if (wasRemoved == true)
		return true;
	else
		return false;
}

bool Service::updateCar(char* oldName, char* oldNumber, char* oldStatus, char* newName, char* newNumber, char* newStatus) {
	Car carWeAreUpdating(oldName, oldNumber, oldStatus);
	bool wasUpdated = repository.updateElem(carWeAreUpdating, newName, newNumber, newStatus);
	if (wasUpdated == true)
		return true;
	else
		return false;
}

list<Car> Service::getAllCars() {
	return repository.getAll();
}

Service::~Service() {
}