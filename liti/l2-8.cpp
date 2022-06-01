#include <iostream>
using namespace std;
int main()
{
    int i=1, num = 0;
    while(i<=100)
    {
        num += i;
        i++;
    }
    cout << "num=" << num << endl;
    getchar();
    return 0;
}
