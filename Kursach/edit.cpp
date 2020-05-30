#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "struct.h"
#include "getInfo.h"
using namespace std;

void edit(vector<AccountingForEquipmentComposition >& EquipmentVector, unsigned int num) //Функция изменяет элемент базы данных по его номеру
{
	if (num < EquipmentVector.size())
	{
		cout << "Before change: \n";
		getInfo(EquipmentVector, num);

		AccountingForEquipmentComposition  EquipmentElement;

		char Equipment[30];

		cout << endl << "Equipment: ";
		cin.getline(EquipmentElement.Equipment, sizeof(Equipment));

		while (EquipmentElement.Equipment == "")
		{
			cout << "You have not entered anything";
			cin.getline(EquipmentElement.Equipment, sizeof(Equipment));
		}

		cout << "Serial number: ";
		cin >> EquipmentElement.SerialNumber;

		cin.ignore();

		cout << "Price: ";
		cin >> EquipmentElement.Price;

		cin.ignore();

		cout << "Number of equipment: ";
		cin >> EquipmentElement.NumberOfEquipment;

		cin.ignore();

		auto iterator = EquipmentVector.begin();

		*(iterator + num) = EquipmentElement;

		ofstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
		if (!file) //Проверка открыт ли файл
			cout << "File does not open";
		else {
			for (unsigned int i = 0; i < EquipmentVector.size(); i++)
			{
				file.write((char*)&EquipmentVector[i], sizeof(AccountingForEquipmentComposition));
			}
		}
		file.close();

		cout << endl << "After change: \n";
		getInfo(EquipmentVector, num);
	}
	else cout << "Wrong number\n";
}