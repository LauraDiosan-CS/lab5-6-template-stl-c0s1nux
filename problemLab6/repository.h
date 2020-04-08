#pragma once

#include <list>
#include "Car.h"

using namespace std;

class Repository {
protected:
    list<Car> elem;
public:
    Repository();
    ~Repository();
    void addElem(Car&);
    list<Car> getAll();
    bool checkIfCarIsOk(Car);
    bool removeElem(Car);
    bool updateElem(Car, char*, char*, char*);
    bool checkIfCarIsOkForUpdate(Car);
    void clearForFile();
    bool checkIfCarCanBeDeleted(Car);
    Car getCarFromAPosition(int);
};