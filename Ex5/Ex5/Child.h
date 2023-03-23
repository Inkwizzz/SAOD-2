#pragma once
#include <iostream>
#include "Test.h"

class Child : public Test
{
public:
	static int chCount;
	Child() :Test(t)
	{
		using namespace std;
		cout << "child created" << endl;
		chCount++;
		cout << chCount << endl;
	}

	Child(const Child& s)
	{
		using namespace std;
		cout << "child created" << endl;
		chCount++;
		cout << chCount << endl;

	}

	~Child() {
		using namespace std;
		cout << "child deleted" << endl;
		chCount--;
		cout << chCount << endl;
	}
};