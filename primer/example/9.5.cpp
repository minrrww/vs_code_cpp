//9.5 额外的string操作
//9.5.3 string搜索操作
/*每个搜索操作都返回一个string::size_type值，
搜索失败返回一个const string：：size_type值npos=-1
表9.14：string 搜索操作
搜索操作返回指定字符出现的下标，如果未找到则返回npos。
s.find(args)               在s中查找args第一次出现的位置
s.rfind(args)              在s中查找args最后一次出现的位置
s.find_first_of(args)      在s中查找args中任何一个字符第一次出现的位置
s.find_last_of(args)       在s中查找args中任何一个字符最后一次出现的位置
s.find_first_not_of(args)  在s中查找第一个不在args中的字符
s.find_last_not_of(args)   在s中查找最后一个不在args中的字符
args必须是以下形式之一
c,pos      从s中位置pos开始查找格字符c。pos默认为0
s2,pos     从s中位置pos开始查找格字符串s2。pos默认为0
cp,pos     从s中位置pos开始查找指针cp指向的以空字符结尾的C风格字符串。pos默认为0
cp,pos,n   从s中位置pos开始查找指针cp指向的数组的前n个字符。pos和n无默认值
*/
//9.5.4 compare函数

#include <iostream>
#include <vector>
using namespace std;
//9.5.1 构造string的其他方法
/*表9.11：构造string的其他方法
n、len2和pos2都是无符号值
string s(cp,n)          s使cp指向的数组中前n个字符的拷贝。此数组至少应该包含n个字符。
string s(s2,pos2)       s是string s2从下标pos2开始的字符的拷贝。
                        若pos2>s2.size()，构造函数的行为未定义。
string s(s2,pos2,len2)  s是string s2从下标pos2开始len2个字符的拷贝。
                        若pos2>s2.size()，构造函数的行为未定义。
                        不管len2的值是多少，构造函数直到拷贝s2.size()-pos2个字符
这些构造函数接受一个string或一个const char*参数，还接受（可选的）指定拷贝多少个字符的参数。
从const char*创建string时，指针指向的数组必须以空字符结尾，拷贝操作遇到空字符时停止。
如果未传递计数值且数组也未以空字符结尾，或给定的计数值大于数组大小，则构造函数的行为未定义。
如果开始位置大于size，则构造函数抛出一个out_of_range异常。
1.substr操作
表9.12：子字符串操作
s.substr(pos,n) 返回一个string，包含s中从pos开始的n个字符的拷贝。
pos的默认值为0。n的默认值为s.size()-pos，即拷贝从pos开始的所有字符。
如果开始位置超过了string的大小，则substr函数抛出一个out_of_range异常。
如果开始位置加上计数值大于string的大小，则substr会调整计数值，只拷贝到string的末尾。*/
void fun9_5_1()
{
    const char *cp = "Hello World!!！"; //以空字符结束的数组
    char noNull[] = {'H', 'i'};         //不是以空字符结束的数组
    string s1(cp);                      //拷贝cp中的字符直到遇到控制符；s1=="Hello World!!!"
    string s2(noNull, 2);               //从noNull拷贝两个字符；s2=="Hi"
    //string s3(noNull);                //未定义：noNull不是以空字符结束
    string s4(cp + 6, 5); //从cp[6]开始拷贝5个字符；s4=="World"
    string s5(s1, 6, 5);  //从cp[6]开始拷贝5个字符；s5=="World"
    string s6(s1, 6);     //从cp[6]开始拷贝，直到s1末尾；s6=="World!!!"
    string s7(s1, 6, 20); //正确，只拷贝到s1末尾；s7=="World!!!"
    //string s8(s1, 16);                //抛出一个out_of_range异常。
    cout << s1 << " " << s2 << " " << s4 << " "
         << s5 << " " << s6 << " " << s7 << endl;
    string s("hello world");
    string str1 = s.substr(0, 5);  //str1=hello
    string str2 = s.substr(6);     //str2=world
    string str3 = s.substr(6, 11); //str3=world
    //string str4 = s1.substr(14); //抛出一个out_of+range异常。
    cout << str1 << " " << str2 << " " << str3 << endl;
}
//9.5.2 改变string的其他方法
/*string类型支持顺序容器的赋值运算符以及assign、insert和erase操作，还定义了额外的insert和erase。
除了迭代器的insert和erase，还有下标版本
string类型还提供了接受C风格字符数组的insert和assign版本。
1.append和replace函数
string类定义了两个额外的成员函数：append和replace，这两个函数可以改变string的内容。
表9.13：修改string的操作
s.insert(pos,args)   在pos之前插入args指定的字符。pos可以是一个下标或一个迭代器。
接受下标版本返回一个指向s的引用；接受迭代器的版本返回指向第一个插入字符的迭代器。
s.erase(pos,len)     删除从位置pos开始的len个字符。
如果len被省略，则删除从pos开始直到s末尾的所有字符，返回一个指向s的引用
s.assign(args)       将s中的字符替换为args指定的字符。返回一个指向s的引用
s.append(args)       将args追加到s。返回一个指向s的引用
s.replace(range,args)删除s中范围range内的字符，替换为args指定的字符。
range或者是一个下标和一个长度，或者是一对指向s的迭代器。返回一个指向s的引用。
args可以是下列形式之一；append和assign可以使用所有形式。
str不能与s相同，迭代器b和e不能指向s。
str          字符串str
str,pos,len  str中从pos开始最多len个字符
cp,len       从cp指向的字符数组的前（最多）len个字符
cp           cp指向的以空字符结尾的字符数组
n,c          n个字符c
b,e          迭代器b和e指定的范围内的字符
初始化列表   花括号包围的，以逗号分隔的字符列表
replace和insert所允许的args形式依赖于range和pos是如何指定的。
replace           replace       insert        insert          args可以是
(pos,len,args)    (b,e,args)    (pos,args)    (iter,args)
是                是            是            否              str
是                否            是            否              str,pos,len
是                是            是            否              cp,len
是                是            否            否              cp
是                是            是            是              n,c
否                是            否            是              b2,e2
否                是            否            是              初始化列表

2.改变string的多种重载函数
assign总是替换string中的所有内容，append总是将新字符追加到string末尾。
replace可以通过一个位置和一个长度来指定位置，也可以通过一个迭代器范围来指定。
insert允许用一个下标或一个迭代器来指定插入点。新元素插入到下标或迭代器之前的位置。
可以用好几种方式来指定要添加到string中的字符。
来自另一个string，一个字符指针，花括号包围的字符列表，一个字符和一个计数值。*/
void fun9_5_2()
{
    string s("hello world");
    s.insert(s.size(), 5, '!'); //在s末尾插入5个感叹号
    cout << s << endl;
    s.erase(s.size() - 5, 5); //从s删除最后的5个字符
    cout << s << endl;

    const char *cp = "Stately, plump Buck";
    s.assign(cp, 7); //s=="Stately"
    cout << s << endl;
    s.insert(s.size(), cp + 7); //s=="Stately, plump Buck";
    cout << s << endl;

    string s1 = "some string", s2 = "some other string";
    s1.insert(0, s2); //在s中位置0之前插入s2的拷贝
    cout << s1 << endl;
    //在s1[0]之前插入s2中s2[0]开始的s2.size()个字符
    s1.insert(0, s2, 0, s2.size());
    cout << s1 << endl;

    string s3("C++ Prinmer"), s4 = s3; //将s3和s4初始化为"C++ Prinmer"
    cout << s3 << " " << s4 << endl;
    s3.insert(s3.size(), " 4th Ed."); //s3=="C++ Prinmer 4th Ed."
    s4.append(" 4th Ed.");            //等价方法：将" 4th Ed."追加到s4；s3==s4
    cout << s3 << " " << s4 << endl;
    //将"4th"替换为"5th"的等价方法
    s3.erase(11, 4);       //s3=="C++ Prinmer Ed."
    s3.insert(11, " 5th"); //s3=="C++ Prinmer 5th Ed."
    //从位置11开始，删除3个字符并插入"5th"
    s4.replace(11, 4, " 5th"); //等价方法：s3==s3
    cout << s3 << " " << s4 << endl;
    s3.replace(11, 4, " Fifth"); //s3=="C++ Prinmer Fifth Ed."
    cout << s3 << endl;
}
//9.5.3 string 搜索操作
/*每个搜索操作都返回一个名为string::size_type值，失败返回一个string::npos的static成员。
标准库npos定义为一个const string::size_type类型，初始化为-1。string::size_type是一个unsigned类型。

表9.14：string搜索操作
搜索操作返回指定字符出现的下标，如果未找到则返回npos。
s.find(args)                 //在s中args第一次出现的位置
s.rfind(args)                //在s中args最后一次出现的位置
s.find_first_of(args)        //在s中查找args中任何一个字符第一次出现的位置
s.fin_last_of(args)          //在s中查找args中任何一个字符最后一次出现的位置
s.find_first_not_of(args)    //在s中查找第一个不在args中的字符
s.find_last_not_of(args)     //在s中查找最后一个不在args中的字符
args必须是以下形式之一
c,pos              //从s中位置pos开始查找字符c。pos默认为0
s2,pos             //从s中位置pos开始查找字符串s2。pos默认为0
cp,pos             //从s中位置pos开始查找指针cp指向的以空字符结尾的C风格字符串。pos默认值为0
cp,pos,n           //从s中位置pos开始查找指针cp指向的数组的前n个字符。pos和n无默认值
1.指定在哪里开始搜索
2.逆向搜索*/
void fun9_5_3()
{
    string name("AnnaBelle");
    auto pos1 = name.find("Anna"); //pos1==0
    cout << pos1 << endl;
    //搜索是大小写敏感的。
    string lowercase("annabelle");
    pos1 = lowercase.find("Anna"); //pos1==npos
    cout << pos1 << endl;
    string numbers("0123456789"), name1("r2d2");
    //返回1，即name1中第一个数字的下标
    auto pos = name1.find_first_not_of(numbers);
    cout << pos << endl;
    string dept("03714p3");
    //返回5——字符'p'的下标
    pos = dept.find_first_not_of(numbers);
    cout << pos << endl;
    //1.指定在哪里开始搜索
    string::size_type pos2 = 0;
    //每步循环查找name中下一个数
    while ((pos2 = name.find_first_of(numbers, pos2)) != string::npos)
    {
        cout << "found number at index: " << pos2
             << " element is " << name[pos2] << endl;
        ++pos2; //移动到下一个字符
    }
    //2.逆向搜索
    string river("Mississippi");
    auto first_pos = river.find("is"); //返回1
    auto last_pos = river.rfind("is"); //返回4
    cout << first_pos << " " << last_pos << endl;
}
//9.5.4 compare函数
/*根据s是等于、大于还是小于参数指定的字符串，s.compare返回0、正数或负数。
表9.15：s.compare的几种参数形式
s2                  比较s和s2
pos1,n1,n2          将s中从pos1开始的n1个字符与s2进行比较
pos1,n1,s2,pos2,n2  将s中从pos1开始的n1个字符与s2中从pos2开始的n2个字符进行比较
cp                  比较s与cp指向的以空字符结尾的字符数组
pos1,n1,cp          将s中从pos1开始的n1个字符与cp指向的以空字符结尾的字符数组进行比较
pos1,n1,cp,n2       将s中从pos1开始的n1个字符与cp指向的地址开始的n2个字符进行比较*/
void fun9_5_4()
{
    string s1("1234567890"), s2("0123456789");
    cout << s1.compare(1, 5, s2, 2, 5) << endl;
}
//9.5.5 数值转换
/*新标准引入了多个函数，可以实现数值数据与标准库string之间的转换
如果string不能转换为一个数值，这些函数抛出一个invalid_argument异常。
如果转换得到的数值无法用任何类型来表示，则抛出一个out_of_range异常。
表9.16：string和数值之间的转换
to_string(val)  一组重载函数，返回数值val的string表示。val可以是任何算术类型。
                对每个浮点类型和int或更大的整型，都有相应版本的to_string。
                与往常一样，小整型会被提升。
stoi(s,p,b)     返回s的起始子串的数值，返回类型分别是int
stol(s,p,b)     long
stoul(s,p,b)    unsigned long
stoll(s,p,b)    long long
stoull(s,p,b)   unsigned long long。b表示转换所用的基数，默认值为10。
                p是size_t指针，用来保存s中第一个非数值字符的下标，p默认值为0，即函数不保存下标。
stof(s,p)       返回s的起始子串的数值，返回值类型分别是float
stod(s,p)       double
stold(s,p)      long double。参数p的作用与整数转换 函数中一样。*/
void fun9_5_5()
{
    int i = 42;
    string s = to_string(i); //将整数i转换为字符表示形式
    double d = stod(s);      //将字符串s转换为浮点数
    cout << d << endl;

    string s2 = "pi=3.14";
    //转换s中以数字开始的第一个子串，结果d=3.14
    d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
    cout << d << endl;
}
int main()
{
    fun9_5_1();
    fun9_5_2();
    fun9_5_3();
    fun9_5_4();
    fun9_5_5();
    return 0;
}
