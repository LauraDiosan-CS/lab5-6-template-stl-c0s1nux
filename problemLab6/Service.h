#pragma once
#include "repositoryFile.h" 

class Service {
private:
	int parkingLotSpaceSize;
	int currentParkingLotSize;
	RepositoryFile repositoryFile;
public:
	Service();
	Service(const RepositoryFile&);
	bool addCar(char*, char*, char*);
	void setParkingLotSpaceSize(int);
	int removeCar(char*, char*, char*);
	bool updateCar(char*, char*, char*, char*, char*, char*);
	list<Car> getAllCars();
	int parkingSystemEnter(Car);
	int parkingSystemExit(Car);
	int setCurrentParkingLotSize();
	int currentSpaceInParkingLot();
	~Service();
};