#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "struct.h"
using namespace std;

void getInfo(vector<AccountingForEquipmentComposition>& EquipmentVector, unsigned int num) //Функция выводит элемент базы данных по его номеру
{
	unsigned int size1 = sizeof(AccountingForEquipmentComposition);
	ifstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
	if (!file) //Проверка открыт ли файл 
		cout << "File does not open";
	else
	{
		if (num < EquipmentVector.size())
		{
			AccountingForEquipmentComposition  EquipmentElement;
			file.seekg((__int64)size1 * num); //Переход к нужному элементу в файле
			file.read((char*)&EquipmentElement, sizeof(AccountingForEquipmentComposition));
			cout << "Equipment: " << EquipmentVector[num].Equipment << endl;
			cout << "SerialNumber: " << EquipmentVector[num].SerialNumber << endl;
			cout << "Price: " << EquipmentVector[num].Price << endl;
			cout << "NumberOfEquipment: " << EquipmentVector[num].NumberOfEquipment << endl;
		}
		else cout << "Wrong number\n";
	}
	file.close();
}