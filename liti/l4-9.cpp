#include <cmath>
#include <iostream>
using namespace std;
class SavingAccount
{
public:
    SavingAccount(int date, int id, double rate); //构造函数
    int getId() { return id; }                    //获得账号
    double getBalance() { return balance; }       //获得余额
    double getRate() { return rate; }             //获得年利率
    void deposit(int date, double amount);        //存入现金
    void withdraw(int date, double amount);       //取出现金
    void settle(int date);                        //结算利息
    void show();                                  //

private:
    int id;                               //账号
    double balance;                       //余额
    double rate;                          //存款年利率
    int lastDate;                         //上次变更余额信息
    double accumulation;                  //余额按日累加之和
    void record(int date, double amount); //记录一笔账
    const double accumulate(int date)     //获得到指定日期为止的存款金额按日累积值
    {
        return accumulation + balance * (date - lastDate);
    };
};
SavingAccount::SavingAccount(int date, int id, double rate) :
id(id), balance(0), rate(rate), lastDate(date), accumulation(0)
{
    cout << date << "\t#" << id << " is created" << endl;
}
void SavingAccount::record(int date, double amount)
{
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount * 100 + .5) / 100;
    balance += amount;
    cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
void SavingAccount::deposit(int date, double amount)
{
    record(date, amount);
}
void SavingAccount::withdraw(int date, double amount)
{
    if (amount > getBalance())
        cout << "Error:not enough money" << endl;
    else
        record(date, -amount);
}
void SavingAccount::settle(int date)
{
    double interest = accumulate(date) * rate / 365;
    if (interest != 0)
        record(date, interest);
    accumulation = 0;
}
void SavingAccount::show()
{
    cout << "#" << id << "\tBalance:" << balance;
}
int main()
{
    SavingAccount sa0(1, 21325302, 0.015);
    SavingAccount sa1(1, 58320212, 0.015);
    sa0.deposit(5, 5000);
    sa1.deposit(25, 10000);
    sa0.deposit(45, 5500);
    sa1.withdraw(60, 4000);
    sa0.settle(90);
    sa1.settle(90);
    sa0.show();
    cout << endl;
    sa1.show();
    cout << endl;
    return 0;
}
