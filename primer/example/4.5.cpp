#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i = 0, j;
    j = ++i; //j=i=i+1;j=1,i=1;
    cout << i << " " << j << endl;
    j = i++; //j=i=1,i=i+1;j=1,i=2
    cout << i << " " << j << endl;
    i = 0;
    j = i++; //j=i=0,i=i+1;j=0,i=1
    cout << i << " " << j << endl;
    j = ++i; //j=i=i+1;j=2,i=2;
    cout << i << " " << j << endl;

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pbeg = v.begin();
    //输出元素直至遇到第一个负值为止
    while (pbeg != v.end() && *pbeg >= 0)
        //后置递增优先级高于解引用，相当于*pbeg;++pbeg;
        cout << *pbeg++ << endl; //输出当前值并将pbeg向前移动一个元素

    string s = "welcome to China.";
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    {
        *it = toupper(*it);
        cout << *it;
    }
    cout << endl;
    auto beg = s.begin();
    while (beg != s.end() && !isspace(*beg))
    {
        *beg = toupper(*beg);//*beg = toupper(*beg++)未定义行为
        cout << *beg;
        beg += 1;
    }
    cout << endl;

    return 0;
}
