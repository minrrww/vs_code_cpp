//6.3 返回类型和return语句
//6.3.1无返回值函数
/*1.没有返回值的return语句只能用在返回类型为void的函数中。
    返回void的函数不要求非得有return语句。
    无返回语句需要中途退出，可用用return语句。*/
//6.3.2 有返回值函数
/*1.只要函数的返回类型不是void，则该函数每条return必须返回一个值。
    返回的值必须和函数的返回类型相同，或可以隐式地转换成函数的返回类型。
  2.含有return语句的循环后面应该也有一条return语句。
  3.值是如何被返回的：
    返回的值用于初始化调用点的一个临时量，该临时量就是函数调用的结果。
    返回类型是普通变量，返回值将被拷贝到调用点。
    函数返回引用，该引用仅是它所引对象的一个别名。
  4.不要返回局部对象的引用或指针，
    函数终止，局部变量的引用指向不再有效的内存区域
  5.返回类类型的函数和调用运算符
    如果函数返回指针、引用或类的对象，
    我们就能使用函数调用的结果访问结果对象的成员。*/
/*6.引用返回左值，函数返回类型决定函数调用是否是左值。
    调用一个返回引用得函数得到左值，其他返回类型得到右值。
    能为返回类型是非常量引用得函数的结果赋值。
  7.列表初始化返回值
    C++11函数可以返回花括号保卫的值得列表。
    对表示函数返回的临时量进行初始化。
    如果列表为空，临时量执行值初始化；
    否则，返回的值有函数的返回类型决定。
    如果返回的事内置类型，则花括号包围的列表最多包含一个值，
    所占空间不应该大于目标类型的空间。
    如果返回的事类类型，由类本身定义初始值如何使用。
  8.主函数main的返回值
    如果main函数结尾处没有return语句，编译器隐式插入一条return 0语句。
  9.递归，函数调用自身，不管调用时直接还是间接，
    都称该函数为递归函数（recursive function)。
    递归函数中，一定有某条路径是不包含递归调用的。
    递归循环（recursion loop）*/
//6.3.3 返回数组指针
/*1.函数不能返回数组，但可以返回数组指针。
    使用类型别名可以简化定义返回数组指针的函数。
  2.声明一个返回数组指针的函数。返回数组指针的函数形式如下：
    Type (*function(parameter_list))[dimension]{}
    Type表示元素的类型，dimension标书数组的大小。
    (*function(parameter_list))两端的括号必须存在。
    函数的形参必须紧跟函数名字之后。形参列表先于数组的维度。
    func(int i)表示调用func函数时需要一个int类型的实参
    （*func(int i))意味着我们可以对函数调用的结果执行解引用操作
    (*fun(int i))[10]表示解引用func的调用将得到一个大小是10的数组
  3.使用尾置返回类型（trailing return type）
    任何函数都可以使用尾置返回。
    尾置返回类型跟在形参列表后面并以一个->符号开头。
    返回类型设置为auto:
    //func接受一个int类型的实参，返回一个指针，该指针指向一个含有10个整数的数组。
    auto func(int i) -> int(*)[10];
  4.使用decltype
    */
#include <iostream>
#include <cstddef>
#include <vector>
#include <cstdlib>
using namespace std;
void swap(int &v1, int &v2)
{
    //6.3.1
    //如果两个值相等，则不需要交换，直接退出
    if (v1 == v2)
        return;
    //若果程序执行到这里，说明还需要继续完成某些功能
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
    //此处无需显式的return语句
}
//因为含有不正确的返回值，所以这段代码无法通过编译
/*bool str_subrange(const string &str1, const string &str2)
{
    //大小相同：此时用普通的相等性判断结果作为返回值
    if (str1.size() == str2.size())
        return str1 == str2; //正确：==运算符返回布尔值
    //得到较短string对象的大小
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    //检查两个string对象的对应字符是否相等，以较短的字符串长度为限
    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            return; //错误#1：没有返回值，编译器讲报告这一错误
    }
    //错误#2：控制流可能尚未返回任何值就结束了函数的执行
    //编译器可能检查不出这一错误
}*/
//如果ctr的值大于1，返回word的复数形式
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
//挑出两个string对象中较短的那个，返回其引用
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
//严重错误：这个函数试图返回局部对象的引用
/*const string &manip()
{
    string ret;
    //以某种方式改变一下ret
    if (!ret.empty())
        return ret; //错误：返回局部对象的引用！
    else
        return "Empty"; //错误："Empty"是一个局部临时量
}*/

char &get_val(string &str, string::size_type ix)
{
    return str[ix]; //get_val假定索引值时有效的
}
vector<string> process()
{
    //...
    //expected,actual是string对象
    string expected = "A", actual = "B";
    if (expected.empty())
        return {}; //返回一个空vector对象
    else if (expected == actual)
        return {"functionX", "okay"}; //返回列表初始化的vector对象
    else
        return {"functionX", expected, actual};
}
//计算val的阶乘，即1*2*3...*val
int factorial(int val)
{
    if (val > 1)
        return factorial(val - 1) * val;
    return 1;
}
typedef int arrT[5]; //arrT是一个类型别名，表示类型是含有10个整数的数组
//using arrT = int[5];//arrT的等价声明
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
arrT *func(int i);               //func返回一个指向含有10个整数的数组的指针
int (*func(int i))[5];          //等同上面的函数声明
auto func(int i) -> int (*)[5] //等同上面的函数声明
{
    return (i % 2) ? &odd : &even; //返回一个指向数组的指针
}

//返回一个指针，该指针指向含有5个整数的数组
decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even; //返回一个指向数组的指针
}
int main()
{
    string s("a value");
    cout << s << endl;   //输出a value
    get_val(s, 0) = 'A'; //将s[0]的值改为A
    cout << s << endl;   //输出A value
    cout << *++process().begin() << endl;
    cout << factorial(5) << endl;
    int arr[10];         //arr是一个含有10个整数的数组
    int *p1[10];         //p1是一个含有10个指针的数组
    int(*p2)[10] = &arr; //p2是一个指针，指向含有10个整数的数组
    cout << **arrPtr(4)<< endl;
    cout << **func(4) << endl;
    bool some_failure = 1;
    if (some_failure)
        return EXIT_FAILURE; //定义在cstdlib头文件中
    else
        return EXIT_SUCCESS; //定义在cstdlib头文件中

    //return 0;
}
