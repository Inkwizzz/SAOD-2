#pragma once
#include "Test.h"
class Aggregate
{
private:
	Test* m_object;
public:
	Aggregate(Test* m_object = nullptr)
	{
		using namespace std;
		this->m_object = new Test;
		cout << "aggregate created" << endl;

	}

	~Aggregate() {
		using namespace std;
		delete m_object;
		cout << "aggregate deleted" << endl;
	}

};

