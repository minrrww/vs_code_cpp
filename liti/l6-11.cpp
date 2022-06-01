#include <iostream>

using namespace std;
void printStuff(float)
{
    cout << "This is the print stuff function." << endl;
}
void printMessage(float data)
{
    cout << "The data to be printed is " << data << endl;
}
void printFloat(float data)
{
    cout << "The data to be printed is " << data << endl;
}
const float PI = 3.14159f;
const float TWO_PI = PI * 2.0f;
//typedef void (*functionPointer)(float);
int main() //主函数
{
    //functionPointer为形参float类型，无返回值函数指针类型的别名(是类型，不是函数名)
    typedef void (*functionPointer)(float);
    printStuff(PI);
    functionPointer fun; //声明函数指针
    fun = printStuff;    //函数指针指向printStuff(),函数名为指针
    fun(PI);             //函数指针调用
    fun = printMessage;  //函数指针指向printStuff(),函数名为指针
    fun(TWO_PI);         //函数指针调用
    fun(13.0);           //函数指针调用
    fun = printFloat;    //函数指针指向printStuff(),函数名为指针
    fun(PI);             //函数指针调用
    printFloat(PI);
    return 0;
}
/*输出
This is the print stuff function.
This is the print stuff function.
The data to be printed is 6.28318
The data to be printed is 13
The data to be printed is 3.14159
The data to be printed is 3.14159
*/
