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

void priceForAll(vector<AccountingForEquipmentComposition>& EquipmentVector) //Функция считает цену всего оборудования
{
	int price = 0;
	for (int i = 0; i < EquipmentVector.size(); i++)
	{
		price = EquipmentVector[i].Price * EquipmentVector[i].NumberOfEquipment;
		cout << "SerialNumber: " << EquipmentVector[i].SerialNumber << "\tPrice for all equipment: " << price << endl;
	}
}
