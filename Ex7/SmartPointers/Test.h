#pragma once
#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	Test() {
		cout << "Created" << endl;
	}
	~Test() {
		cout << "Deleted" << endl;
	}
};

