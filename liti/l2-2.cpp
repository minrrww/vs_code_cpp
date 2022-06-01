#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;
int main()
{
    for (int i = 33; i <= 126; i++)
    {
        if ((i - 32) % 3)
        {
            cout << bitset<8>(i) << " | ";        //二进制输出
            cout << setw(4) << oct << i << " | "; //八进制输出
            cout << setw(2) << hex << i << " | "; //十六进制输出
            cout << setw(3) << dec << i << " | "; //十进制输出
            cout << char(i) << "  ||  ";          //char类型输出
        }
        else
        {
            cout << bitset<8>(i) << " | ";        //二进制输出
            cout << setw(4) << oct << i << " | "; //八进制输出
            cout << setw(2) << hex << i << " | "; //十六进制输出
            cout << setw(3) << dec << i << " | "; //十进制输出
            cout << char(i) << "  ||  " << endl;  //char类型输出
        }
    }


    return 0;
}
