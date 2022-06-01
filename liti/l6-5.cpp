#include <iostream>
using namespace std;
int main(){
    int i;
    int *ptr= &i;
    i = 10;
    *ptr = 50;
    cout << "i=" << i << endl;
    cout << "*ptr=" << *ptr << endl;
    cout << "ptr=" << ptr << endl;
    int b;
    ptr = &b;
    cout << "ptr=" << ptr << endl;
    return 0;
}
