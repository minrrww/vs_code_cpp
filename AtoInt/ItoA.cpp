#include<cstdio>//printf
#include<cstdlib>//_itoa
int main()
{
    int num = 0b1111111 ^ 0b1010101<<2;
    char str[100];
    _itoa(num, str, 2);  //c++中一般用_itoa，用itoa也行,
    //_itoa(num, str, 2); num是一个int型的，是要转化的10进制数，str是转化结果，后面的值为目标进制。
    printf("%s\n", str);
    getchar();
    return 0;
}
