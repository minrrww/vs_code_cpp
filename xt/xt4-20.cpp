#include <iostream>

using namespace std;
class Complex
{
public:
    Complex(double x, double y) : a(x), b(y) {}
    Complex(double x) : a(x), b(0) {}
    Complex(const Complex &c) : a(c.a), b(c.b) {}
    ~Complex() {}
    void add(Complex C)
    {
        a = a + C.a;
        b = b + C.b;
    }
    void show()
    {
        if (b == 0)
            cout << a << endl;
        else if (a == 0)
            cout << b << "i" << endl;
        else
            cout << a << "+" << b << "i" << endl;
    }

protected:
private:
    double a, b;
};
int main()
{
    Complex c1(0, 5);
    Complex c2=4.5;
    c2=Complex(0,6);
    c1.add(c2);
    c1.show();
    Complex(8.2, 5).show();
    return 0;
}
