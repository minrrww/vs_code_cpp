#include <iostream>
using namespace std;
int main ()
{
	int a,b,sum;
	cout<<"请输入加数与被加数\n";
	cin>>a>>b;
	sum=a+b;
	cout<<"sum="<<sum<<endl;
	/*while(getchar()!='\n')  //这两句代码是清空输入缓冲区内容，等同于fflush(stdin);
    continue;
    getchar();*/


	system("pause");
}

