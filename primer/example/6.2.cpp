//6.2 参数传递
/*1.每次调用函数都会重新创建它的形参，并用传入的实参进行初始化。
    2.形参类型决定了形参和实参的交互方式。
    如果形参是引用类型，它将绑定到对应的实参上，
    否则，将实参的值拷贝后赋给形参。
    3.形参是引用类型，对应的实参被引用传递（passed by reference）
    或者函数被传引用调用（called by reference）。引用形参是实参的别名。
    4.实参的值被拷贝给形参时，形参和实参是两个相互独立的对象。
    实参被值传递（passed by value）或函数被传值调用（called by value）。*/
//6.2.1 传值参数
/*1.指针形参
    当执行指针拷贝时，拷贝的是指针的值，拷贝后是两个不同的指针。
    通过指针可以修改它所指对象的值。
    c++中建议用引用代替指针*/
//6.2.2 传引用参数
/*1.引用的操作实际上是作用在引用所引得对象上的。
  2.使用引用避免拷贝
    拷贝大的类类型对象或者容器对象比较低效，
    甚至有的类类型（包括IO类型在内）根部不支持拷贝操作。
  3.使用引用形参返回额外信息
    使用引用形参为我们一次返回多个结果提供了有效的途径。*/
//6.2.3 const形参和实参
/*1.当实参初始化形参时，会忽略掉形参的顶层const。
    即函数重载时，形参列表中的const变量，与不带const的变量相同。
  2.指针或引用形参与const
  3.尽量使用常量引用
    把函数不会改变的形参定义成普通的引用是一种比较常见的错误。
    误以为函数可以改变实参的值。
    使用引用而非常量引用也会极大地限制函数所能接受的实参类型。*/
//6.2.4 数组形参
/*1.数组的两个特殊性质：一是不允许拷贝数组，无法以值传递的方式使用数组参数。
    二使用数组时（通常）会将其转换成指针，传递一个数组时，
    实际上传递的是指向数组首元素的指针。
  2.使用标记指定数组长度
    管理数组实参的第一种方法是要求数组本身包含一个结束标记，
    典型的就是C风格字符串
  3.使用标准库规范
    管理数组实参的第二种技术是传递指向数组首元素和尾元素的指针。
  4.显示传递一个表示数组大小的形参
    专门定义一个表示数组大小的形参
  5.数组形参和const
    当函数不需要对素组元素执行写操作的时候，数组形参应该是指向const指针
  6.数组引用形参，引用形参绑定到对应的实参上，也就是绑定到数组上。
  7.传递多维数组
    处理的事数组的数组，元素首元素本身就是一个数组，
    指针就是一个指向数组的指针，数组的第二维的大小都是素组类型的一部分。*/
//6.2.5 main：处理命令行选项
/*1.有时，我们需要给main传递实参，
    用户可以通过设置一组选项来确定函数所要执行的操作。
    main函数位于prog之内，我们可以向程序传递下面的选项：
    prog -d -o ofile data0
    这些命令通过两个（可选的）形参传递给main函数
    int main（int argc,char *argv[]){...}
    int main (int argc,char **argv){...}
    argv指向char *,当实参传递给main函数之后，
    argv的第一个元素指向程序的名字或者一个空字符串，
    接下来的元素一次传递命令行提供的实参。最后一个指针之后的元素值保证为0。
    以上的命令行，argc等于5，
    argv[0]="prog";//或者argv[0]也可以指向一个空字符串
    argv[1]="-d";
    argv[2]="-o";
    argv[3]="ofile";
    argv[4]="data0";
    argv[5]=0;*/
//6.2.6 含有可变形参的函数
/*1.为了编写能处理不同数量实参的函数，c++11提供了两种主要方法：
    如果所有的实参类型相同，可以传递一个名为initializer_list的标准类型；
    如果实参的类型不同，编写一个特殊函数，也就是所谓的可变参数模板。
    还有一种特殊的形参类型（即省略符），可以用它传递可变数量的实参。
    一般只用于与C函数交互的接口程序。
  2.initializer_list用于特定类型的值的数组，定义在同名头文件中。
  3.  表6.1:initializer_list提供的操作
  initializer_list<T>lst;   默认初始化；T类型元素的空列表
  initializer_list<T>lst{a,b,c...};
  lst的元素数量和初始值一样多；lst的元素是对应初始值的副本；列表中的元素是const
  lst2(lst)或lst2=lst 拷贝或赋值一个initializer_list对象不会拷贝列表中的元素；
  拷贝后，原始列表和副本共享元素
  lst.size()  列表中的元素数量
  lst.begin() 返回指向lst中首元素的指针
  lst.end() 返回指向lst中尾元素下一位置的指针
  4.和vector，一样是模板类型，必须说明列表元素的类型
    和vector不同，initializer_list对象的元素永远是常量值，无法改变其对象中的元素的值。*/
#include <iostream>
#include <cstddef>
#include <system_error>
using namespace std;
//该函数接受一个指针，然后将指针所指的值置为0
void reset(int *ip)
{
    *ip = 0; //改变指针ip所指对象的值
    ip = 0;  //只改变了ip的局部拷贝，实参未被改变
}
//该函数接受一个int对象的引用，然后将对象的值置为0
void reset(int &i) //i是传给reset函数的对象的另一个名字
{
    i = 0; //改变了i所引用对象的值
}
//比较两个string对象的长度
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

