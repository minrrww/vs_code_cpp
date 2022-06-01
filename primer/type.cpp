#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <limits>
using namespace std;
int main()
{
     cout << setiosflags(ios::left) << setw(4) << typeid(bool).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(bool)
          << setw(4)<< "Max:" << setw(22) << numeric_limits<bool>::max()
          << setw(4)<< "Min:" << setw(22) << numeric_limits<bool>::min() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(char).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(char)
          << setw(4)<< "Max:" << setw(22) << (int)numeric_limits<char>::max()
          << setw(4)<< "Min:" << setw(22) << (int)numeric_limits<char>::min() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(signed char).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(signed char)
          << setw(4)<< "Max:" << setw(22) << (int)numeric_limits<signed char>::max()
          << setw(4)<< "Min:" << setw(22) << (int)numeric_limits<signed char>::min() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(unsigned char).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(unsigned char)
          << setw(4)<< "Max:" << setw(22) << (int)numeric_limits<unsigned char>::max()
          << setw(4)<< "Min:" << setw(22) << (int)numeric_limits<unsigned char>::min() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(wchar_t).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(wchar_t)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<wchar_t>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<wchar_t>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(char16_t).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(char16_t)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<char16_t>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<char16_t>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(char32_t).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(char32_t)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<char32_t>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<char32_t>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(short).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(short)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<short>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<short>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(unsigned short).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(unsigned short)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<unsigned short>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<unsigned short>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(int).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(int)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<int>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<int>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(unsigned int).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(unsigned)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<unsigned>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<unsigned>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(long).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(long)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<long>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<long>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(unsigned long).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(unsigned long)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<unsigned long>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<unsigned long>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(long long).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(long long)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<long long>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<long long>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(unsigned long long).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(unsigned long long)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<unsigned long long>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<unsigned long long>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(__int64).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(__int64)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<__int64>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<__int64>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(unsigned __int64).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(unsigned __int64)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<unsigned __int64>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<unsigned __int64>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(float).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(float)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<float>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<float>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(double).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(double)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<double>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<double>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(long double).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(long double)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<long double>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<long double>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << typeid(size_t).name()
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(size_t)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<size_t>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<size_t>::min)() << endl;
     cout << setiosflags(ios::left) << setw(4) << "str"
          << setw(16) << "占用字节数：" << setw(3)<<sizeof(string)
          << setw(4)<< "Max:" << setw(22) << (numeric_limits<string>::max)()
          << setw(4)<< "Min:" << setw(22) << (numeric_limits<string>::min)() << endl;
     return 0;
}
/*
b   占用字节数：1  Max:1                     Min:0
c   占用字节数：1  Max:127                   Min:-128
a   占用字节数：1  Max:127                   Min:-128
h   占用字节数：1  Max:255                   Min:0
w   占用字节数：2  Max:65535                 Min:0
Ds  占用字节数：2  Max:65535                 Min:0
Di  占用字节数：4  Max:4294967295            Min:0
s   占用字节数：2  Max:32767                 Min:-32768
t   占用字节数：2  Max:65535                 Min:0
i   占用字节数：4  Max:2147483647            Min:-2147483648
j   占用字节数：4  Max:4294967295            Min:0
l   占用字节数：4  Max:2147483647            Min:-2147483648
m   占用字节数：4  Max:4294967295            Min:0
x   占用字节数：8  Max:9223372036854775807   Min:-9223372036854775808
y   占用字节数：8  Max:18446744073709551615  Min:0
x   占用字节数：8  Max:9223372036854775807   Min:-9223372036854775808
y   占用字节数：8  Max:18446744073709551615  Min:0
f   占用字节数：4  Max:3.40282e+38           Min:1.17549e-38
d   占用字节数：8  Max:1.79769e+308          Min:2.22507e-308
e   占用字节数：16 Max:1.18973e+4932         Min:3.3621e-4932
y   占用字节数：8  Max:18446744073709551615  Min:0
str 占用字节数：32 Max:                      Min:
*/
