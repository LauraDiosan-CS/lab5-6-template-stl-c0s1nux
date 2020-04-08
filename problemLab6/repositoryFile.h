#pragma once
#include "repository.h"

class RepositoryFile: public Repository {
private:
	const char* fis;
public:
	RepositoryFile();
	~RepositoryFile();
	RepositoryFile(const char*);
	void loadFromFile(const char*);
	/*bool updateElem(Car, char*, char*, char*);
	bool removeElem(Car);
	list<Car>getAll();
	bool checkIfCarIsOk(Car);*/
	void saveToFile();

};