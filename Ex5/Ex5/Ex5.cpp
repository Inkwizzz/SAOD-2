#include <iostream>
#include "Test.h"
#include "Child.h"
#include "Aggregate.h"
#include "AggregateT.h"
using namespace std;

Test t;
void foo(Test t)
{
    cout << "foo is running" << endl;
}

int main()
{
    cout << "start of creation" << endl;
    Test c;
    cout << "end of creation" << endl;

    Test* p = new Test;
    delete p;

    Test* test = new Test[3];
    delete[] test;

    foo(t);

    Child ch;

    Aggregate a(&c);
    AggregateT<Test> aT(c);
    AggregateT<Child> aCh(ch);

    Test t1(5);
    Child ch1;

    Aggregate a1(&t1);
}
