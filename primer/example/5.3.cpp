//5.3 条件语句
//5.3.1 if语句（if statement）
/*1.if语句：判断一个指定的条件是否为真，根据判断结果决定是否执行另外一条语句
  if语句两种形式：一种含有else,另一种没有*/
/*2.嵌套if语句*/
/*3.悬垂else（dangling else）：c++规定else与离它最近的尚未匹配的if匹配*/
//5.3.2 switch语句（switch statement）
/*1.switch语句：提供了一条便利的途径使得我们能够在若干固定选项中做出选择。
    如果switch(表达式)中的表达式与case标签的值匹配成功，
    程序从该标签之后第一条语句开始执行，
    直到达到了switch的结尾或者遇到一条break语句为止。
  2.break语句的作用是中断当前的控制流。
    在switch语句中，break将语句控制权转移到switch语句外面。
    有时，我们希望两个或更多值共享同一组操作，故意省略掉break语句。
    写漏break语句容易引发缺陷。
  3.case关键字和它对应的值一起被称为case标签（case label），
    必须是整型常量表达式，任何两个case标签值不能相同，
  4.default也是一种特殊的case标签。default:...break;
    表示程序默认情况，如果switch结构以一个空default标签作为结束，
    必须跟上一个空语句或空块
  5.switch内部的变量定义：若果有变量定义在跳过的case标签后，
    应该把变量定义在块内，确保后面的所有case标签都在变量的作用域之外。*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //5.3.1
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    unsigned int grade;
    string lettergrade;
    cin >> grade;
    //如果成绩不合格，不需要添加+或-
    if (grade < 60)
        cout << (lettergrade = scores[0]) << endl;
    else
    {
        lettergrade = scores[(grade - 50) / 10]; //获得字幕形式的成绩
        if (grade != 100)                        //只要成绩不是A++，就考虑+或-
            if (grade % 10 > 7)
                lettergrade += '+'; //末尾是8或9，添加一个+
            else if (grade % 10 < 3)
                lettergrade += '-'; //末尾是0,1或2，添加一个-
        cout << lettergrade << endl;
    }

    //5.3.2
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch)
    {
        //如果ch是元音字母，将其对应的计数器值加1
        switch (ch)
        {
        case 'a':
            ++aCnt;
            break;
        case 'e':
            ++eCnt;
            break;
        case 'i':
            ++iCnt;
            break;
        case 'o':
            ++oCnt;
            break;
        case 'u':
            ++uCnt;
            break;
        default:
            break;
        }
    }
    cout << aCnt << " " << eCnt << " " << iCnt << " " << oCnt << " " << uCnt << endl;
    return 0;
}
