#include<cstdio>//printf
#include<cstdlib>//_itoa
int main()
{
    int num = 0b1111111 ^ 0b1010101<<2;
    char str[100];
    _itoa(num, str, 2);  //c++��һ����_itoa����itoaҲ��,
    //_itoa(num, str, 2); num��һ��int�͵ģ���Ҫת����10��������str��ת������������ֵΪĿ����ơ�
    printf("%s\n", str);
    getchar();
    return 0;
}
