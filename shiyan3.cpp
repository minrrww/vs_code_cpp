#include <iostream>
using namespace std;
int main()
{
    const float PI = 3.14159;
    float s, r;
    cout << "请输入半径：" << endl;
    cin >> r;
    s = PI * r * r;
    cout << s << endl;
}
