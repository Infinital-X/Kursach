#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "struct.h"
#include "getInfo.h"
#include "addNew.h"
#include "outputAll.h"
#include "priceForAll.h"
#include "sorting.h"
#include "search.h"
#include "remove.h"
#include "edit.h"
using namespace std;
const int NotUsed = system("color F0");

vector<AccountingForEquipmentComposition>EquipmentVector; //Объявляем вектор для удобной работы с элементами базы данных
AccountingForEquipmentComposition  EquipmentElement; //Объявляем имя структуры

Menu menu[] =
{
	{ 1, "Enter new equipment" },
	{ 2, "Delete equipment" },
	{ 3, "Info about equipment" },
	{ 4, "Dump everything from the database" },
	{ 5, "Change info" },
	{ 6, "Search for an item by serial number" },
	{ 7, "Sort by price" },
	{ 8, "Count price for all equipment" },
	{ 9, "Exit"}
};

int showMenu(const Menu* menu1) //Функция показывающая меню и возвращающая выбор пользователя
{
	for (int i = 0; i < 9; i++)
	{
		cout << menu1[i].number << ") " << menu1[i].text << endl;
	}

	int choice;
	cout << "Make your choose: ";
	cin >> choice;
	return choice;
}


int main()
{
	fstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
	streampos begin, end;
	begin = file.tellg(); //Начало файла
	file.seekg(0, ios::end);
	end = file.tellg(); //Конец файла
	long long begend = end - begin;
	int size3 = (int)begend / sizeof(AccountingForEquipmentComposition); //Размер файла
	file.close();

	for (int i = 0; i < size3; i++)
		EquipmentVector.push_back(EquipmentElement); //Заполняем вектор

	file.open("Equipment List.txt", ios::binary | ios::in | ios::app); //Открываем файл в бинарном режиме
	for (int i = 0; i < size3; i++)
	{
		file.read((char*)&EquipmentVector[i], sizeof(AccountingForEquipmentComposition));
	}

	int choice; //Выбор пользователя

	do //Цикл в котором вызываются все функции
	{
		cout << endl;
		choice = showMenu(menu);
		if (EquipmentVector.size() == 0)
		{
			switch (choice)
			{
			case 1:
				cin.ignore();
				addNew(EquipmentVector);
				break;
			case 9:
				break;
			default:
				cout << "Anything in base" << endl;

			}
		}
		else {
			switch (choice)
			{
			case 1:
				cin.ignore();
				addNew(EquipmentVector);
				break;
			case 2:
				int num0;
				cout << "Enter number to delete: ";
				cin >> num0;
				cin.ignore();
				remove(EquipmentVector, num0 - 1);
				break;
			case 3:
				int num1;
				cout << "Enter number in base: ";
				cin >> num1;
				cin.ignore();
				getInfo(EquipmentVector, num1 - 1);
				break;
			case 4:
				outputAll(EquipmentVector);
				break;
			case 5:
				int num2;
				cout << "Enter number of item you want to change: ";
				cin >> num2;
				cin.ignore();
				edit(EquipmentVector, num2 - 1);
				break;
			case 6:
				search(EquipmentVector);
				break;
			case 7:
				sorting(EquipmentVector);
				break;
			case 8:
				priceForAll(EquipmentVector);
				break;
			case 9:
				break;
			default:
				cout << "Wrong number" << endl;
			}
		}
	} while (choice != 9);
}