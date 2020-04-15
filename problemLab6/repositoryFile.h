#pragma once
#include "repository.h"
#include <fstream>

template <class T>class RepositoryFile: public Repository<T> {
protected:
	const char* fis;
public:
	RepositoryFile<T>();
	~RepositoryFile();
	RepositoryFile<T>(const char*);
	void loadFromFile(const char*);
	void saveToFile();

};

template <class T> RepositoryFile<T>::RepositoryFile() :Repository<T>()
{
	fis = "";
}

template <class T> RepositoryFile<T>::RepositoryFile(const char* fileName) : Repository<T>()
{
	this->elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* name = new char[10];
	char* number = new char[10];
	char* status = new char[10];
	while (!f.eof()) {
		f >> name >> number >> status;
		if (name != "" && number != "" && (strcmp(status, "liber") == 0 || strcmp(status, "ocupat") == 0)) {
			T car1(name, number, status);
			this->elem.push_back(car1);
		}
	}
	delete[] name;
	delete[] number;
	delete[] status;
	f.close();
}

template <class T> void RepositoryFile<T>::loadFromFile(const char* fileName)
{
	this->elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* name = new char[10];
	char* number = new char[10];
	char* status = new char[10];
	while (!f.eof()) {
		f >> name >> number >> status;
		if (name != "" && number != "" && (strcmp("liber", status) == 0 || strcmp("ocupat", status) == 0)) {
			T car1(name, number, status);
			this->elem.push_back(car1);
		}
	}
	delete[] name;
	delete[] number;
	delete[] status;
	f.close();
}

template <class T>RepositoryFile<T>::~RepositoryFile()
{

}


template <class T> void RepositoryFile<T>::saveToFile()
{
	ofstream f(fis);
	for (int index = 0; index < this->elem.size(); index++)
		f << this->getCarFromAPosition(index).getName() << " " << this->getCarFromAPosition(index).getNumber() << " " << this->getCarFromAPosition(index).getStatus() << "\n";
	f.close();
}