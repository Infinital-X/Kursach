#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

struct  AccountingForEquipmentComposition //Главная структура
{
	char Equipment[30];
	int NumberOfEquipment;
	int SerialNumber;
	int Price;
};
void getInfo(vector<AccountingForEquipmentComposition>& EquipmentVector, int num); //Функция выводит элемент базы данных по его номеру

void edit(vector<AccountingForEquipmentComposition >& EquipmentVector, int num) //Функция изменяет элемент базы данных по его номеру
{
	if (num >= 0 && num < EquipmentVector.size())
	{
		cout << "Before change: \n";
		getInfo(EquipmentVector, num);

		AccountingForEquipmentComposition  EquipmentElement;

		char Equipment[30];
		int NumberOfEquipment;
		int SerialNumber;
		int Price;

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
			for (int i = 0; i < EquipmentVector.size(); i++)
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