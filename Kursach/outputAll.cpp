#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "struct.h"
using namespace std;

void outputAll(vector<AccountingForEquipmentComposition >& EquipmentVector) //Функция выводит все элементы базы данных
{
	unsigned int size2 = sizeof(AccountingForEquipmentComposition);
	ifstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
	if (!file) //Проверка открыт ли файл
		cout << "File does not open";
	else
	{
		for (unsigned int i = 0; i < EquipmentVector.size(); i++)
		{
			AccountingForEquipmentComposition  EquipmentElement;
			file.seekg((__int64)size2 * i);
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