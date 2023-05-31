﻿#include "stdafx.h"
#include "SuffixTree.h"
#include <string>
#include <vector>
using namespace std;

// Получает метку ребра
string GetLabel(STLink* pLnk)
{
	// Выясняем длину метки
	int lnkLen = pLnk->Length();
	// Сохраняем символ за меткой
	char ch = ((const char*)(*pLnk))[lnkLen];
	// Получаем указатель на начало метки
	char* p = (char*)(const char*)(*pLnk);
	// Ограничиваем ее 0
	p[lnkLen] = 0;
	// Строим строку
	string t = (const char*)(*pLnk);
	// Восстанавливаем символ, который заменяли 0
	p[lnkLen] = ch;

	return t;
}
//Пробегает по дереву и выводит его на консоль
void IterateTree(STNode* node, string pref = ". ")
{
	for (int i = 0; i < AlphaBetSize; i++)
	{
		STLink* pLnk = node->GetLink(i);
		if (pLnk != 0)
		{
			// Нашли внутренний узел (не лист)
			if (pLnk->GetTarget()->IsNode())
			{
				string t = GetLabel(pLnk);
				// Добавим в префикс метку ребра и стрелку
				t = pref + t + " -> ";
				// проходим поддерево 
				IterateTree(pLnk->GetNode(), t);
			}
			else // Нашли лист
			{
				// Добавим в префикс метку ребра и =
				string t = GetLabel(pLnk);
				t = pref + t + "\t = ";
				// Выводим префикс ребра и полный суффикс с позиции указанной в листе

				cout << '['; cout.width(2); cout << (int)*(pLnk->GetTarget()) << ']' << t << '"' << SuffixTree::GetData() + (int)*(pLnk->GetTarget()) << '"' << endl;
			}
		}
	}
}

vector <int> prefix_function(string s) 
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 0; i < n; i++)
		for (int k = 0; k <= i; k++)
			if (s.substr(0, k) == s.substr(i - k + 1, k))
				pi[i] = k;
	return pi;
}

int main()
{
	// Данные для построения дерева
	char s[] = "atrfq12q3fqwertdf_";
	// Заменяем последний символ (подчеркиваение) на "уникальный" (=> ни один суффикс не совпадет ни с одним префиксом).
	s[strlen(s) - 1] = char(AlphaBetSize - 1);

	// Строим дерево суффиксов
	SuffixTree::Init(s);

	// Выводим строку и ее длину 
	cout << SuffixTree::GetSize() << ' ' << SuffixTree::GetData() << endl << endl;

	// Проходим по дереву и выводим его на консоль
	IterateTree(SuffixTree::GetRoot());

	cout << endl;
	char s2[] = "fFq12";
	if (SuffixTree::Contains(s2))
		cout << "1" << endl;
	else
		cout << "0" << endl;
}
