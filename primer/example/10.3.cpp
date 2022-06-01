//10.3 定制操作
/*很多算法都会比较输入序列中的元素。默认情况下，这类算法使用元素类型的<或==运算符完成比较。
标准库还为这些算法定义了额外的版本，允许我们提供自己定义的操作来代替默认运算符。*/
//10.3.1 向算法传递函数
/*1.谓词（predicate）
谓词是一个可调用的表达式，其返回结果是一个能用作条件的值。
标准库算法所使用的谓词分为两类：一元谓词（unary predicate）和二元谓词（binary predicate）。
接受谓词参数的算法对输入序列中元素调用谓词。元素类型必须能转换为谓词的参数类型。
2.排序算法
stable_sort算法，可以保持等长度间的字典序*/
//10.3.2 lambda表达式
/*1.介绍lambda
我们可以向一个算法传递任何类别的可调用对象（callable object）。
对于一个对象或一个表达式，如果可以对其使用调用运算符，则称它为可调用的。
我们使用过的仅有两种可调用对象是函数和函数指针。
还有两种可调用对象：重载了函数调用运算符的类以及lambda表达式（lambda expressi）。
一个lambda表达式表示一个可调用的代码单元。我们可以理解为一个未命名的内联函数。
与任何函数类似，一个lambda具有一个返回类型、一个参数列表和一个函数体。
但与函数不同，lambda可能定义在函数内部。一个lambda表达式具有如下形式：
[capture list](parameter lsit)->return type {function body}
capture list（捕获列表）是一个lambda所在函数中定义的局部变量的列表（通常为空）；
return type、parameter list和function body与任何普通函数一样，分别表示返回类型，参数列表和函数体。
与函数不同，lambda必须使用尾置返回来指定返回类型。
可以忽略参数列表和返回类型，但必须永远包含捕获类别和函数体
auto f=[]{return 42};
lambda的调用方式与普通函数的调用方式相同
cout<<f()<<endl;
在lambda中忽略括号和参数列表等价于指定一个空参数列表。
如果忽略返回类型，lambda根据函数体中的代码推断出返回类型。
如果函数体只是一个return语句，则返回类型从返回的表达式的类型推断出来。
否则，返回类型为void
如果lambda的函数体包含任何单一return语句之外的内容，且未指定返回类型，则返回void。
2.向lambda传递参数
与普通函数调用类似，调用一个lambda时给定的实参被用来初始化lambda的形参。
实参和形参的类型必须匹配。与普通函数不同，lambda不能有默认参数。
lambda调用的实参数目永远与形参数目相等。
空捕获列表表明此lambda不实用它所在函数中的任何局部变量。
3.使用捕获列表
虽然一个lambda可以出现在一个函数中，使用其局部变量，但它只能使用那些明确指明的变量。
一个lambda通过将局部变量包含在其捕获列表中类指出将会使用这些变量。
一个lambda只有在其捕获列表中捕获一个它所在函数中的局部变量，才能在函数体中使用该变量。
4.调用find_if
find_if的调用返回一个迭代器，指向第一个长度不小于给定参数sz的元素。
如果这样的元素不存在，则返回words.end()的一个拷贝。
make_plural单词的单数或复数
5.for_each算法
此算法接受一个可调用对象，并对输入序列中每个元素调用此对象。

捕获列表只用于局部非static变量，lambda可以直接使用局部static变量和在它所在函数之外声明的名字。*/

