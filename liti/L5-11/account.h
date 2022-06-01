//account.h
#ifndef _ACCOUNT_H_ //如果"_ACCOUNT_H_"未被定义过
                    //编译程序段1
                    //否则编译程序段2
                    //没有程序段2,省略#else
#define _ACCOUNT_H_
class SavingsAccount
{
public:
    SavingsAccount(int date, int id, double rate);
    int getId() const { return id; }
    double getBalance() const { return balance; }
    double getRate() const { return rate; }
    static double getTotal() { return total; }//静态函数
    void deposit(int date, double amount);
    void withdraw(int date, double amount);
    void settle(int date);
    void show() const;//常函数

private:
    int id;
    double balance;
    double rate;
    int lastDate;
    double accumulation;
    static double total;
    void record(int date, double amount);
    double accumulate(int date) const{
        return accumulation + balance * (date - lastDate);
    }
};
#endif//_ACCOUNT_H_
