//example-3.3.2-.cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1, v2; //空vector对象
    for (int i = 0; i != 100; i++)
        v2.push_back(i); //依次把整数值放到v2尾端
    //循环结束后v2有100个元素，值丛0-99

    //从标准库中读取单词，将其作为vector对象的元素
    /*string word;
    vector<string> text; //空vector对象
    while (cin >> word)
    {
        text.push_back(word); //把word添加到text后面
    }*/
    if (!v2.empty())
        cout << v2.size() << v2[v2.size() - 1] << endl;
    v1 = v2;
    if (!(v1 != v2))
        cout << (v1 == v2) << (v1 < v2) << (v1 > v2) << (v1 <= v2) << (v1 >= v2) << endl;

    for (auto &i : v2)
        i *= i;

    //decltype(v2.size())可以用vector<int>::size_type代替
    for (decltype(v2.size()) i = 0; i < v2.size(); i++)
    {
        if ((i + 1) % 10)
            cout << v2[i] << "\t";
        else
            cout << v2[i] << endl;
    }
    cout << endl;
    //以10分为一个分数段统计成绩单数量：0~9，……，100
    unsigned grade;
    vector<unsigned> scores(11, 0); //11个分数段，全部初始值为0
    while (cin >> grade)            //读取成绩
    {
        if (grade <= 100)         //只处理有效成绩
            ++scores[grade / 10]; //将对应的分数段的计数器加1
    }
    for (unsigned s : scores) //对于scores中的每个计数值
        cout << s << " ";     //输出当前的计数值
    cout << endl;
    return 0;
}
/*
123
^Z
10099
10011
0       1       4       9       16      25      36      49      64      81
100     121     144     169     196     225     256     289     324     361
400     441     484     529     576     625     676     729     784     841
900     961     1024    1089    1156    1225    1296    1369    1444    1521
1600    1681    1764    1849    1936    2025    2116    2209    2304    2401
2500    2601    2704    2809    2916    3025    3136    3249    3364    3481
3600    3721    3844    3969    4096    4225    4356    4489    4624    4761
4900    5041    5184    5329    5476    5625    5776    5929    6084    6241
6400    6561    6724    6889    7056    7225    7396    7569    7744    7921
8100    8281    8464    8649    8836    9025    9216    9409    9604    9801
42 65 95 100 39 67 95 76 88 76 83 92 76 93^Z
0 0 0 1 1 0 2 3 2 4 1
*/
