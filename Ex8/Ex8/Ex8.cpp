#include "WF.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    WF wf;
    string s1, s2;

    cout << "Первое слово:" << "\n";
    cin >> s1;

    cout << "Второе слово:" << "\n";
    cin >> s2;

    cout << "До\n";
    wf.Init(s1, s2);
    wf.PrintMatrix();
    cout << "\n";

    cout << "После\n";
    wf.WagnerFischerAlgorithm();
    wf.PrintMatrix();
    cout << "\n";

    cout << "Distance: ";
    cout << wf.Distance() << "\n";
}