//返回s中c第一次出现的位置索引
//引用形参occurs负责统计c出现的总次数
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size(); //第一次出现的位置（如果有的话），没有就不对
    occurs = 0;          //设置表示出现次数的形参的值
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i; //记录c第一次出现的位置
            ++occurs;    //记录出现的次数加1
        }
    }
    return ret; //出现的次数通过occurs隐式地返回
}
//尽管声明形式不同，但这三个print函数是等价的
//每个函数都有一个const int*类型的形参
void print(const int *);
void print(const int[]);   //可以看出来，函数的意图是作用与一个数组
void print(const int[10]); //这里的维度表示我们期望数组含有多少个元素，实际不一定
void print(const int i[10])
{
    cout << *i << endl;
}
void print(const char *cp)
{
    if (cp)                //若cp不是一个空指针
        while (*cp)        //只要指针所指的字符不是空字符
            cout << *cp++; //输出当前字符并将指针向前移动一个位置
    cout << endl;
}
void print(const string str)
{
    auto beg = str.begin(), end = str.end();
    while (beg != end)
        cout << *beg++ << " ";
    cout << endl;
}
void print(const int *beg, const int *end)
{
    //输出beg到end之间（不含end）的所有元素
    while (beg != end)
        cout << *beg++ << " "; //输出当前元素并将指针移动一个位置
    cout << endl;
}
//const int *ia等价于const int ia[]
//size表示数组的大小，将它显式地传给函数用于控制对ia元素的访问
void print(const int *ia, size_t size)
{
    for (size_t i = 0; i != size; i++)
        cout << ia[i] << " ";
    cout << endl;
}
//形参时数组的引用，维度是类型的一部分
void print(const int (&arr)[10])
{
    for (auto elem : arr)
        cout << elem << " ";
    cout << endl;
}
//matrix看起来是一个二维数组，实际上形参是指向含有10个整数的数组的指针
void print(const int matrix[][10], size_t rowsize); //与下面等价
//matrix指向数组的首元素，该数组的元素是由10个整数构成的数组
void print(const int (*matrix)[10], size_t rowSize)
{
    for (size_t i = 0; i != rowSize; i++)
        print(matrix[i], 10);
}
//编写输出错误信息的函数
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}
void error_msg(string e,initializer_list<string> il)
{
    cout << e.size() << ": ";
    for(const auto &elem:il)
        cout << elem << " ";
    cout << endl;
}
int main()
{
    //6.2.1 传值参数
    int n = 0, i = n; //int类型的初始变量，i是n的值得副本:n=0,i=0
    i = 42;           //i的值改变，但n的值不变n=0,i=42

    int *p = &n, *q = &i; //p指向变量n，q指向变量i
    *p = 42;              //n的值改变；p不变：n=42
    p = q;                //p指向变量i；但i和n的值不变n=42,i=42

    reset(&i);                   //改变i的值而非i的地址i=0
    cout << "i = " << i << endl; //输出i=0

    int &r = n; //r绑定了n（即r是n的另一个名字）
    r = 42;     //n=42
    r = i;      //n=i=0;
    i = r;      //i=r=n=0;
    //6.2.2 传引用参数
    int j = 42;
    reset(j);                    //j采用传引用方式，它的值被改变
    cout << "j = " << j << endl; //输出j = 0

    const string s1 = "123456789", s2 = "abcdefghijk", s3 = "";
    cout << isShorter(s1, s2) << endl;

    string::size_type ctr;
    auto index = find_char(s2, 'g', ctr);
    cout << index << ctr << endl;

    //6.2.3
    const int ci = 42;   //不能改变ci但值，const是顶层的
    i = ci;              //正确：当拷贝ci时，忽略了它的顶层const
    int *const cp = &i;  //const是顶层的，不能给cp赋值
    *cp = 0;             //正确：通过解引用改变cp所指对象的值
    const int *cp2 = &i; //指针cp2是常量
    const int &r1 = i;   //引用r1是常量
    const int &r2 = 42;  //引用r2是常量

    //int *p = cp2;//常量不能初始化变量,不能给变量赋值，0，nullptr,NULL对指针除外
    //int &r3 = r;//常量不能初始化变量,不能给变量赋值
    //int &r4 = 42;//常量不能初始化变量,不能给变量赋值

    ctr = 0;
    reset(&i); //调用形参类型是int*的reset函数
    //rest(&ci);//不能用指向const int对象的指针初始化int *
    reset(i); //调用形参是int&的reset函数
    //reset(ci);//不能把普通引用绑定到const int对象上
    //reset(42);//不能把普通引用绑定到字面值上
    //reset(ctr);//ctr是无符号类型，类型不匹配
    //正确：find_char的第一个形参时对常量的引用
    find_char("Hello World", 'o', ctr);

    int m = 0, l[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(&m); //正确：&m的类型是int *
    print(l);  //正确：n转换成int *并指向n[0]

    print("Hello World");
    print(s1);
    print(s2);
    //l转换成指向它首元素的指针
    //第二个实参是指向ld的尾后元素的指针
    print(begin(l), end(l));
    print(l, end(l) - begin(l));
    print(l); //实参是含有10个整数元素的数组

    const int arr[2][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
    print(arr, end(arr) - begin(arr));

    string expected = "a", actual = "b";
    if (expected != actual)
        //形参传递一个值得序列，必须把序列放在一对花括号内：
        error_msg({"functionX", expected, actual});
    else
        error_msg({"functionX", "okay"});
    if (expected != actual)
        //形参传递一个值得序列，必须把序列放在一对花括号内：
        error_msg({"Hello","functionX", expected, actual});
    else
        error_msg({"World!","functionX", "okay"});
    return 0;
}
/*
i = 0
j = 0
1
61
0
0 1 2 3 4 5 6 7 8 9
Hello World
1 2 3 4 5 6 7 8 9
a b c d e f g h i j k
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9 10
0 1 2 3 4 5 6 7 8 9
functionX a b
Hello functionX a b
*/
