#include <iostream> //#include 指令:告诉编译器，需要用iostream库
/*
 *简单主函数：
 *读取两个数，求它们的和
 */
using namespace std;
int main()
{
    //提示用户输入两个数
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;   //保存我们读入的输入数据的变量
    std::cin >> v1 >> v2; //读取输入数据
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    std::cout << "标准输出对象" << std::endl;
    std::cerr << "输出警告和错误信息" << std::endl;
    std::clog << "输出程序运行时的一般信息" << std::endl;
    return 0;
}
