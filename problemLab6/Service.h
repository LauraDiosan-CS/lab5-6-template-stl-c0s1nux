#pragma once
#include "repository.h"

class Service {
private:
	Repository repository;
public:
	Service();
	bool addCar(char*, char*, char*);
	bool removeCar(char*, char*, char*);
	bool updateCar(char*, char*, char*, char*, char*, char*);
	list<Car> getAllCars();
	~Service();
};