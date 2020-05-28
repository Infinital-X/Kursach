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

void outputAll(vector<AccountingForEquipmentComposition >& EquipmentVector) //Функция выводит все элементы базы данных
{
	ifstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
	if (!file) //Проверка открыт ли файл
		cout << "File does not open";
	else
	{
		for (int i = 0; i < EquipmentVector.size(); i++)
		{
			AccountingForEquipmentComposition  EquipmentElement;
			file.seekg(i * sizeof(AccountingForEquipmentComposition));
			file.read((char*)&EquipmentElement, sizeof(AccountingForEquipmentComposition));
			cout << "Item number " << i + 1 << endl;
			cout << "Equipment: " << EquipmentVector[i].Equipment << "\t";
			cout << "SerialNumber: " << EquipmentVector[i].SerialNumber << "\t";
			cout << "Price: " << EquipmentVector[i].Price << "\t";
			cout << "NumberOfEquipment: " << EquipmentVector[i].NumberOfEquipment << endl;
		}
	}
	file.close();
}