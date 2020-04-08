#pragma once
#include <iostream>
using namespace std;

class Car {
private:
	char* name;
	char* number;
	char* status;
public:
	Car();
	Car(const char*, const char*, const char*);
	Car(const Car&);
	bool operator==(const Car&);
	char* getName();
	char* getNumber();
	char* getStatus();
	void setName(const char*);
	void setNumber(const char*);
	void setStatus(const char*);
	Car& operator=(const Car&);
	~Car();
	friend ostream& operator <<(ostream& os, Car aCar);
};