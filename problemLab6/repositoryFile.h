#pragma once
#include "repository.h"

class RepositoryFile: public Repository<Car> {
private:
	const char* fis;
public:
	RepositoryFile();
	~RepositoryFile();
	RepositoryFile(const char*);
	void loadFromFile(const char*);
	void saveToFile();

};