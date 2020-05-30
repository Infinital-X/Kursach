#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "struct.h"
using namespace std;

void search(vector<AccountingForEquipmentComposition>& EquipmentVector) //Функция выводит название элемента по его серийному номеру
{
	int num;
	bool found = false;
	cout << "Enter serial number: ";
	cin >> num;
	for (unsigned int i = 0; i < EquipmentVector.size(); i++)
	{
		if (num == EquipmentVector[i].SerialNumber)
		{
			found = true;
			break;
		}
	}
	if (found == true)
	{
		for (unsigned int i = 0; i < EquipmentVector.size(); i++)
		{
			if (num == EquipmentVector[i].SerialNumber)
			{
				cout << endl << "Equipment: " << EquipmentVector[i].Equipment << endl;
				cout << "Serial number: " << EquipmentVector[i].SerialNumber << endl;
			}
		}
	}
	else cout << "Wrong serial number" << endl;
}