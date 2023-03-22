#include <iostream>
using namespace std;

void rot(int a[], int n, bool cw)
{
	if (!cw) 
	{
		int x = a[0];
		for (int i = 1; i < n; i++)
			a[i - 1] = a[i];
		a[n - 1] = x;
	}
	else
	{
		int x = a[n - 1];
		for (int i = n - 1; i > 0; i--)
			a[i] = a[i - 1];
		a[0] = x;
	}
}

int main()
{
	int a[5]{ 0,1,2,3,4 };
	rot(a, 5, true);
	for (int *p = a; p - a < 5; p++)
		cout << *p << ' ';
	cout << endl;
	return 0;
}