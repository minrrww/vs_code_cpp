#include <iostream>
using namespace std;
int main()

{
	int a = 3;
	int *b = &a;
	cout << "a：" << a << endl;
	cout << "b：" << b << endl;
	*b = 10;
	cout << "&a：" << &a << endl;
	cout << "b：" << b << endl;
    cout << "*b：" << *b << endl;
	system("pause");
}
