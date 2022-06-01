#include <iostream>

using namespace std;
class Base
{
private:
public:
    virtual void fun1() { cout << "Base::fun1()" << endl; }
    virtual ~Base() {}
};
class Derived1 : public Base
{
private:
public:
    virtual void fun1() { cout << "Derived1::fun1()" << endl; }
    virtual void fun2() { cout << "Derived1::fun2()" << endl; }
};
class Derived2 : public Derived1
{
private:
public:
    virtual void fun1() { cout << "Derived2::fun1()" << endl; }
    virtual void fun2() { cout << "Derived2::fun2()" << endl; }
};
void fun(Base *b)
{
    b->fun1();
    Derived1 *d = dynamic_cast<Derived1 *>(b);
    if (d!= 0)
        d->fun2();
}

int main()
{
    Base b;
    fun(&b);
    Derived1 d1;
    fun(&d1);
    Derived2 d2;
    fun(&d2);
    return 0;
}
