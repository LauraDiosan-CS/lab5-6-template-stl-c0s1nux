#include "repository.h"
#include <assert.h>
#include <iostream>
#include <list>
using namespace std;

void repositoryTests() {
	cout << "Beginning tests adding to the repository...\n";
	Repository repo;
	Car car1("1", "2", "3");
	Car car2("4", "5", "6");
	repo.addElem(car1);
	repo.addElem(car2);
	assert(repo.getAll().front() == car1);
	assert(repo.getAll().back() == car2);
	cout << "Success!";
	cout << "-------------------------------------------------------------\n";
}