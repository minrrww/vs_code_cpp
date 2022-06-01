#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;

    for (int i = 0; i < 10; i++)
    {
        int item;
        cin >> item;
        list.insertFront(item);
    }
    cout << "List:";
    list.reset();

    while (!list.endOfList())
    {
        cout << list.data() << " ";
        list.next();
    }
    cout << endl;

    int key;
    cout << "Please enter some integer needed to be deleted:";
    cin >> key;

    list.reset();
    while (!list.endOfList())
    {
        if (list.data() == key)
            list.deleteCurrent();
        list.next();
    }
    cout << "List:";
    list.reset();

    while (!list.endOfList())
    {
        cout << list.data() << " ";
        list.next();
    }
    cout << endl;
    return 0;
}
