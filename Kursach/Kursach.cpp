#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;
const int NotUsed = system("color F0");

struct Menu //Структура для меню
{
	int number;
	const char* text;
};

struct  AccountingForEquipmentComposition //Главная структура
{
	char Equipment[30];
	int NumberOfEquipment;
	int SerialNumber;
	int Price;
};

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

void addNew(vector<AccountingForEquipmentComposition>&EquipmentVector); //Функция которая добавляет новые элементы структуры и сохраняет их в файл
void getInfo(vector<AccountingForEquipmentComposition>&EquipmentVector, int num); //Функция выводит элемент базы данных по его номеру
void outputAll(vector<AccountingForEquipmentComposition>&EquipmentVector); //Функция выводит все элементы базы данных
void remove(vector<AccountingForEquipmentComposition>&EquipmentVector, int num); //Функция удаляет элемент базы данных по его номеру
void edit(vector<AccountingForEquipmentComposition>&EquipmentVector, int num); //Функция изменяет элемент базы данных по его номеру
void search(vector<AccountingForEquipmentComposition>&EquipmentVector); //Функция выводит название элемента по его серийному номеру
void sorting(vector<AccountingForEquipmentComposition>&EquipmentVector); //Функция сортирует файлы по цене методом пузырька
void priceForAll(vector<AccountingForEquipmentComposition>&EquipmentVector); //Функция считает цену всего оборудования

int main()
{
	fstream file("Equipment List.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
	streampos begin, end;
	begin = file.tellg(); //Начало файла
	file.seekg(0, ios::end);
	end = file.tellg(); //Конец файла
	int size = (end - begin) / sizeof(AccountingForEquipmentComposition); //Размер файла
	file.close();

	vector<AccountingForEquipmentComposition>EquipmentVector; //Объявляем вектор для удобной работы с элементами базы данных
	AccountingForEquipmentComposition  EquipmentElement; //Объявляем имя структуры
	for (int i = 0; i < size; i++)
		EquipmentVector.push_back(EquipmentElement); //Заполняем вектор

	file.open("Equipment List.txt", ios::binary | ios::in | ios::app); //Открываем файл в бинарном режиме
	for (int i = 0; i < size; i++)
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