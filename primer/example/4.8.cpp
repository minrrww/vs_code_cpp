//4.8 位运算符
/*1.位运算符作用于整数类型的运算对象，并把运算对象看成是二进制位的集合。*/
/*2.一种名为bitset的标准库类型可以表示任意大小的二进制集合。*/
/*3.表4.3：位运算符（左结合律）
运算符      功能      用法
~           位求反    expr

<<          左移      expr1 << expr2
>>          右移      expr1 >> expr2

&           位与      expr & expr

^           位异或    expr ^ expr

|           位或      expr | expr
*/
/*4.小整型会被自动提升成较大的整数类型。*/
/*5.运算对象可以带符号，如果是负数，如何处理符号位依赖机器。
    此时左位移操作会改变符号位的值，是一种未定义的行为。
    建议仅将位运算用于处理无符号类型。*/
//6.左移运算符<<在右侧插入值为0的二进制位，左侧提升位补符号位
//7.右移运算符>>无符号左侧插入0,有符号，左侧插入符号位
/*8.&对应位置都是1，则结果是1，否则是0；
    |对应位置至少一个是1,则结果是1，否则是0；
    ^对应位置有且只有一个为1，则运算结果是1，否则是0。*/
//9.移位运算符（又叫IO运算符）满足左结合律，比算术运算符低，比关系运算符高
#include <iostream>
#include <bitset>
#include <typeinfo>
#include <cmath>
using namespace std;
int main()
{
    unsigned char bits = 0233;
    //输出char类型的对象bits的二进制，占8位
    cout << bitset<sizeof(decltype(bits)) * 8>(bits) << endl;
    //输出bits<<8的二进制，自动提升为32位
    cout << bitset<sizeof(decltype(bits << 8)) * 8>(bits << 8) << endl;
    cout << bitset<sizeof(decltype(bits << 31)) * 8>(bits << 31) << endl;
    cout << bitset<sizeof(decltype(bits >> 3)) * 8>(bits >> 3) << endl;
    short s = -0233;
    /*原码:0b1000000010011011-->
      反码:0b1111111101100100-->
      补码:0b1111111101100101*/
    cout << bitset<sizeof(decltype(s)) * 8>(s) << endl;
    /*原码: 10000000000000001001101100000000-->
      反码：11111111111111110110010011111111-->
      补码：11111111111111110110010100000000*/
    //负数左位移,右侧插入0补齐，左侧插入符号位
    cout << bitset<sizeof(decltype(s << 8)) * 8>(s << 8) << endl;
    //左移8位，与乘以2的8次方值相同，类型不同
    cout << bitset<sizeof(s * int(pow(2, 8))) * 8>(s * int(pow(2, 8))) << endl;
    //求反运算符
    cout << bitset<sizeof(~bits) * 8>(~bits) << endl;
    //位与，位或，位异或运算符
    unsigned char b1 = 0145, b2 = 0257;
    cout << bitset<sizeof(decltype(b1 & b2)) * 8>(b1 & b2) << endl;
    cout << bitset<sizeof(decltype(b1 | b2)) * 8>(b1 | b2) << endl;
    cout << bitset<sizeof(decltype(b1 ^ b2)) * 8>(b1 ^ b2) << endl;

    unsigned long quiz1 = 0; //把值当位的集合
    quiz1 |= 1UL << 27;      //第27位改为1
    cout << bitset<sizeof(quiz1) * 8>(quiz1) << endl;
    quiz1 &= ~(1UL << 27); //第27位改为0
    cout << bitset<sizeof(quiz1) * 8>(quiz1) << endl;
    bool status = quiz1 & (1UL << 27); //第27位是否是1；
    cout << status << endl;

    return 0;
}
/*
10011011
00000000000000001001101100000000
10000000000000000000000000000000
00000000000000000000000000010011
1111111101100101
11111111111111110110010100000000
11111111111111110110010100000000
11111111111111111111111101100100
00000000000000000000000000100101
00000000000000000000000011101111
00000000000000000000000011001010
00001000000000000000000000000000
00000000000000000000000000000000
0
*/
