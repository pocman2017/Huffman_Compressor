#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
//Абстрактный класс "контейнер"
//Умеет загружать из файла, сохранять в файл
//А также описывает абстрактные методы Pack/Unpack
class Container
{
private:
	long FileSize(FILE * F)
	//Узнать длину файла в байтах. Должен быть открыт
	{
		fseek(F, 0, SEEK_END);
		long result = ftell(F);
		fseek(F, 0, SEEK_SET);
		return result;
	}



protected:
	unsigned char * source; //Исходные данные
	long sourceLen;
	unsigned char * target; //Упакованные данные
	long targetLen;
	unsigned char * table; //Таблица кодировки. Форма представления определяется наследниками
	long tableLen;

	void freesource()
	{
		if (sourceLen) delete[] source;
		sourceLen = 0;
		source = NULL;
	}
	void freetarget()
	{
		if (tableLen) delete[] table;
		table = NULL;
		tableLen = 0;
		if (targetLen) delete[] target;
		target = NULL;
		targetLen = 0;
	}

public:

	Container()
	{
		source = target = table = NULL;
		sourceLen = targetLen = tableLen = 0;
	}

	~Container()
	{
		freesource();
		freetarget();
	}

	bool LoadSource(char * FileName)
	{
		//Освободить память
		freesource();
		//Открыть файл
		FILE * F = fopen(FileName, "rb+");
		if (!F) return false;
		//Узнать его длину
		sourceLen = FileSize(F);
		//выделить память
		source = new unsigned char[sourceLen];
		//Прочитать
		fread(source, 1, sourceLen, F);
		fclose(F);
		return true;
	}

	bool SaveSource(char * FileName)
	{
		//Открыть файл
		FILE * F = fopen(FileName, "wb+");
		if (!F) return false;
		//записать
		fwrite(source, 1, sourceLen, F);
		fclose(F);
		return true;
	}

	int LoadTarget(char * FileName)
	{
		freetarget();
		//Открыть файл
		FILE * F = fopen(FileName, "rb+");
		if (!F) return 1;
		//Узнать его длину
		targetLen = FileSize(F);
		//Прочитать заголовок
		char HA[2];
		fread(HA, 1, 2, F);
		targetLen -= 2;
		if (HA[0] != 'H' || HA[1] != 'A')
		{
			targetLen = 0;
			fclose(F);
			return 2; //Это не наш архив!
		}
		//прочитать длину таблицы
		fread(&tableLen, sizeof(tableLen), 1, F);
		targetLen -= sizeof(tableLen);
		targetLen -= tableLen;
		//выделить память
		table = new unsigned char[tableLen];
		//выделить память для данных
		target = new unsigned char[targetLen];
		//прочитать таблицу
		fread(table, 1, tableLen, F);
		//прочитать данные
		fread(target, 1, targetLen, F);
		//Закрыть файл
		fclose(F);
		return 0;
	}

	bool SaveTarget(char * FileName)
	{
		//Открыть файл
		FILE * F = fopen(FileName, "wb+");
		if (!F) return false;
		//Записать заголовок
		char HA[2] = { 'H','A' };
		fwrite(HA, 1, 2, F);
		//записать длину таблицы
		fwrite(&tableLen, sizeof(tableLen), 1, F);
		//записать таблицу
		fwrite(table, 1,tableLen, F);
		//записать данные
		fwrite(target, 1, targetLen, F);
		fclose(F);
		return true;
	}

	virtual void Pack() = 0; //Абстрактный метод "упаковать"
	virtual void Unpack() = 0; //Абстрактный метод "распаковать"

};

