#include<cstdio>  //sprintf,puts
#define _USE_MATH_DEFINES  //M_PI
#include <cmath> //M_PI
int main()
{
	char s[100]={0};
	sprintf(s, "%d", 123); //ʮ�����������"123"
    puts(s);
    sprintf(s, "%4d%4d", 123, 4567); //ָ����Ȳ������߲��ո񣬲�����" 1234567"
    puts(s);
	sprintf(s, "%8o", 123);	//�˽�����������ռ8��λ��
    puts(s);
	sprintf(s, "%8x", 4567); //Сд16 ���ƣ����ռ8 ��λ�ã��Ҷ���
    puts(s);
	sprintf(s, "%10.3f", 3.1415626); //������" 3.142"
    puts(s);
	int i = 100;
	sprintf(s, "%.2f",/*(float)*/i);	//ע�����ǲ��Ե�
    puts(s);
	sprintf(s, "%.2f", (double)i);	//Ҫ�������ַ�ʽ����
    puts(s);
    sprintf(s, "%.2e", (double)i);	//Ҫ�������ַ�ʽ����
    puts(s);
    sprintf(s, "%s", "asvd");	//�ַ���
    puts(s);
    sprintf(s, "%c", 97);	//�ַ�
    puts(s);
    sprintf(s, "Pi ��ֵ = %.18f", M_PI); //��ֵĽ��
    puts(s);
    getchar();
    return 0;
}
//sprintf ��printf ����
