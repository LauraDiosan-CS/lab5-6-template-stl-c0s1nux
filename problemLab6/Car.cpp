#include "Car.h"
#include <iostream>
#include <cstring>

using namespace std;

Car::Car() {
	name = NULL;
	number = NULL;
	status = NULL;
}

Car::Car(const Car& aCar) {
	this->name = new char[strlen(aCar.name) + 1];
	strcpy_s(this->name, strlen(aCar.name) + 1, aCar.name);
	this->number = new char[strlen(aCar.number) + 1];
	strcpy_s(this->number, strlen(aCar.number) + 1, aCar.number);
	this->status = new char[strlen(aCar.status) + 1];
	strcpy_s(this->status, strlen(aCar.status) + 1, aCar.status);
}

Car::Car(const char* name, const char* number, const char* status) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->number = new char[strlen(number) + 1];
	strcpy_s(this->number, strlen(number) + 1, number);
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

bool Car::operator==(const Car& aCar) {
	return (strcmp(name, aCar.name) == 0) and (strcmp(number, aCar.number) == 0) and (strcmp(status, aCar.status) == 0);
}

char* Car::getName() {
	return name;
}

char* Car::getNumber() {
	return number;
}

char* Car::getStatus() {
	return status;
}

Car::~Car() {
	if (name) {
		delete[] name;
		name = NULL;
	}

	if (number) {
		delete[] number;
		number = NULL;
	}

	if (status) {
		delete[] status;
		status = NULL;
	}
}

void Car::setName(char* aName) {
	if (name) delete[]name;
	name = new char[strlen(aName) + 1];
	strcpy_s(name, strlen(aName) + 1, aName);
}

void Car::setNumber(char* aNumber) {
	if (number) delete[]number;
	number = new char[strlen(aNumber) + 1];
	strcpy_s(number, strlen(aNumber) + 1, aNumber);
}

void Car::setStatus(char* aStatus) {
	if (status) delete[]status;
	status = new char[strlen(aStatus) + 1];
	strcpy_s(status, strlen(aStatus) + 1, aStatus);
}

Car& Car::operator=(const Car& aCar) {
	if (this == &aCar) return *this;
	if (name) delete[] name;
	name = new char[strlen(aCar.name) + 1];
	strcpy_s(name, strlen(aCar.name) + 1, aCar.name);
	if (number) delete[] number;
	number = new char[strlen(aCar.number) + 1];
	strcpy_s(number, strlen(aCar.number) + 1, aCar.number);
	if (status) delete[] status;
	status = new char[strlen(aCar.status) + 1];
	strcpy_s(status, strlen(aCar.status) + 1, aCar.status);
	return *this;
}