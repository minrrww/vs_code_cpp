#include <iostream>
using namespace std;
int main ()
{
	double f,c;                //定义存放华氏温度及摄氏温度的两个变量空间
	cout<<"请输入华氏温度";	   //输出提示信息
	cin>>f;                    //从键盘输入华氏温度
	c=(f-32)*5/9;              //计算摄氏温度
	cout<<"摄氏温度="<<c<<endl;
    system("pause");
}
