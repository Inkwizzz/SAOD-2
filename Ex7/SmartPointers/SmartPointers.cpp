#include "Test.h"
int main()
{
    {
        // Внутренний блок
        shared_ptr<Test> sp(new Test());
        cout << "use_count = " << sp.use_count() << endl;
        weak_ptr<Test> wp = sp;
        cout << "use_count = " << sp.use_count() << endl;

        // Преобразование weak_ptr в shared_ptr
        shared_ptr<Test> p = wp.lock();
        if (p) cout << "object is alive, use_count = " << p.use_count() << endl;
        else cout << "no owning object" << endl;
    }
    cout << "End of inner block" << endl;

    // Повторный вызов блока
    {
        shared_ptr<Test> sp(new Test());
        cout << "use_count = " << sp.use_count() << endl;
        weak_ptr<Test> wp = sp;
        cout << "use_count = " << sp.use_count() << endl;

        // Преобразование weak_ptr в shared_ptr
        shared_ptr<Test> p = wp.lock();
        if (p) {
            cout << "object is alive, use_count = " << p.use_count() << endl;
        }
        else {
            cout << "no owning object" << endl;
        }
    }
    cout << "End of outer block" << endl;

    return 0;
}


