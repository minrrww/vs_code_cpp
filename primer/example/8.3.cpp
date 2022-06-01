//8.3 string流
/*sstream 头文件定义类三个类型来支持内存IO。
istringstream 从string读取数据
ostringstream 向string写入数据
stringstream 既可以从string读数据，也可以向string写数据。
表8.5：stringstream特有的操作
sstream strm        strm是一个未绑定的stringstream对象。
                    sstream是头文件sstream中定义的一个类型
sstream strm(s)     strm是一个sstream对象，保存strings的一个拷贝。
                    此构造函数时explicit的。
strm.str()          返回strm所保存的string拷贝
strm.str(s)         将string s拷贝到strm中。返回void*/
//8.3.1 使用istringstream
/*istringstream必须用sstream头文件*/
//8.3.2 使用ostringstream
/*我们用标准输出运算符<<向ostringstream对象写入数据，实际上转换为string。*/
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
//成员默认为共有
struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;         //分别保存来自输入的一行和单词
    vector<PersonInfo> people; //保存来自输入的所有记录
    //逐行从输入读取数据，直至cin遇到文件尾(或其他错误)
    while (getline(cin, line))
    {
        PersonInfo info;                 //创建一个保存此记录数据的对象
        istringstream record(line);      //将记录绑定到刚读入的行
        record >> info.name;             //读取名字
        while (record >> word)           //读取电话号码
            info.phones.push_back(word); //保存它们
        people.push_back(info);          //将记录追加到people末尾
    }
    for (const auto &entry : people) //对people中每一项
    {
        ostringstream formatted, badNums;     //每个循环步创建对象
        for (const auto &nums : entry.phones) //对每个数
        {
            if (nums.size() == 0)
            {
                badNums << " " << nums;
            }
            else
                formatted << " " << nums;
        }
        if (badNums.str().empty())           //没有错误的数
            cout << entry.name << " "        //打印名字
                 << formatted.str() << endl; //和格式化的数
        else                                 //否则，打印名字和错误的数
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
    return 0;
}
