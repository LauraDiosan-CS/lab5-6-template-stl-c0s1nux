#include "repositoryFile.h"
#include <fstream>
#include <string>
using namespace std;

RepositoryFile::RepositoryFile():Repository<Car>()
{
	fis = "";
}

RepositoryFile::RepositoryFile(const char* fileName) : Repository<Car>()
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* name = new char[10];
	char* number = new char[10];
	char* status = new char[10];
	while (!f.eof()) {
		f >> name >> number >> status;
		if (name != "" && number!= "" && (strcmp(status, "liber") == 0 || strcmp(status, "ocupat")==0)) {
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