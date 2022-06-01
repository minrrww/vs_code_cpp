#include<iostream>
#include<string>
#include<sstream>//stringstream
using namespace std;
int main(void)
{
	string s="20";
	int a;
	stringstream ss;
	ss<<hex<<s;  //以16进制读入流中
	ss>>a; //10进制int型输出
	cout<<a<<endl;//输出：32

    string s1,s2;
    int b = 30;
    stringstream sss;
    sss << oct << b; //10进制转成八进制读入流中，再以字符串输出
    sss >> s1;
    cout << s1 << endl; //输出：36
    sss.clear();        //不清空可能会出错。
    sss << hex << b;    //10进制转成十六进制读入流中，，再以字符串输出
    sss >> s2;
    cout << s2 << endl; //输出：1e
    return 0;
}

