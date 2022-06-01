#include <iostream>
using namespace std;
int _reverse(int x);
bool ispalindromenum(int n);
int main()
{
    int n;
    cout << "Enter a number:" << endl;
    cin >> n;
    cout << "The new number is:" << _reverse(n) << endl;
    for (int i = 0; i <= 10000; i++)
    {
        if (ispalindromenum(i))
            cout << "Spalindrome Number:" << i << endl;
        if (ispalindromenum(i) && ispalindromenum(i * i) && ispalindromenum(i * i * i))
            cout << i << "is super Spalindrome Number!" << endl;
    }
    getchar();
    return 0;
}
int _reverse(int x) //数的倒序数
{
    int n = x, newnum = 0, right_dijit;
    do
    {
        right_dijit = n % 10;
        newnum = right_dijit + newnum * 10;
        n /= 10;
    } while (n != 0);
    return newnum;
}
bool ispalindromenum(int n) //回文数
{
    int a = n;
    if (a == _reverse(a))
        return true;
    else
        return false;
}
