#include <iostream>
using namespace std;
class Clock
{
public:
    Clock(int newH = 0, int newM = 0, int newS = 0) : hour(newH), minute(newM), second(newS){};
    Clock(const Clock &c):hour(c.hour),minute(c.minute),second(c.second){}
    void setTime(int newH, int newM, int newS)
    {
        hour = newH;
        minute = newM;
        second = newS;
    }
    void showTime()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
    ~Clock() {} //析构函数，对象生存期即将结束时被调用，完成一些清理工作
private:
    int hour, minute, second;
};
int main()
{
    Clock myClock(2, 35, 36); //构造函数在对象被创建时利用特定的值构造对象，将对象初始化为一个特定状态
    cout << "First time set and output:" << endl;
    myClock.showTime();
    myClock.setTime(8, 30, 30);
    cout << "Second time set and output:" << endl;
    myClock.showTime();
    return 0;
}
