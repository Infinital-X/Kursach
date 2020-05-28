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

void addNew(vector<AccountingForEquipmentComposition >& EquipmentVector) //Функция которая добавляет новые элементы структуры и сохраняет их в файл
{
	AccountingForEquipmentComposition  EquipmentElement;

	char Equipment[30];
	int NumberOfEquipment;
	int SerialNumber;
	int Price;

	cout << "Equipment: ";
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

	cout << "Number of  equipment: ";
	cin >> EquipmentElement.NumberOfEquipment;

	cin.ignore();

	EquipmentVector.push_back(EquipmentElement);

	ofstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
	if (!file) //Проверка открыт ли файл
		cout << "File does not open";
	else
	{
		file.write((char*)&EquipmentElement, sizeof(AccountingForEquipmentComposition)); //Записываем данные в файл
	}
	file.close();
}