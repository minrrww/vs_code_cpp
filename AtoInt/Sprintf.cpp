#include<cstdio>  //sprintf,puts
#define _USE_MATH_DEFINES  //M_PI
#include <cmath> //M_PI
int main()
{
	char s[100]={0};
	sprintf(s, "%d", 123); //十进制输出产生"123"
    puts(s);
    sprintf(s, "%4d%4d", 123, 4567); //指定宽度不足的左边补空格，产生：" 1234567"
    puts(s);
	sprintf(s, "%8o", 123);	//八进制输出，宽度占8个位置
    puts(s);
	sprintf(s, "%8x", 4567); //小写16 进制，宽度占8 个位置，右对齐
    puts(s);
	sprintf(s, "%10.3f", 3.1415626); //产生：" 3.142"
    puts(s);
	int i = 100;
	sprintf(s, "%.2f",/*(float)*/i);	//注意这是不对的
    puts(s);
	sprintf(s, "%.2f", (double)i);	//要按照这种方式才行
    puts(s);
    sprintf(s, "%.2e", (double)i);	//要按照这种方式才行
    puts(s);
    sprintf(s, "%s", "asvd");	//字符串
    puts(s);
    sprintf(s, "%c", 97);	//字符
    puts(s);
    sprintf(s, "Pi 的值 = %.18f", M_PI); //奇怪的结果
    puts(s);
    getchar();
    return 0;
}
//sprintf 与printf 相似
