#pragma once
#include <iostream>
 using namespace std;
class Test
{
public:
	int t;
	static int nCount;
	Test()
	{
		using namespace std;
		cout << "created" << endl;
		nCount++;
		cout << nCount << endl;
	}

	Test(int t)
	{
		using namespace std;
		this->t = t;
		cout << "created" << endl;
		nCount++;
		cout << nCount << endl;
	}

	Test(const Test& s)
	{
		using namespace std;
		cout << "created" << endl;
		nCount++;
		cout << nCount << endl;

	}

	~Test() {
		using namespace std;
		cout << "deleted" << endl;
		nCount--;
		cout << nCount << endl;
	}
};


