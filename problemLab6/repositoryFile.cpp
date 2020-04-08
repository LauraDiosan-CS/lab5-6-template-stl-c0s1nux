#include "repositoryFile.h"
#include <fstream>
#include <string>
using namespace std;

RepositoryFile::RepositoryFile():Repository()
{
	fis = "";
}

RepositoryFile::RepositoryFile(const char* fileName) : Repository()
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* name = new char[10];
	char* number = new char[10];
	char* status = new char[10];
	while (!f.eof()) {
		f >> name >> number >> status;
		if (name != "" && number!= "" && (status == "liber" || status=="ocupat")) {
			Car car1(name, number, status);
			elem.push_back(car1);
		}
	}
	delete[] name;
	delete[] number;
	delete[] status;
	f.close();
}

void RepositoryFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* name = new char[10];
	char* number = new char[10];
	char* status = new char[10];
	while (!f.eof()) {
		f >> name >> number >> status;
		if (name != "" && number != "" && (strcmp("liber", status) == 0  || strcmp("ocupat", status) == 0 )) {
			Car car1(name, number, status);
			elem.push_back(car1);
		}
	}
	delete[] name;
	delete[] number;
	delete[] status;
	f.close();
}

/*bool RepositoryFile::updateElem(Car car1,  char* newName, char* newNumber, char* newStatus)
{
	return repository.updateElem(car1, newName, newNumber, newStatus);
}



bool RepositoryFile::removeElem(Car car1)
{
	return repository.removeElem(car1);
}

list<Car>RepositoryFile::getAll() {
	return repository.getAll();
}


bool RepositoryFile::checkIfCarIsOk(Car aCar) {
	return repository.checkIfCarIsOk(aCar);
}*/

RepositoryFile::~RepositoryFile()
{

}


void RepositoryFile::saveToFile()
{
	ofstream f(fis);
	for (int index = 0; index < elem.size(); index++)
		f << getCarFromAPosition(index).getName() << " " <<getCarFromAPosition(index).getNumber() << " "<<getCarFromAPosition(index).getStatus() << "\n";
	f.close();
}