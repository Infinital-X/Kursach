#pragma once
#ifndef struct_h
#define struct_h

struct  AccountingForEquipmentComposition //Объявляем структуру с нужными нам полями
{
	char Equipment[30];
	unsigned int NumberOfEquipment;
	unsigned int SerialNumber;
	unsigned int Price;
};

struct Menu //Структура для меню
{
	int number;
	const char* text;
};

#endif