//5.5 跳转语句
//1.C++提供了4中跳转语句：break、continue、goto和return。
//5.5.1 break语句
/*1.break语句（break statement）负责终止离它最近的while、do while、for或switch语句，
    并从这些语句之后的第一条语句开始继续执行。
  2.break语句只能出现在迭代语句或者switch语句内部。*/
//5.5.2 continue语句
/*1.continue语句（continue statement）终止最近的循环中的当前迭代并立即开始下一次迭代。
  2.continue语句只能出现在for、while、do while循环的内部，
  或嵌套在此类循环里的语句或块内部。
  3.出现在嵌套循环中的continue语句仅作用于离它最近的循环，
  只有当switch语句嵌套在迭代语句内部时，才能在switch里使用continue。*/
//5.5.3 goto语句
//goto语句（goto statement）的作用是从goto语句无条件跳转到同一函数内的另一条语句。
//1.不要在程序中使用goto语句，因为它使得程序既难理解。
/*2.goto语句的语法形式：goto label;label是用于标识一条语句的标示符。
    带标签语句（labeled statement）是一种特殊的语句，在它之前有一个标示符以及一个冒号：
    end:return;
  3.和switch语句类似，goto语句不能将程序的控制权从变量的作用域之外
    转移到作用域之内。
  4.向后跳过一个已经执行的定义是合法的。
    跳回到变量定义之前意味着系统将销毁该变量，然后重新创建它。*/

#include <iostream>

using namespace std;

int main()
{
    //5.5.1
    string buf;
    while (cin >> buf && !buf.empty())
    {
        switch (buf[0])
        {
        case '-':
            //处理到第一个空白为止
            for (auto it = buf.begin() + 1; it != buf.end(); ++it)
            {
                if (*it == ' ')
                    break; //#1，离开for循环
                //...
            }
            //break #1将控制权转移到这里
            //剩余的'-'处理：
            break; //#2,离开switch语句
        case '+':; //...
        }          //结束switch
        //结束switch：break #2将控制权转移到这里
    } //结束while
    cin.clear();
    cin.sync();

    //5.5.2
    while (cin >> buf && !buf.empty())
    {
        ir(buf[0] != '_') continue; //接着读取下一个输入
        //程序执行过程到了这里？说明当前的输入是以下划线开始的；接着处理buf...
    }
    return 0;
}
