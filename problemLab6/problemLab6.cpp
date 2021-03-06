#include "carTests.h"
#include <iostream>
#include "repositoryTests.h"
#include "serviceTests.h"
#include "parkingTests.h"
#include "UI.h"
#include <Windows.h>

using namespace std;

int main() {
	cout << "Testing the app!";
	Sleep(4000);
	system("CLS");
	creationCarTests();
	system("CLS");
	repositoryTests(); 
	system("CLS");
	serviceTests();
	system("CLS");
	parkingTests();
	system("CLS");
	cout << "All tests passed! ";
	Sleep(1000);
	cout<<"Running the app!\n";
	Sleep(1000);
	cout << "Clearing the screen";
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	system("CLS");
	RepositoryFile<Car> repository("fileWithCars.txt");
	Service service(repository);
	UI UI(service);
	UI.runApplication();
	return 0;
}