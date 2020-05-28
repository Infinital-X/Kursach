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

void search(vector<AccountingForEquipmentComposition>& EquipmentVector) //Функция выводит название элемента по его серийному номеру
{
	int num;
	bool found = false;
	cout << "Enter serial number: ";
	cin >> num;
	for (int i = 0; i < EquipmentVector.size(); i++)
	{
		if (num == EquipmentVector[i].SerialNumber)
		{
			found = true;
			break;
		}
	}
	if (found == true)
	{
		for (int i = 0; i < EquipmentVector.size(); i++)
		{
			if (num == EquipmentVector[i].SerialNumber)
			{
				cout << endl << "Equipment: " << EquipmentVector[i].Equipment << endl;
				cout << "Serial number: " << EquipmentVector[i].SerialNumber << endl;
			}
		}
	}
	else cout << "Any equipment with so serial number" << endl;
}