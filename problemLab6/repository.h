#pragma once

#include <list>
#include "Car.h"

using namespace std;

class Repository {
private:
    list<Car> elem;
    int size;
public:
    Repository();
    ~Repository();
    void addElem(const Car&);
    list<Car> getAll();
    bool checkIfCarIsOk(Car);
    bool removeElem(Car);
    bool updateElem(Car, char*, char*, char*);
    bool checkIfCarIsOkForUpdate(Car);
};