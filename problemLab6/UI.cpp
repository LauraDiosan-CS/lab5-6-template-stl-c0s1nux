#include <iostream>
#include "UI.h"
#include <Windows.h>

using namespace std;

UI::UI() {
}

void UI::showMenu() {
	cout << "-------------------------------------------------------------\n";
	cout << "1. Add car.\n";
	cout << "2. Remove car.\n";
	cout << "3. Update car.\n";
	cout << "4. Show all cars.\n";
	cout << "5. Exit.\n";
}

void UI::addCar() {
	char* name = new char[20];
	char* number = new char[20];
	char* status = new char[20];
	cout << "-------------------------------------------------------------\n";
	cout << "Dati numele proprietarului masinii: ";
	cin >> name;
	cout << "Dati numarul de inmatriculare al masinii: ";
	cin >> number;
	cout << "Dati status-ul locului de parcare ( liber/ocupat ): ";
	cin >> status;
	bool wasAdded = service.addCar(name, number, status);
	delete[]name;
	delete[]number;
	delete[]status;
	if (wasAdded == true)
	{
		cout << "-------------------------------------------------------------\n";
		cout << "Ai adaugat cu succes masina!\n";
		cout << "-------------------------------------------------------------\n";
	}
	else
	{
		cout << "-------------------------------------------------------------\n";
		cout << "Masina ta NU a fost adaugata!\n";
		cout << "-------------------------------------------------------------\n";
	}
	Sleep(3000);
	system("CLS");
}

void UI::removeCar() {
	char* name = new char[20];
	char* number = new char[20];
	char* status = new char[20];
	cout << "-------------------------------------------------------------\n";
	cout << "Dati numele detinatorului masinii pe care vreti sa o stergeti: ";
	cin >> name;
	cout << "Dati numarul de inmatriculare al masinii pe care vreti sa o stergeti: ";
	cin >> number;
	cout << "Dati status-ul locului de parcare ( liber/ocupat ): ";
	cin >> status;
	bool wasRemoved = service.removeCar(name, number, status);
	delete[]name;
	delete[]number;
	delete[]status;
	if (wasRemoved == true) {
		cout << "-------------------------------------------------------------\n";
		cout << "Masina a fost stearsa cu succes!\n";
		cout << "-------------------------------------------------------------\n";
	}
	else {
		cout << "-------------------------------------------------------------\n";
		cout << "Masina NU a fost gasita si NU a fost stearsa!\n";
		cout << "-------------------------------------------------------------\n";
	}
	Sleep(3000);
	system("CLS");
}

void UI::updateCar() {
	char* name = new char[20];
	char* number = new char[20];
	char* status = new char[20];
	cout << "-------------------------------------------------------------\n";
	cout << "Dati numele detinatorului masinii pe care vreti sa o updatati: ";
	cin >> name;
	cout << "Dati numarul de inmatriculare al masinii pe care vreti sa o updatati: ";
	cin >> number;
	cout << "Dati status-ul locului de parcare ( liber/ocupat ): ";
	cin >> status;
	char* newName = new char[20];
	char* newNumber = new char[20];
	char* newStatus = new char[20];
	cout << "Dati noul nume al detinatorului: ";
	cin >> newName;
	cout << "Dati noul numarul de inmatriculare al masinii: ";
	cin >> newNumber;
	cout << "Dati noul status-ul locului de parcare ( liber/ocupat ): ";
	cin >> newStatus;
	bool wasUpdated = service.updateCar(name, number, status, newName, newNumber, newStatus);
	delete[]name;
	delete[]number;
	delete[]status;
	delete[]newName;
	delete[]newNumber;
	delete[]newStatus;
	if (wasUpdated == true) {
		cout << "-------------------------------------------------------------\n";
		cout << "Masina a fost updatata cu succes!\n";
		cout << "-------------------------------------------------------------\n";
	}
	else {
		cout << "-------------------------------------------------------------\n";
		cout << "Masina NU a fost updatata cu succes!\n";
		cout << "-------------------------------------------------------------\n";
	}
	Sleep(3000);
	system("CLS");
}

void UI::showAllCars() {
	list<Car> myList = service.getAllCars();
	list<Car>::iterator it = myList.begin();
	cout << "\n-------------------------------------------------------------\n\n";
	while (it != myList.end()) {
		cout << *it;
		it++;
	}
	cout << "\n-------------------------------------------------------------\n";
	Sleep(4000);
	system("CLS");
}

void UI::runApplication() {
	int option;
	bool isRunning = true;
	while (isRunning)
	{
		showMenu();
		cout << "-------------------------------------------------------------\n";
		cout << "Optiunea pe care o aleg este: ";
		cin >> option;
		while (option > 5 || option < 1)
		{
			cout << "-------------------------------------------------------------\n";
			cout << "Alegeti o optiune valida!\n";
			cout << "Optiunea pe care o aleg este: ";
			cin >> option;
		}
		if (option == 1)
			addCar();
		else
			if (option == 2)
				removeCar();
			else
				if (option == 3)
					updateCar();
				else
					if (option == 4)
						showAllCars();
					else
						if (option == 5)
							break;
	}
}

UI::~UI() {
}