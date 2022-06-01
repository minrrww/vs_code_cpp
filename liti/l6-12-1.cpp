#include <iostream>
using namespace std;
class Clock //时钟类
{
public:                                                                       //外部接口
    Clock(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {} //构造函数
    //比较两个时钟对象
    Clock &contrastClock(Clock &otherClock)
    {
        //相等
        bool con = hour == otherClock.hour && minute == otherClock.minute && second == otherClock.second;
        //如果相等返回当前对象，否则返回参数对象，此时必须用到this指针
        return con ? *this : otherClock;
    }
    inline void showTime() const
    { //显示当前对象时间
        cout << "Time  " << hour << ":" << minute << ":" << second << endl;
    }

private: //私有成员
    int hour;
    int minute;
    int second;
};
int main()
{
    Clock c1(12, 35, 36);            //第一个对象
    Clock c2(c1);                    //第二对象
    Clock c3(1, 35, 36);             //第三个对象
    c1.showTime();                   //显示对象1时间
    c2.showTime();                   //显示对象2时间
    c3.showTime();                   //显示对象3时间
    c1.contrastClock(c2).showTime(); //比较对象1,2，并显示返回时间
    c1.contrastClock(c3).showTime(); //比较对象1,3，并显示返回时间
}
/*
Time  12:35:36
Time  12:35:36
Time  1:35:36
Time  12:35:36
Time  1:35:36
*/
