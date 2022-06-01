//Sine正弦, cosine余弦, tangent正切,angle角度
//输入角度，求正弦，余弦，正切
#include <iostream>
#include <cmath>//数学函数
using namespace std;
const double PI = 3.14159265358979;
int main()
{
    double angle;
    cout << "Enter the angle:";
    cin >> angle;
    cout << "The sine value:" << sin(angle*PI/180) << endl;
    cout << "The cosine value:" << cos(angle*PI/180) << endl;
    cout << "The tangent value:" << tan(angle*PI/180) << endl;
    getchar();
    return 0;
}
