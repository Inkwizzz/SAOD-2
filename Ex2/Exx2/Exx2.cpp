#include <iostream>
using namespace std;

void swapp(int *pa, int *pb) 
{
    int c = *pa;
    *pa = *pb;
    *pb = c;

}

int main()
{
   /* int x = 3;
    int *p = &x;
    cout << x << " " << *p << " " << p << endl;
    cout << ++p << endl;
    cout << p - &x << endl;

    typedef unsigned char byte;
    byte *pb = (byte *)--p;
    for (byte *pt = pb; pt - pb < sizeof(int); pt++)
        cout << (int)*pt << ' ';
    cout << endl;*/

    int a = 3, b = 5;
    swapp(&a, &b);
    cout << a << ' ' << b << endl;


}
