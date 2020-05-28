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

void getInfo(vector<AccountingForEquipmentComposition>& EquipmentVector, int num) //Функция выводит элемент базы данных по его номеру
{
	ifstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
	if (!file) //Проверка открыт ли файл 
		cout << "File does not open";
	else
	{
		if (num >= 0 && num < EquipmentVector.size())
		{
			AccountingForEquipmentComposition  EquipmentElement;
			file.seekg(num * sizeof(AccountingForEquipmentComposition)); //Переход к нужному элементу в файле
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