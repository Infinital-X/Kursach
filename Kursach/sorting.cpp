#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "struct.h"
#include "outputAll.h"
using namespace std;

void sorting(vector<AccountingForEquipmentComposition>& EquipmentVector) //Функция сортирует файлы по цене методом пузырька
{
	for (unsigned int i = 0; i < EquipmentVector.size() - 1; i++)
	{
		for (unsigned int j = 0; j < EquipmentVector.size() - i - 1; j++)
		{
			if (EquipmentVector[j].Price < EquipmentVector[j + 1].Price)
			{
				swap(EquipmentVector[j], EquipmentVector[j + 1]);
			}
		}
	}
	outputAll(EquipmentVector);
}