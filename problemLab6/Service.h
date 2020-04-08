#pragma once
#include "repositoryFile.h" 

class Service {
private:
	int parkingSpace;
	RepositoryFile repositoryFile;
public:
	Service();
	Service(const RepositoryFile&);
	bool addCar(char*, char*, char*);
	void setParkngSize(int);
	bool removeCar(char*, char*, char*);
	bool updateCar(char*, char*, char*, char*, char*, char*);
	list<Car> getAllCars();
	~Service();
};