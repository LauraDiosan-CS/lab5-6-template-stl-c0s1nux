#pragma once

#include <list>
#include "Car.h"

using namespace std;

template <class T>class Repository {
protected:
    list<T> elem;
public:
    Repository<T>();
    ~Repository();
    void addElem(T&);
    list<T> getAll();
    bool checkIfCarIsOk(T);
    int removeElem(T);
    bool updateElem(T, char*, char*, char*);
    bool checkIfCarIsOkForUpdate(T);
    int getSize();
    bool checkIfCarCanBeDeleted(T);
    T getCarFromAPosition(int);
};

template <class T> Repository<T>::Repository() {

}

template <class T> Repository<T>::~Repository() {

}

template <class T> void Repository<T>::addElem(T& aCar) {
	this->elem.push_back(aCar);
}

template <class T> int Repository<T>::removeElem(T aCar) {
	typename list<T>::iterator it = elem.begin();
	while (it != elem.end()) {
		if (*(it) == aCar)
		{
			if (strcmp(it->getStatus(), "liber") == 0)
			{
				elem.erase(it);
				return 1;
			}
			else
				return 2;
		}
		it++;
	}
	return 3;
}

template <class T> bool Repository<T>::updateElem(T aCar, char* newName, char* newNumber, char* newStatus) {
	typename list<T>::iterator it = elem.begin();
	bool wasUpdated;
	while (it != elem.end()) {
		if (*(it) == aCar)
		{
			T newCar(newName, newNumber, newStatus);
			if (checkIfCarIsOkForUpdate(newCar) == true)
			{
				(*it) = newCar;
				if (checkIfCarIsOkForUpdate(newCar) == true)
				{
					wasUpdated = true;
					break;
				}
				else
				{
					(*it) = aCar;
					wasUpdated = false;
				}
			}
			else
				wasUpdated = false;
		}
		else
			wasUpdated = false;
		it++;
	}
	return wasUpdated;
}

template <class T> list<T> Repository<T>::getAll() {
	return elem;
}

template <class T> bool Repository<T>::checkIfCarIsOk(T aCar) {
	typename list<T>::iterator it = elem.begin();
	bool carOk = true;
	while (it != elem.end()) {
		if (strcmp(it->getNumber(), aCar.getNumber()) == 0)
			carOk = false;
		if ((strcmp(aCar.getStatus(), "liber") != 0) and (strcmp(aCar.getStatus(), "ocupat") != 0))
			carOk = false;
		it++;
	}
	return carOk;
}

template <class T> bool Repository<T>::checkIfCarIsOkForUpdate(T aCar) {
	typename list<T>::iterator it = elem.begin();
	bool carOk = true;
	int counter = -1;
	while (it != elem.end()) {
		if (strcmp(it->getNumber(), aCar.getNumber()) == 0)
			counter += 1;
		if ((strcmp(aCar.getStatus(), "liber") != 0) and (strcmp(aCar.getStatus(), "ocupat") != 0))
			carOk = false;
		it++;
	}
	if (counter != -1 and counter != 0)
		carOk = false;
	return carOk;
}

template <class T> bool Repository<T>::checkIfCarCanBeDeleted(T car1) {
	if (strcmp(car1.getStatus(), "liber") == 0)
		return true;
	else
		return false;
}

template <class T> T Repository<T>::getCarFromAPosition(int position) {
	typename list<T>::iterator it;
	int index = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (index == position)
			return *(it);
		index++;

	}
}

template <class T> int Repository<T>::getSize() {
	return elem.size();
}