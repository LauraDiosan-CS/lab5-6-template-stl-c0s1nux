#include "Service.h"
#include <iostream>

using namespace std;

Service::Service() {

}

Service::Service(const RepositoryFile& repo)
{
	repositoryFile = repo;
}

void Service::setParkngSize(int number) {
	parkingSpace = number;
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

bool Service::removeCar(char* name, char* number, char* status) {
	Car carWeAreRemoving(name, number, status);
	bool wasRemoved = repositoryFile.removeElem(carWeAreRemoving);
	if (wasRemoved == true)
		return true;
	else
		return false;
}

bool Service::updateCar(char* oldName, char* oldNumber, char* oldStatus, char* newName, char* newNumber, char* newStatus) {
	Car carWeAreUpdating(oldName, oldNumber, oldStatus);
	bool wasUpdated = repositoryFile.updateElem(carWeAreUpdating, newName, newNumber, newStatus);
	if (wasUpdated == true)
		return true;
	else
		return false;
}

list<Car> Service::getAllCars() {
	return repositoryFile.getAll();
}

Service::~Service() {
}