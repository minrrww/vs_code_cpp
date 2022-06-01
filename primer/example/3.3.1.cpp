//example-3.3.1-.cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1;      //v1是一个空vector，int类型
    vector<int> v2(v1);  //v2包含v1所有元素副本
    vector<int> v3 = v1; //v3包含v1所有元素副本
    int n = 5, val = 5;
    vector<int> v4(n, val);//v4包含5个5
    //vector<string> v5('5');//不能使用字符串字面值创建vector 对象
    vector<int> v5{1, 2, 3, 4, 5, 6};    //v5包含1, 2, 3, 4, 5, 6
    vector<int> v6 = {9, 8, 7, 6, 5, 4}; //v6包含9, 8, 7, 6, 5, 4
    vector<int> v7 = vector<int>(v6);    //v7包含v6全部副本
    vector<int> v8(10);                  //10个元素，都是0
    vector<string> v9(10);               //10个元素，都是""
    return 0;
}
