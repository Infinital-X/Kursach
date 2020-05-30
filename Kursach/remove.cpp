#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "struct.h"
using namespace std;


void remove(vector<AccountingForEquipmentComposition >& EquipmentVector, unsigned int num) //Функция удаляет элемент базы данных по его номеру
{
	if (num < EquipmentVector.size())
	{
		auto iterator = EquipmentVector.begin();
		EquipmentVector.erase(iterator + num); //Удаляем элемент из вектора

		ofstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
		if (!file) //Проверка открыт ли файл 
			cout << "File does not open";
		else
		{
			for (unsigned int i = 0; i < EquipmentVector.size(); i++) //Перезаписываем все данные из вектора в файл
			{
				file.write((char*)&EquipmentVector[i], sizeof(AccountingForEquipmentComposition));
			}
		}
		file.close();
		cout << "Item successfully deleted\n";
	}
	else cout << "Dont have so text\n";
}