#include <iostream>
using namespace std;
int Atoi(string s, int radix);
int main()
{
    cout << Atoi("1520", 8) << endl;//01520 to 848
	cout << Atoi("10101111", 2) << endl;//0b10101111 to 175
	cout << Atoi("5c", 16) << endl;//0x6fe3 to 28643
    system("pause");//system("PAUSE")  是暂停的意思，等待用户信号；不然控制台程序会一闪即过，
    //你来不及看到执行结果
    return 0;
}
int Atoi(string s,int radix)    //s是给定的radix进制字符串
{
	int ans=0;
	for(int i=0;i<(int)(s.size());i++)
	{
		char t=s[i];//s[0]-s[i]从左至右
		if(t>='0'&&t<='9') ans=ans*radix+t-'0';//2-36进制中小于10的数字转化为10进制
		else ans=ans*radix+t-'a'+10;//t-'a'+10,表示2-36进制大于9的t转为10进制
	}
		return ans;
}//0-9 and a-z 共36个字符，最多可表示36进制，最少表示2进制
