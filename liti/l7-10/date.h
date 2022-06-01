#ifndef _DATE_H_
#define _DATE_H_
//日期类
class Date
{
private:
    int year;      //年
    int month;     //月
    int day;       //日
    int totalDays; //该日期是从公元元年1月1日开始的第几天
public:
    //用年月日构造日期
    Date(int year, int month, int day);
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    //获得当月有多少天
    int getMaxDay() const;
    //判断当年是否为闰年
    bool isLeapYear() const
    {
        return (((year % 4 == 0) && (year % 100 != 0)) ||(year % 400 == 0));
    }
    //输入当前日期
    void show() const;
    //计算两个日期之间差多少天
    int distance(const Date &date) const
    {
        return totalDays - date.totalDays;
    }
};

#endif
