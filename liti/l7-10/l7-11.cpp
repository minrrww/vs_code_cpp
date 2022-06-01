#include <iostream>
#include "account.h"
using namespace std;

int main()
{
    Date date(2008, 11, 1); //起始日期
    //建立几个帐户
    SavingsAccount sa1(date, "s3755217", 0.015);
    SavingsAccount sa2(date, "02342342", 0.015);
    CreditAccount ca(date, "c5392394", 10000, 0.000, 50);
    Account *accounts[] = {&sa1, &sa2, &ca};
    const int n = sizeof(accounts) / sizeof(Account *);
    for (int i = 0; i < n;i++){
        accounts[i]->show();
        cout << endl;
    }
    return 0;
}
