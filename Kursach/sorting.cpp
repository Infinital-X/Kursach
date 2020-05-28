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

void outputAll(vector<AccountingForEquipmentComposition >& EquipmentVector); //Функция выводит все элементы базы данных

void sorting(vector<AccountingForEquipmentComposition>& EquipmentVector) //Функция сортирует файлы по цене методом пузырька
{
	for (int i = 0; i < EquipmentVector.size() - 1; i++)
	{
		for (int j = 0; j < EquipmentVector.size() - i - 1; j++)
		{
			if (EquipmentVector[j].Price < EquipmentVector[j + 1].Price)
			{
				swap(EquipmentVector[j], EquipmentVector[j + 1]);
			}
		}
	}
	outputAll(EquipmentVector);
}