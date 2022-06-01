//4.9 sizeof运算符
//1.sizeof运算符返回一条表达式或一个类型所占的字节数。
//2.sizeof运算符满足右结合律，所得值是一个size_t类型的常量表达式。
//3.sizeof与*运算符优先级相同，满足右结合律。
/*4.sizeof运算符不会实际求运算对象的值，
    运算对象可以是无效指针或未赋值的对象，
    也可以通过作用域运算符来获取类成员的大小。*/
//5.运算结果部分地依赖其作用的类型。
#include <iostream>
//#include <typeinfo>
using namespace std;
struct student
{
    string name;
    string num;
    unsigned grade;
};
int main()
{
    student s1 = {"Lilei", "20082958", 99}, *p, &r = s1;
    int i[5];
    cout << sizeof(student) << endl;              //存储结构体的对象所占的空间大小
    cout << sizeof s1 << endl;                    //s1的类型的大小，与sizeof(student) 相同
    cout << sizeof p << endl;                     //1.指针类型，结果是指针所占空间的大小
    cout << sizeof *p << endl;                    //2.解引用，得到p所指对象类型的大小，与sizeof(student) 相同
    cout << sizeof s1.name << endl;               //3.成员类型的大小
    cout << sizeof student::grade << endl;        //另一种获得成员类型大小的方法
    cout << sizeof(char) << endl;                 //4.char或类型为char的表达式，sizeof运算结果是1
    cout << sizeof r << endl;                     //5.引用类型，结果是引用对象所占空间大小
    cout << sizeof i << endl;                     //6.数组类型，结果是所有元素大小之和
    constexpr size_t sz = sizeof(i) / sizeof(*i); //数组占用空间大小与单个元素占用空间大小之商
    cout << sz << endl;
    int arr[sz];                    //sizeof返回的是常量表达式，所以可以用sizeof的结果声明数组的纬度
    cout << sizeof(string) << endl; //7.string类型，只返回该类型固定部分的大小，不会计算对象中的元素占用了多少空间
    return 0;
}
/*
72
72
8
72
32
4
1
72
20
5
32
*/
