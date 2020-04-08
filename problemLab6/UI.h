#pragma once

#include "Service.h"

class UI {
private:
	Service service;
public:
	UI();
	UI(const Service&);
	void showMenu();
	void addCar();
	void removeCar();
	void updateCar();
	void showAllCars();
	void runApplication();
	~UI();
};