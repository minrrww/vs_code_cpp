#include<iostream>
#include<string>
#include<sstream>//stringstream
using namespace std;
int main(void)
{
	string s="20";
	int a;
	stringstream ss;
	ss<<hex<<s;  //��16���ƶ�������
	ss>>a; //10����int�����
	cout<<a<<endl;//�����32

    string s1,s2;
    int b = 30;
    stringstream sss;
    sss << oct << b; //10����ת�ɰ˽��ƶ������У������ַ������
    sss >> s1;
    cout << s1 << endl; //�����36
    sss.clear();        //����տ��ܻ����
    sss << hex << b;    //10����ת��ʮ�����ƶ������У��������ַ������
    sss >> s2;
    cout << s2 << endl; //�����1e
    return 0;
}

