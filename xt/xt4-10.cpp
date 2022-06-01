#include <iostream>

using namespace std;
enum sex
{
    male,
    female
};
class BirthofDate
{
public:
    BirthofDate(int Year, int Month, int Day) : year(Year), month(Month), day(Day){}
    BirthofDate(const BirthofDate &b) : year(b.year), month(b.month), day(b.day) {}
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
protected:
private:
    int year, month, day;
};
class Personnel
{
public:
    Personnel(int Num, enum ::sex S,BirthofDate B,string Id) : num(Num), s(S), b(B), id(Id) {}
    Personnel(const Personnel &p) : num(p.num), s(p.s),b(p.b), id(p.id) {}
    ~Personnel(){}
    int getNum() { return num; }
    sex getS() { return s; }
    BirthofDate getB() { return b; }
    string getId() { return id; }
    void show();

protected:
private:
    int num;
    enum ::sex s;
    BirthofDate b;
    string id;
};
inline void Personnel::show(){
    cout << "编号：\t\t" << getNum() << endl;
    cout << "性别：\t\t" << (getS()?"female":"male") << endl;
    cout << "出生日期：\t" << getB().getYear() <<"年"<<getB().getMonth()<<"月"<<getB().getDay()<<"日"<< endl;
    cout << "身份证号：\t" << getId() << endl;
}

int main()
{
    BirthofDate wrm_birth_date(1986, 10, 6);
    Personnel wrm(15, male, wrm_birth_date, "510923198610063931");
    wrm.show();
    return 0;
}
