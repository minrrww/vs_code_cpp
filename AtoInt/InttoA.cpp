#include <iostream>
#include <algorithm>//声明reverse()
using namespace std;
string intToA(int n, int radix);
int main()
{
    cout<<intToA(49540, 2)<<endl;

}
string intToA(int n,int radix) //n是待转数字，radix是指定的进制
{
	string ans="";
	do{
		int t=n%radix;
		if(t>=0&&t<=9)	ans+=t+'0';
		else ans+=t-10+'a';
		n/=radix;
	}while(n!=0);	//使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(),ans.end());//reverse函数用于反转在[first,last)范围内的顺序（包括first指向的元素，不包括last指向的元素），reverse函数没有返回值
	return ans;
}
