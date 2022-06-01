#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cout << '\x61'<< endl;
    cout << 'a'<< endl;
    cout << '\x22' << endl;
    cout << '\134' << endl;
    cout << '\047' << endl;
    cout << (sizeof '\047') << endl;
    cout << sizeof('\047') << endl;
    cout << sizeof(char) << endl;
    cout <<oct<<(0b1111111 & 0b01010101) << endl;
    return 0;
}