//10.3.3 lambda捕获和返回
/*当定义一个lambda时，编译器生成一个与lambda对应的新的（未命名的）类类型。
当向一个函数传递一个lambda时，同时定义了一个新类型和该类型的一个对象：
传递的参数就是此编译器生成的类类型的未命名对象。
当使用auto定义一个用lambda初始化的变量时，定义了一个从lambda生成的类型的对象。
从lambda生成的类都包含一个对应该lambda所捕获的变量的数据成员。
类似任何普通类的数据成员，lambda的数据成员也在lambda对象创建时被初始化。
1.值捕获
类似参数传递，变量的捕获方式也可以是值或引用。
与传递值参数类似，采用值捕获的前提是变量可以拷贝。
与参数不同，被捕获的变量的值是在lambda创建时拷贝，而不是调用时拷贝。
2.引用捕获
一个以引用方式捕获的变量与其他任何类型的引用的行为类似。
当我们在lambda函数体内使用此变量时，实际上是用的时引用所绑定的对象。
采用引用方式捕获一个变量，就必须确保被引用的对象在lambda执行的时候是存在的。
如果函数返回一个lambda，则与函数不能返回一个局部变量的引用类似，此lambda也不能包含引用捕获。
建议：尽量保持lambda的变量捕获简单化
捕获一个普通变量，如int，string或其它非指针类型，通常可以采用简单的值捕获方式。
如果我们捕获一个指针或迭代器，或采用引用捕获方式，
必须保证lambda执行时，绑定到迭代器、指针或引用的对象仍然存在。
3.隐式捕获
为了指示编译器推断捕获列表，应在捕获列表中写一个&或=。
&表示采用捕获引用方式，=则表示采用值捕获方式。
可以部分变量采用值捕获，其它变量采用引用捕获。
表 10.1 ：lambda捕获列表
[]                    空捕获类别。lambda不能使用所在函数中的变量。
                      一个lambda只有捕获变量后才能使用它们
[names]               names时一个逗号分隔的名字列表，这些名字都是lambda所在函数的局部变量。
                      默认情况下，捕获列表中变量都被拷贝。
                      名字前如果使用&，则采用引用捕获方式
[&]                   隐式捕获列表，采用引用捕获方式。
                      lambda体中所使用的来自所在函数的实体都采用引用方式使用
[=]                   隐式捕获列表，采用值捕获方式。
                      lambda体将拷贝所使用的来自所在函数的实体的值
[&,identifier_list]   identifier_list是一个逗号分隔的列表，包含0个或多个来自所在函数的变量。
                      这些变量采用值捕获方式，而隐式捕获的变量都采用引用方式捕获。
                      identifier_list中的名字前面不能使用&
[=,identifier_list]   identifier_list中的变量都采用引用方式捕获，
                      而任何隐式捕获的变量都采用值方式捕获。
                      identifier_list中的名字不能包含this，且这些名字之前必须使用&

4.可变lambda
默认情况下，对于一个值被拷贝的变量，lambda不会改变其值。
如果希望改变一个被捕获的变量的值，就必须在参数列表首加上关键字mutable。
5.指定lambda返回类型
默认情况下，如果一个lambda体包含return之外的任何语句，则编译器假定此lambda返回void。
被推断返回void的lambda不能返回值。
当我们需要为一个lambda定义返回类型时，必须使用位置返回类型。*/
//10.3.4 参数绑定
/*对于只在一两个地方使用的简单操作，lambda表达式最有用。
如果需要在多个地方使用相同操作，通常应该定义一个函数。
如果一个操作需要很多语句才能完成，通常使用 函数更好。

如果lambda的捕获列表为空，通常可以用函数来代替它。
但对于捕获局部变量的lambda，用函数来替换它就不是那么容易了。
例如find_if可以调用lambda，而不能用函数作为find_if的参数。

1.标准库bind函数
解决传递参数的方法是使用一个新的名为bind的标准库函数，定义在头文件functional中。
可以将bind函数看作一个通用的函数适配器，
它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表。
调用bind的一般形式为：
auto  newCallable=bind(callable,arg_list);
其中newCallable本身是一个可调用对象，arg_list是一个逗号分隔的参数列表，对应给定的callable的参数。
当调用newCallable时，newCallable会调用callable，并传递它arg_list中的参数。
arg_list 中的参数可能包含形如_n的名字，其中n是一个整数。
这些参数是“占位符”，表示newCallable的参数，它们占据了传递给newCallable的参数的“位置”。
数值n表示生成的可调用对象中参数的位置：_1为newCallable的第一个参数，_2为第二个参数。
2.绑定check_size的sz参数
3.使用placeholders名字
名字_n都定义在一个名为placeholders的命名空间中，这个命名空间本身定义在std命名空间中。
using std::placeholder::_1;
可以用如下代替
using namespace namespace_name;
写为：
using namespace std::placeholder;
placeholders也定义在functional头文件中。
4.bind的参数
可以用bind修正参数的值。
可以用bind绑定给定可调用对象中的参数或重新安排其顺序。
//g是一个有两个参数的可调用对象
auto g=bind(f,a,b,_2,c,_1);
bind调用会将g(_1,_2)映射为f(a,b,_2,c,_1)
对g的调用会调用f，用g的参数代替占位符，再加上绑定的参数a,b和c。
5.用bind重排参数顺序
可以用bind颠倒isShorter的含义。
6.绑定引用参数
与lambda类似，有时对有些绑定的参数我们希望以引用的方式传递，或是要绑定参数的类型无法拷贝。
如果我们希望传递给bind一个对象而又不拷贝它，就必须使用标准库ref函数。
函数ref返回一个对象，包含给定的引用，此对象是可以拷贝的。
标准库中还有一个cref函数，生成一个保存const引用的类。
与bind一样，函数ref和cref也定义在头文件functional中。
7.向后兼容：参数绑定
旧版本绑定函数参数的语言特性限制更多。
标准库定义了两个分别名为bind1st和bind2nd的函数。
接受一个函数作为参数，生成一个新的可调用对象，该对象调用给定函数，并将绑定的参数传递给它。
但这些函数分别只能绑定第一个或第二个参数。*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using std::placeholders::_1;
using namespace std::placeholders;

//比较函数，用来按长度排序单词
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void print(vector<string> vec)
{
    for (auto v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}
void print(vector<int> vec)
{
    for (auto v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}
void elimDups(vector<string> &words)
{
    //按字典序排序words，以便查找重复单词
    sort(words.begin(), words.end());
    print(words);
    //unique重排输入范围，使得每个单词只出现一次
    //排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
    auto end_unigue = unique(words.begin(), words.end());
    print(words);
    //使用向量操作erase删除重复单词
    words.erase(end_unigue, words.end());
    print(words);
}
//按长度由短至长排序words
void fun_1()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words); //将words按字典序重排，并消除重复单词
    //按长度重新排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), isShorter);
    print(words);
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return ((ctr > 1) ? (word + ending) : word);
}
void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    elimDups(words); //将words按字典顺序排序，删除重复单词
    //按长度重新排序，长度相同的单词维持字典序
    //stable_sort(words.begin(), words.end(), isShorter);

    //按长度重新排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    //获取一个迭代器，指向第一个满足size()>=sz的元素
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a)
                      { return a.size() >= sz; });
    //sz为隐式捕获，值捕获方式
    wc = find_if(words.begin(), words.end(), [=](const string &a)
                 { return a.size() >= sz; });
    //计算满足size>=sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    //打印长度等于给定值的单词，每个单词后面接一个空格。
    for_each(wc, words.end(), [&os, c](const string &s)
             { os << s << c; }); //当for_each执行时，biggies中的变量时存在的。
    cout << endl;
    for_each(wc, words.end(), [&, c](const string &s) //os隐式捕获，c显式捕获
             { os << s << c; });
    cout << endl;
    for_each(wc, words.end(), [=, &os](const string &s) //c隐式捕获，os显式捕获
             { os << s << c; });
    cout << endl;
}
void fun_2()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
}
void fun_3()
{
    size_t v1 = 42; //局部变量
    //将v1拷贝到名为f1的可调用对象
    auto f1 = [v1]
    { return v1; };
    //对象f2包含v1的引用
    auto f2 = [&v1]
    { return v1; };
    //f3可以改变它所捕获的变量的值
    auto f3 = [v1]() mutable
    { return ++v1; };
    //&v1是一个非const变量的引用
    //可以同f4中的引用来改变它
    auto f4 = [&v1]() mutable
    { return ++v1; };
    v1 = 0;
    auto j1 = f2(); //j1为42；f1保存了我们创建它时v1的拷贝
    auto j2 = f2(); //j2为0；f2保存v1的引用，而非拷贝
    auto j3 = f3(); //j3为43；
    auto j4 = f4(); //j4为2；
    cout << f1() << " " << j1 << endl;
    cout << f2() << " " << j2 << endl;
    cout << f3() << " " << j3 << endl;
    cout << f4() << " " << j4 << endl;

    vector<int> vi{-1, 2, -3, 4, -5, 6, -7, 8, -9, 0};
    transform(vi.begin(), vi.end(), vi.begin(), [](int i)
              { return i < 0 ? -i : i; });
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int
              {
                  if (i < 0)
                      return -i;
                  else
                      return i;
              });
    print(vi);
}
//函数替换lambda
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
void biggies2(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    elimDups(words); //将words按字典顺序排序，删除重复单词
    //按长度重新排序，长度相同的单词维持字典序
    //stable_sort(words.begin(), words.end(), isShorter);

    //按长度重新排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    //获取一个迭代器，指向第一个满足size()>=sz的元素,使用check_size的版本
    auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
    //计算满足size>=sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    //打印长度等于给定值的单词，每个单词后面接一个空格。
    for_each(wc, words.end(), [&os, c](const string &s)
             { os << s << c; }); //当for_each执行时，biggies中的变量时存在的。
    cout << endl;
    for_each(wc, words.end(), [&, c](const string &s) //os隐式捕获，c显式捕获
             { os << s << c; });
    cout << endl;
    for_each(wc, words.end(), [=, &os](const string &s) //c隐式捕获，os显式捕获
             { os << s << c; });
    cout << endl;
}

ostream &prints(ostream &os,const string &s,char c)
{
    return os << s << c;
}
void biggies3(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    elimDups(words); //将words按字典顺序排序，删除重复单词
    //按长度重新排序，长度相同的单词维持字典序
    //stable_sort(words.begin(), words.end(), isShorter);

    //按长度重新排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    //获取一个迭代器，指向第一个满足size()>=sz的元素,使用check_size的版本
    auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
    //计算满足size>=sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    //打印长度等于给定值的单词，每个单词后面接一个空格。
    for_each(wc, words.end(), [&os, c](const string &s)
             { os << s << c; }); //当for_each执行时，biggies中的变量时存在的。
    cout << endl;
    for_each(wc, words.end(), [&, c](const string &s) //os隐式捕获，c显式捕获
             { os << s << c; });
    cout << endl;
    for_each(wc, words.end(), [=, &os](const string &s) //c隐式捕获，os显式捕获
             { os << s << c; });
    cout << endl;
    for_each(words.begin(), words.end(), bind(prints, ref(os), _1, c));
    cout << endl;
}
void fun_4()
{
    //check6是一个可调用对象，接受一个string类型的参数
    //并用此string和值6来调用check_size
    auto check6 = bind(check_size, _1, 6);
    string s = "hello";
    bool b1 = check6(s); //check6(s)会调用check_size(s,6)
    cout << b1 << endl;
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies2(words, 4);
    elimDups(words); //将words按字典序重排，并消除重复单词
    stable_sort(words.begin(), words.end(), bind(isShorter,_2,_1));
    print(words);
    //按单词长度由短至长排列
    sort(words.begin(), words.end(), isShorter);
    print(words);
    //按单词长度由长至短排列
    sort(words.begin(), words.end(), bind(isShorter,_2,_1));
    print(words);
    biggies3(words, 4);
}
int main()
{
    fun_1();
    fun_2();
    fun_3();
    fun_4();
    return 0;
}
