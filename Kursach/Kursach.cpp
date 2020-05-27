#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;
const int NotUsed = system("color F0");


struct Menu
{
	int number;
	const char* text;
};

struct  AccountingForEquipmentComposition
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

int showMenu(const Menu* menu1)
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

void addNew(vector<AccountingForEquipmentComposition >& EquipmentVector)
{
	AccountingForEquipmentComposition  EquipmentElement;

	char Equipment[30];
	int NumberOfEquipment;
	int SerialNumber;
	int Price;

	cout << "Equipment: ";
	cin.getline(EquipmentElement.Equipment, sizeof(Equipment));

	while (EquipmentElement.Equipment == "")
	{
		cout << "You have not entered anything";
		cin.getline(EquipmentElement.Equipment, sizeof(Equipment));
	}

	cout << "Serial number: ";
	cin >> EquipmentElement.SerialNumber;

	cin.ignore();

	cout << "Price: ";
	cin >> EquipmentElement.Price;

	cin.ignore();

	cout << "Number of  equipment: ";
	cin >> EquipmentElement.NumberOfEquipment;

	cin.ignore();

	EquipmentVector.push_back(EquipmentElement);

	ofstream file("Equipment List.txt", ios::binary | ios::out | ios::app);
	if (!file) 
		cout << "File does not open";
	else 
	{
		file.write((char*)&EquipmentElement, sizeof(AccountingForEquipmentComposition));
	}
	file.close();
}

void getInfo(vector<AccountingForEquipmentComposition>&EquipmentVector, int num)
{
	ifstream file("Equipment List.txt", ios::binary | ios::out | ios::app);
	if (!file) 
		cout << "File does not open";
	else
	{
		if (num >= 0 && num < EquipmentVector.size())
		{
			AccountingForEquipmentComposition  EquipmentElement;
			file.seekg(num * sizeof(AccountingForEquipmentComposition) );
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

void outputAll(vector<AccountingForEquipmentComposition >& EquipmentVector)
{
	ifstream file("Equipment List.txt", ios::binary | ios::out | ios::app);
	if (!file)
		cout << "File does not open";
	else
	{
		for(int i = 0; i < EquipmentVector.size(); i++)
		{
			AccountingForEquipmentComposition  EquipmentElement;
			file.seekg(i * sizeof(AccountingForEquipmentComposition));
			file.read((char*)&EquipmentElement, sizeof(AccountingForEquipmentComposition));
			cout << "Item number " << i+1 << endl;
			cout << "Equipment: " << EquipmentVector[i].Equipment << "\t";
			cout << "SerialNumber: " << EquipmentVector[i].SerialNumber << "\t";
			cout << "Price: " << EquipmentVector[i].Price << "\t";
			cout << "NumberOfEquipment: " << EquipmentVector[i].NumberOfEquipment << endl;
		}
	}
	file.close();
}

void remove(vector<AccountingForEquipmentComposition >& EquipmentVector, int num)
{
	if (num >= 0 && num < EquipmentVector.size())
	{
		auto iterator = EquipmentVector.begin();
		EquipmentVector.erase(iterator + num);

		ofstream file("Equipment List.txt", ios::binary | ios::out | ios::app);
		if (!file) 
			cout << "File does not open";
		else {
			for (int i = 0; i < EquipmentVector.size(); i++)
			{
				file.write((char*)&EquipmentVector[i], sizeof(AccountingForEquipmentComposition));
			}
		}
		file.close();
		cout << "Item successfully deleted\n";
	}
	else cout << "Dont have so text\n";
}

void edit(vector<AccountingForEquipmentComposition >& EquipmentVector, int num)
{
	if (num >= 0 && num < EquipmentVector.size())
	{
		cout << "Before change: \n";
		getInfo(EquipmentVector, num);

		AccountingForEquipmentComposition  EquipmentElement;

		char Equipment[30];
		int NumberOfEquipment;
		int SerialNumber;
		int Price;

		cout << endl << "Equipment: ";
		cin.getline(EquipmentElement.Equipment, sizeof(Equipment));

		while (EquipmentElement.Equipment == "")
		{
			cout << "You have not entered anything";
			cin.getline(EquipmentElement.Equipment, sizeof(Equipment));
		}

		cout << "Serial number: ";
		cin >> EquipmentElement.SerialNumber;

		cin.ignore();

		cout << "Price: ";
		cin >> EquipmentElement.Price;

		cin.ignore();

		cout << "Number of equipment: ";
		cin >> EquipmentElement.NumberOfEquipment;

		cin.ignore();

		auto iterator = EquipmentVector.begin();

		*(iterator + num) = EquipmentElement;

		ofstream file("Equipment List.txt", ios::binary | ios::out | ios::app);
		if (!file)
			cout << "File does not open";
		else {
			for (int i = 0; i < EquipmentVector.size(); i++)
			{
				file.write((char*)&EquipmentVector[i], sizeof(AccountingForEquipmentComposition));
			}
		}
		file.close();

		cout << endl << "After change: \n";
		getInfo(EquipmentVector, num);
	}
	else cout << "Wrong number\n";
}

void search(vector<AccountingForEquipmentComposition>&EquipmentVector)
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

void sorting(vector<AccountingForEquipmentComposition>&EquipmentVector)
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

void priceForAll(vector<AccountingForEquipmentComposition>&EquipmentVector)
{
	int price = 0;
	for (int i = 0; i < EquipmentVector.size(); i++)
	{
		price = EquipmentVector[i].Price * EquipmentVector[i].NumberOfEquipment;
		cout << "SerialNumber: " << EquipmentVector[i].SerialNumber << "\tPrice for all equipment: " << price << endl;
	}
}

int main()
{
	fstream file("Equipment List.txt", ios::binary | ios::out | ios::app);
	streampos begin, end;
	begin = file.tellg();
	file.seekg(0, ios::end);
	end = file.tellg();
	int size = (end - begin) / sizeof(AccountingForEquipmentComposition);
	file.close();

	vector<AccountingForEquipmentComposition>EquipmentVector;
	AccountingForEquipmentComposition  EquipmentElement;
	for (int i = 0; i < size; i++) EquipmentVector.push_back(EquipmentElement);

	file.open("Equipment List.txt", ios::binary | ios::in | ios::app);
	for (int i = 0; i < size; i++)
	{
		file.read((char*)&EquipmentVector[i], sizeof(AccountingForEquipmentComposition));
	}

	int choice;

	do
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