#include <iostream>
#include "myList.hpp"
using namespace std;

typedef struct Teacher
{
    int age;
    char name[24];
} Teacher;

int main()
{
    Teacher t1, t2, tmp;
    t1.age = 123;
    t2.age = 55;

    MyList<Teacher> list;
    list.insert(t1, 0);
    list.insert(t2, 0);

    for (int i = 0; i < list.length(); i++)
    {
        list.get(tmp, i);
        cout << tmp.age << endl;
    }
    cout << "len " << list.length() << endl;
    cout << "------" << endl;
    while (list.length())
    {
        list.del(tmp, 0);
        cout << tmp.age << endl;
    }

    cout << "len " << list.length() << endl;

    return 0;
}