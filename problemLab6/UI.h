#pragma once

#include "Service.h"

class UI {
private:
	Service service;
public:
	UI();
	void showMenu();
	void addCar();
	void removeCar();
	void updateCar();
	void showAllCars();
	void runApplication();
	~UI();
};