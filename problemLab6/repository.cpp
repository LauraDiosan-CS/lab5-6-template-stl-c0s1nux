#include "repository.h"
#include "Car.h"
#include <iterator>
using namespace std;

Repository::Repository() {
	this->size = 100;
}

Repository::~Repository() {
	this->size = 0;
}

void Repository::addElem(const Car& aCar) {
	this->elem.push_back(aCar);
}

bool Repository::removeElem(Car aCar) {
	list<Car>::iterator it = elem.begin();
	while (it != elem.end()) {
		if (*(it) == aCar)
		{
			elem.erase(it);
			return true;
		}
		it++;
	}
	return false;
}

bool Repository::updateElem(Car aCar, char* newName, char* newNumber, char* newStatus) {
	list<Car>::iterator it = elem.begin();
	bool wasUpdated;
	while (it != elem.end()) {
		if (*(it) == aCar)
		{
			Car newCar(newName, newNumber, newStatus);
			if (checkIfCarIsOkForUpdate(newCar) == true)
			{
				(*it) = newCar;
				if (checkIfCarIsOkForUpdate(newCar) == true)
				{
					wasUpdated = true;
					break;
				}
				else
				{
					(*it) = aCar;
					wasUpdated = false;
				}
			}
			else
				wasUpdated = false;
		}
		else
			wasUpdated = false;
		it++;
	}
	return wasUpdated;
}

list<Car> Repository::getAll() {
	return elem;
}

bool Repository::checkIfCarIsOk(Car aCar) {
	list<Car>::iterator it = elem.begin();
	bool carOk = true;
	while (it != elem.end()) {
		if (strcmp(it->getNumber(), aCar.getNumber()) == 0)
			carOk = false;
		if ((strcmp(aCar.getStatus(), "liber") != 0) and (strcmp(aCar.getStatus(), "ocupat") != 0))
			carOk = false;
		it++;
	}
	return carOk;
}

bool Repository::checkIfCarIsOkForUpdate(Car aCar) {
	list<Car>::iterator it = elem.begin();
	bool carOk = true;
	int counter = -1;
	while (it != elem.end()) {
		if (strcmp(it->getNumber(), aCar.getNumber()) == 0)
			counter += 1;
		if ((strcmp(aCar.getStatus(), "liber") != 0) and (strcmp(aCar.getStatus(), "ocupat") != 0))
			carOk = false;
		it++;
	}
	if (counter != -1 and counter != 0)
		carOk = false;
	return carOk;
}
