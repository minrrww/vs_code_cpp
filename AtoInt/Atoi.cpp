#include <iostream>
using namespace std;
int Atoi(string s, int radix);
int main()
{
    cout << Atoi("1520", 8) << endl;//01520 to 848
	cout << Atoi("10101111", 2) << endl;//0b10101111 to 175
	cout << Atoi("5c", 16) << endl;//0x6fe3 to 28643
    system("pause");//system("PAUSE")  ����ͣ����˼���ȴ��û��źţ���Ȼ����̨�����һ��������
    //������������ִ�н��
    return 0;
}
int Atoi(string s,int radix)    //s�Ǹ�����radix�����ַ���
{
	int ans=0;
	for(int i=0;i<(int)(s.size());i++)
	{
		char t=s[i];//s[0]-s[i]��������
		if(t>='0'&&t<='9') ans=ans*radix+t-'0';//2-36������С��10������ת��Ϊ10����
		else ans=ans*radix+t-'a'+10;//t-'a'+10,��ʾ2-36���ƴ���9��tתΪ10����
	}
		return ans;
}//0-9 and a-z ��36���ַ������ɱ�ʾ36���ƣ����ٱ�ʾ2����
