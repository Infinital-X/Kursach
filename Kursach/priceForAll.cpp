#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "struct.h"
using namespace std;


void priceForAll(vector<AccountingForEquipmentComposition>& EquipmentVector) //Функция считает цену всего оборудования
{
	int price = 0;
	for (unsigned int i = 0; i < EquipmentVector.size(); i++)
	{
		price = EquipmentVector[i].Price * EquipmentVector[i].NumberOfEquipment;
		cout << "SerialNumber: " << EquipmentVector[i].SerialNumber << "\tPrice for all equipment: " << price << endl;
	}
}
