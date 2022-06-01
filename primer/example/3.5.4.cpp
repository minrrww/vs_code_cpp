//eaample-3.5.4-.cpp
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    string s1 = "A string example"; //声明并定义一个string类型s1
    cout << ++n;                    //1
    //用下标输出s1每一个字符
    for (decltype(s1.size()) i = 0; i != s1.size(); i++)
    {
        s1[i] = char(s1[i] + 1); //使用下标修改字符
        cout << s1[i];           //用下标输出s1每一个字符
    }
    cout << endl;

    vector<char> vc(s1.begin(), s1.end());
    //用下标输出vc每一个字符
    for (decltype(vc.size()) i = 0; i != vc.size(); i++)
    {
        vc[i] = char(vc[i] + 1); //使用下标修改字符
        cout << vc[i];           //用下标输出s1每一个字符
    }
    cout << endl;

    //范文for循环修改字符
    for (auto &st1 : s1)
        st1 = st1 + 1;
    cout << ++n; //2
    //用迭代器输出s1重新赋值后的每一个字符
    for (auto i = s1.begin(); i != s1.end(); i++)
        cout << *i;
    cout << endl;

    string s2 = "A different string";    //声明并定义一个string类型s2
    cout << ++n;                         //3
    cout << s1 << " " << s2 << endl;     //用输出流连接s1,s2
    cout << ++n;                         //4
    cout << (s1 < s2 ? s1 : s2) << endl; //比较s1,s2大小,因s1>s2,输出s2
    string largeStr = s1 + " " + s2;     //string对象相加
    cout << ++n;                         //5
    cout << largeStr << endl;

    //指针不能指向表达式和字面值，但是可以指向字符串字面值，把字符串字面值看着字符数组
    char *const cap1 = "A string example"; //定义一个指针cap1，指向字符串字面值
    //不能改变cap1的值，只能看着指向常量字符数组
    cout << ++n; //6
    //用下标输出cap1每一个字符，用strlen
    //strlen不包括字符串末尾的空字符'\0'
    for (decltype(strlen(cap1)) i = 0; i != strlen(cap1); i++)
        cout << cap1[i];
    /*不支持范围for循环，迭代器
    for (auto st1 : cap1)
        cout << st1;
    cout << endl;
    for (auto i = begin(cap1); i != end(cap1); i++)
        cout << cap1[i];
    cout << endl;
    */
    cout << endl;
    cout << ++n;                         //7
    cout << cap1 << endl;                //直接输出指针，输出字符数组
    cout << ++n;                         //
    cout << *cap1 << endl;               //输出解引用，输出指针指向的首字符
    cout << ++n;                         //9
    cout << cap1 + 1 << endl;            //支持指针运算，输出还是字符数组
    cout << ++n << endl;                 //10
    cout << cap1 + strlen(cap1) << endl; //输出最后一个字符，即'\0'
    cout << ++n << endl;                 //11
    cout << cap1 + 17 << endl;           //超范围输出看紧邻定义的常量，字符串字面值在同一内存区域？
    cout << ++n << endl;                 //12
    cout << *(cap1 + 17) << endl;        //超范围输出指针解引用？不知道输出为空？

    char *const cap2 = "A different string"; //定义一个指针cap2，指向字符串字面值
    char largetCap[37];                      //定义一个字符数组，它的大小会影响输出结果
    strcpy(largetCap, cap1);                 //将cap1拷贝给largetCap
    strcat(largetCap, " ");                  //将largetCap末尾加上一个空格
    strcat(largetCap, cap2);                 //将cap2连接到largetCap后面
    cout << ++n;                             //13
    cout << largetCap << endl;               //largetCap的长度影响输出结果
    cout << ++n;                             //14
    //比较指针，不管怎么理解编译器，只能说无意义
    cout << (cap1 < cap2 ? cap1 : cap2) << endl;
    cout << ++n; //15
    //比较字符串大小，'s'>'d',所以cap1指向的数组大于cap2指向的数组
    //strcmp(cap1,cap2)返回正值，条件为假，输出cap2
    cout << (strcmp(cap1, cap2) < 0 ? cap1 : cap2) << endl;

    char ca1[] = "A string example"; //声明并定义一个字符数组ca1
    cout << ++n;                     //16
    //用下标输出s1每一个字符
    for (decltype(strlen(ca1)) i = 0; i != strlen(ca1); i++)
        cout << ca1[i];
    cout << endl;

    //范文for循环为每一字符赋值
    for (auto &st1 : ca1)
        st1 = st1 + 1;
    cout << ++n; //17
    //用迭代器输出重s1新赋值后d的每一个字符
    for (auto i = begin(ca1); i != end(ca1); i++)
        cout << *i;
    cout << endl;

    const char ca2[] = "A different string"; //声明并定义一个字符数组ca2
    char largetCh[36];                       //定义一个空字符数组
    strcpy(largetCh, ca1);                   //将ca1拷贝给largetCh
    strcat(largetCh, " ");                   //将largetCh末尾加上一个空格
    strcat(largetCh, ca2);                   //将ca2连接到largetCh后面
    cout << ++n;                             //18
    cout << largetCh << endl;
    cout << ++n;                               //19
    cout << ca1 + 7 << " " << ca2 + 7 << endl; //支持指针运算
    cout << ++n;                               //20
    //比较指针，比较两个不同对象的指针无意义
    cout << (ca1 > ca2 ? ca1 : ca2) << endl;
    cout << ++n; //21
    //比较字符串大小，'B'>'A',所以cap1指向的数组大于cap2指向的数组
    //strcmp(cap1,cap2)返回正值，条件为假，输出cap2
    cout << (strcmp(ca1, ca2) < 0 ? ca1 : ca2) << endl;
    return 0;
}
/*输出结果很奇怪，所以尽量不用C风格字符串
1B!tusjoh!fybnqmf
C"uvtkpi"gzcorng
2C"uvtkpi"gzcorng
3C"uvtkpi"gzcorng A different string
4A different string
5C"uvtkpi"gzcorng A different string
6A string example
7A string example
8A
9 string example
10

11
A different string
12

13A string example A different string
14A string example
15A different string
16A string example
17B!tusjoh!fybnqmf
18B!tusjoh!fybnqmf A different string
19h!fybnqmf rent string
20B!tusjoh!fybnqmf
21A different string
*/
