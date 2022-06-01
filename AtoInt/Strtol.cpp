#include <cstdio>//声明printf()
#include <cstdlib>//声明strtol()
int main()
{
    char buffer[20]="10549stend#12";
    char *stop;
    int ans=strtol(buffer, &stop, 8);//将八进制数1054转成十进制556，后面均为非法字符
    /*long int strtol(const char *nptr, char **endptr, int base)
    base是要转化的数的进制，非法字符会赋值给endptr，nptr是要转化的字符*/
    printf("%d\n",ans);//十进制输出
    printf("%s\n",stop);//输出字符串
    printf("%05o\n",35);    //按八进制格式输出，保留5位高位补零，(正数不输出符号)
    printf("%3d\n",-35);    //按十进制格式输出，保留3位高位补零(正数不输出符号)
    printf("%03u\n",35);    //按十进制格式输出，无符号整数
    printf("%05x\n",35);    //按十六进制格式输出，保留5位高位补零(不输出前缀0x)
    printf("%#05x\n",35);  //按十六进制格式输出，保留5位高位补零(输出前缀0x)
    printf("%f\n",35.23);    //以小数形式输出单、双精度实数
    printf("%e\n",0.0013523);    //	以指数形式输出单、双精度实数
    printf("%g\n",0.001355);    //	以指数形式输出单、双精度实数
    printf("%g\n",0.00000001355);//以%f或%e中较短的输出宽度输出单、双精度实数
    printf("%c\n",97);//输出单个字符
    getchar();
    return 0;
}
