#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 4;i++)
    {
        for (int j = 1; j <= 30;j++)
        {
            cout << " ";
        }
            for (int j = 1; j <= 8 - 2 * i; j++)
            {
                cout << " ";
            }
        for (int j = 1; j <= 2 * i - 1;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i < 4;i++)
    {
         for (int j = 1; j <= 30;j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 7 - 2 * i;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i <= 100;i++)
    {
        if((i+100)%3==0)
            cout << i + 100 << endl;
    }
    getchar();
    return 0;
}
