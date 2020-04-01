#pragma once

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
	void setName(char*);
	void setNumber(char*);
	void setStatus(char*);
	Car& operator=(const Car&);
	~Car();
};