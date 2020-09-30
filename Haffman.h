#pragma once
//Класс "алгоритм Хаффмана"

#include "Container.h"
class Haffman :
	public Container
{
private:
	struct stat
	{
		int count; //Для статистики - сколько раз встретился в массиве
		unsigned char c; //код символа //unsigned важно, положительные!
		stat * left;  //для сохранения в памяти
		stat * right; //
	};
	stat * Tree; //Статистика появления символов в тексте. Хитрая структура,
	//изначально массив, потом превратится в дерево
	int TreeLen;

	void freeTree()
	{
		if (TreeLen) delete[] Tree;
		TreeLen = 0;
	}

	void MakeStat() //По source накопить статистику
	{
		freeTree();
		Tree = new stat[256];
		TreeLen = 256;
		for (int k = 0; k < 256; k++) 
		{
			Tree[k].count = 0;
			Tree[k].c = k;
			Tree[k].left = Tree[k].right = NULL;
		}
		for (int k = 0; k < sourceLen; k++) Tree[source[k]].count++;
	}

	//Сортировать статистику по count
	void SortStat()
	{
		for (int k = 0; k < TreeLen; k++)
		{
			int best = k;
			for (int i = k + 1; i < TreeLen; i++)
				if (Tree[i].count < Tree[best].count)
					best = i;
			if (best != k)
			{
				stat temp = Tree[best];
				Tree[best] = Tree[k];
				Tree[k] = temp;
			}
		}
	}

	//Положить кусочек статистики в массив (в конец, но это неважно)
	void Push(stat SubTree)
	{
		Tree = (stat*)realloc(Tree, (sizeof(stat)*(TreeLen + 1)));
		Tree[TreeLen++] = SubTree;
	}

	//Извлечь статистику. Из начала. Это важно - извлекается самый редкий символ
	stat Pop()
	{
		stat Result = Tree[0];
		for (int k = 0; k < TreeLen - 1; k++)
			Tree[k] = Tree[k + 1];
		Tree = (stat*)realloc(Tree, (sizeof(stat)*(--TreeLen)));
		return Result;
	}

	//Убрать из начала дерева неиспользованные символы
	void CleanTree()
	{
		while (Tree[0].count == 0 && TreeLen>0) Pop();
	}

	//Построить по Stat дерево кодировки
	void MakeTree()
	{
		while (TreeLen > 1)
		{
			//Вынуть первый элемент
			stat * E1 = new stat();
			*E1 = Pop();
			//Вынуть второй элемент
			stat * E2 = new stat();
			*E2 = Pop();
			//Создать их объединение
			stat E;
			E.c = 0; //Неважно
			E.count = E1->count + E2->count; //Сумма весов 
			E.left = E1;
			E.right = E2;
			//Положить обратно
			Push(E);
			//Сортировать
			SortStat();
		}
	}

	//Сохранить имеющийся набор частот (статистику)
	void PackStat()
	{
		//Просто поместить в table значения:
		//сам символ (1 байт)
		//количество раз, сколько он встретился (3 байта, до 16 777 216 раз)
		tableLen = TreeLen * 4;
		table = (unsigned char*)realloc(table, tableLen);
		for (int k = 0; k < TreeLen; k++)
		{
			table[4 * k] = Tree[k].c;
			int x = Tree[k].count;
			table[4 * k + 3] = x & 0xFF;
			x >>= 8;
			table[4 * k + 2] = x & 0xFF;
			x >>= 8;
			table[4 * k + 1] = x & 0xFF;
		}
	}

	//по массиву table восстановить набор частот  (статистику)
	void UnpackStat()
	{
		TreeLen = tableLen / 4;
		Tree = (stat*)realloc(Tree, sizeof(stat)*TreeLen);
		for (int k = 0; k < TreeLen; k++)
		{
			Tree[k].c = table[4 * k];
			Tree[k].left = Tree[k].right = NULL;
			Tree[k].count = 0;
			Tree[k].count += table[4 * k + 1]; 
			Tree[k].count <<= 8;
			Tree[k].count += table[4 * k + 2];
			Tree[k].count <<= 8;
			Tree[k].count += table[4 * k + 3];
		}
	}

	//Построить таблицу кодировки по дереву
	struct CodeTable
	{
		int len;
		bool path[256]; //С избытком
	};
	CodeTable codetable[256]; //Таблица кодировки
	CodeTable current; //Текущий

	void MakeTableFromTree(stat * subtree)
	{
		if (!subtree) 
			return; //Это какая-то ошибка, так не бывает
		if (subtree->left == NULL && subtree->right == NULL)
		{
			//Это лист. У него есть код символа. Записать и вернуться
			codetable[subtree->c] = current;
			return;
		}

		//Это еще не лист. Обойти левую и правую ветки
		current.path[current.len++] = false;
		MakeTableFromTree(subtree->left);
		current.len--;
		current.path[current.len++] = true;
		MakeTableFromTree(subtree->right);
		current.path[current.len] = (bool)2; //Не обязательно, для наглядности при отладке
		current.len--;
	}


public:

	Haffman():Container()
	{
		Tree = NULL;
		TreeLen = 0;
	}

	//Добавить байт (или больше) 
	void PackCurrentPath()
	{
		while (current.len >= 8) 
		{
			//Получить битовое представление фрагмента current.path[0..7]
			unsigned char c = 0;
			for (int k = 0; k < 8; k++)
			{
				c <<= 1;
				if (current.path[k]) c++;
			}
			//Уменьшить длину
			current.len -= 8;
			//И скопировать оставшиеся данные
			for (int k = 0; k < current.len; k++)
				current.path[k] = current.path[k + 8];
			//Положить в target
			target = (unsigned char*)realloc(target, targetLen + 1);
			target[targetLen++] = c;
		}
	}

	//Добавить к current.path код для символа c
	void AddToTarget(unsigned char c)
	{
		for (int k = 0; k < codetable[c].len; k++)
			current.path[current.len++] = codetable[c].path[k];
		PackCurrentPath(); //И при необходимости отправить в выходной поток
	}

	virtual void Pack() override
	{
		freetarget(); //Очистить результат
		MakeStat(); //Набрать статистику по тексту
		SortStat(); //Привести статистику в порядок
		CleanTree(); //Выбросить лишнее
		PackStat();	//Упаковать дерево в table с сохранением только полезной для декодировки информации
		//Создавать table именно здесь: уже нет лишних символов
		MakeTree(); //Построить кодирующее дерево

		current.len = 0;
		//Очистить кодировочную таблицу
		for (int k = 0; k < 256; k++) 
		{
			codetable[k].len = 0;
			for (int i = 0; i < sizeof(codetable[k].path); i++)
				codetable[k].path[i] = false;
		}
		MakeTableFromTree(&Tree[0]); //Построить кодировочную таблицу по дереву
		
		current.len = 0;
		//Сама кодировка: берется очередной символ из входного потока и добавляется к выходному
		for (int k = 0; k < sourceLen; k++)
			AddToTarget(source[k]);
		for (int k = current.len; k < 9; k++)
		{
			current.path[k] = true; 
		};
		current.len = 9;
		PackCurrentPath();
	}

	virtual void Unpack() override
	{
		freesource();
		UnpackStat(); //Восстановить исходную статистику
		MakeTree(); //Построить кодирующее дерево
		//Для каждого байта упакованного текста
		stat * decoder = &Tree[0];
		for (int k = 0; k < targetLen; k++)
		{
			unsigned char c = target[k];
		//Для каждого бита упакованного текста
			for (int b = 0; b < 8; b++)
			{
				//Выделить бит
				bool x = (c >= 128); //true, если единица
				c <<= 1; //Для следующего прохода цикла
				//изменить положение в кодирующем дереве
				if (x)
					decoder = decoder->right;
				else
					decoder = decoder->left;
				//Если decoder оказался "листом", то добавить в source соответствующий символ и вернуться в начало дерева
				if (decoder->left == NULL && decoder->right == NULL)
				{
					source = (unsigned char *)realloc(source, sourceLen + 1);
					source[sourceLen++] = decoder->c;
					//Вернуться в начало дерева
					decoder = &Tree[0];
				}

			}
		}
	}

	//Сохранить таблицу частот в текстовом формате
	//Предполагается, что распаковываемый файл уже загружен
	void SaveTable(char* fileName)
	{
		FILE* F = fopen(fileName, "w");

		UnpackStat(); //Восстановить исходную статистику

		fprintf(F, "%5s%8s\n", "Char", "Count");
		for (int k = 0; k < TreeLen; k++)
		{
			if (Tree[k].c < ' ')
				fprintf(F,"0x%3d", Tree[k].c);
			else
				fprintf(F, "%5c", Tree[k].c);
			fprintf(F,"%8d\n", Tree[k].count);
		}

		fclose(F);
	}

};

