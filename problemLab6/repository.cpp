#include "repository.h"

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

list<Car> Repository::getAll() {
	return elem;
}
