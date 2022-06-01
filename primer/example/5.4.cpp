//5.4 迭代语句
//迭代语句通常称为循环。
//5.4.1 while语句
/*1.只要条件为真，while语句（while statement）就重复地执行循环体。
  2.while的的条件部分可以是一个表达式或者一个带初始化的变量声明，
    条件本身或循环体设法 改变表达式的值，否则循环可能无法终止。
  3.当不确定到底要迭代多少次时，使用while循环比较合适。
*/
//5.4.2 传统的for语句
/*1.for语句的语法形式：for(init-statement;condition;expression)statement;
    init-statement必须是以下三中形式中的一种：声明语句、表达式语句或者空语句。
    expression负责修改init-statement初始化的变量，
    这个变量正式condition检查的对象。
  2.for语句头中的多重定义，init-statement可以定义多个对象，但只能有一条声明语句。
  3.省略for语句头的某些部分：可以省略任何一个或全部。
    省略init-statement，可以用空语句。
    省略condition，在循环体内必须有语句负责退出循环，否则就会一直循环下去。
    省略expression，这样的循环要求条件部分或循环体内必须改变迭代变量的值。*/
//5.4.3 范围for语句
/*1.C++11引入了一种更简单的for语句，这种语句可以遍历容器或其他序列的所有元素。
    范围for语句（range for statement）的语法形式：
    for(declaration:expression)statement
    1.expression表示一个序列，比如用花括号括起来的初始值列表、
      数组、vector、string等类型的对象，
      这些类型的共同特点是能返回迭代器begin和end成员。
    2.declaration定义一个变量，序列中每个元素都能转化成该变量的类型。
      如果需要对序列中的元素执行写操作，循环变量必须声明成引用类型。*/
//5.4.4 do while 语句
/*1.do while先执行循环体，再检查条件，不管条件如何，至少循环一次。
  2.do while语句的语法形式：do statement while(condition).
    condition不能为空，condition使用变量必须定义在循环体外。
    不能再循环体，和条件部分定义变量。*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //5.4.1
    vector<int> v;
    //重复读入数据，直到达到文件末尾或者遇到其他输入问题
    for (int i; cin >> i; /*表达式为空*/)
        v.push_back(i);
    cin.clear(); //设置cin状态为0
    cin.sync();  //清除缓存区数据流
    //int i;
    /*while (cin >> i)
         v.push_back(i);*/
    //寻找第一个负值元素
    auto beg = v.begin();
    while (beg != v.end() && *beg >= 0)
        ++beg;
    if (beg == v.end())
        cout << "v中所有元素大于等于0" << endl;
    //5.4.2
    string s = "Hello,world!";
    //重复处理s中的字符直至我们处理完全部字符或者遇到一个表示空白的字符
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
        cout << (s[index] = toupper(s[index])); //将当前字符改成大写形式
    cout << endl;

    for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
        cout << v[i] << endl;

    beg = v.begin();
    for (/*空语句*/; beg != v.end() && *beg >= 0; ++beg)
        ; //什么也不做
    //5.4.3
    vector<int> iv = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //范围变量必须是引用类型，这样才能对元素执行写操作
    for (auto &r : iv) //对于iv中的每一个元素
        cout << (r *= 2) << " ";
    cout << endl;
    for (auto beg = iv.begin(), end = iv.end(); beg != end; ++beg)
    {
        auto &r = *beg;          //r必须是引用类型，这样才能对元素执行写操作
        cout << (r *= 2) << " "; //对于iv中的每一个元素的值翻倍
    }
    cout << endl;
    //5.4.4
    //不断提示用户输入一对数，然后求和
    string rsp; //作为循环的条件，不能定义在do的内部
    do
    {
        cout << "please enter two values:" << endl;
        int val1 = 0, val2 = 0;
        cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
             << " = " << val1 + val2 << "\n\n"
             << "More?Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
    return 0;
}
/*
23
56
89
98
65
32
^Z
v中所有元素大于等于0
HELLO,WORLD!
23
56
89
98
65
32
0 2 4 6 8 10 12 14 16 18
0 4 8 12 16 20 24 28 32 36
please enter two values:
23
65
The sum of 23 and 65 = 88

More?Enter yes or no:
2
please enter two values:
56
98
The sum of 56 and 98 = 154

More?Enter yes or no:
23
please enter two values:
65
56
The sum of 65 and 56 = 121

More?Enter yes or no:
n
*/
