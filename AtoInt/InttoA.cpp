#include <iostream>
#include <algorithm>//����reverse()
using namespace std;
string intToA(int n, int radix);
int main()
{
    cout<<intToA(49540, 2)<<endl;

}
string intToA(int n,int radix) //n�Ǵ�ת���֣�radix��ָ���Ľ���
{
	string ans="";
	do{
		int t=n%radix;
		if(t>=0&&t<=9)	ans+=t+'0';
		else ans+=t-10+'a';
		n/=radix;
	}while(n!=0);	//ʹ��do{}while�����Է�ֹ����Ϊ0�����
	reverse(ans.begin(),ans.end());//reverse�������ڷ�ת��[first,last)��Χ�ڵ�˳�򣨰���firstָ���Ԫ�أ�������lastָ���Ԫ�أ���reverse����û�з���ֵ
	return ans;
}
