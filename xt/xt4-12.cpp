#include <iostream>

using namespace std;
class DataType
{
private:
    char c;
    int i;
    float f;

public:
    DataType(char cc) : c(cc), i(int(cc)), f(float(cc)) {}
    DataType(int ii) : c(char(ii)), i(ii), f(float(ii)) {}
    DataType(float ff) : c(char(ff)), i(int(ff)), f(ff) {}
    DataType(char cc, int ii, float ff) : c(cc), i(ii), f(ff) {}
    DataType(const DataType &dt) : c(dt.c), i(dt.i), f(dt.f) {}
    char getC() { return c; }
    int getI() { return i; }
    float getF() { return f; }
};
int main()
{
    char c = 97;
    DataType a = 25;
    DataType b = c;
    DataType pi = 3.141593f;
    cout << a.getI() + pi.getI() << endl;
    cout << b.getC() << endl;
    cout << pi.getF() << endl;
    cout << DataType(96, 24, 3.14).getF() << endl;
    return 0;
}
